#pragma once




/*Begin: Header Configuration System*/

/*set the configuration, for this file*/
#define HEADER_CONFIGURATION_SYSTEM_IMPLEMENTATION

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

#include <hpml/header_configuration_system/header_configuration_system.h>
/*End: Header Configuration System*/