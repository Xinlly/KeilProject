#include "Uint8ToBin.h"
#include "REG52.H"
#include "ABSACC.H"
#include "8255A.h"

void init8255A()
{
    XBYTE[IO_8255A_portCtrl] = 0x80;
}