#ifndef _Motor_h
#define _Motor_h
#include "CustomType.h"

#define pulsesPerRevolution 360
#define currentPulsesH TH1
#define currentPulsesL TL1
#define pulsesPerRevolution 360
#define pulseSamplesCycle_ms 50
// gain_pulsesToRPM = 60000 / pulsesPerRevolution / pulseSamplesCycle_ms
// 10/3
int8 sampleRPM();
float64 getRPM();
void setGain_pulsesToRPM(float64 value);
void taskSampleRPM();

#endif