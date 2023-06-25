#ifndef _KeyPad_h
#define _KayPad_h
#include "CustomType.h"

#define eventSelect(scanIndex, keyCode) eventSelect##scanIndex##(keyCode)
#define keyCodePort _8255A_0PC_port
#define scanPort _8255A_0PCtrl_port
#define setScanPort(bitNum, value_bit) _8255A_setPC(0, bitNum, value_bit)
#define getScanWord(bitNum, value_bit) _8255A_getPCWord(bitNum, value_bit);

int8 scanKeycode();

/* typedef struct struct_Keypad_code_table
{
    uint8 num[10];
    uint8 div;
    uint8 mul;
    uint8 add;
    uint8 sub;
    uint8 clr;
    uint8 euq;
} Keypad_code_table;
extern Keypad_code_table keypad_code_table; */
#endif