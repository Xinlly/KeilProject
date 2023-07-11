#include "8255A.h"
#include "KeyPad.h"
#include "MATH.H"
#include "Led.h"

#include "REG52.H"
#include "ABSACC.H"

uint8 scanLineIndex = 0;

void keypadScanTask()
{
    EX1 = 0;
    scanLineIndex = ++scanLineIndex >= 4 ? 0 : scanLineIndex;
    scanLine(scanLineIndex);
    EX1 = 1;
}