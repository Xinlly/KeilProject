#ifndef _Pid_h
#define _Pid_h

void increPIDCalculate(float32 targetValue, float32 currentValue, float32 sampleCycle_s);
float32 getdeltaUcontrol();
uint8 getUcontrol();

#endif