#include "Motor.h"
#include "Pid.h"
#include "Timer.h"
#include "CustomType.h"
#include "REG51.H"
static float64 gain_pulsesToRPM;
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
        increPIDCalculate(150, currentRPM);
        return 0;
    }
    return -1;
}
void setGain_pulsesToRPM(float64 value){
    gain_pulsesToRPM = value;
}
void taskSampleRPM()
{
    static int32 currentPulses;
    currentPulses = currentPulsesH * 256 + currentPulsesL;
    currentRPM = currentPulses * gain_pulsesToRPM;
    currentPulsesH = 0x00;
    currentPulsesL = 0x00;
    TF1 = 0;
}
float64 getRPM()
{
    return currentRPM;
}