#include "ti_msp_dl_config.h"
#include "gray_sensor.h"
//左侧边缘巡线
#define N1 DL_GPIO_readPins(GPIO_GraySensor_N1_PORT,GPIO_GraySensor_N1_PIN)
//左边内测巡线
#define N2 DL_GPIO_readPins(GPIO_GraySensor_N2_PORT,GPIO_GraySensor_N2_PIN)
#define N3 DL_GPIO_readPins(GPIO_GraySensor_N3_PORT,GPIO_GraySensor_N3_PIN)
#define N4 DL_GPIO_readPins(GPIO_GraySensor_N4_PORT,GPIO_GraySensor_N4_PIN)
//右边内测巡线
#define N5 DL_GPIO_readPins(GPIO_GraySensor_N5_PORT,GPIO_GraySensor_N5_PIN)
#define N6 DL_GPIO_readPins(GPIO_GraySensor_N6_PORT,GPIO_GraySensor_N6_PIN)
#define N7 DL_GPIO_readPins(GPIO_GraySensor_N7_PORT,GPIO_GraySensor_N7_PIN)
//右边边缘巡线
#define N8 DL_GPIO_readPins(GPIO_GraySensor_N8_PORT,GPIO_GraySensor_N8_PIN)
//定义前进
#define move 0  
//定义停止
#define stop 1

//定义灰度变量
uint32_t gray;
//检测到停止线，则返回停止标志，否则返回移动标志
uint32_t Stop_flag(void)
{
    if(N2==0 && N3==0 && N4==0 && N5==0 && N6==0 && N7==0)
    {
        return stop;
    }
    return move;
}


// void Left_turn()
// {

// }

// void Right_turn()
// {
    
// }

// void Straight_line()
// {
    
// }

// void Circle_line()
// {
    
// }