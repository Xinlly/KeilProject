#ifndef _Timer_h
#define _Timer_h

//系统时钟周期（us）
#define sysTimer_Cycle 100
// 设置定时器T0为8位自动重装模式 02 for 100us@11.0592MHz
#define sysTimer_mod 0x02
// A4 for 100us@11.0592MHz
#define sysTimer_initValue_H 0xA4
//33 for 100us@11.0592MHz，考虑LED显示，矫正为54：
#define sysTimer_initValue_L 0xA4

extern bit flag_inter;

void initTimer0();
void initTimer1();
uint32 getSysCycleNum();
uint32 getSysTime_us();
uint32 getSysTime_ms();
uint32 getSysTime_s();

#endif