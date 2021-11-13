
#pragma once

#include <stdint.h>

typedef uint16_t u16; 
typedef int16_t s16;

typedef uint32_t u32;
typedef int32_t s32; 

typedef uint64_t u64; 
typedef int64_t s64; 

typedef uint8_t u8; 
typedef int8_t s8; 

#ifndef __cplusplus
#define nullptr NULL
#endif

#define IGNORE_CONST(type, value) *(type*)(&value)

#ifdef GLOBAL_DEBUG 

#define ASSERT(boolean, ...)\
do\
{\
	if(!(boolean))\
	{\
		printf(__VA_ARGS__);\
		exit(0);\
	}\
} while(0)
#else 
#	define ASSERT(boolean, ...)
#endif