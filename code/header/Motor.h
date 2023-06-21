#ifndef _Motor_h
#define _Motor_h
#include "CustomType.h"

#define pulsesPerRevolution 360
#define currentPulsesH TH1
#define currentPulsesL TL1
#define pulseSamplesCycle_ms 100
//gain_pulsesToRPM = 60000 / pulsesPerRevolution / pulseSamplesCycle_ms
#define gain_pulsesToRPM 5/3 //

int8 sampleRPM();
float64 getRPM();

#endif