#ifndef _MOTORS_H_
#define _MOTORS_H_

//Speeds of the Motors
#define MOTOR_MAX_SPEED 200
#define MOTOR_MIN_SPEED 0

#define MOTOR_BASE_SPEED          100
#define MOTOR_LEFT_BASE_SPEED     MOTOR_BASE_SPEED
#define MOTOR_RIGHT_BASE_SPEED    MOTOR_BASE_SPEED

typedef enum
{
  LEFT_MOTOR = 0,
  RIGHT_MOTOR,

} Motors_t;

typedef enum
{
  DIRECTION_FORWARD = 0,
  DIRECTION_BACKWARD

} Directions_t;

void Motor_SpeedControl(double PIDadjustment, int16_t MotorLeftSpeed, int16_t MotorRightSpeed);
void Motor_SetSpeed(Motors_t Motor, uint8_t Period);
void Motor_SetDirection(Motors_t Motor, Directions_t Direction);
void Motor_Stop(uint32_t delay_ms);
void Motor_Brake(uint32_t delay_ms);
void Motor_Turn(int16_t MotorLeftSpeed, int16_t MotorRightSpeed);

#endif /* _MOTORS_H_ */