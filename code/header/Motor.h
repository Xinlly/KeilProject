#ifndef _Motor_h
#define _Motor_h
#include "CustomType.h"

#define currentPulsesH TH1
#define currentPulsesL TL1
#define pulsesPerRevolution 300
#define pulseSamplesCycle_ms 80
// gain_pulsesToRPM = 60000 / pulsesPerRevolution / pulseSamplesCycle_ms
/* extern float32 gain_pulsesToRPM;
extern float32 currentRPM; */

int8 sampleRPM();
float32 getRPM();
void setGain_pulsesToRPM(float32 value);
void taskSampleRPM();

#endif