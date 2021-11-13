#ifndef __HPML_QUAT_TEMPLATE_DEFINITION_H__
#define __HPML_QUAT_TEMPLATE_DEFINITION_H__


#include <hpml/template_system.h>
#include <hpml/exception/exception.h>
#include <hpml/no_compile_header.h>

#include <math.h>

/* Begin: template signatures*/
#define quat_t(T) template(quat_t, T)
#define quat(T) template(quat, T)
#define quat_add(T) template(quat_add, T)
#define quat_sub(T) template(quat_sub, T)
#define quat_mul(T) template(quat_mul, T)
#define quat_div(T) template(quat_div, T)
#define quat_mul_component_wise(T) template(quat_mul_component_wise, T)
#define quat_identity(T) NOT_IMPLEMENTED
#define quat_inverse(T) template(quat_inverse, T)
/* End: template signatures*/

/* Begin: template declarations*/
#define quat(T) quat_t(T) quat(T)(T x, T y, T z, T w)
#define quat_add(T) quat_t(T) quat_add(T)(quat_t(T) q1, quat_t(T) q2)
#define quat_sub(T) quat_t(T) quat_sub(T)(quat_t(T) q1, quat_t(T) q2)
#define quat_mul(T) quat_t(T) quat_mul(T)(quat_t(T) q1, quat_t(T) q2)
#define quat_div(T) quat_t(T) quat_div(T)(quat_t(T) q1, quat_t(T) q2)
#define quat_mul_component_wise(T) quat_t(T) quat_mul_component_wise(T)(quat_t(T) q1, quat_t(T) q2)
#define quat_identity(T) NOT_IMPLEMENTED
#define quat_inverse(T) quat_t(T) quat_inverse(T)(quat_t(T) q)
/* End: template dclarations*/

/* Begin: template definitiosn*/
#define instantiate_quat_struct(T)\
typedef struct quat_t(T)\
{
	T x;\
	T y;\
	T z;\
	T w;\
} quat_t(T)

#define instantiate_implementation_quat(T)\
quat_t(T) quat(T)(T x, T y, T z, T w)\
{\
	quat_t(T) q = { x, y, z, w };\
	return q;\
}

#define instantiate_implementation_quat_add(T)\
quat_t(T) quat_add(T)(quat_t(T) q1, quat_t(T) q2)\
{\
	quat_t(T) q = { q1.x + q2.x, q1.y + q2.y, q1.z + q2.z, q1.w + q2.w };\
	return q;\
}

#define instantiate_implementation_quat_sub(T)\
quat_t(T) quat_sub(T)(quat_t(T) q1, quat_t(T) q2)\
{\
	quat_t(T) q = { q1.x - q2.x, q1.y - q2.y, q1.z - q2.z, q1.w - q2.w };\
	return q;\
}

/* End: template definitions*/

#endif