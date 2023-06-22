#ifndef _Pid_h
#define _Pid_h

void increPIDCalculate(float32 targetValue, float32 currentValue);
void taskIncrePIDCalculate(float32 targetValue, float32 currentValue);
float32 getdeltaUcontrol();
float32 getUcontrol();
void PID_setKp(float32 value);
void PID_setTi(float32 value);
void PID_seTd(float32 value);
void initPID(float32 KpValue, float32 TiValue, float32 TdValue, float32 sampleCycle_s);

#endif