#include "CustomType.h"
#include "Timer.h"
float32 Kp = 1;
static float32 Ki, Kd, Ti, Td, Ucontrol, deltaUcontrol;
void increPIDCalculate(float32 error, float32 targetValue, float32 currentValue, float32 sampleCycle_s)
{
    static float32 error_old[2], deltaUp, deltaUi, deltaUd;
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
