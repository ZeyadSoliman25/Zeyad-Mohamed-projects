
#include "Micromouse.h"


void Motor_Turn(int16_t MotorLeftSpeed, int16_t MotorRightSpeed)
{ 

}


void Motor_SetDirection(Motors_t Motor, Directions_t Direction)
{
  switch (Motor)
  {
    case LEFT_MOTOR:

      if ( DIRECTION_BACKWARD == Direction )
      {
        digitalWrite(MOTOR_LEFT_IN1_PIN, 1);
        digitalWrite(MOTOR_LEFT_IN2_PIN, 0);
        vLogEvent("LEFT MOTOR BACKWARD\n");
      }
      else
      {
        digitalWrite(MOTOR_LEFT_IN1_PIN, 0);
        digitalWrite(MOTOR_LEFT_IN2_PIN, 1);
        vLogEvent("LEFT MOTOR FORWARD\n");
      }

    break;

    case RIGHT_MOTOR:

      if ( DIRECTION_BACKWARD == Direction )
      {
        digitalWrite(MOTOR_RIGHT_IN1_PIN, 1);
        digitalWrite(MOTOR_RIGHT_IN2_PIN, 0);
        vLogEvent("RIGHT MOTOR BACKWARD\n");
      }
      else
      {
        digitalWrite(MOTOR_RIGHT_IN1_PIN, 0);
        digitalWrite(MOTOR_RIGHT_IN2_PIN, 1);
        vLogEvent("RIGHT MOTOR FORWARD\n");
      }

    break;
  }
}


void Motor_SetSpeed(Motors_t Motor, uint8_t Period)
{
  switch (Motor)
  {
    case LEFT_MOTOR:

      analogWrite(MOTOR_LEFT_ENA_PIN, Period);

    break;

    case RIGHT_MOTOR:

      analogWrite(MOTOR_RIGHT_ENA_PIN, Period);

    break;
  }
}


void Motor_SpeedControl(double PIDerror, int16_t MotorLeftSpeed, int16_t MotorRightSpeed) 
{
  // Motor_Stop();

  if ( (-PID_STOP_ERROR_REFERENCE <= PIDerror) && (PIDerror <= PID_STOP_ERROR_REFERENCE) )
  {
    if ( (-PID_FORWARD_ERROR_TOLERANCE < PIDerror) && (PIDerror < PID_FORWARD_ERROR_TOLERANCE))
    {
      Motor_SetDirection(LEFT_MOTOR, DIRECTION_FORWARD);
      Motor_SetDirection(RIGHT_MOTOR, DIRECTION_FORWARD);

      MotorLeftSpeed = MOTOR_MAX_SPEED / 2;
      MotorRightSpeed = MOTOR_MAX_SPEED / 2;
    }
    else if ( PIDerror < 0 )
    {
      Motor_SetDirection(LEFT_MOTOR, DIRECTION_BACKWARD);
      Motor_SetDirection(RIGHT_MOTOR, DIRECTION_FORWARD);
    }
    else if ( PIDerror > 0)
    {
      Motor_SetDirection(LEFT_MOTOR, DIRECTION_FORWARD);
      Motor_SetDirection(RIGHT_MOTOR, DIRECTION_BACKWARD);
    }
  }



  // Step 2 Set motor PWM values
  if ( MotorLeftSpeed < 0)
  {
    MotorLeftSpeed *= -1;
  }
  
  if (MotorLeftSpeed > 255)
  {
    MotorLeftSpeed = 255;
  }

  if ( MotorRightSpeed < 0)
  {
    MotorRightSpeed *= -1;
  }

  if (MotorRightSpeed > 255)
  {
    MotorRightSpeed = 255;
  }

  Motor_SetSpeed(LEFT_MOTOR, MotorLeftSpeed);
  Motor_SetSpeed(RIGHT_MOTOR, MotorRightSpeed);

  taskEXIT_CRITICAL( &xCriticalSectionMutex );
}

/**********************************************************************/

// /* 
//    Function: MotorTurnLeft()
//    Description: This function turns the robot left.
//    Parameters: 
//     - int MotorRightSpeed: Speed of the right motor.
//     - int MotorLeftSpeed: Speed of the left motor.
//    Returns: void
//    Key Steps:
//    1. left motor Anticlockwise
//    2. right motor clockwise
//    3. give both motors a specific speed
// */
// void MotorTurnLeft(uint8_t MotorLeftSpeed, uint8_t MotorRightSpeed) 
// {
// // Step 1: left motor Anticlockwise
//   digitalWrite(MOTOR_LEFT_IN1_PIN, 0);
//   digitalWrite(MOTOR_LEFT_IN2_PIN, 1);

// // Step 2: right motor clockwise
//   digitalWrite(MOTOR_RIGHT_IN1_PIN, 1);
//   digitalWrite(MOTOR_RIGHT_IN2_PIN, 0);

// // Step 3: give both motors a specific speed
//   analogWrite(MOTOR_LEFT_ENA_PIN, MotorLeftSpeed);
//   analogWrite(MOTOR_RIGHT_ENA_PIN, MotorRightSpeed);
// }

// /**********************************************************************/

// /* 
//    Function: MotorTurnRight()
//    Description: This function turns the robot right.
//    Parameters: 
//     - int MotorRightSpeed: Speed of the right motor.
//     - int MotorLeftSpeed: Speed of the left motor.
//    Returns: void
//    Key Steps:
//    1. left motor clockwise
//    2. right motor Anticlockwise
//    3. give both motors a specific speed
// */
// void MotorTurnRight(uint8_t MotorLeftSpeed, uint8_t MotorRightSpeed) 
// {
// // Step 1: left motor clockwise
//   digitalWrite(MOTOR_LEFT_IN1_PIN, 1);
//   digitalWrite(MOTOR_LEFT_IN2_PIN, 0);

// // Step 2: right motor Anticlockwise
//   digitalWrite(MOTOR_RIGHT_IN1_PIN, 0);
//   digitalWrite(MOTOR_RIGHT_IN2_PIN, 1);

// // Step 3: give both motors a specific speed
//   analogWrite(MOTOR_LEFT_ENA_PIN, MotorLeftSpeed);
//   analogWrite(MOTOR_RIGHT_ENA_PIN, MotorRightSpeed);
// }

// /**********************************************************************/

// /* 
//    Function: TurnBack()
//    Description: This function drives the robot to the opposite direction.
//    Parameters: 
//     - int MotorRightSpeed: Speed of the right motor.
//     - int MotorLeftSpeed: Speed of the left motor.
//    Returns: void
//    Key Steps:
//    1. left motor clockwise
//    2. right motor Anticlockwise
//    3. give both motors a specific speed
// */
// void MotorTurnBack(uint8_t MotorLeftSpeed, uint8_t MotorRightSpeed) 
// {
//   while (!(IR.ErrorValue)) 
//   {
// // Step 1: left motor clockwise
//     digitalWrite(MOTOR_LEFT_IN1_PIN, 1);
//     digitalWrite(MOTOR_LEFT_IN2_PIN, 0);

// // Step 2: right motor Anticlockwise
//     digitalWrite(MOTOR_RIGHT_IN1_PIN, 0);
//     digitalWrite(MOTOR_RIGHT_IN2_PIN, 1);

// // Step 3: give both motors a specific speed
//     analogWrite(MOTOR_LEFT_ENA_PIN, MotorLeftSpeed);
//     analogWrite(MOTOR_RIGHT_ENA_PIN, MotorRightSpeed);
//   }
// }

// /**********************************************************************/

// /* 
// Function: MotorLineFollow()
// Description: This function continuously checks sensor readings and controls the motors accordingly.
// Parameters: ErrorValue:which indicates to the direction of the robot 
// Returns: void
// Key Steps:
// 1.switch case for the errorvalue which indicates to the direction of movement.
// 2. set the robot directions according to the retained IR.ErrorValue
// */
// void MotorLineFollow(uint8_t ErrorValue) 
// {
//   switch (ErrorValue) 
//       {
//         // Set the robot to move forward
//         case FORWARD:
//           MotorSpeed(MOTOR_MAX_SPEED, MOTOR_MAX_SPEED);
//         break;

//         // Set the robot to turn left
//         case LEFT:
//           MotorTurnLeft(MOTOR_MAX_SPEED, MOTOR_MED_SPEED);
//         break;
        
//         // Set the robot to turn to the opposite direction
//         case BACKWARD:
//           MotorTurnBack(MOTOR_MAX_SPEED, MOTOR_MAX_SPEED);
//         break;

//         // Set the robot to turn right
//         case RIGHT:
//           MotorTurnRight(MOTOR_MED_SPEED, MOTOR_MAX_SPEED);
//         break;
        
//         // Stop the robot
//         case STOP:
//           MotorStop();
//         break;
//       }
// }

// /**********************************************************************/


void Motor_Brake(uint32_t delay_ms)
{
  digitalWrite(MOTOR_LEFT_IN1_PIN, HIGH);
  digitalWrite(MOTOR_LEFT_IN2_PIN, HIGH);
  digitalWrite(MOTOR_RIGHT_IN1_PIN, HIGH);
  digitalWrite(MOTOR_RIGHT_IN2_PIN, HIGH);
  digitalWrite(MOTOR_RIGHT_ENA_PIN, LOW);
  digitalWrite(MOTOR_LEFT_ENA_PIN, LOW);

  vTaskDelay( pdMS_TO_TICKS(delay_ms) );
}


void Motor_Stop(uint32_t delay_ms) 
{
  Motor_Brake(delay_ms);
  
  taskENTER_CRITICAL( &xCriticalSectionMutex );
  digitalWrite(MOTOR_LEFT_IN1_PIN, LOW);
  digitalWrite(MOTOR_LEFT_IN2_PIN, LOW);
  
  digitalWrite(MOTOR_RIGHT_IN1_PIN, LOW);
  digitalWrite(MOTOR_RIGHT_IN2_PIN, LOW);
  taskEXIT_CRITICAL( &xCriticalSectionMutex );
}
