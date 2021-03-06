
/* Documentation:
 * Exception System
 *
 * Version History: 
 * Version 1.0 (Announced)
 * Version 1.1
 */


#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include <hpml/defines.h>

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#ifdef NO_EXCEPTION
#	define EXCEPTION_BLOCK(x)
#else
#	define EXCEPTION_BLOCK(x) x
#endif

#ifdef NO_EXCEPTION
/* Changes: 
 * Version 1.0: THROW
 * Version 1.1: THROW_EXCEPTION
 */
#	define THROW_EXCEPTION(exception)
#else
#	define THROW_EXCEPTION(exception) __throw_exception(__exception_name(exception), __LINE__, __FUNCTION__ , __FILE__)
#endif

/*Added in version 1.1*/
#define throw_exception(exception) THROW_EXCEPTION(exception)

#ifndef NO_EXCEPTION
typedef char* exception_t;
#	define __exception_name(exception_name) EXCEPTION_##exception_name
#	define define_exception(exception_name) const exception_t __exception_name(exception_name) = #exception_name
#	define declare_exception(exception_name) extern const exception_t __exception_name(exception_name)
#else
#	define __exception_name(exception_name)
#	define define_exception(exception_name)
#	define declare_exception(exception_name)
#endif

#ifndef NO_EXCEPTION
/* Changes:
 * Version 1.0: __throw
 * Version 1.1: __throw_exception
 */
HPML_API void __throw_exception(exception_t exception, uint64_t line_no, const char* method_name, const char* file_name);
#endif


/*Added in version 1.1*/
#include <hpml/exception/exception_declarations.h>

#ifdef __cplusplus
}
#endif // __cplusplus

#endif/*__EXCEPTION_H__*/
