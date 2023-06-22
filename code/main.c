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
#include "ExInterrupt.h"

#define Globals
#include "Global.h"

void sampleButton()
{
    if (flag_interrupt0 && flag_interrupt1)
    {
        flag_interrupt0 = 0;
        flag_interrupt1 = 0;
    }
    else
    {
        if (flag_interrupt0)
        {
            targetRPM = targetRPM >= 295 ? 300 : targetRPM + 5;
            flag_interrupt0 = 0;
        }
        if (flag_interrupt1)
        {
            targetRPM = targetRPM <= 5 ? 0 : targetRPM - 5;
            flag_interrupt1 = 0;
        }
    }
    ET0 = 1;
    ET1 = 1;
}

void init()
{
    targetRPM = 150;
    // gain_pulsesToRPM = 60000 / pulsesPerRevolution / pulseSamplesCycle_ms
    setGain_pulsesToRPM(3);
    //PID: 0.28, 0.14, 0
    setPIDValue(0.28, 0.14, 0);
    initLedSegData();
    initExInterrupt();
    initTimer0();
    initTimer1();
    PT1 = 1;
    PT0 = 1;
    EX0 = 1;
    EX1 = 1;
    EA = 1;
}

void main()
{
    static uint32 timeMark_ms;
    P2 = 0x80; // 上电时转速置0
    init();
    while (1)
    {
        sampleButton();
        if (getSysTime_ms() - timeMark_ms >= pulseSamplesCycle_ms - 1)
        {
            timeMark_ms = getSysTime_ms();
            taskSampleRPM();
            increPIDCalculate(targetRPM, getRPM());
            setLedOut_int(getRPM() + 0.5, 0, 4);
            setLedOut_int(targetRPM, 4, 4);
        }
    }
}