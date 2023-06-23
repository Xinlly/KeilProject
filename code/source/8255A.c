#include "Uint8ToBin.h"
#include "REG52.H"
#include "ABSACC.H"
#include "8255A.h"

void init8255A()
{
    _8255A_0PCtrl_port = 0x80;
    _8255A_1PCtrl_port = 0x80;
}