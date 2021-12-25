#ifndef __EXCEPTION_DECLARATIONS_H__
#define __EXCEPTION_DECLARATIONS_H__

#ifdef __cplusplus
extern "C" {
#endif

declare_exception(METHOD_NOT_IMPLEMENTED);
declare_exception(ACCESS_TO_RESTRICTED_CODE);
declare_exception(DIVIDE_BY_ZERO);
declare_exception(INVERSION_OF_SINGULAR_MATRIX);
declare_exception(NEGATIVE_VALUE);

#ifdef __cplusplus
}
#endif

#endif/*__EXCEPTION_DECLARATIONS_H__*/