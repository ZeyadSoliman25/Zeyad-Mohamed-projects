#ifndef _PID_H_
#define _PID_H_

#define PID_MAGNIFICATION_FACTOR      1
#define PID_DAMPING_FACTOR            2
#define PID_FORWARD_ERROR_TOLERANCE   10
#define PID_STOP_ERROR_REFERENCE      150

void PID_Init(double Kp, double Ki, double Kd, double SetPoint);
void PID_Control (double *Output, double *PrevOutput, double FeedbackError, double SaturationLimit, double dt_ms);
double PID_MapError(uint8_t SensorReadings);

uint8_t isSameSign(double x, double y);

#endif /* _PID_H_ */