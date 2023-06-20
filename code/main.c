#include "Uint8ToBin.h"
#include "CustomType.h"
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
    uint32 num_ms = 0;
    uint8 index = 0;
    int32 currentSpeed;
    initLedSegData();
    initTimer0();
    initTimer1();
    TR1 = 1;
    while (1)
    {
        if(currentSpeed =getSpeed() >= 0){
            ledDisplayUint(currentSpeed, 0, 8);
        }
    }
}