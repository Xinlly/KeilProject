#ifndef _Led_h
#define _Led_h

#include "REG52.H"
#define led_bitCount 8
#define led_segPort P0
#define led_bitPort P1
sbit led_selectSeg_enable = P2 ^ 6;
sbit led_selectBit_enable = P2 ^ 7;

extern uint8 led_bitIndex;
extern uint8 led_segData[];
extern uint8 led_bitIndex_table[];
typedef struct struct_Led_segData_table
{
    uint8 normal[16];
    uint8 line; //"-"
    uint8 off;  // 熄灭
    uint8 H;    //"H"
    uint8 L;    //"L"
    uint8 n;    //"n"
    uint8 u;    //"u"
    uint8 P;    //"P"
    uint8 o;    //"o"
} Led_segData_table;
extern Led_segData_table led_segData_table;

void initLedSegData();
uint8 uint8ToSeg(uint8 uint8Data);
void ledDisplayUint(uint32 dispalyData, uint8 bitIndex, uint8 bitCount);
void ledDisplayTask();
#endif