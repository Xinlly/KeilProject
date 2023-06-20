#include "Uint8ToBin.h"
#include "CustomType.h"
#include "Pid.h"
#include "Motor.h"
#include "Timer.h"
#include "REG52.H"
#include "Led.h"
#include "INTRINS.H"
#include "CTYPE.H"
#include "ABSACC.H"

#define Globals
#include "Global.h"

void main()
{
    int32 currentRPM;
    initLedSegData();
    initTimer0();
    initTimer1();
    TR1 = 1;
    while (1)
    {
        if((currentRPM = sampleRPM()) >= 0){
            ledDisplayUint(currentRPM, 0, 3);
        }
    }
}