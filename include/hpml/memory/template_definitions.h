
#pragma once

#include <hpml/template_system.h>

#include <string.h>

#include <hpml/no_compile_header.h>
#include <hpml/defines.h>

#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C
#endif

#define move(T) c_template(move, T)
#define instantiate_declaration_move(T) EXTERN_C HPML_API void move(T)(T* dst, T src)
#define instantiate_implementation_move(T)\
EXTERN_C HPML_API void move(T)(T* dst, T src)\
{\
	memcpy(dst, &src, sizeof(T));\
}

#define copy(T)(dst, src) memcpy(T)(&dst, &src, sizeof(T))
#define instantiate_declaration_copy(T) NOT_IMPLEMENTED
#define instantiate_implementation_copy(T) NOT_IMPLEMENTED

