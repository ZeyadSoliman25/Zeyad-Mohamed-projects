#ifndef _MICROMOUSE_H_
#define _MICROMOUSE_H_

#include "MicromousePIDControl.h"
#include "MicromouseMotors.h"

#if CONFIG_FREERTOS_UNICORE
  #define ARDUINO_RUNNING_CORE    0
#else
  #define ARDUINO_RUNNING_CORE    1
#endif

// Switches pin definitions
#define SWITCH_SYSTEM_RUNNING_PIN 15
#define SWITCH_IS_MAZE_PIN        2
#define SWITCH_IS_MAIN_RUN_PIN    4

// IR Sensor pin defintions
#define FAR_RIGHT_IR_PIN          18
#define RIGHT_IR_PIN              19
#define MIDDLE_IR_PIN             21
#define LEFT_IR_PIN               22
#define FAR_LEFT_IR_PIN           23


// Motor Driver pin defintions
#define MOTOR_LEFT_ENA_PIN        13
#define MOTOR_LEFT_IN1_PIN        12
#define MOTOR_LEFT_IN2_PIN        14

#define MOTOR_RIGHT_ENA_PIN       25
#define MOTOR_RIGHT_IN1_PIN       27
#define MOTOR_RIGHT_IN2_PIN       26


// User-defined types
typedef volatile union
{
  struct
  {
    uint8_t FarRight  : 1;
    uint8_t Right     : 1;
    uint8_t Middle    : 1;
    uint8_t Left      : 1;
    uint8_t FarLeft   : 1;
    uint8_t RESERVED  : 3;

  } Instance;
  uint8_t ErrorValue;

} IR_t;


// typedef volatile struct
// {
//   uint8_t isOn          : 1;  // Determines whether the micromouse is operating or not.
//   uint8_t isMazeSolver  : 1;  // Determines whether we are running in a maze solving mode or a line following mode.
//   uint8_t isMainMazeRun : 1;  // Determines whether the current run is the main run or not. Meaningful in the maze solving mode only.
//   uint8_t RESERVED      : 5;

// } Switch_t;


// Global variable declarations
extern IR_t IR;
// extern Switch_t Switch;


// FreeRTOS objects declarations
extern portMUX_TYPE        xCriticalSectionMutex;
extern EventGroupHandle_t  xEventFlags;

// Event Group bit definitions
#define NO_BITS_TO_SET                    0
#define SYSTEM_RUNNING_BIT                (1 << 0)
#define SAMPLE_SWITCHES_EVENT_BIT         (1 << 1)
#define SAMPLE_IR_EVENT_BIT               (1 << 2)
#define SAMPLE_WIFI_DATA_EVENT_BIT        (1 << 3)
#define RUN_LINE_FOLLOWER_TASK_BIT        (1 << 4)
#define RUN_SPEED_CONTROL_TASK_BIT        (1 << 5)
#define RUN_MAZE_SOLVER_TASK_BIT          (1 << 6)
#define MAZE_START_TEST_RUN_EVENT_BIT     (1 << 7)
#define MAZE_TEST_RUN_DONE_BIT            (1 << 8)
#define MAZE_START_EXEC_RUN_EVENT_BIT     (1 << 9)
#define MAZE_EXEC_RUN_DONE_BIT            (1 << 10)
#define INTERSECTION_DETECTED_BIT         (1 << 11)
#define MOTORS_RUNNING_BIT                (1 << 12)
#define UPDATE_MOTOR_STATE_BIT            (1 << 13)
#define UPDATE_PID_STATE_BIT              (1 << 14)


void vInputsProcessing(void *pvArguments);
void vConnectivtyManager(void *pvArguments);
void vMazeSolver(void *pvArguments);
void vLineFollower(void *pvArguments);
void vSpeedControl(void *pvArguments);
void vOutputsProcesing(void *pvArguments);
void vLogEvent(const char *ErrorMessage);
void vLogNumber(const double Number);
void vUpdateSystemModes(void);


#endif /* _MICROMOUSE_H_ */