#pragma once

#if (defined _WIN32 || defined __CYGWIN__) && defined(__GNUC__)
#	define HPML_IMPORT_API __declspec(dllimport)
#	define HPML_EXPORT_API __declspec(dllexport)
#else
#	define HPML_IMPORT_API __attribute__((visibility("default")))
#	define HPML_EXPORT_API __attribute__((visibility("default")))
#endif

#ifdef HPML_BUILD_STATIC_LIBRARY
#	define HPML_API
#elif defined(HPML_BUILD_DYNAMIC_LIBRARY)
#	define HPML_API HPML_EXPORT_API
#elif defined(HPML_USE_DYNAMIC_LIBRARY)
#	define HPML_API HPML_IMPORT_API
#elif defined(HPML_USE_STATIC_LIBRARY)
#	define HPML_API
#else
#	define HPML_API
#endif
