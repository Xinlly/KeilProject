#ifndef _Pid_h
#define _Pid_h

extern idata float32 deltaErrorMax;
/* extern idata float32 Kp;
extern idata float32 Ti_sampleCycleNum, Td_sampleCycleNum, Ki, Kd;
extern idata float32 error, error_old[2], sampleCycle_s;
extern idata float32 Ucontrol, deltaUcontrol, deltaUcontrol_old;
extern idata float32 deltaUp, deltaUi, deltaUd; */

#define Uctrl_Port _8255A_1PA_port
#define maxUd_Abs 300
#define minUd_Abs 0
#define maxUc_Abs 127
#define minUc_Abs 0

void setPIDValue(float32 valueKp, float32 valueKi, float32 valueKd);
void increPIDCalculate(float32 targetValue, float32 currentValue);
float32 getDeltaUcontrol();
float32 getUcontrol();
void PID_setKp(float32 value);
void PID_setTi(float32 value);
void PID_seTd(float32 value);
void initPID(float32 KpValue, float32 TiValue_sampleCycleNum, float32 TdValue_sampleCycleNum);
#endif