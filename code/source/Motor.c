#include "Motor.h"
#include "Timer.h"
#include "CustomType.h"
#include "REG52.H"
int32 calculateSpeed()
{
    int32 currentPulses;
    float64 currentRPM;
    currentPulses = currentPulsesH * 256 + currentPulsesL;
    currentRPM = currentPulses * gain_pulsesToRPM ;
    currentRPM += 0.5;//四舍五入
    return currentRPM;
}
int32 getSpeed()
{
    static uint32 timeMark_ms;
    int32 currentRPM;
    if (getSysTimeMs() - timeMark_ms >= getSpeedPeriod_ms)
    {
        timeMark_ms = getSysTimeMs();
        currentRPM = calculateSpeed();
        currentPulsesH = 0x00;
        currentPulsesL = 0x00;
        TF1 = 0;
        return currentRPM;
    }
    else
    {
        return -1;
    }
}