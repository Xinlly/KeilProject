#ifndef _KeyPad_h
#define _KayPad_h
#include "CustomType.h"

#define eventSelect(scanIndex, keyCode) eventSelect##scanIndex##(keyCode)
#define keypadPort _8255A_0PC_port
#define scanLine(num) (keypadPort = num + 15)
#define setScanPort(bitNum, value_bit) _8255A_setPC(0, bitNum, value_bit)
#define getScanWord(bitNum, value_bit) _8255A_getPCWord(bitNum, value_bit);

void keypadScanTask();

#endif