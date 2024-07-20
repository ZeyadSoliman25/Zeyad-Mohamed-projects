#include "MicromousePIDControl.h"

//PID Control Variables
typedef volatile struct
{
  double Kp;
  double Ki;
  double Kd;
  double AccumulatedError;
  double PrevDeDt;
  double PrevError;
  double SetPoint;
} PIDTypeDef;

//Create a memory space with a variable type of PID
static PIDTypeDef PID;
static double initialKi;

//Initilialize PID Control
void PID_Init(double Kp, double Ki, double Kd, double SetPoint)
{
  //Initialize PID Gain values
  PID.Kp = Kp;

  PID.Ki = Ki;
  initialKi = PID.Ki;

  PID.Kd = Kd;
  
  //Initialize PID Errors
  PID.AccumulatedError = 0;
  PID.PrevError = 0;

  //Initialize PID Set Point
  PID.SetPoint = SetPoint;
}

//Compute the PID Control Correction
void PID_Control (double *Output, double *PrevOutput, double FeedbackError, double SaturationLimit, double dt_ms)
{
  double error = PID.SetPoint - FeedbackError;
  double de_dt = 1000 * ( (error - PID.PrevError) / dt_ms );

  *PrevOutput = *Output;

  double RawOutput = (PID.Kp * error) + (PID.Ki * PID.AccumulatedError) + (PID.Kd * de_dt);

  if ( ((0 - SaturationLimit) <= RawOutput) && (RawOutput <= SaturationLimit) )
  {
    *Output = RawOutput;
  }
  else if ( RawOutput < (0 - SaturationLimit) )
  {
    *Output = (0 - SaturationLimit);
  }
  else
  {
    *Output = SaturationLimit;
  }


  if ( (*Output != RawOutput) && isSameSign(error, RawOutput) )
  {
    PID.Ki = 0;
  }
  else
  {
    PID.Ki = initialKi;
    PID.AccumulatedError += error;
  }

  PID.PrevError = error;  
}



double PID_MapError(uint8_t SensorReadings)
{
  double feedback_error = 0;

  switch (SensorReadings)
  {
    case 0b00000:
    case 0b00100:
    case 0b01110:
    case 0b11111:

      feedback_error = 0.0f;
      break;

    case 0b00110:
      feedback_error = -0.6f;
      break;

    case 0b00010:
      feedback_error = -0.7f;
      break;

    case 0b00001:
      feedback_error = -1.0f;
      break;

    case 0b00011:
      feedback_error = -0.9f;
      break;

    case 0b00111:
      feedback_error = -0.8f;
      break;


    case 0b01100:
      feedback_error = 0.6f;
      break;

    case 0b01000:
      feedback_error = 0.7f;
      break;

    case 0b10000:
      feedback_error = 1.0f;
      break;

    case 0b11000:
      feedback_error = 0.9f;
      break;

    case 0b11100:
      feedback_error = 0.8f;
      break;

    default: break;
  }

  return feedback_error;
}


uint8_t isSameSign(double x, double y)
{
  return (x >= 0) ^ (y < 0);
}