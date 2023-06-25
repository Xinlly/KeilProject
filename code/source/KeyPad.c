#include "8255A.h"
#include "KeyPad.h"
#include "MATH.H"
#include "Led.h"

#include "ABSACC.H"

uint8 Keypad_lineCode[4] = {1, 2, 4, 8};
idata uint8 Keypad_code_table[8][8];
/* Keypad_code_table keypad_code_table = {
    {
        0x84, //"0"
        0x41, //"1"
        0x42, //"2"
        0x44, //"3"
        0x21, //"4"
        0x22, //"5"
        0x24, //"6"
        0x11, //"7"
        0x12, //"8"
        0x14  //"9"
    },
    0 //
};
void initKeypadCodeData()
{
    keypad_code_table.add = 0x88;
    keypad_code_table.sub = 0x48;
    keypad_code_table.mul = 0x28;
    keypad_code_table.div = 0x18;
    keypad_code_table.euq = 0x84;
    keypad_code_table.clr = 0x81;
} */
/* void eventSelect0(uint8 keyCode)
{
} */
int8 scanKeycode()
{
    static uint8 scanIndex, scanCode, keyCode, scanWord;
    /* for (scanIndex = 0; scanIndex < 4; scanIndex++)
    { */
    scanWord = getScanWord(scanIndex, 1);
    scanPort = scanWord;
    scanCode = Keypad_lineCode[scanIndex];
    keyCode = keyCodePort;
    setLedOut_int(1, 0, 8);
    // }
    return 0;
}