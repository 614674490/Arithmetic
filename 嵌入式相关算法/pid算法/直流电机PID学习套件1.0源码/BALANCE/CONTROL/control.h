#ifndef __CONTROL_H
#define __CONTROL_H
#include "sys.h"
  /**************************************************************************
作者：平衡小车之家
我的淘宝小店：http://shop114407458.taobao.com/
**************************************************************************/
#define PI 3.14159265
#define ZHONGZHI 3085
extern	int Balance_Pwm,Velocity_Pwm;
int TIM1_UP_IRQHandler(void);
void Set_Pwm(int moto);
void Key(void);
void Xianfu_Pwm(void);
int myabs(int a);
int Incremental_PI (int Encoder,int Target);
int Position_PID (int Encoder,int Target);
#endif
