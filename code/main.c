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

void init()
{
    P2 = 0x80;
    // gain_pulsesToRPM = 60000 / pulsesPerRevolution / pulseSamplesCycle_ms
    setGain_pulsesToRPM(3);
    initLedSegData();
    // initPID(1000, 0, 0, pulseSamplesCycle_ms / 1000);
    setPIDValue(0.28, 0.14, 0);
    initTimer0();
    initTimer1();
}

void main()
{
    static uint32 timeMarkForCal_ms, timeMarkForLED_ms;
    static int32 temp;
    init();
    while (1)
    {
        if (getSysTime_ms() - timeMarkForCal_ms >= pulseSamplesCycle_ms - 1)
        {
            timeMarkForCal_ms = getSysTime_ms();
            taskSampleRPM();
            increPIDCalculate(150, getRPM());
            /* }
            if (getSysTime_ms() - timeMarkForLED_ms > 100)
            { */
            timeMarkForLED_ms = getSysTime_ms();
            temp = getUcontrol();
            setLedOut_int(temp, 4, 4);
            setLedOut_int(getRPM() + 0.5, 0, 4);
        }
    }
}