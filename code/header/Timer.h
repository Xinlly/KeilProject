#ifndef _Timer_h
#define _Timer_h

extern bit flag_inter;

void initTimer0();
void initTimer1();
uint32 getSysPeriod();
uint32 getSysTimeUs();
uint32 getSysTimeMs();
uint32 getSysTimeS();

#endif