#include "CustomType.h"
#include "Timer.h"
idata float32 Kp;
static idata float32 Ti, Td, Ucontrol, deltaUcontrol;
void increPIDCalculate(float32 targetValue, float32 currentValue, float32 sampleCycle_s)
{
    static idata float32 error_old[2];
    idata float32 deltaUp, deltaUi, deltaUd, Ki, Kd;
    idata float32 error = targetValue - currentValue;
    Ki = 0 == Ti ? 0 : Kp * sampleCycle_s / Ti;
    Kd = Kp * Td / sampleCycle_s;
    deltaUp = Kp * (error - error_old[0]);
    deltaUi = Ki * error;
    deltaUd = Kd * (error - 2 * error_old[0] + error_old[1]);
    deltaUcontrol = deltaUp + deltaUi + deltaUd;
    
    error_old[1] = error_old[0];
    error_old[0] = error;
}

float32 getdeltaUcontrol()
{
    return deltaUcontrol;
}
