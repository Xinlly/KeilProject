#include "Motor.h"
#include "Timer.h"
#include "CustomType.h"
#include "REG52.H"
static float64 currentRPM;
int8 sampleRPM()
{
    static uint32 timeMark_ms;
    static int32 currentPulses;
    if (getSysTime_ms() - timeMark_ms >= pulseSamplesCycle_ms)
    {
        timeMark_ms = getSysTime_ms();
        currentPulses = currentPulsesH * 256 + currentPulsesL;
        currentRPM = currentPulses * gain_pulsesToRPM;
        currentPulsesH = 0x00;
        currentPulsesL = 0x00;
        TF1 = 0;
        return 0;
    }
    return -1;
}
float64 getRPM()
{
    return currentRPM;
}