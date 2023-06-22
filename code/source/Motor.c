#include "Motor.h"
#include "Pid.h"
#include "Timer.h"
#include "CustomType.h"
#include "REG51.H"
static float32 gain_pulsesToRPM;
static float32 currentRPM;
void setGain_pulsesToRPM(float32 value)
{
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
float32 getRPM()
{
    return currentRPM;
}