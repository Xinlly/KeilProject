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
    // gain_pulsesToRPM = 60000 / pulsesPerRevolution / pulseSamplesCycle_ms
    // 10/3
    idata float64 gain_pulsesToRPM = 10 / 3;
    P2 = 0;
    setGain_pulsesToRPM(gain_pulsesToRPM);
    initLedSegData();
    initPID(10, 0, 0, pulseSamplesCycle_ms * 1000);
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
        if (getSysTime_ms() - timeMarkForCal_ms >= pulseSamplesCycle_ms)
        {
            timeMarkForCal_ms = getSysTime_ms();
            taskSampleRPM();
            taskIncrePIDCalculate(100, getRPM());
        }
        if (getSysTime_ms() - timeMarkForLED_ms > 1000)
        {
            timeMarkForLED_ms = getSysTime_us();
            temp = getUcontrol();
            setLedOut_int(-12, 4, 3);
            setLedOut_int(getRPM() + 0.5, 0, 4);
        }
    }
}