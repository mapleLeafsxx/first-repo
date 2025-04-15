#include "ti_msp_dl_config.h"
#include "pid.h"

#define integralLimit 1000

// 增量式PID初始化
void Incremental_PID_Init(PID_TypeDef *pid, float Kp, float Ki, float Kd) {
    pid->Kp = Kp;
    pid->Ki = Ki;
    pid->Kd = Kd;
    pid->setpoint = 0.0;
    pid->prev_error = 0.0;
    pid->prev_prev_error = 0.0;
    pid->integral = 0.0;
    pid->output = 0.0;
	  pid->IntegralLimit = integralLimit;
    pid->IntegralSum = 0;
}

// 增量式PID计算
float Incremental_PID_Compute(PID_TypeDef *pid, float feedback) {
    float error = pid->setpoint - feedback;
	
    pid->IntegralSum += error;
    if (pid->IntegralSum > pid->IntegralLimit)
        pid->IntegralSum = pid->IntegralLimit;
    else if (pid->IntegralSum < -pid->IntegralLimit)
        pid->IntegralSum = -pid->IntegralLimit;
		
    float increment = pid->Kp * (error - pid->prev_error) +
                      pid->Ki * error +
                      pid->Kd * (error - 2 * pid->prev_error + pid->prev_prev_error);

    pid->output += increment;
    pid->prev_prev_error = pid->prev_error;
    pid->prev_error = error;

    return pid->output;
}
	
// 位置式PID初始化
void Positional_PID_Init(PID_TypeDef *pid, float Kp, float Ki, float Kd, float errorThreshold) {
    pid->Kp = Kp;
    pid->Ki = Ki;
    pid->Kd = Kd;
    pid->setpoint = 0.0;
    pid->prev_error = 0.0;
    pid->integral = 0.0;
    pid->output = 0.0;
	pid->IntegralLimit = integralLimit;
    pid->IntegralSum = 0;
    pid->Error_Threshold = errorThreshold;
}

// 位置式 PID 计算
float Positional_PID_Compute(PID_TypeDef *pid, float feedback) {
    float error = pid->setpoint - feedback;
    
    // 只有当误差小于阈值时才累加积分项
    if (fabs(error) <= pid->Error_Threshold) {
        pid->integral += error;
        pid->IntegralSum += error;
        
        // 积分限幅
        if (pid->IntegralSum > pid->IntegralLimit)
            pid->IntegralSum = pid->IntegralLimit;
        else if (pid->IntegralSum < -pid->IntegralLimit)
            pid->IntegralSum = -pid->IntegralLimit;
    } else {
        // 误差较大时，保持积分不变（或可选择清零，视需求而定）
        pid->integral = 0; // 可选：清零积分
        // pid->IntegralSum = 0; // 可选：清零积分和
    }
    
    float derivative = error - pid->prev_error;

    // 计算输出，积分项仅在误差小时起作用
    pid->output = pid->Kp * error + pid->Ki * pid->integral + pid->Kd * derivative;
    pid->prev_error = error;

    return pid->output;
}

// 设置PID目标值
void PID_Set_Setpoint(PID_TypeDef *pid, float setpoint) {
    pid->setpoint = setpoint;
}

/**********************************************************************************/

PID_TypeDef Position_left;			//左边位置环
PID_TypeDef Position_right;			//右边位置环

//PID_TypeDef Velocity_left;			//左边速度环
//PID_TypeDef Velocity_right;			//右边速度环

PID_TypeDef Angle_yaw;					//小车角度环

void Set_Position_left_PID(float Kp, float Ki, float Kd, float errorThreshold)
{
		Positional_PID_Init(&Position_left, Kp, Ki, Kd, errorThreshold);						//左边位置环初始化
}
void Set_Position_left_Target(float Target)
{
		PID_Set_Setpoint(&Position_left, Target);										//左边位置环设置目标值
}
int32_t Position_left_PID(float Actual)													
{
	return Positional_PID_Compute(&Position_left, Actual);				//左边位置位置式PID
}


void Set_Position_right_PID(float Kp, float Ki, float Kd, float errorThreshold)
{
   Positional_PID_Init(&Position_right, Kp, Ki, Kd, errorThreshold);						//右边位置环初始化
}
void Set_Position_right_Target(float Target)
{
		PID_Set_Setpoint(&Position_right, Target);									//右边位置环设置目标值
}
int32_t Position_right_PID(float Actual)												
{
	return Positional_PID_Compute(&Position_right, Actual);				//右边位置位置式PID
}


//void Set_Velocity_left_PID(float Kp, float Ki, float Kd)
//{
//    Incremental_PID_Init(&Velocity_left, Kp, Ki, Kd);						//左边速度环初始化
//}
//void Set_Velocity_left_Target(float Target)
//{
//		PID_Set_Setpoint(&Velocity_left, Target);										//左边速度环设置目标值
//}
//int32_t Velocity_left_PID(float Actual)												
//{
//	return Incremental_PID_Compute(&Velocity_left, Actual);				//左边速度增量式PID
//}


//void Set_Velocity_right_PID(float Kp, float Ki, float Kd)
//{
//    Incremental_PID_Init(&Velocity_right, Kp, Ki, Kd);					//右边速度环初始化
//}
//void Set_Velocity_right_Target(float Target)
//{
//		PID_Set_Setpoint(&Velocity_right, Target);									//右边速度环设置目标值
//}
//int32_t Velocity_right_PID(float Actual)												
//{
//	return Incremental_PID_Compute(&Velocity_right, Actual);			//右边速度增量式PID
//}


void Set_Angle_yaw_PID(float Kp, float Ki, float Kd, float errorThreshold)
{
    Positional_PID_Init(&Angle_yaw, Kp, Ki, Kd, errorThreshold);			//小车角度环初始化
}
void Set_Angle_yaw_Target(float Target)
{
		PID_Set_Setpoint(&Angle_yaw, Target);								//小车角度环设置目标值
}
int32_t Angle_yaw_PID(float Actual)	 											
{
	return Positional_PID_Compute(&Angle_yaw, Actual);						//小车角度位置式PID
}


