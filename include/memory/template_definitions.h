
#pragma once

#include <template.h>

#include <memory.h>

#include <no_compile_header.h>


#define move(T) template(__move, T)
#define instantiate_declaration_move(T) void move(T)(T* dst, T src)
#define instantiate_implementation_move(T)\
void move(T)(T* dst, T src)\
{\
	memcpy(dst, &src, sizeof(src));\
}

#define copy(dst, src) memcpy(&dst, &src, sizeof(src))
#define instantiate_declaration_copy(T) NOT_IMPLEMENTED
#define instantiate_implementation_copy(T) NOT_IMPLEMENTED