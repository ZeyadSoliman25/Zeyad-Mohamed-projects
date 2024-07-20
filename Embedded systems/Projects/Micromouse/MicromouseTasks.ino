#include <WiFi.h>
#include "Micromouse.h"

// FreeRTOS Objects
double              Wifi_Rx = 0; 
double              PID_Output = 0;
double              prevPID_Output = 0;
double              Kp = 20;
double              Ki = 1;
double              Kd = 1;
portMUX_TYPE        xCriticalSectionMutex;
EventGroupHandle_t  xEventFlags;


IR_t IR = {.ErrorValue = 0};


void vInputsProcessing(void *pvArguments)
{
  // Task's initialization
  // vLogEvent("Inputs Processing Task Running...\n");

  // TickType_t xLastWokenTickCount = xTaskGetTickCount();

  EventBits_t xBitsToWaitFor = (SAMPLE_SWITCHES_EVENT_BIT | SAMPLE_IR_EVENT_BIT);
  EventBits_t xEventFlagsValue;

  // Read from the switches and update the flags accordingly

  taskENTER_CRITICAL( &xCriticalSectionMutex );

  vUpdateSystemModes();

  IR.Instance.FarLeft   = digitalRead(FAR_LEFT_IR_PIN);
  IR.Instance.Left      = digitalRead(LEFT_IR_PIN);
  IR.Instance.Middle    = digitalRead(MIDDLE_IR_PIN);
  IR.Instance.Right     = digitalRead(RIGHT_IR_PIN);
  IR.Instance.FarRight  = digitalRead(FAR_RIGHT_IR_PIN);

  taskEXIT_CRITICAL( &xCriticalSectionMutex );

  while ( pdTRUE )
  { 
    xEventFlagsValue = xEventGroupWaitBits(xEventFlags, xBitsToWaitFor, pdFALSE, pdFALSE, portMAX_DELAY);

    if ( (xEventFlagsValue & SAMPLE_SWITCHES_EVENT_BIT) != 0 )
    {
      // Read from the switches and update the flags accordingly

      taskENTER_CRITICAL( &xCriticalSectionMutex );

      vUpdateSystemModes();
      xEventGroupClearBits(xEventFlags, SAMPLE_SWITCHES_EVENT_BIT);

      taskEXIT_CRITICAL( &xCriticalSectionMutex );

      // vLogEvent("Is Sytem Running? ");
      // vLogNumber((xEventGroupGetBits(xEventFlags) & SYSTEM_RUNNING_BIT));
      // vLogEvent("\n");

      // vLogEvent("Is Maze Solver? ");
      // vLogNumber((xEventGroupGetBits(xEventFlags) & RUN_MAZE_SOLVER_TASK_BIT));
      // vLogEvent("\n");

      // vLogEvent("Is Maze Execution Run? ");
      // vLogNumber((xEventGroupGetBits(xEventFlags) & MAZE_START_EXEC_RUN_EVENT_BIT));
      // vLogEvent("\n");
    }

    if ( (xEventFlagsValue & SAMPLE_IR_EVENT_BIT) != 0 )
    {

      taskENTER_CRITICAL( &xCriticalSectionMutex );

      IR.Instance.FarLeft   = digitalRead(FAR_LEFT_IR_PIN);
      IR.Instance.Left      = digitalRead(LEFT_IR_PIN);
      IR.Instance.Middle    = digitalRead(MIDDLE_IR_PIN);
      IR.Instance.Right     = digitalRead(RIGHT_IR_PIN);
      IR.Instance.FarRight  = digitalRead(FAR_RIGHT_IR_PIN);
    
      // uint8_t Error = IR.ErrorValue;

      // if ( 0b11111 ==  Error )
      // {
      //   xEventGroupSetBits(xEventFlags, INTERSECTION_DETECTED_BIT);
      // }

      xEventGroupClearBits(xEventFlags, SAMPLE_IR_EVENT_BIT);
      taskEXIT_CRITICAL( &xCriticalSectionMutex );
      
    // vLogEvent("IR Readings: ");
    // vLogNumber(IR.Instance.FarLeft);
    // vLogNumber(IR.Instance.Left);
    // vLogNumber(IR.Instance.Middle);
    // vLogNumber(IR.Instance.Right);
    // vLogNumber(IR.Instance.FarRight);
    // vLogEvent("\n");

    }

    // vTaskDelayUntil(&xLastWokenTickCount, pdMS_TO_TICKS(50));
  }

  vTaskDelete(NULL);
}




void vConnectivtyManager(void *pvArguments)
{
  // Task's initialization
  TickType_t xLastWokenTickCount = xTaskGetTickCount();

  const char *ssid = "Ahmed's iPhone";
  const char *password = "0123456789";

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.println("Connecting to WiFi...");
    WiFi.begin(ssid, password);

    vTaskDelay(pdMS_TO_TICKS(500));
  }

  Serial.println("Connected to WiFi successfully!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());


  while ( pdTRUE )
  {

    vTaskDelayUntil(&xLastWokenTickCount, pdMS_TO_TICKS(200));
  }

  vTaskDelete(NULL);
}




void vMazeSolver(void *pvArguments)
{
  // Task's initialization
  TickType_t xLastWokenTickCount;

  EventBits_t xEventFlagsValue;
  const EventBits_t xBitsToWaitFor = (SYSTEM_RUNNING_BIT | RUN_MAZE_SOLVER_TASK_BIT);

  while ( pdTRUE )
  {
    xEventGroupWaitBits(xEventFlags, xBitsToWaitFor, pdFALSE, pdTRUE, portMAX_DELAY);
    xLastWokenTickCount = xTaskGetTickCount();

    // xEventGroupClearBits(xEventFlags, RUN_MAZE_SOLVER_TASK_BIT);

    xEventFlagsValue = xEventGroupGetBits(xEventFlags);

    // Maze solving logic here

    // To do: detect when the test run and the execution run are over
    if ( (xEventFlagsValue & MAZE_START_TEST_RUN_EVENT_BIT) != 0 )
    {
      // Test run logic here
      // Path logging and optimizing
    }
    else if ( (xEventFlagsValue & MAZE_START_EXEC_RUN_EVENT_BIT) != 0 )
    {
      // Execution run logic here
      // Follow the optimized path 
    }

    vTaskDelayUntil(&xLastWokenTickCount, pdMS_TO_TICKS(250));
  }

  vTaskDelete(NULL);
}




void vLineFollower(void *pvArguments)
{
  // vLogEvent("Line Follower Running...\n");

  // Task's initialization
  TickType_t xLastWokenTickType;
  TickType_t xMsBetweenCalls = 200;

  double Error;

  while ( pdTRUE )
  { 
    xEventGroupWaitBits(xEventFlags, SYSTEM_RUNNING_BIT, pdFALSE, pdTRUE, portMAX_DELAY);
    // xEventGroupClearBits(xEventFlags, UPDATE_PID_STATE_BIT);

    xLastWokenTickType = xTaskGetTickCount();

    // Line follower logic here
    // Inputs -> Sensor Readings

    taskENTER_CRITICAL( &xCriticalSectionMutex );
    
    Error = PID_MapError(IR.ErrorValue);
    PID_Control(&PID_Output, &prevPID_Output, Error, (255 - MOTOR_BASE_SPEED), xMsBetweenCalls);

    taskEXIT_CRITICAL( &xCriticalSectionMutex );

    vLogEvent("PID Output: ");
    vLogNumber(PID_Output);
    vLogEvent("\n");

    xEventGroupSetBits(xEventFlags, UPDATE_MOTOR_STATE_BIT);

    vTaskDelayUntil(&xLastWokenTickType, pdMS_TO_TICKS(xMsBetweenCalls));
  }

  vTaskDelete(NULL);
}



void vSpeedControl(void *pvArguments)
{
  vLogEvent("Speed Control Running...\n");

  // Task's initialization
  const EventBits_t xBitsToWaitFor = (SYSTEM_RUNNING_BIT | RUN_SPEED_CONTROL_TASK_BIT);

  while ( pdTRUE )
  {
    xEventGroupWaitBits(xEventFlags, xBitsToWaitFor, pdFALSE, pdTRUE, portMAX_DELAY);
    xEventGroupClearBits(xEventFlags, RUN_SPEED_CONTROL_TASK_BIT);

    taskENTER_CRITICAL( &xCriticalSectionMutex );

    if ( (xEventGroupGetBits(xEventFlags) & SAMPLE_WIFI_DATA_EVENT_BIT) != 0)
    {
      // WiFi speed control logic here
      // Set the speed that was recieved from the computer vision application to be the speed used by the outputs processing task

      xEventGroupClearBits(xEventFlags, SAMPLE_WIFI_DATA_EVENT_BIT);
    }
    else
    {
      Wifi_Rx = 0;
    }
    
    taskEXIT_CRITICAL( &xCriticalSectionMutex );
  }

  vTaskDelete(NULL);
}



void vOutputsProcesing(void *pvArguments)
{
  // Task's initialization
  TickType_t xLastWokenTickCount;
  
  int16_t RightMotorPeriod;
  int16_t LeftMotorPeriod;
  // double PIDadjustment;

  while ( pdTRUE )
  {
    xEventGroupWaitBits(xEventFlags, SYSTEM_RUNNING_BIT | UPDATE_MOTOR_STATE_BIT, pdFALSE, pdFALSE, 0);
    xLastWokenTickCount = xTaskGetTickCount();

    if ( (xEventGroupGetBits(xEventFlags) & SYSTEM_RUNNING_BIT) != 0)
    { 
      // Reaching this block means that the system is operational
      // Insert motor control logic here

      // vLogEvent("Running the motor...\n");
      if ( (xEventGroupGetBits(xEventFlags) & UPDATE_MOTOR_STATE_BIT) != 0)
      {
        xEventGroupClearBits(xEventFlags, UPDATE_MOTOR_STATE_BIT);

        taskENTER_CRITICAL( &xCriticalSectionMutex );

        if ( 0 == Wifi_Rx )
        {
          // PIDadjustment = (PID_MAGNIFICATION_FACTOR * PID_Output) / PID_DAMPING_FACTOR;

          RightMotorPeriod = ( (MOTOR_RIGHT_BASE_SPEED - PID_Output) < 0) ? 0 : MOTOR_RIGHT_BASE_SPEED - PID_Output;
          LeftMotorPeriod = ( (MOTOR_LEFT_BASE_SPEED + PID_Output) >= 255) ? 255 : MOTOR_LEFT_BASE_SPEED + PID_Output;

          if ( !isSameSign(PID_Output, prevPID_Output) || !(xEventGroupGetBits(xEventFlags) & MOTORS_RUNNING_BIT) )
          {
            Motor_Stop(100);
            
            if ( (-PID_FORWARD_ERROR_TOLERANCE <= PID_Output) && (PID_Output <= PID_FORWARD_ERROR_TOLERANCE))
            {
              Motor_SetDirection(LEFT_MOTOR, DIRECTION_FORWARD);
              Motor_SetDirection(RIGHT_MOTOR, DIRECTION_FORWARD);

              Motor_SetSpeed(LEFT_MOTOR, MOTOR_BASE_SPEED);
              Motor_SetSpeed(RIGHT_MOTOR, MOTOR_BASE_SPEED);
            }
            else if ( PID_Output < 0 )
            {
              Motor_SetDirection(LEFT_MOTOR, DIRECTION_BACKWARD);
              Motor_SetDirection(RIGHT_MOTOR, DIRECTION_FORWARD);
              
              Motor_SetSpeed(LEFT_MOTOR, LeftMotorPeriod); //LeftMotorPeriod
              Motor_SetSpeed(RIGHT_MOTOR, RightMotorPeriod);
            }
            else if ( PID_Output > 0)
            {
              Motor_SetDirection(LEFT_MOTOR, DIRECTION_FORWARD);
              Motor_SetDirection(RIGHT_MOTOR, DIRECTION_BACKWARD);
              
              Motor_SetSpeed(LEFT_MOTOR, LeftMotorPeriod);
              Motor_SetSpeed(RIGHT_MOTOR, RightMotorPeriod); //RightMotorPeriod
            }
          }
          else
          {
            Motor_SetSpeed(LEFT_MOTOR, LeftMotorPeriod);
            Motor_SetSpeed(RIGHT_MOTOR, RightMotorPeriod);
          }

          // Motor_SpeedControl(PID_Output, LeftMotorPeriod, RightMotorPeriod);
        }
        else
        {
          // Wifi Speed Processing and PID Direction Processing
        }

        taskEXIT_CRITICAL( &xCriticalSectionMutex );

        xEventGroupSetBits(xEventFlags, MOTORS_RUNNING_BIT | UPDATE_PID_STATE_BIT);
      }
      
    }
    else
    {
      if ( (xEventGroupGetBits(xEventFlags) & MOTORS_RUNNING_BIT) != 0 )
      {
        // vLogEvent("Stopping the motor...\n");

        Motor_Stop(100);
        xEventGroupClearBits(xEventFlags, MOTORS_RUNNING_BIT);
      }
    }

    vTaskDelayUntil(&xLastWokenTickCount, pdMS_TO_TICKS(250));
  }

  vTaskDelete(NULL);
}


void vUpdateSystemModes(void)
{ 
  xEventGroupSetBits(xEventFlags, UPDATE_MOTOR_STATE_BIT);

  if ( LOW == digitalRead(SWITCH_SYSTEM_RUNNING_PIN) )
  {
    PID_Init(Kp, Ki, Kd, 0);
    xEventGroupSetBits(xEventFlags, SYSTEM_RUNNING_BIT);
  }
  else
  {
    xEventGroupClearBits(xEventFlags, SYSTEM_RUNNING_BIT);
  }


  if ( LOW == digitalRead(SWITCH_IS_MAZE_PIN) )
  {
    xEventGroupSetBits(xEventFlags, RUN_MAZE_SOLVER_TASK_BIT);    
  }
  else
  {
    xEventGroupClearBits(xEventFlags, RUN_MAZE_SOLVER_TASK_BIT);
  }


  if ( HIGH == digitalRead(SWITCH_IS_MAIN_RUN_PIN) )
  {
    xEventGroupSetBits(xEventFlags, MAZE_START_EXEC_RUN_EVENT_BIT);
    xEventGroupClearBits(xEventFlags, MAZE_START_TEST_RUN_EVENT_BIT);
  }
  else
  {
    xEventGroupSetBits(xEventFlags, MAZE_START_TEST_RUN_EVENT_BIT);
    xEventGroupClearBits(xEventFlags, MAZE_START_EXEC_RUN_EVENT_BIT);
  }
}