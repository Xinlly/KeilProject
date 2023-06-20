#include "Motor.h"
#include "Timer.h"
#include "CustomType.h"
#include "REG52.H"
uint32 timeMark_ms;
int32 currentPulses;
int32 getSpeed()
{
    if (getSysTimeUs() - timeMark_ms >= getSpeedPeriod_ms)
    {
        currentPulses = currentPulsesH * 256 + currentPulsesL;
        timeMark_ms = getSysTimeMs();
        currentPulsesH = 0x00;
        currentPulsesL = 0x00;
        TF1 = 0;
        return currentPulses / pulsesPerRevolution / getSpeedPeriod_ms * 60000;
    }
    else
    {
        return -1;
    }
}