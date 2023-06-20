#include "REG52.H"
#include "CustomType.h"
#include "Led.h"
uint32 currentSysTime_us = 0;
uint32 currentSysPeriod = 0;
uint32 taskPlan_timeMarkMs;
bit flag_inter = 0;
void interruptTimer0() interrupt 1
{
	TL0 = 0x33;
	TH0 = 0xFE;
	currentSysPeriod += 1;
	currentSysTime_us += 500;
	ledDisplayTask();
}
void initTimer0() // 500us@11.0592MHz
{
	TMOD |= 0x01; // 设置定时器模式
	TL0 = 0x33;	  // 设置定时初始值
	TH0 = 0xFE;	  // 设置定时重载值
	TF0 = 0;	  // 清除TF0标志
	EA = 1;
	ET0 = 1;
	TR0 = 1; // 定时器0开始计时
}
void initTimer1() // 500us@11.0592MHz
{
	TMOD |= 0x60; 
	TL1 = 0x00;	  
	TH1 = 0x00;	  
	TF1 = 0;	  
}
uint32 getSysPeriod()
{
	return currentSysPeriod;
}
uint32 getSysTimeUs()
{
	return currentSysTime_us;
}
uint32 getSysTimeMs()
{
	return currentSysTime_us / 1000;
}
uint32 getSysTimeS()
{
	return currentSysTime_us / 1000000;
}