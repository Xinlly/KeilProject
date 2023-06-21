#include "CustomType.h"
#include "Uint8ToBin.h"
#include "Pid.h"
#include "Motor.h"
#include "Timer.h"
#include "REG51.H"
#include "Led.h"
#include "INTRINS.H"
#include "CTYPE.H"
#include "ABSACC.H"

#define Globals
#include "Global.h"

void main()
{
    P2 = 0;
    initLedSegData();
    initTimer0();
    initTimer1();
    TR1 = 1;
    while (1)
    {
        sampleRPM();
        ledDisplayUint(getRPM() + 0.5, 0, 3);
        ledDisplayUint(getdeltaUcontrol(), 4, 4);
        P2 = getUcontrol();
    }
}