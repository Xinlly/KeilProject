#ifndef _Pid_h
#define _Pid_h

void increPIDCalculate(int32 error, int32 targetValue, int32 currentValue, uint8 sampleCycle);
int32 getdeltaUcontrol();

#endif