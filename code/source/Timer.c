#include "REG52.H"
#include "CustomType.h"
#include "Led.h"
#include "Timer.h"
uint32 currentSysTime_us = 0;
uint32 currentSysCycleNum = 0;
bit flag_inter = 0;
void interruptTimer0() interrupt 1
{
	TL0 = sysTimer_initValue_L;
	TH0 = sysTimer_initValue_H;
	currentSysCycleNum += 1;
	currentSysTime_us += sysTimer_Cycle;
	ledDisplayTask();
}
void initTimer0()
{
	TMOD |= sysTimer_mod;
	TL0 = sysTimer_initValue_L;	  
	TH0 = sysTimer_initValue_H;	  
	TF0 = 0;	  
	EA = 1;
	ET0 = 1;
	TR0 = 1; 
}
void initTimer1() // 500us@11.0592MHz
{
	TMOD |= 0x50; 
	TL1 = 0x00;	  
	TH1 = 0x00;	  
	TF1 = 0;
	T1 = 0xFF;
}
uint32 getSysCycleNum()
{
	return currentSysCycleNum;
}
uint32 getSysTime_us()
{
	return currentSysTime_us;
}
uint32 getSysTime_ms()
{
	return currentSysTime_us / 1000;
}
uint32 getSysTime_s()
{
	return currentSysTime_us / 1000000;
}