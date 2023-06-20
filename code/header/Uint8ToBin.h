#ifndef _Uint8ToBin_h
#define _Uint8ToBin_h
#define uint8ToBin(n) (((n >> 21) & 0x80) | \
                       ((n >> 18) & 0x40) | \
                       ((n >> 15) & 0x20) | \
                       ((n >> 12) & 0x10) | \
                       ((n >> 9) & 0x08) |  \
                       ((n >> 6) & 0x04) |  \
                       ((n >> 3) & 0x02) |  \
                       ((n)&0x01))

#define bin(n) uint8ToBin(0x##n##l)
#endif