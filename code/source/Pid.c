#include "CustomType.h"
#include "Global.h"
#include "Timer.h"
#include "Pid.h"
#include "8255A.h"

#include "REG52.H"
#include "MATH.H"
#include "ABSACC.H"

idata float32 deltaErrorMax;
idata float32 Kp = 1;
static idata float32 Ti_sampleCycleNum, Td_sampleCycleNum, Ki, Kd;
static idata float32 error, error_old[2], sampleCycle_s;
static idata float32 Ucontrol, deltaUcontrol, deltaUcontrol_old;
static idata float32 deltaUp, deltaUi, deltaUd;

void increPIDCalculate(float32 targetValue_Abs, float32 currentValue_Abs)
{
    static uint8 UcontrolForOut;
    if (targetRPM_Abs != 0)
    {
        error = targetValue_Abs - currentValue_Abs;
        deltaUp = Kp * (error - error_old[0]);
        deltaUi = Ki * error;
        deltaUd = Kd * (error - 2 * error_old[0] + error_old[1]);
        deltaUcontrol = deltaUp + deltaUi + deltaUd;
        // Ucontrol += abs(error) < deltaErrorMax ? 0 :  deltaUcontrol;
        Ucontrol += deltaUcontrol;
        if (Ucontrol < 0)
        {
            Ucontrol = 0;
        }
        else if (Ucontrol > 127)
        {
            Ucontrol = 127;
        }
        UcontrolForOut = sign_taegetRPM * (uint8)(Ucontrol + 0.5) + 0x80;
    }
    else
    {
        UcontrolForOut = 0x80;
    }
    Uctrl_Port = UcontrolForOut;

    error_old[1] = error_old[0];
    error_old[0] = error;
}

float32 getDeltaUcontrol()
{
    return deltaUcontrol;
}

float32 getUcontrol()
{
    return Ucontrol;
}
void setPIDValue(float32 valueKp, float32 valueKi, float32 valueKd)
{
    Kp = valueKp;
    Ki = valueKi;
    Kd = valueKd;
}
void PID_setKp(float32 value)
{
    Kp = value;
}
void PID_setTi(float32 value)
{
    Ti_sampleCycleNum = value;
}
void PID_seTd(float32 value)
{
    Td_sampleCycleNum = value;
}
void initPID(float32 KpValue, float32 TiValue_sampleCycleNum, float32 TdValue_sampleCycleNum)
{
    Kp = KpValue;
    Ti_sampleCycleNum = TiValue_sampleCycleNum;
    Td_sampleCycleNum = TdValue_sampleCycleNum;
    Ki = 0 == Ti_sampleCycleNum ? 0 : Kp / Ti_sampleCycleNum;
    Kd = Kp * Td_sampleCycleNum;
}