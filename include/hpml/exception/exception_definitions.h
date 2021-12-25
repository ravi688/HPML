#ifndef __EXCEPTION_DEFINITIONS_H__
#define __EXCEPTION_DEFINITIONS_H__

#ifdef __cplusplus
extern "C" {
#endif


define_exception(METHOD_NOT_IMPLEMENTED);
define_exception(ACCESS_TO_RESTRICTED_CODE);
define_exception(DIVIDE_BY_ZERO);
define_exception(INVERSION_OF_SINGULAR_MATRIX);
define_exception(NEGATIVE_VALUE);

#ifdef __cplusplus
}
#endif

#endif/*__EXCEPTION_DEFINITIONS_H__*/