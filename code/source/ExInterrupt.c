#include "REG52.H"
#include "Global.h"
#include "CustomType.h"

bit flag_interrupt0 = 0;
bit flag_interrupt1 = 0;

void exInterrupt0() interrupt 0
{
    ET0 = 0;
    ET1 = 0;
    flag_interrupt0 = 1;
}
void exInterrupt1() interrupt 2
{
    ET0 = 0;
    ET1 = 0;
    flag_interrupt1 = 1;
}
void initExInterrupt()
{
    IT0 = 1;
    IT1 = 1;
}