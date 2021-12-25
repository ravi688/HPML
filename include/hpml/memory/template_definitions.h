
#pragma once

#include <hpml/template_system.h>

#ifdef __cplusplus
#	include <memory>
#else
#	include <memory.h>
#endif

#include <hpml/no_compile_header.h>

#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C
#endif

#define move(T) template(move, T)
#define instantiate_declaration_move(T) EXTERN_C void move(T)(T* dst, T src)
#define instantiate_implementation_move(T)\
void move(T)(T* dst, T src)\
{\
	memcpy(dst, &src, sizeof(T));\
}

#define copy(T)(dst, src) memcpy(T)(&dst, &src, sizeof(T))
#define instantiate_declaration_copy(T) NOT_IMPLEMENTED
#define instantiate_implementation_copy(T) NOT_IMPLEMENTED

