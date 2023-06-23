#include "CustomType.h"
#include "Uint8ToBin.h"
#include "Pid.h"
#include "Motor.h"
#include "Timer.h"
#include "ExInterrupt.h"
#include "Led.h"

#include "REG51.H"
#include "INTRINS.H"
#include "CTYPE.H"
#include "ABSACC.H"
#include "MATH.H"

#define Globals
#include "Global.h"

void sampleButton()
{
    if (flag_interrupt0 || flag_interrupt1)
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
                targetRPM = targetRPM >= (300 - 15) ? 300 : targetRPM + 15;
                flag_interrupt0 = 0;
            }
            if (flag_interrupt1)
            {
                targetRPM = targetRPM <= -(300 - 15) ? -300 : targetRPM - 15;
                flag_interrupt1 = 0;
            }
        }
        targetRPM_Abs = abs(targetRPM);
        deltaErrorMax = 0.03 * targetRPM_Abs;
        sign_taegetRPM = targetRPM < 0 ? -1 : 1;
    }
    ET0 = 1;
    ET1 = 1;
}

void init()
{
    targetRPM = 150;
    targetRPM_Abs = 150;
    sign_taegetRPM = 1;
    deltaErrorMax = 0.03 * targetRPM_Abs;
    // gain_pulsesToRPM = 60000 / pulsesPerRevolution / pulseSamplesCycle_ms
    setGain_pulsesToRPM(3);
    // setPIDValue((maxUc_Abs-minUc_Abs)/(maxUd_Abs-minUd_Abs)/8, Kp/2, Kp*0.1);
    setPIDValue(0.052917, 0.029398, 0.026458);
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
    static uint32 timeMarkCalculate_ms;
    // static uint32 timeMarkRefreshLED_ms;
    P2 = 0x80; // 上电时转速置0
    init();
    while (1)
    {
        sampleButton();
        if (getSysTime_ms() - timeMarkCalculate_ms >= pulseSamplesCycle_ms - 1)
        {
            timeMarkCalculate_ms = getSysTime_ms();
            taskSampleRPM();
            increPIDCalculate(targetRPM_Abs, getRPM());
            setLedOut_int(targetRPM, 4, 4);
            setLedOut_int(sign_taegetRPM * getRPM() + 0.5, 0, 4);
        }
        /* if (getSysTime_ms() - timeMarkRefreshLED_ms >= 360)
        {
            timeMarkRefreshLED_ms = getSysTime_ms();
            setLedOut_int(targetRPM, 4, 4);
            setLedOut_int(sign_taegetRPM * getRPM() + 0.5, 0, 4);
        } */
    }
}