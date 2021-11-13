
#define HEADER_CONFIGURATION_SYSTEM_HEADER

#ifdef GLOBAL_DEBUG
#	ifndef DEBUG
#		define DEBUG
#	endif 
#endif

#ifdef GLOBAL_RELEASE
#	ifndef RELEASE
#		define RELEASE
#	endif 
#endif

#define VEC4_ENABLE_SIMD_ACCELERATION

#include <hpml/header_configuration_system/header_configuration_system.h>