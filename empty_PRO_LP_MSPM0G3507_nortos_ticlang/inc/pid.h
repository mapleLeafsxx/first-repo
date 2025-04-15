#ifndef _PID_H
#define _PID_H
//#include "stm32f10x.h"   
//#include <math.h>

typedef struct {
    float Kp;
    float Ki;
    float Kd;
    float setpoint;
    float prev_error;
    float prev_prev_error;
    float integral;
    float output;
	float IntegralLimit;
	float IntegralSum;
	float Error_Threshold;
} PID_TypeDef;

// 增量式PID初始化
void Incremental_PID_Init(PID_TypeDef *pid, float Kp, float Ki, float Kd);

// 增量式PID计算
float Incremental_PID_Compute(PID_TypeDef *pid, float feedback);

// 位置式PID初始化
void Positional_PID_Init(PID_TypeDef *pid, float Kp, float Ki, float Kd, float errorThreshold);

// 位置式PID计算
float Positional_PID_Compute(PID_TypeDef *pid, float feedback);

// 设置PID目标值
void PID_Set_Setpoint(PID_TypeDef *pid, float setpoint);

/*************************************************************************/
void Set_Position_left_PID(float Kp, float Ki, float Kd, float errorThreshold);
void Set_Position_left_Target(float Target);
int32_t Position_left_PID(float Actual);


void Set_Position_right_PID(float Kp, float Ki, float Kd, float errorThreshold);
void Set_Position_right_Target(float Target);
int32_t Position_right_PID(float Actual);


void Set_Velocity_left_PID(float Kp, float Ki, float Kd);
void Set_Velocity_left_Target(float Target);	
int32_t Velocity_left_PID(float Actual);		
	

void Set_Velocity_right_PID(float Kp, float Ki, float Kd);
void Set_Velocity_right_Target(float Target);
int32_t Velocity_right_PID(float Actual);
	

void Set_Angle_yaw_PID(float Kp, float Ki, float Kd, float errorThreshold);
void Set_Angle_yaw_Target(float Target);	
int32_t Angle_yaw_PID(float Actual);

#endif
