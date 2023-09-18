#include<util/delay.h>


//libraries layer
#include "../libraries/types.h"
#include"../libraries/Error_State.h"

#include "../libraries/math.h"
//MCAL  DIO
#include "../MCAL/1-DIO/DIO_interface.h"
#include "../MCAL/5-TIMERS/TIMERS_interface.h"

//HAL layer
#include "../HAL/1-LCD/LCD_interface.h"
#include "../HAL/2-KPD/KPD_interface.h"
#include "../HAL/3-DC_Motor/DC_MOTOR_interface.h"
#include "../HAL/4-STEPPER_Motor/STEPPER_MOTOR_interface.h"
#include "../HAL/5-SERVO_Motor/SERVO_MOTOR_interface.h"
/*************************************************************************************************/

void motor_option();
void choice_angle_stepper();
void choice_angle_servo();
void stepper_MOTOR_void_direction();
void DC_MOTOR_void_direction(void);

u8 stepper_direction;

#define len 4
#define pass "0000"
#define MAX_try_check    3
u8 Local_u8_input[len] ;
/**************************************************************************************************/
