#ifndef __HPML_MAT22_TEMPLATE_DEFINITION_H__
#define __HPML_MAT22_TEMPLATE_DEFINITION_H__

#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <exception/exception.h>
#include <template_system.h>
#include <no_compile_header.h>

/*Begin: Template Definitions*/
/*template signatures*/
#define mat22_t(T) template(mat22_t, T)
#define mat22(T) template(mat22, T)
#define mat22_add(T) template(mat22_add, T)
#define mat22_sub(T) template(mat22_sub, T)
#define mat22_mul(T) template(mat22_mul, T)
#define mat22_mul_component_wise(T) template(mat22_mul_component_wise, T)
#define mat22_div(T) template(mat22_div, T)
#define mat22_is_null(T) template(mat22_is_null, T)
#define mat22_is_equal(T) template(mat22_is_equal, T)
#define mat22_null(T) mat22(T)(0, 0, 0, 0)
#define mat22_zero(T) mat22_null(T)
#define mat22_print(T) template(mat22_print, T)
#define mat22_negate(T) template(mat22_negate, T)
#define mat22_identity(T) mat22(T)(1, 0, 1, 0)
#define mat22_lerp(T) template(mat22_lerp, T)
#define mat22_mul_with_scalar(T) template(mat22_mul_with_scalar, T)
#define mat22_inverse(T) template(mat22_inverse, T)
#define mat22_transpose(T) template(mat22_transpose, T)
#define mat22_trace(T) template(mat22_trace, T)
#define mat22_rotation(T) template(mat22_rotation, T)

#define instantiate_mat22_struct(T)\
typedef struct mat22_t(T)\
{\
	T m0, m1, m2, m3;\
} mat22_t(T)


#define instantiate_declaration_mat22_print(T) void mat22_print(T)(mat22_t(T) m)
#define instantiate_declaration_mat22(T) mat22_t(T) mat22(T)(T v0, T v1, T v2, T v3)
#define instantiate_declaration_mat22_add(T) mat22_t(T) mat22_add(T)(mat22_t(T) m1, mat22_t(T) m2)
#define instantiate_declaration_mat22_sub(T) mat22_t(T) mat22_sub(T)(mat22_t(T) m1, mat22_t(T) m2)
#define instantiate_declaration_mat22_mul(T) mat22_t(T) mat22_mul(T)(mat22_t(T) m1, mat22_t(T) m2)
#define instantiate_declaration_mat22_div(T) mat22_t(T) mat22_div(T)(mat22_t(T) m1, mat22_t(T) m2)
#define instantiate_declaration_mat22_mul_component_wise(T) mat22_t(T) mat22_mul_component_wise(T)(mat22_t(T) m1, mat22_t(T) m2)
#define instantiate_declaration_mat22_is_null(T) bool mat22_is_null(T)(mat22_t(T) m)
#define instantiate_declaration_mat22_is_equal(T) bool mat22_is_equal(T)(mat22_t(T) m1, mat22_t(T) m2)
#define instantiate_declaration_mat22_null(T) mat22_t(T) mat22_null(T)()
#define instantiate_declaration_mat22_negate(T) mat22_t(T) mat22_negate(T)(mat22_t(T) m)
#define instantiate_declaration_mat22_identity(T) mat22_t(T) mat22_identity(T)()
#define instantiate_declaration_mat22_lerp(T) mat22_t(T) mat22_lerp(T)(mat22_t(T) m1, mat22_t(T) m2, float lerp_value)
#define instantiate_declaration_mat22_mul_with_scalar(T) mat22_t(T) mat22_mul_with_scalar(T)(mat22_t(T) m, T s)
#define instantiate_declaration_mat22_inverse(T) mat22_t(T) mat22_inverse(T)(mat22_t(T) m)
#define instantiate_declaration_mat22_transpose(T) mat22_t(T) mat22_transpose(T)(mat22_t(T) m)
#define instantiate_declaration_mat22_trace(T) T mat22_trace(T)(mat22_t(T) m)
#define instantiate_declaration_mat22_rotation(T) mat22_t(T) mat22_rotation(T)(T angle)

/* mat22(T): mat22 contructor taking four parameter to initialize the components
 * T v0: element at [0, 0] -> [Row, Column]
 * T v1: element at [0, 1] -> [Row, Column]
 * T v2: element at [1, 1] -> [Row, Column]
 * T v3: element at [1, 0] -> [Row, Column]
 * returns: mat22_t(T) initialized matrix
 */
#define instantiate_implementation_mat22(T)\
mat22_t(T) mat22(T)(T v0, T v1, T v2, T v3)\
{\
	mat22_t(T) m = { v0, v1, v2, v3 };\
	return m;\
}

/* mat22_trace(T): Calculates trace of 2x2 matrix 
 * mat22_t(T) m: Matrix of which the trace to be calculated
 * returns: T trace value
 */
#define instantiate_implementation_mat22_trace(T)\
T mat22_trace(T)(mat22_t(T) m)\
{\
	return m.m0 + m.m3;\
}

/* mat22_add(T): Adds a 2x2 matrix into another one [component-wise]
 * mat22_t(T) m1: Addend matrix
 * mat22_t(T) m2: Adder matrix
 * returns: mat22_t(T) addition resultant matrix
 */
#define instantiate_implementation_mat22_add(T)\
mat22_t(T) mat22_add(T)(mat22_t(T) m1, mat22_t(T) m2)\
{\
	mat22_t(T) m;\
	m.m0 = m1.m0 + m2.m0;\
	m.m1 = m1.m1 + m2.m1;\
	m.m2 = m1.m2 + m2.m2;\
	m.m3 = m1.m3 + m2.m3;\
	return m;\
}

/* mat22_sub(T): Subtracts a 2x2 matrix from another one [component-wise]
 * mat22_t(T) m1: Subtractend matrix
 * mat22_t(T) m2: Subtractor matrix
 * returns: mat22_t(T) subtraction resultant matrix
 */
#define instantiate_implementation_mat22_sub(T)\
mat22_t(T) mat22_sub(T)(mat22_t(T) m1, mat22_t(T) m2)\
{\
	mat22_t(T) m;\
	m.m0 = m1.m0 - m2.m0;\
	m.m1 = m1.m1 - m2.m1;\
	m.m2 = m1.m2 - m2.m2;\
	m.m3 = m1.m3 - m2.m3;\
	return m;\
}


/* mat22_mul(T): Multiplies two matrices [3x2 order] by Matrix-Multiplication-Rule
 * mat22_t(T) m1: Left side matrix in multiplication
 * mat22_t(T) m2: right side matrix in mulitplication
 * returns: mat22_t(T) resultant matrix
 */
#define instantiate_implementation_mat22_mul(T)\
mat22_t(T) mat22_mul(T)(mat22_t(T) m1, mat22_t(T) m2)\
{\
	mat22_t(T) m;\
	m.m0 = m1.m0 * m2.m0 + m1.m1 * m2.m2;\
	m.m1 = m1.m0 * m2.m1 + m1.m1 * m2.m3;\
	m.m2 = m1.m2 * m2.m0 + m1.m3 * m2.m2;\
	m.m3 = m1.m2 * m2.m1 + m1.m3 * m2.m3;\
	return m;\
}

/* mat22_mul_with_scalar(T): Multiplies a 2x2 matrix with a scalar component wise
 * mat22_t(T) m: Matrix to be multiplied for each components
 * T scalar: scalar value to be multiplied [float, double, char, and int etc.]
 * returns: mat22_t(T) resultant matrix
 */
#define instantiate_implementation_mat22_mul_with_scalar(T)\
mat22_t(T) mat22_mul_with_scalar(T)(mat22_t(T) m, T scalar)\
{\
	mat22_t(T) _m = m;\
	_m.m0 *= scalar;\
	_m.m1 *= scalar;\
	_m.m2 *= scalar;\
	_m.m3 *= scalar;\
	return _m;\
}

/* mat22_div(T): Divides two 2x2 matrices components
 * mat22_t(T) m1: nominator matrix [Dividend]
 * mat22_t(T) m2: denominator matrix [Divisor]
 * returns: mat22_t(T) quotient matrix
 */
#define instantiate_implementation_mat22_div(T)\
mat22_t(T) mat22_div(T)(mat22_t(T) m1, mat22_t(T) m2)\
{\
	EXCEPTION_BLOCK(\
		if(mat22_is_null(T)(m2))\
			THROW_EXCEPTION(DIVIDE_BY_ZERO);\
	)\
	mat22_t(T) m;\
	m.m0 = m1.m0 / m2.m0;\
	m.m1 = m1.m1 / m2.m1;\
	m.m2 = m1.m2 / m2.m2;\
	m.m3 = m1.m3 / m2.m3;\
	return m;\
}

/* TODO: Replace the equal to operator with some approximation [because of floating point errors]
 * mat22_is_null(T): Checks if the matrix is null or not
 * mat22_t(T) m: matrix to be checked for null
 * returns: bool true if the matrix is null, otherwise false
 */
#define instantiate_implementation_mat22_is_null(T)\
bool mat22_is_null(T)(mat22_t(T) m)\
{\
	return (m.m0 == 0) && (m.m1 == 0) && (m.m2 == 0) && (m.m3 == 0);\
}

/* TODO: Replace the equal to operator with some approximation [because of floating point errors]
 * mat22_is_equal(T): Checks if two mat22_t's are equal or not
 * mat22_t(T) m1: first matrix to be checked against
 * mat22_t(T) m2: second matrix to be checked against
 * returns: bool true if the two matrix are approximately equal, otherwise false
 */
#define instantiate_implementation_mat22_is_equal(T)\
bool mat22_is_equal(T)(mat22_t(T) m1, mat22_t(T) m2)\
{\
	return (m1.m0 == m2.m0) && (m1.m1 == m2.m1) && (m1.m2 == m2.m2) && (m1.m3 == m2.m3);\
}

/* mat22_negate(T): Negates all the elements of 2x2 matrix
 * mat22_t(T) m: matrix to be negated
 * returns: mat22_t(T) negated matrix
 */
#define instantiate_implementation_mat22_negate(T)\
mat22_t(T) mat22_negate(T)(mat22_t(T) m)\
{\
	mat22_t(T) _m;\
	_m.m0 = -m.m0;\
	_m.m1 = -m.m1;\
	_m.m2 = -m.m2;\
	_m.m3 = -m.m3;\
	return _m;\
}

/* mat22_mul_component_wise(T): Multiplies two matrices component wise
 * mat22_t(T) m1: First matrix involved in the calculation
 * mat22_t(T) m2: Second matrix involved in the calculation
 * returns: mat22_t(T) resultant matrix
 */
#define instantiate_implementation_mat22_mul_component_wise(T)\
mat22_t(T) mat22_mul_component_wise(T)(mat22_t(T) m1, mat22_t(T) m2)\
{\
	mat22_t(T) m = m1;\
	m.m0 *= m2.m0;\
	m.m1 *= m2.m1;\
	m.m2 *= m2.m2;\
	m.m3 *= m2.m3;\
	return m;\
}

/* mat22_transpose(T): Transposes a 2x2 matrix
 * mat22_t(T) m: Matrix to be transposed
 * returns: mat22_t(T) transposed matrix
 */
#define instantiate_implementation_mat22_transpose(T)\
mat22_t(T) mat22_transpose(T)(mat22_t(T) m)\
{\
	mat22_t(T) _m = m;\
	_m.m1 = m.m2;\
	_m.m2 = m.m1;\
	return _m;\
}

/* mat22_lerp(T): Linearly interpolates each elements of 2x2 matrices
 * mat22_t(T) m1: starting matrix
 * mat22_t(T) m2: ending matrix
 * float lerp_value: linear interpolation value [0, 1]
 * returns: mat22_t(T) interpolated matrix
 */
#define instantiate_implementation_mat22_lerp(T)\
mat22_t(T) mat22_lerp(T)(mat22_t(T) m1, mat22_t(T) m2, float lerp_value)\
{\
	mat22_t(T) m;\
	float _lerp_value = 1 - lerp_value;\
	m.m0 = m1.m0 * _lerp_value + lerp_value * m2.m0;\
	m.m1 = m1.m1 * _lerp_value + lerp_value * m2.m1;\
	m.m2 = m1.m2 * _lerp_value + lerp_value * m2.m2;\
	m.m3 = m1.m3 * _lerp_value + lerp_value * m2.m3;\
	return m;\
}

/* mat22_inverse(T): Inverts a 2x2 matrix 
 * mat22_t(T) m: Matrix to be inverted
 * returns: mat22_t(T) inverted 2x2 matrix
 */
#define instantiate_implementation_mat22_inverse(T)\
mat22_t(T) mat22_inverse(T)(mat22_t(T) m)\
{\
	float det = m.m0 * m.m1 - m.m2 * m.m3;\
	EXCEPTION_BLOCK(\
		if(det == 0)\
			THROW_EXCEPTION(INVERSION_OF_SINGULAR_MATRIX);\
	)\
	float inverse_det = 1 / det;\
	mat22_t(T) _m;\
	_m.m0 = m.m2 * inverse_det;\
	_m.m2 = m.m0 * inverse_det;\
	_m.m3 = -m.m3 * inverse_det;\
	_m.m1 = -m.m1 * inverse_det;\
	return _m;\
}

#define instantiate_implementation_mat22_rotation(T)\
mat22_t(T) mat22_rotation(T)(T angle)\
{\
	float cos_angle = cos(angle);\
	float sin_angle = sin(angle);\
	mat22_t(T) m;\
	m.m0 = cos_angle;\
	m.m1 = sin_angle;\
	m.m2 = -sin_angle;\
	m.m3 = cos_angle;\
	return m;\
}

/*End: Template Definitions*/

#endif