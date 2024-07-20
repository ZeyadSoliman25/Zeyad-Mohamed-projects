/******************************************************
 * File: MicromouseHelper.ino
 * Author: Yusuf Abulfotouh
 * Date: 01/05/2024
 * Description: This file contains the code for a line follower robot using ESP32.
 ******************************************************/





/*Define Variables*/
//speeds of the motors 
/* 
   Function: GoForward()
   Description: This function controls the robot to move forward.
   Parameters: None
   Returns: void
   Key Steps:
   1. Set motor pins to move forward.
*/
// void GoForward() 
// {
//   // Step 1: Set motor pins to move forward
//   analogWrite(LEFT_MOTOR_PIN_BW, left_motor_speed);
//   analogWrite(RIGHT_MOTOR_PIN_BW, right_motor_speed);
// }

// /* 
//    Function: Stop()
//    Description: This function stops the robot.
//    Parameters: None
//    Returns: void
//    Key Steps:
//    1. Set motor enable pins to 1 1.
//    2. Delay for 500 milliseconds.
//    3. Reset motor enable pins to 0 0

// */
// void Stop() {
//   // Step 1: Set motor PWM to 0
//   analogWrite(LEFT_MOTOR_PIN_BW, MOTOR_MAX_SPEED);
//   analogWrite(RIGHT_MOTOR_PIN_BW, MOTOR_MAX_SPEED);
  
//   vTaskDelay( pdMS_TO_TICKS(500));
      
//   analogWrite(LEFT_MOTOR_PIN_BW, MOTOR_MIN_SPEED);
//   analogWrite(RIGHT_MOTOR_PIN_BW, MOTOR_MIN_SPEED);

// }

// /* 
//    Function: PID_Control()
//    Description: This function implements the PID Control in which you have a reference value and an error value, 
//                 to reduce the error present in turning use integral gain, derivative gain, and proportional gain. (Ki,Kd,Kp)
//    Parameters: None
//    Returns: void
//    Key Steps:
//    1. Calculate proportional, integral, and derivative terms.
//    2. Update error value.
//    Note: There should be a feedback using low-pass filter to reduce the noise
// */
// void PID_Control() {
//   // Step 1: Calculate proportional, integral, and derivative terms
  
//   // Step 2: Update error value
  
// }

// /* 
//    Function: Turn_Speed()
//    Description: This function calculates turning speed based on the error value.
//    Parameters: None
//    Returns: void
//    Key Steps:
//    1. Restrict error value within a range.
//    2. Calculate right and left motor speeds.
// */
// void Turn_Speed() {
//   // Step 1: Calculate right and left motor speeds
//   left_motor_speed = MOTOR_MAX_SPEED - correction_speed;
//   right_motor_speed = MOTOR_MAX_SPEED + correction_speed;

//   // Step 2: Restrict error value within a range
//   if (left_motor_speed > MOTOR_MAX_SPEED)
//   {
//     left_motor_speed = MOTOR_MAX_SPEED ; 
//   }
//   else if (left_motor_speed < MOTOR_MIN_SPEED)
//   {
//     left_motor_speed = MOTOR_MIN_SPEED;
//   }

//   if (right_motor_speed > MOTOR_MAX_SPEED)
//   {
//     right_motor_speed = MOTOR_MAX_SPEED;
//   }
//   else if (right_motor_speed < MOTOR_MIN_SPEED)
//   {
//     right_motor_speed = MOTOR_MIN_SPEED;
//   }
  
// }

// /* 
//    Function: GoMotor()
//    Description: This function drives the motors with specified speeds.
//    Parameters: 
//     - int x "placeholder": Speed of the right motor.
//     - int y "placeholder": Speed of the left motor.
//    Returns: void
//    Key Steps:
//    1. Ensure motor speeds are within bounds.
//    2. Set motor directions and PWM values.
//    3. Delay for stability.
// */
// void GoMotor(int X, int Y) {
//   // Step 1: Ensure motor speeds are within bounds
//   // Step 2: Set motor directions and PWM values
//   // Step 3: Delay for stability
//   // Clamp motor speeds
//     X = constrain(X, MOTOR_MIN_SPEED, MOTOR_MAX_SPEED);
//     Y = constrain(Y, MOTOR_MIN_SPEED, MOTOR_MAX_SPEED);
    
//     // Set PWM for left motor
//     analogWrite(LEFT_MOTOR_PIN_BW, Y);
//     analogWrite(LEFT_MOTOR_PIN_FW, Y);

//     // Set PWM for right motor
//     analogWrite(RIGHT_MOTOR_PIN_BW, X);
//     analogWrite(RIGHT_MOTOR_PIN_FW, X);
//     // Delay for stability
//     vTaskDelay( pdMS_TO_TICKS(100));
// }
// void TurnBack(void){
//   while(!(IR.ErrorValue)){
//      GoMotor(oppositeDir ,max_speed);
//   }
// }

// /* 
//    Function: LineFollow()
//    Description: This function continuously checks sensor readings and controls the motors accordingly.
//    Parameters: None
//    Returns: void
//    Key Steps:
//    1. Read sensor values. (Check if digitalRead or analogRead first)
//    2. Implement line following algorithm.
// */
// void LineFollow(Direction direction) {
//   // Step 1: Read sensor values

//  switch (direction) {
//         case FORWARD:
//             // Set the robot to move forward
//             GoMotor(max_speed ,max_speed);
           
//             break;
//         case LEFT:
//             // Set the robot to turn left
//             GoMotor(max_speed ,oppositeDir);

//             break;
//         case BACKWARD:
//             // Set the robot to turn to the opposite direction 
//           TurnBack();
//             break;

//         case RIGHT:
//             // Set the robot to turn right
//             GoMotor(oppositeDir ,max_speed);
//             break;
//         case STOP:
//             // Stop the robot
//             Stop();
//             break;
//     }
// }
