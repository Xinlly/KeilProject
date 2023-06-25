#ifndef _8255A_h
#define _8255A_h

#define _8255A_0PA_addr 0x0000
#define _8255A_0PB_addr 0x0001
#define _8255A_0PC_addr 0x0002
#define _8255A_0PCtrl_addr 0x0003
#define _8255A_0PA_port XBYTE[_8255A_0PA_addr]
#define _8255A_0PB_port XBYTE[_8255A_0PB_addr]
#define _8255A_0PC_port XBYTE[_8255A_0PC_addr]
#define _8255A_0PCtrl_port XBYTE[_8255A_0PCtrl_addr]

#define _8255A_1PA_addr 0x0010
#define _8255A_1PB_addr 0x0011
#define _8255A_1PC_addr 0x0012
#define _8255A_1PCtrl_addr 0x0013
#define _8255A_1PA_port XBYTE[_8255A_1PA_addr]
#define _8255A_1PB_port XBYTE[_8255A_1PB_addr]
#define _8255A_1PC_port XBYTE[_8255A_1PC_addr]
#define _8255A_1PCtrl_port XBYTE[_8255A_1PCtrl_addr]

#define _8255A_getPCWord(bitNum,value_bit) (bitNum*2 + value_bit) 
#define _8255A_setPC(nPC, bitNum, value_bit) (_8255A_##nPC##PCtrl_port = _8255A_getPCWord(bitNum,value_bit))

void init8255A();

#endif