#ifndef _Global_h
#define _Global_h
#include "CustomType.h"
#ifdef Globals
#define EXT
#else
#define EXT extern
#endif
EXT int16 targetRPM;
EXT uint16 targetRPM_Abs;
EXT int8 sign_taegetRPM;
#endif