#ifndef _Timer_h
#define _Timer_h

//系统时钟周期（us）
#define sysTimer_Cycle 500
// 设置定时器模式01_500us@11.0592MHz
#define sysTimer_mod 0x01
// FE for 500us@11.0592MHz
#define sysTimer_initValue_H 0xFE
//33 for 500us@11.0592MHz，考虑LED显示，矫正为54：
#define sysTimer_initValue_L 0x59

extern bit flag_inter;

void initTimer0();
void initTimer1();
uint32 getSysCycleNum();
uint32 getSysTime_us();
uint32 getSysTime_ms();
uint32 getSysTime_s();

#endif