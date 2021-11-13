
#pragma once

#include <hpml/template_system.h>

#include <memory.h>

#include <hpml/no_compile_header.h>


#define move(T) template(move, T)
#define instantiate_declaration_move(T) void move(T)(T* dst, T src)
#define instantiate_implementation_move(T)\
void move(T)(T* dst, T src)\
{\
	memcpy(dst, &src, sizeof(T));\
}

#define copy(T)(dst, src) memcpy(T)(&dst, &src, sizeof(T))
#define instantiate_declaration_copy(T) NOT_IMPLEMENTED
#define instantiate_implementation_copy(T) NOT_IMPLEMENTED