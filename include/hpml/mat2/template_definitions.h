#pragma once

#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <hpml/exception/exception.h>
#include <hpml/template_system.h>
#include <hpml/no_compile_header.h>
#include <hpml/defines.h>

/*Begin: Template Definitions*/
/*template signatures*/
#define mat2_t(T) template(mat2_t, T)
#define mat2(T) template(mat2, T)
#define mat2_add(T) template(mat2_add, T)
#define mat2_sub(T) template(mat2_sub, T)
#define mat2_mul(T) template(mat2_mul, T)
#define mat2_mul_component_wise(T) template(mat2_mul_component_wise, T)
#define mat2_div(T) template(mat2_div, T)
#define mat2_is_null(T) template(mat2_is_null, T)
#define mat2_is_equal(T) template(mat2_is_equal, T)
#define mat2_null(T) mat2(T)(0, 0, 0, 0)
#define mat2_zero(T) mat2_null(T)
#define mat2_print(T) template(mat2_print, T)
#define mat2_negate(T) template(mat2_negate, T)
#define mat2_identity(T) template(mat2_identity, T)
#define mat2_lerp(T) template(mat2_lerp, T)
#define mat2_mul_with_scalar(T) template(mat2_mul_with_scalar, T)
#define mat2_inverse(T) template(mat2_inverse, T)
#define mat2_transpose(T) template(mat2_transpose, T)
#define mat2_trace(T) template(mat2_trace, T)
#define mat2_rotation(T) template(mat2_rotation, T)

#define instantiate_mat2_struct(T)\
typedef struct mat2_t(T)\
{\
	T m0, m1, m2, m3;\
} mat2_t(T)

/*mat2_identity(T)*/
#define instantiate_declaration_mat2_identity(T) HPML_API mat2_t(T) mat2_identity(T)()
#define instantiate_implementation_mat2_identity(T) HPML_API mat2_t(T) mat2_identity(T)() { return (mat2_t(T)) { 1, 0, 0, 1 }; }

#define instantiate_declaration_mat2_print(T) HPML_API void mat2_print(T)(mat2_t(T) m)
#define instantiate_declaration_mat2(T) HPML_API mat2_t(T) mat2(T)(T v0, T v1, T v2, T v3)
#define instantiate_declaration_mat2_add(T) HPML_API mat2_t(T) mat2_add(T)(mat2_t(T) m1, mat2_t(T) m2)
#define instantiate_declaration_mat2_sub(T) HPML_API mat2_t(T) mat2_sub(T)(mat2_t(T) m1, mat2_t(T) m2)
#define instantiate_declaration_mat2_mul(T) HPML_API mat2_t(T) mat2_mul(T)(mat2_t(T) m1, mat2_t(T) m2)
#define instantiate_declaration_mat2_div(T) HPML_API mat2_t(T) mat2_div(T)(mat2_t(T) m1, mat2_t(T) m2)
#define instantiate_declaration_mat2_mul_component_wise(T) HPML_API mat2_t(T) mat2_mul_component_wise(T)(mat2_t(T) m1, mat2_t(T) m2)
#define instantiate_declaration_mat2_is_null(T) HPML_API bool mat2_is_null(T)(mat2_t(T) m)
#define instantiate_declaration_mat2_is_equal(T) HPML_API bool mat2_is_equal(T)(mat2_t(T) m1, mat2_t(T) m2)
#define instantiate_declaration_mat2_null(T) HPML_API mat2_t(T) mat2_null(T)()
#define instantiate_declaration_mat2_negate(T) HPML_API mat2_t(T) mat2_negate(T)(mat2_t(T) m)
#define instantiate_declaration_mat2_lerp(T) HPML_API mat2_t(T) mat2_lerp(T)(mat2_t(T) m1, mat2_t(T) m2, float lerp_value)
#define instantiate_declaration_mat2_mul_with_scalar(T) HPML_API mat2_t(T) mat2_mul_with_scalar(T)(mat2_t(T) m, T s)
#define instantiate_declaration_mat2_inverse(T) HPML_API mat2_t(T) mat2_inverse(T)(mat2_t(T) m)
#define instantiate_declaration_mat2_transpose(T) HPML_API mat2_t(T) mat2_transpose(T)(mat2_t(T) m)
#define instantiate_declaration_mat2_trace(T) HPML_API T mat2_trace(T)(mat2_t(T) m)
#define instantiate_declaration_mat2_rotation(T) HPML_API mat2_t(T) mat2_rotation(T)(T angle)

/* mat2(T): mat2 contructor taking four parameter to initialize the components
 * T v0: element at [0, 0] -> [Row, Column]
 * T v1: element at [0, 1] -> [Row, Column]
 * T v2: element at [1, 1] -> [Row, Column]
 * T v3: element at [1, 0] -> [Row, Column]
 * returns: mat2_t(T) initialized matrix
 */
#define instantiate_implementation_mat2(T)\
HPML_API mat2_t(T) mat2(T)(T v0, T v1, T v2, T v3)\
{\
	mat2_t(T) m = { v0, v1, v2, v3 };\
	return m;\
}

/* mat2_trace(T): Calculates trace of 2x2 matrix 
 * mat2_t(T) m: Matrix of which the trace to be calculated
 * returns: T trace value
 */
#define instantiate_implementation_mat2_trace(T)\
HPML_API T mat2_trace(T)(mat2_t(T) m)\
{\
	return m.m0 + m.m3;\
}

/* mat2_add(T): Adds a 2x2 matrix into another one [component-wise]
 * mat2_t(T) m1: Addend matrix
 * mat2_t(T) m2: Adder matrix
 * returns: mat2_t(T) addition resultant matrix
 */
#define instantiate_implementation_mat2_add(T)\
HPML_API mat2_t(T) mat2_add(T)(mat2_t(T) m1, mat2_t(T) m2)\
{\
	mat2_t(T) m;\
	m.m0 = m1.m0 + m2.m0;\
	m.m1 = m1.m1 + m2.m1;\
	m.m2 = m1.m2 + m2.m2;\
	m.m3 = m1.m3 + m2.m3;\
	return m;\
}

/* mat2_sub(T): Subtracts a 2x2 matrix from another one [component-wise]
 * mat2_t(T) m1: Subtractend matrix
 * mat2_t(T) m2: Subtractor matrix
 * returns: mat2_t(T) subtraction resultant matrix
 */
#define instantiate_implementation_mat2_sub(T)\
HPML_API mat2_t(T) mat2_sub(T)(mat2_t(T) m1, mat2_t(T) m2)\
{\
	mat2_t(T) m;\
	m.m0 = m1.m0 - m2.m0;\
	m.m1 = m1.m1 - m2.m1;\
	m.m2 = m1.m2 - m2.m2;\
	m.m3 = m1.m3 - m2.m3;\
	return m;\
}


/* mat2_mul(T): Multiplies two matrices [3x2 order] by Matrix-Multiplication-Rule
 * mat2_t(T) m1: Left side matrix in multiplication
 * mat2_t(T) m2: right side matrix in mulitplication
 * returns: mat2_t(T) resultant matrix
 */
#define instantiate_implementation_mat2_mul(T)\
HPML_API mat2_t(T) mat2_mul(T)(mat2_t(T) m1, mat2_t(T) m2)\
{\
	mat2_t(T) m;\
	m.m0 = m1.m0 * m2.m0 + m1.m1 * m2.m2;\
	m.m1 = m1.m0 * m2.m1 + m1.m1 * m2.m3;\
	m.m2 = m1.m2 * m2.m0 + m1.m3 * m2.m2;\
	m.m3 = m1.m2 * m2.m1 + m1.m3 * m2.m3;\
	return m;\
}

/* mat2_mul_with_scalar(T): Multiplies a 2x2 matrix with a scalar component wise
 * mat2_t(T) m: Matrix to be multiplied for each components
 * T scalar: scalar value to be multiplied [float, double, char, and int etc.]
 * returns: mat2_t(T) resultant matrix
 */
#define instantiate_implementation_mat2_mul_with_scalar(T)\
HPML_API mat2_t(T) mat2_mul_with_scalar(T)(mat2_t(T) m, T scalar)\
{\
	mat2_t(T) _m = m;\
	_m.m0 *= scalar;\
	_m.m1 *= scalar;\
	_m.m2 *= scalar;\
	_m.m3 *= scalar;\
	return _m;\
}

/* mat2_div(T): Divides two 2x2 matrices components
 * mat2_t(T) m1: nominator matrix [Dividend]
 * mat2_t(T) m2: denominator matrix [Divisor]
 * returns: mat2_t(T) quotient matrix
 */
#define instantiate_implementation_mat2_div(T)\
HPML_API mat2_t(T) mat2_div(T)(mat2_t(T) m1, mat2_t(T) m2)\
{\
	EXCEPTION_BLOCK(\
		if(mat2_is_null(T)(m2))\
			THROW_EXCEPTION(DIVIDE_BY_ZERO);\
	)\
	mat2_t(T) m;\
	m.m0 = m1.m0 / m2.m0;\
	m.m1 = m1.m1 / m2.m1;\
	m.m2 = m1.m2 / m2.m2;\
	m.m3 = m1.m3 / m2.m3;\
	return m;\
}

/* TODO: Replace the equal to operator with some approximation [because of floating point errors]
 * mat2_is_null(T): Checks if the matrix is null or not
 * mat2_t(T) m: matrix to be checked for null
 * returns: bool true if the matrix is null, otherwise false
 */
#define instantiate_implementation_mat2_is_null(T)\
HPML_API bool mat2_is_null(T)(mat2_t(T) m)\
{\
	return (m.m0 == 0) && (m.m1 == 0) && (m.m2 == 0) && (m.m3 == 0);\
}

/* TODO: Replace the equal to operator with some approximation [because of floating point errors]
 * mat2_is_equal(T): Checks if two mat2_t's are equal or not
 * mat2_t(T) m1: first matrix to be checked against
 * mat2_t(T) m2: second matrix to be checked against
 * returns: bool true if the two matrix are approximately equal, otherwise false
 */
#define instantiate_implementation_mat2_is_equal(T)\
HPML_API bool mat2_is_equal(T)(mat2_t(T) m1, mat2_t(T) m2)\
{\
	return (m1.m0 == m2.m0) && (m1.m1 == m2.m1) && (m1.m2 == m2.m2) && (m1.m3 == m2.m3);\
}

/* mat2_negate(T): Negates all the elements of 2x2 matrix
 * mat2_t(T) m: matrix to be negated
 * returns: mat2_t(T) negated matrix
 */
#define instantiate_implementation_mat2_negate(T)\
HPML_API mat2_t(T) mat2_negate(T)(mat2_t(T) m)\
{\
	mat2_t(T) _m;\
	_m.m0 = -m.m0;\
	_m.m1 = -m.m1;\
	_m.m2 = -m.m2;\
	_m.m3 = -m.m3;\
	return _m;\
}

/* mat2_mul_component_wise(T): Multiplies two matrices component wise
 * mat2_t(T) m1: First matrix involved in the calculation
 * mat2_t(T) m2: Second matrix involved in the calculation
 * returns: mat2_t(T) resultant matrix
 */
#define instantiate_implementation_mat2_mul_component_wise(T)\
HPML_API mat2_t(T) mat2_mul_component_wise(T)(mat2_t(T) m1, mat2_t(T) m2)\
{\
	mat2_t(T) m = m1;\
	m.m0 *= m2.m0;\
	m.m1 *= m2.m1;\
	m.m2 *= m2.m2;\
	m.m3 *= m2.m3;\
	return m;\
}

/* mat2_transpose(T): Transposes a 2x2 matrix
 * mat2_t(T) m: Matrix to be transposed
 * returns: mat2_t(T) transposed matrix
 */
#define instantiate_implementation_mat2_transpose(T)\
HPML_API mat2_t(T) mat2_transpose(T)(mat2_t(T) m)\
{\
	mat2_t(T) _m = m;\
	_m.m1 = m.m2;\
	_m.m2 = m.m1;\
	return _m;\
}

/* mat2_lerp(T): Linearly interpolates each elements of 2x2 matrices
 * mat2_t(T) m1: starting matrix
 * mat2_t(T) m2: ending matrix
 * float lerp_value: linear interpolation value [0, 1]
 * returns: mat2_t(T) interpolated matrix
 */
#define instantiate_implementation_mat2_lerp(T)\
HPML_API mat2_t(T) mat2_lerp(T)(mat2_t(T) m1, mat2_t(T) m2, float lerp_value)\
{\
	mat2_t(T) m;\
	float _lerp_value = 1 - lerp_value;\
	m.m0 = m1.m0 * _lerp_value + lerp_value * m2.m0;\
	m.m1 = m1.m1 * _lerp_value + lerp_value * m2.m1;\
	m.m2 = m1.m2 * _lerp_value + lerp_value * m2.m2;\
	m.m3 = m1.m3 * _lerp_value + lerp_value * m2.m3;\
	return m;\
}

/* mat2_inverse(T): Inverts a 2x2 matrix 
 * mat2_t(T) m: Matrix to be inverted
 * returns: mat2_t(T) inverted 2x2 matrix
 */
#define instantiate_implementation_mat2_inverse(T)\
HPML_API mat2_t(T) mat2_inverse(T)(mat2_t(T) m)\
{\
	float det = m.m0 * m.m1 - m.m2 * m.m3;\
	EXCEPTION_BLOCK(\
		if(det == 0)\
			THROW_EXCEPTION(INVERSION_OF_SINGULAR_MATRIX);\
	)\
	float inverse_det = 1 / det;\
	mat2_t(T) _m;\
	_m.m0 = m.m2 * inverse_det;\
	_m.m2 = m.m0 * inverse_det;\
	_m.m3 = -m.m3 * inverse_det;\
	_m.m1 = -m.m1 * inverse_det;\
	return _m;\
}

#define instantiate_implementation_mat2_rotation(T)\
HPML_API mat2_t(T) mat2_rotation(T)(T angle)\
{\
	float cos_angle = cos(angle);\
	float sin_angle = sin(angle);\
	mat2_t(T) m;\
	m.m0 = cos_angle;\
	m.m1 = sin_angle;\
	m.m2 = -sin_angle;\
	m.m3 = cos_angle;\
	return m;\
}

/*End: Template Definitions*/
