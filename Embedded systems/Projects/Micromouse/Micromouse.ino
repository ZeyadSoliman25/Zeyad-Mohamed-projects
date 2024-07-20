#include "Micromouse.h"

#include <esp_task_wdt.h>
#include "soc/rtc_wdt.h"

#define DEBUG 1

#if (DEBUG == 0)
#define vLogEvent(str) 
#define vLogNumber(num)
#endif



void IRAM_ATTR Switch_Handler(void)
{
  BaseType_t xHigherPriortityTaskWoken = pdFALSE;
  BaseType_t xResult;

  xResult = xEventGroupSetBitsFromISR(xEventFlags, SAMPLE_SWITCHES_EVENT_BIT, &xHigherPriortityTaskWoken);

  if (xResult != pdFAIL)
  {
    portYIELD_FROM_ISR(xHigherPriortityTaskWoken);
  }
}


void IRAM_ATTR IR_Handler(void)
{
  BaseType_t xHigherPriortityTaskWoken = pdFALSE;
  BaseType_t xResult;

  xResult = xEventGroupSetBitsFromISR(xEventFlags, SAMPLE_IR_EVENT_BIT, &xHigherPriortityTaskWoken);

  if (xResult != pdFAIL)
  {
    portYIELD_FROM_ISR(xHigherPriortityTaskWoken);
  }
}



void setup(void)
{
  // Initialize serial communication
  Serial.begin(115200);

  // Initialize motor pins (right and left)
  pinMode(MOTOR_LEFT_ENA_PIN,   OUTPUT);
  pinMode(MOTOR_LEFT_IN1_PIN,   OUTPUT);
  pinMode(MOTOR_LEFT_IN2_PIN,   OUTPUT);
  pinMode(MOTOR_RIGHT_ENA_PIN,  OUTPUT);
  pinMode(MOTOR_RIGHT_IN1_PIN,  OUTPUT);
  pinMode(MOTOR_RIGHT_IN2_PIN,  OUTPUT);


  // Initialize sensor pins
  pinMode(FAR_LEFT_IR_PIN,  INPUT);
  attachInterrupt(digitalPinToInterrupt(FAR_LEFT_IR_PIN), IR_Handler, CHANGE);

  pinMode(LEFT_IR_PIN,      INPUT);
  attachInterrupt(digitalPinToInterrupt(LEFT_IR_PIN), IR_Handler, CHANGE);

  pinMode(MIDDLE_IR_PIN,    INPUT);
  attachInterrupt(digitalPinToInterrupt(MIDDLE_IR_PIN), IR_Handler, CHANGE);

  pinMode(RIGHT_IR_PIN,     INPUT);
  attachInterrupt(digitalPinToInterrupt(RIGHT_IR_PIN), IR_Handler, CHANGE);

  pinMode(FAR_RIGHT_IR_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(FAR_RIGHT_IR_PIN), IR_Handler, CHANGE);


  // Initiqliaze Trigger Pin for sensors
  pinMode(SWITCH_SYSTEM_RUNNING_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(SWITCH_SYSTEM_RUNNING_PIN), Switch_Handler, CHANGE);

  pinMode(SWITCH_IS_MAZE_PIN,        INPUT);
  attachInterrupt(digitalPinToInterrupt(SWITCH_IS_MAZE_PIN), Switch_Handler, CHANGE);

  pinMode(SWITCH_IS_MAIN_RUN_PIN,    INPUT);
  attachInterrupt(digitalPinToInterrupt(SWITCH_IS_MAIN_RUN_PIN), Switch_Handler, CHANGE);

  // Create FreeRTOS objects
  portMUX_INITIALIZE( &xCriticalSectionMutex );

  xEventFlags = xEventGroupCreate();

  // if (NULL == xEventFlags)
  // {
  //   vLogEvent("\n\n0\n");
  // }
  // else
  // {
  //   vLogEvent("1\n");
  // }

  volatile BaseType_t xStatus;
  xStatus = xTaskCreatePinnedToCore(vInputsProcessing,          // Task's function ID
                                    NULL,                       // Task's description
                                    4096,   // Task's stack size in words
                                    NULL,                       // Task's arguments
                                    7,                          // Task's priority
                                    NULL,                       // Task's handle (pointer)
                                    ARDUINO_RUNNING_CORE); 
  // if (pdFAIL == xStatus)
  // {
  //   vLogEvent("0\n");
  // }
  // else
  // {
  //   vLogEvent("1\n");
  // }

  xStatus = xTaskCreatePinnedToCore(vConnectivtyManager,        // Task's function ID
                                    NULL,                       // Task's description
                                    4096,   // Task's stack size in words
                                    NULL,                       // Task's arguments
                                    0,                          // Task's priority
                                    NULL,                       // Task's handle (pointer)
                                    ARDUINO_RUNNING_CORE); 
  // if (pdFAIL == xStatus)
  // {
  //   vLogEvent("0\n");
  // }
  // else
  // {
  //   vLogEvent("1\n");
  // }

  xStatus = xTaskCreatePinnedToCore(vMazeSolver,                // Task's function ID
                                    NULL,                       // Task's description
                                    4096,   // Task's stack size in words
                                    NULL,                       // Task's arguments
                                    0,                          // Task's priority
                                    NULL,                       // Task's handle (pointer)
                                    ARDUINO_RUNNING_CORE); 
  // if (pdFAIL == xStatus)
  // {
  //   vLogEvent("0\n");
  // }
  // else
  // {
  //   vLogEvent("1\n");
  // }

  xStatus = xTaskCreatePinnedToCore(vLineFollower,              // Task's function ID
                                    NULL,                       // Task's description
                                    4096,   // Task's stack size in words
                                    NULL,                       // Task's arguments
                                    5,                          // Task's priority
                                    NULL,                       // Task's handle (pointer)
                                    ARDUINO_RUNNING_CORE); 
  // if (pdFAIL == xStatus)
  // {
  //   vLogEvent("0\n");
  // }
  // else
  // {
  //   vLogEvent("1\n");
  // }

  xStatus = xTaskCreatePinnedToCore(vSpeedControl,              // Task's function ID
                                    NULL,                       // Task's description
                                    4096,   // Task's stack size in words
                                    NULL,                       // Task's arguments
                                    0,                          // Task's priority
                                    NULL,                       // Task's handle (pointer)
                                    ARDUINO_RUNNING_CORE);
  // if (pdFAIL == xStatus)
  // {
  //   vLogEvent("0\n");
  // }
  // else
  // {
  //   vLogEvent("1\n");
  // }

  xStatus = xTaskCreatePinnedToCore(vOutputsProcesing,          // Task's function ID
                                    NULL,                       // Task's description
                                    4096,   // Task's stack size in words
                                    NULL,                       // Task's arguments
                                    6,                          // Task's priority
                                    NULL,                       // Task's handle (pointer)
                                    ARDUINO_RUNNING_CORE); 
  // if (pdFAIL == xStatus)
  // {
  //   vLogEvent("0\n");
  // }
  // else
  // {
  //   vLogEvent("1\n");
  // }

  // vTaskStartScheduler();
}



void loop(void)
{
  while ( pdTRUE );
}



void vLogEvent(const char *Event)
{ 
  portENTER_CRITICAL( &xCriticalSectionMutex );
  Serial.print(Event);
  portEXIT_CRITICAL( &xCriticalSectionMutex );
}

void vLogNumber(const double Number)
{
  // esp_task_wdt_reset();
  
  portENTER_CRITICAL( &xCriticalSectionMutex );
  Serial.print(Number);
  portEXIT_CRITICAL( &xCriticalSectionMutex );
}
