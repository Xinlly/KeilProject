#ifndef _Global_h
#define _Global_h
#include "CustomType.h"
#ifdef Globals
#define EXT
#else
#define EXT extern
#endif
EXT uint16 targetRPM;
#endif