#include "CustomType.h"
#include "Uint8ToBin.h"
#include "REG52.H"
#include "Led.h"
#include "Timer.h"
uint8 led_bitIndex;
uint8 led_segData[led_bitCount] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
uint8 led_bitIndex_table[] = {
    bin(00000001),
    bin(00000010),
    bin(00000100),
    bin(00001000),
    bin(00010000),
    bin(00100000),
    bin(01000000),
    bin(10000000) //
};
Led_segData_table led_segData_table = {
    {
        0xC0, //"0"
        0xF9, //"1"
        0xA4, //"2"
        0xB0, //"3"
        0x99, //"4"
        0x92, //"5"
        0x82, //"6"
        0xF8, //"7"
        0x80, //"8"
        0x90, //"9"
        0x88, //"A"
        0x83, //"B"
        0xC6, //"C"
        0xA1, //"D"
        0x86, //"E"
        0x8E  //"F"
    },
    0 //
};
void initLedSegData()
{
    led_segData_table.line = 0x40; //"-"
    led_segData_table.off = 0xFF;  // 熄灭
    led_segData_table.H = 0x76;    //"H"
    led_segData_table.L = 0x38;    //"L"
    led_segData_table.n = 0x37;    //"n"
    led_segData_table.u = 0x3E;    //"u"
    led_segData_table.P = 0x73;    //"P"
    led_segData_table.o = 0x5C;    //"o"
}

uint8 uint8ToSeg(uint8 unit8Data)
{
    uint8 led_displayData;
    if (unit8Data >= 0 && unit8Data <= 9)
    {
        led_displayData = led_segData_table.normal[unit8Data];
    }
    else if (unit8Data >= '0' && unit8Data <= '9')
    {
        led_displayData = led_segData_table.normal[unit8Data - '0'];
    }
    else if (unit8Data >= 'A' && unit8Data <= 'F')
    {
        led_displayData = led_segData_table.normal[unit8Data - 'A' + 10];
    }
    else
    {
        switch (unit8Data)
        {
        case 'H':
            led_displayData = led_segData_table.H;
            break;
        case 'L':
            led_displayData = led_segData_table.L;
            break;
        case 'n':
            led_displayData = led_segData_table.n;
            break;
        case 'u':
            led_displayData = led_segData_table.u;
            break;
        case 'P':
            led_displayData = led_segData_table.P;
            break;
        default:
            led_displayData = led_segData_table.line;
            break;
        }
    }
    return led_displayData;
}

void ledDisplay(uint8 displayData, uint8 led_bitIndex)
{
    led_segPort = led_segData_table.off;
    led_bitPort = led_bitIndex_table[led_bitIndex];
    led_segPort = 0xFF;
    led_segPort = displayData;
}

void ledDisplayUint(uint32 dispalyData, uint8 bitIndex, uint8 bitCount)
{
    uint8 tempIndex, tempIndexMax = bitIndex + bitCount;
    for (tempIndex = bitIndex; tempIndex < tempIndexMax; tempIndex++)
    {
        led_segData[tempIndex] = uint8ToSeg(dispalyData % 10);
        // ledDisplay(led_segData[tempIndex], tempIndex);
        dispalyData /= 10;
    }
}

void ledDisplayTask()
{
    led_segPort = led_segData_table.off;
    /* led_selectSeg_enable = 1;
    led_selectSeg_enable = 0; */

    led_bitPort = led_bitIndex_table[led_bitIndex];
    /* led_selectBit_enable = 1;
    led_selectBit_enable = 0; */

    led_segPort = led_segData[led_bitIndex];
    /* led_selectSeg_enable = 1;
    led_selectSeg_enable = 0; */

    led_bitIndex = ++led_bitIndex >= led_bitCount ? 0 : led_bitIndex;
}
