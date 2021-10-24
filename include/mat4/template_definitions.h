#ifndef __HPML_MAT4_TEMPLATE_DEFINITION_H__
#define __HPML_MAT4_TEMPLATE_DEFINITION_H__

#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <exception/exception.h>
#include <template_system.h>
#include <no_compile_header.h>

#include <memory/header_config.h>
#include <memory/memory.h>

/*Begin: Template Definitions*/
/*template signatures*/
#define mat4_t(T) template(mat4_t, T)
#define mat4(T) template(mat4, T)


/*mat4_data*/
#define __mat4_data(T) template(__mat4_data, T)
#define mat4_data(T) __mat4_data(T)
#define instantiate_declaration_mat4_data(T) T* const* const __mat4_data(T)(mat4_t(T)* m)
#define instantiate_implementation_mat4_data(T)\
T* const* const __mat4_data(T)(mat4_t(T)* m)\
{\
	m->data[0] = &m->m00;\
	m->data[1] = &m->m10;\
	m->data[2] = &m->m20;\
	m->data[3] = &m->m30;\
	return (T* const* const)m->data;\
}

/*mat4_move*/
#define mat4_move(T) move(T)
#define instantiate_declaration_mat4_move(T) instantiate_declaration_move(T)

/*mat4_copy*/
#define mat4_copy(T) copy(T)
#define instantiate_declaration_mat4_copy(T) instantiate_declaration_copy(T)

#define mat4_add(T) template(mat4_add, T)
#define mat4_sub(T) template(mat4_sub, T)
#define mat4_mul(T) template(mat4_mul, T)
#define mat4_mul_component_wise(T) template(mat4_mul_component_wise, T)
#define mat4_div(T) template(mat4_div, T)
#define mat4_is_null(T) template(mat4_is_null, T)
#define mat4_is_equal(T) template(mat4_is_equal, T)
#define mat4_null(T) mat4(T)(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
#define mat4_zero(T) mat4_null(T)
#define mat4_print(T) template(mat4_print, T)
#define mat4_negate(T) template(mat4_negate, T)
#define mat4_identity(T) mat4(T)(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1)
#define mat4_lerp(T) template(mat4_lerp, T)
#define mat4_mul_with_scalar(T) template(mat4_mul_with_scalar, T)
#define mat4_inverse(T) template(mat4_inverse, T)
#define mat4_transpose(T) template(mat4_transpose, T)
#define mat4_trace(T) template(mat4_trace, T)
#define mat4_diagonal(T) template(mat4_diagonal, T)

#define instantiate_mat4_struct(T)\
typedef struct mat4_t(T)\
{\
	union\
	{\
		struct\
		{\
			T m00, m01, m02, m03;\
			T m10, m11, m12, m13;\
			T m20, m21, m22, m23;\
			T m30, m31, m32, m33;\
		};\
		T values[16];\
	};\
} mat4_t(T)


#define instantiate_declaration_mat4_print(T) void mat4_print(T)(mat4_t(T) m)
#define instantiate_declaration_mat4(T) mat4_t(T) mat4(T) (\
																T v00, T v01, T v02, T v03,\
																T v10, T v11, T v12, T v13,\
																T v20, T v21, T v22, T v23,\
																T v30, T v31, T v32, T v33\
															 )
#define instantiate_declaration_mat4_add(T) mat4_t(T) mat4_add(T)(mat4_t(T) m1, mat4_t(T) m2)
#define instantiate_declaration_mat4_sub(T) mat4_t(T) mat4_sub(T)(mat4_t(T) m1, mat4_t(T) m2)
#define instantiate_declaration_mat4_mul(T) mat4_t(T) mat4_mul(T)(mat4_t(T) m1, mat4_t(T) m2)
#define instantiate_declaration_mat4_div(T) mat4_t(T) mat4_div(T)(mat4_t(T) m1, mat4_t(T) m2)
#define instantiate_declaration_mat4_mul_component_wise(T) mat4_t(T) mat4_mul_component_wise(T)(mat4_t(T) m1, mat4_t(T) m2)
#define instantiate_declaration_mat4_is_null(T) bool mat4_is_null(T)(mat4_t(T) m)
#define instantiate_declaration_mat4_is_equal(T) bool mat4_is_equal(T)(mat4_t(T) m1, mat4_t(T) m2)
#define instantiate_declaration_mat4_null(T) mat4_t(T) mat4_null(T)()
#define instantiate_declaration_mat4_negate(T) mat4_t(T) mat4_negate(T)(mat4_t(T) m)
#define instantiate_declaration_mat4_identity(T) mat4_t(T) mat4_identity(T)()
#define instantiate_declaration_mat4_lerp(T) mat4_t(T) mat4_lerp(T)(mat4_t(T) m1, mat4_t(T) m2, float lerp_value)
#define instantiate_declaration_mat4_mul_with_scalar(T) mat4_t(T) mat4_mul_with_scalar(T)(mat4_t(T) m, T s)
#define instantiate_declaration_mat4_inverse(T) mat4_t(T) mat4_inverse(T)(mat4_t(T) m)
#define instantiate_declaration_mat4_transpose(T) mat4_t(T) mat4_transpose(T)(mat4_t(T) m)
#define instantiate_declaration_mat4_trace(T) T mat4_trace(T)(mat4_t(T) m)
#define instantiate_declaration_mat4_diagonal(T) mat4_t(T) mat4_diagonal(T)(T x, T y, T z, T w)

/* mat4(T): mat4 contructor taking 16 parameter to initialize the components
 * T v00: element at [0, 0] -> [Row, Column]
 * T v01: element at [0, 1] -> [Row, Column]
 * T v02: element at [0, 2] -> [Row, Column]
 * T v03: element at [0, 3] -> [Row, Column]
 * T v10: element at [1, 0] -> [Row, Column]
 * T v11: element at [1, 1] -> [Row, Column]
 * T v12: element at [1, 2] -> [Row, Column]
 * T v13: element at [1, 3] -> [Row, Column]
 * T v20: element at [2, 0] -> [Row, Column]
 * T v21: element at [2, 1] -> [Row, Column]
 * T v22: element at [2, 2] -> [Row, Column]
 * T v23: element at [2, 3] -> [Row, Column]
 * T v30: element at [3, 0] -> [Row, Column]
 * T v31: element at [3, 1] -> [Row, Column]
 * T v32: element at [3, 2] -> [Row, Column]
 * T v33: element at [3, 3] -> [Row, Column]
 * returns: mat4_t(T) initialized matrix
 */
#define instantiate_implementation_mat4(T)\
mat4_t(T) mat4(T)(T v00, T v01, T v02, T v03,\
					T v10, T v11, T v12, T v13,\
					T v20, T v21, T v22, T v23,\
					T v30, T v31, T v32, T v33)\
{\
	mat4_t(T) m = \
	{\
		v00, v01, v02, v03,\
		v10, v11, v12, v13,\
		v20, v21, v22, v23,\
		v30, v31, v32, v33\
	};\
	return m;\
}

/* mat4_diagonal(T) : Creates a 4x4 diagonal matrix having diagonal elements as x, y, z, w
 * T x: element at [0, 0]
 * T y: element at [1, 1]
 * T z: element at [2, 2]
 * T w: element at [3, 3]
 * returns: mat4_t(T) 4x4 diagonal matrix
 */
#define instantiate_implementation_mat4_diagonal(T)\
mat4_t(T) mat4_diagonal(T)(T x, T y, T z, T w)\
{\
	mat4_t(T) mat =\
	{\
		x, 0, 0, 0,\
		0, y, 0, 0,\
		0, 0, z, 0,\
		0, 0, 0, w\
	};\
	return mat;\
}

/* mat4_trace(T): Calculates trace of 2x2 matrix 
 * mat4_t(T) m: Matrix of which the trace to be calculated
 * returns: T trace value
 */
#define instantiate_implementation_mat4_trace(T)\
T mat4_trace(T)(mat4_t(T) m)\
{\
	return m.m00 + m.m11 + m.m22 + m.m33;\
}

/* mat4_add(T): Adds a 4x4 matrix into another one [component-wise]
 * mat4_t(T) m1: Addend matrix
 * mat4_t(T) m2: Adder matrix
 * returns: mat4_t(T) addition resultant matrix
 */
#define instantiate_implementation_mat4_add(T)\
mat4_t(T) mat4_add(T)(mat4_t(T) m1, mat4_t(T) m2)\
{\
	mat4_t(T) m;\
	m.m00 = m1.m00 + m2.m00;\
	m.m01 = m1.m01 + m2.m01;\
	m.m02 = m1.m02 + m2.m02;\
	m.m03 = m1.m03 + m2.m03;\
	m.m10 = m1.m10 + m2.m10;\
	m.m11 = m1.m11 + m2.m11;\
	m.m12 = m1.m12 + m2.m12;\
	m.m13 = m1.m13 + m2.m13;\
	m.m20 = m1.m20 + m2.m20;\
	m.m21 = m1.m21 + m2.m21;\
	m.m22 = m1.m22 + m2.m22;\
	m.m23 = m1.m23 + m2.m23;\
	m.m30 = m1.m30 + m2.m30;\
	m.m31 = m1.m31 + m2.m31;\
	m.m32 = m1.m32 + m2.m32;\
	m.m33 = m1.m33 + m2.m33;\
	return m;\
}

/* mat4_sub(T): Subtracts a 4x4 matrix from another one [component-wise]
 * mat4_t(T) m1: Subtractend matrix
 * mat4_t(T) m2: Subtractor matrix
 * returns: mat4_t(T) subtraction resultant matrix
 */
#define instantiate_implementation_mat4_sub(T)\
mat4_t(T) mat4_sub(T)(mat4_t(T) m1, mat4_t(T) m2)\
{\
	mat4_t(T) m;\
	m.m00 = m1.m00 - m2.m00;\
	m.m01 = m1.m01 - m2.m01;\
	m.m02 = m1.m02 - m2.m02;\
	m.m03 = m1.m03 - m2.m03;\
	m.m10 = m1.m10 - m2.m10;\
	m.m11 = m1.m11 - m2.m11;\
	m.m12 = m1.m12 - m2.m12;\
	m.m13 = m1.m13 - m2.m13;\
	m.m20 = m1.m20 - m2.m20;\
	m.m21 = m1.m21 - m2.m21;\
	m.m22 = m1.m22 - m2.m22;\
	m.m23 = m1.m23 - m2.m23;\
	m.m30 = m1.m30 - m2.m30;\
	m.m31 = m1.m31 - m2.m31;\
	m.m32 = m1.m32 - m2.m32;\
	m.m33 = m1.m33 - m2.m33;\
	return m;\
}

/*
 | 00 01 02 03 | | m00 m01 m02 m03 |
 | 10 11 12 13 | | m10 m11 m12 m13 |
 | 20 21 22 23 | | m20 m21 m22 m23 |
 | 30 31 32 33 | | m30 m31 m32 m33 |
 */

/* mat4_mul(T): Multiplies two matrices [4x4 order] by Matrix-Multiplication-Rule
 * mat4_t(T) m1: Left side matrix in multiplication
 * mat4_t(T) m2: right side matrix in mulitplication
 * returns: mat4_t(T) resultant matrix
 */
#define instantiate_implementation_mat4_mul(T)\
mat4_t(T) mat4_mul(T)(mat4_t(T) m1, mat4_t(T) m2)\
{\
	mat4_t(T) m;\
	m.m00 = m1.m00 * m2.m00 + m1.m01 * m2.m10 + m1.m02 * m2.m20 + m1.m03 * m2.m30;\
	m.m01 = m1.m00 * m2.m01 + m1.m01 * m2.m11 + m1.m02 * m2.m21 + m1.m03 * m2.m31;\
	m.m02 = m1.m00 * m2.m02 + m1.m01 * m2.m12 + m1.m02 * m2.m22 + m1.m03 * m2.m32;\
	m.m03 = m1.m00 * m2.m03 + m1.m01 * m2.m13 + m1.m02 * m2.m23 + m1.m03 * m2.m33;\
	m.m10 = m1.m10 * m2.m00 + m1.m11 * m2.m10 + m1.m12 * m2.m20 + m1.m13 * m2.m30;\
	m.m11 = m1.m10 * m2.m01 + m1.m11 * m2.m11 + m1.m12 * m2.m21 + m1.m13 * m2.m31;\
	m.m12 = m1.m10 * m2.m02 + m1.m11 * m2.m12 + m1.m12 * m2.m22 + m1.m13 * m2.m32;\
	m.m13 = m1.m10 * m2.m03 + m1.m11 * m2.m13 + m1.m12 * m2.m23 + m1.m13 * m2.m33;\
	m.m20 = m1.m20 * m2.m00 + m1.m21 * m2.m10 + m1.m22 * m2.m20 + m1.m23 * m2.m30;\
	m.m21 = m1.m20 * m2.m01 + m1.m21 * m2.m11 + m1.m22 * m2.m21 + m1.m23 * m2.m31;\
	m.m22 = m1.m20 * m2.m02 + m1.m21 * m2.m12 + m1.m22 * m2.m22 + m1.m23 * m2.m32;\
	m.m23 = m1.m20 * m2.m03 + m1.m21 * m2.m13 + m1.m22 * m2.m23 + m1.m23 * m2.m33;\
	m.m30 = m1.m30 * m2.m00 + m1.m31 * m2.m10 + m1.m32 * m2.m20 + m1.m33 * m2.m30;\
	m.m31 = m1.m30 * m2.m01 + m1.m31 * m2.m11 + m1.m32 * m2.m21 + m1.m33 * m2.m31;\
	m.m32 = m1.m30 * m2.m02 + m1.m31 * m2.m12 + m1.m32 * m2.m22 + m1.m33 * m2.m32;\
	m.m33 = m1.m30 * m2.m03 + m1.m31 * m2.m13 + m1.m32 * m2.m23 + m1.m33 * m2.m33;\
	return m;\
}

/* mat4_mul_with_scalar(T): Multiplies a 2x2 matrix with a scalar component wise
 * mat4_t(T) m: Matrix to be multiplied for each components
 * T scalar: scalar value to be multiplied [float, double, char, and int etc.]
 * returns: mat4_t(T) resultant matrix
 */
#define instantiate_implementation_mat4_mul_with_scalar(T)\
mat4_t(T) mat4_mul_with_scalar(T)(mat4_t(T) m, T scalar)\
{\
	mat4_t(T) _m = m;\
	_m.values[0] *= scalar;\
	_m.values[1] *= scalar;\
	_m.values[2] *= scalar;\
	_m.values[3] *= scalar;\
	_m.values[4] *= scalar;\
	_m.values[5] *= scalar;\
	_m.values[6] *= scalar;\
	_m.values[7] *= scalar;\
	_m.values[8] *= scalar;\
	_m.values[9] *= scalar;\
	_m.values[10] *= scalar;\
	_m.values[11] *= scalar;\
	_m.values[12] *= scalar;\
	_m.values[13] *= scalar;\
	_m.values[14] *= scalar;\
	_m.values[15] *= scalar;\
	return _m;\
}

/* mat4_div(T): Divides two 2x2 matrices components
 * mat4_t(T) m1: nominator matrix [Dividend]
 * mat4_t(T) m2: denominator matrix [Divisor]
 * returns: mat4_t(T) quotient matrix
 */
#define instantiate_implementation_mat4_div(T)\
mat4_t(T) mat4_div(T)(mat4_t(T) m1, mat4_t(T) m2)\
{\
	EXCEPTION_BLOCK(\
		if(mat4_is_null(T)(m2))\
			THROW_EXCEPTION(DIVIDE_BY_ZERO);\
	)\
	mat4_t(T) m;\
	m.values[0]  = m1.values[0] / m2.values[0] ;\
	m.values[1]  = m1.values[1] / m2.values[1] ;\
	m.values[2]  = m1.values[2] / m2.values[2] ;\
	m.values[3]  = m1.values[3] / m2.values[3] ;\
	m.values[4]  = m1.values[4] / m2.values[4] ;\
	m.values[5]  = m1.values[5] / m2.values[5] ;\
	m.values[6]  = m1.values[6] / m2.values[6] ;\
	m.values[7]  = m1.values[7] / m2.values[7] ;\
	m.values[8]  = m1.values[8] / m2.values[8] ;\
	m.values[9]  = m1.values[9] / m2.values[9] ;\
	m.values[10] = m1.values[10]/ m2.values[10];\
	m.values[11] = m1.values[11]/ m2.values[11];\
	m.values[12] = m1.values[12]/ m2.values[12];\
	m.values[13] = m1.values[13]/ m2.values[13];\
	m.values[14] = m1.values[14]/ m2.values[14];\
	m.values[15] = m1.values[15]/ m2.values[15];\
	return m;\
}

/* TODO: Replace the equal to operator with some approximation [because of floating point errors]
 * mat4_is_null(T): Checks if the matrix is null or not
 * mat4_t(T) m: matrix to be checked for null
 * returns: bool true if the matrix is null, otherwise false
 */
#define instantiate_implementation_mat4_is_null(T)\
bool mat4_is_null(T)(mat4_t(T) m)\
{\
	return (m.values[0] == 0) &&\
		   (m.values[1] == 0) &&\
		   (m.values[2] == 0) &&\
		   (m.values[3] == 0) &&\
		   (m.values[4] == 0) &&\
		   (m.values[5] == 0) &&\
		   (m.values[6] == 0) &&\
		   (m.values[7] == 0) &&\
		   (m.values[8] == 0) &&\
		   (m.values[9] == 0) &&\
		   (m.values[10] == 0) &&\
		   (m.values[11] == 0) &&\
		   (m.values[12] == 0) &&\
		   (m.values[13] == 0) &&\
		   (m.values[14] == 0) &&\
		   (m.values[15] == 0);\
}

/* TODO: Replace the equal to operator with some approximation [because of floating point errors]
 * mat4_is_equal(T): Checks if two mat4_t's are equal or not
 * mat4_t(T) m1: first matrix to be checked against
 * mat4_t(T) m2: second matrix to be checked against
 * returns: bool true if the two matrix are approximately equal, otherwise false
 */
#define instantiate_implementation_mat4_is_equal(T)\
bool mat4_is_equal(T)(mat4_t(T) m1, mat4_t(T) m2)\
{\
		return (m1.values[0]  == m2.values[0] ) &&\
		   	   (m1.values[1]  == m2.values[1] ) &&\
		   	   (m1.values[2]  == m2.values[2] ) &&\
		   	   (m1.values[3]  == m2.values[3] ) &&\
		   	   (m1.values[4]  == m2.values[4] ) &&\
		   	   (m1.values[5]  == m2.values[5] ) &&\
		   	   (m1.values[6]  == m2.values[6] ) &&\
		   	   (m1.values[7]  == m2.values[7] ) &&\
		   	   (m1.values[8]  == m2.values[8] ) &&\
		   	   (m1.values[9]  == m2.values[9] ) &&\
		   	   (m1.values[10] == m2.values[10]) &&\
		   	   (m1.values[11] == m2.values[11]) &&\
		   	   (m1.values[12] == m2.values[12]) &&\
		   	   (m1.values[13] == m2.values[13]) &&\
		   	   (m1.values[14] == m2.values[14]) &&\
		   	   (m1.values[15] == m2.values[15]);\
}

/* mat4_negate(T): Negates all the elements of 4x4 matrix
 * mat4_t(T) m: matrix to be negated
 * returns: mat4_t(T) negated matrix
 */
#define instantiate_implementation_mat4_negate(T)\
mat4_t(T) mat4_negate(T)(mat4_t(T) m)\
{\
	mat4_t(T) m1;\
	m1.values[0]  = -m.values[0] ;\
	m1.values[1]  = -m.values[1] ;\
	m1.values[2]  = -m.values[2] ;\
	m1.values[3]  = -m.values[3] ;\
	m1.values[4]  = -m.values[4] ;\
	m1.values[5]  = -m.values[5] ;\
	m1.values[6]  = -m.values[6] ;\
	m1.values[7]  = -m.values[7] ;\
	m1.values[8]  = -m.values[8] ;\
	m1.values[9]  = -m.values[9] ;\
	m1.values[10] = -m.values[10];\
	m1.values[11] = -m.values[11];\
	m1.values[12] = -m.values[12];\
	m1.values[13] = -m.values[13];\
	m1.values[14] = -m.values[14];\
	m1.values[15] = -m.values[15];\
	return m1;\
}

/* mat4_mul_component_wise(T): Multiplies two matrices component wise
 * mat4_t(T) m1: First matrix involved in the calculation
 * mat4_t(T) m2: Second matrix involved in the calculation
 * returns: mat4_t(T) resultant matrix
 */
#define instantiate_implementation_mat4_mul_component_wise(T)\
mat4_t(T) mat4_mul_component_wise(T)(mat4_t(T) m1, mat4_t(T) m2)\
{\
	mat4_t(T) m = m1;\
	m.values[0]  *= m2.values[0] ;\
	m.values[1]  *= m2.values[1] ;\
	m.values[2]  *= m2.values[2] ;\
	m.values[3]  *= m2.values[3] ;\
	m.values[4]  *= m2.values[4] ;\
	m.values[5]  *= m2.values[5] ;\
	m.values[6]  *= m2.values[6] ;\
	m.values[7]  *= m2.values[7] ;\
	m.values[8]  *= m2.values[8] ;\
	m.values[9]  *= m2.values[9] ;\
	m.values[10] *= m2.values[10];\
	m.values[11] *= m2.values[11];\
	m.values[12] *= m2.values[12];\
	m.values[13] *= m2.values[13];\
	m.values[14] *= m2.values[14];\
	m.values[15] *= m2.values[15];\
	return m;\
}

/* mat4_transpose(T): Transposes a 2x2 matrix
 * mat4_t(T) m: Matrix to be transposed
 * returns: mat4_t(T) transposed matrix
 */
#define instantiate_implementation_mat4_transpose(T)\
mat4_t(T) mat4_transpose(T)(mat4_t(T) m)\
{\
	mat4_t(T) _m = m;\
	_m.m01 = m.m10;\
	_m.m02 = m.m20;\
	_m.m03 = m.m30;\
	_m.m10 = m.m01;\
	_m.m12 = m.m21;\
	_m.m13 = m.m31;\
	_m.m20 = m.m02;\
	_m.m21 = m.m12;\
	_m.m23 = m.m32;\
	_m.m30 = m.m03;\
	_m.m31 = m.m13;\
	_m.m32 = m.m23;\
	return _m;\
}

/* mat4_lerp(T): Linearly interpolates each elements of 2x2 matrices
 * mat4_t(T) m1: starting matrix
 * mat4_t(T) m2: ending matrix
 * float lerp_value: linear interpolation value [0, 1]
 * returns: mat4_t(T) interpolated matrix
 */
#define instantiate_implementation_mat4_lerp(T)\
mat4_t(T) mat4_lerp(T)(mat4_t(T) m1, mat4_t(T) m2, float lerp_value)\
{\
	mat4_t(T) m;\
	float _lerp_value = 1 - lerp_value;\
	m.values[0]  = _lerp_value * m1.values[0]  + lerp_value * m2.values[0] ;\
	m.values[1]  = _lerp_value * m1.values[1]  + lerp_value * m2.values[1] ;\
	m.values[2]  = _lerp_value * m1.values[2]  + lerp_value * m2.values[2] ;\
	m.values[3]  = _lerp_value * m1.values[3]  + lerp_value * m2.values[3] ;\
	m.values[4]  = _lerp_value * m1.values[4]  + lerp_value * m2.values[4] ;\
	m.values[5]  = _lerp_value * m1.values[5]  + lerp_value * m2.values[5] ;\
	m.values[6]  = _lerp_value * m1.values[6]  + lerp_value * m2.values[6] ;\
	m.values[7]  = _lerp_value * m1.values[7]  + lerp_value * m2.values[7] ;\
	m.values[8]  = _lerp_value * m1.values[8]  + lerp_value * m2.values[8] ;\
	m.values[9]  = _lerp_value * m1.values[9]  + lerp_value * m2.values[9] ;\
	m.values[10] = _lerp_value * m1.values[10] + lerp_value * m2.values[10];\
	m.values[11] = _lerp_value * m1.values[11] + lerp_value * m2.values[11];\
	m.values[12] = _lerp_value * m1.values[12] + lerp_value * m2.values[12];\
	m.values[13] = _lerp_value * m1.values[13] + lerp_value * m2.values[13];\
	m.values[14] = _lerp_value * m1.values[14] + lerp_value * m2.values[14];\
	m.values[15] = _lerp_value * m1.values[15] + lerp_value * m2.values[15];\
	return m;\
}


/* Determinant: 
 *
 * | 00 01 02 03 |
 * | 10 11 12 13 |
 * | 20 21 22 23 |
 * | 30 31 32 33 |
 *
 *      | 11 12 13 |        | 10 12 13 |        | 10 11 13 |        | 10 11 12 |
 * 00 * | 21 22 23 | - 01 * | 20 22 23 | + 02 * | 20 21 23 | - 03 * | 20 21 22 |
 *      | 31 32 33 |        | 30 32 33 |        | 30 31 33 |        | 30 31 32 |
 *
 * 00 * [11 * (22 * 33 - 23 * 32) - 12 * (21 * 33 - 23 * 31) + 13 * (21 * 32 - 22 * 31)] - 
 * 01 * [10 * (22 * 33 - 23 * 32) - 12 * (20 * 33 - 23 * 30) + 13 * (20 * 32 - 22 * 30)] + 
 * 02 * [10 * (21 * 33 - 23 * 31) - 11 * (20 * 33 - 23 * 30) + 13 * (20 * 31 - 21 * 30)] -
 * 03 * [10 * (21 * 32 - 22 * 31) - 11 * (20 * 32 - 22 * 30) + 12 * (20 * 31 - 21 * 30)]

 	  | 01 02 03 | 		  | 00 02 03 | 		  | 00 01 03 | 		  | 00 01 02 |
 10 * | 21 22 23 | - 11 * | 20 22 23 | + 12 * | 20 21 23 | - 13 * | 20 21 22 |
 	  | 31 32 33 | 		  | 30 32 33 | 		  | 30 31 33 | 		  | 30 31 32 |

  	  | 01 02 03 | 		  | 00 02 03 |  	  | 00 01 03 | 		  | 00 01 02 |
 20 * | 11 12 13 | - 21 * | 10 12 13 | + 22 * | 10 11 13 | - 23 * | 10 11 12 |
 	  | 31 32 33 | 		  | 30 32 33 | 		  | 30 31 33 | 		  | 30 31 32 |

  	  | 01 02 03 |  	  | 00 02 03 |  	  | 00 01 03 |  	  | 00 01 02 |
 30 * | 11 12 13 | - 31 * | 10 12 13 | + 32 * | 10 11 13 | - 33 * | 10 11 12 |
 	  | 21 22 23 | 		  | 20 22 23 | 		  | 20 21 23 |  	  | 20 21 22 |

	00 = 11 * (22 * 33 - 23 * 32) - 12 * (21 * 33 - 23 * 31) + 13 * (21 * 32 - 22 * 31)
	01 = 10 * (22 * 33 - 23 * 32) - 12 * (20 * 33 - 23 * 30) + 13 * (20 * 32 - 22 * 30)
	02 = 10 * (21 * 33 - 23 * 31) - 11 * (20 * 33 - 23 * 30) + 13 * (20 * 31 - 21 * 30)
	03 = 10 * (21 * 32 - 22 * 31) - 11 * (20 * 32 - 22 * 30) + 12 * (20 * 31 - 21 * 30)
	
 	10 = 01 * (22 * 33 - 23 * 32) - 02 * (21 * 33 - 23 * 31) + 03 * (21 * 32 - 22 * 31)
 	11 = 00 * (22 * 33 - 23 * 32) - 02 * (20 * 33 - 23 * 30) + 03 * (20 * 32 - 22 * 30)
 	12 = 00 * (21 * 33 - 23 * 31) - 01 * (20 * 33 - 23 * 30) + 03 * (20 * 31 - 21 * 30)
 	13 = 00 * (21 * 32 - 22 * 31) - 01 * (20 * 32 - 22 * 30) + 02 * (20 * 31 - 21 * 30)
	 
	20 = 01 * (12 * 33 - 13 * 32) - 02 * (11 * 33 - 13 * 31) + 03 * (11 * 32 - 12 * 31)
	21 = 00 * (12 * 33 - 13 * 32) - 02 * (10 * 33 - 13 * 30) + 03 * (10 * 32 - 12 * 30)
	22 = 00 * (11 * 33 - 13 * 31) - 01 * (10 * 33 - 13 * 30) + 03 * (10 * 31 - 11 * 30)
	23 = 00 * (11 * 32 - 12 * 31) - 01 * (10 * 32 - 12 * 30) + 02 * (10 * 31 - 11 * 30)

	30 = 01 * (12 * 23 - 13 * 22) - 02 * (11 * 23 - 13 * 21) + 03 * (11 * 22 - 12 * 21)
	31 = 00 * (12 * 23 - 13 * 22) - 02 * (10 * 23 - 13 * 20) + 03 * (10 * 22 - 12 * 20)
	32 = 00 * (11 * 23 - 13 * 21) - 01 * (10 * 23 - 13 * 20) + 03 * (10 * 21 - 11 * 20)
	33 = 00 * (11 * 22 - 12 * 21) - 01 * (10 * 22 - 12 * 20) + 02 * (10 * 21 - 11 * 20)
 */

/* mat4_inverse(T): Inverts a 4x4 matrix 
 * mat4_t(T) m: Matrix to be inverted
 * returns: mat4_t(T) inverted 4x4 matrix
 */
#define instantiate_implementation_mat4_inverse(T)\
mat4_t(T) mat4_inverse(T)(mat4_t(T) m)\
{\
	float det = \
	m.m00 * (m.m11 * (m.m22 * m.m33 - m.m23 * m.m32) - m.m12 * (m.m21 * m.m33 - m.m23 * m.m31) + m.m13 * (m.m21 * m.m32 - m.m22 * m.m31)) -\
	m.m01 * (m.m10 * (m.m22 * m.m33 - m.m23 * m.m32) - m.m12 * (m.m20 * m.m33 - m.m23 * m.m30) + m.m13 * (m.m20 * m.m32 - m.m22 * m.m30)) +\
	m.m02 * (m.m10 * (m.m21 * m.m33 - m.m23 * m.m31) - m.m11 * (m.m20 * m.m33 - m.m23 * m.m30) + m.m13 * (m.m20 * m.m31 - m.m21 * m.m30)) -\
	m.m03 * (m.m10 * (m.m21 * m.m32 - m.m22 * m.m31) - m.m11 * (m.m20 * m.m32 - m.m22 * m.m30) + m.m12 * (m.m20 * m.m31 - m.m21 * m.m30));\
	EXCEPTION_BLOCK(\
		if(det == 0)\
			THROW_EXCEPTION(INVERSION_OF_SINGULAR_MATRIX);\
	)\
	float inverse_det = 1 / det;\
	mat4_t(T) _m;\
	_m.m00 = m.m11 * (m.m22 * m.m33 - m.m23 * m.m32) - m.m12 * (m.m21 * m.m33 - m.m23 * m.m31) + m.m13 * (m.m21 * m.m32 - m.m22 * m.m31);\
	_m.m10 = m.m10 * (m.m22 * m.m33 - m.m23 * m.m32) - m.m12 * (m.m20 * m.m33 - m.m23 * m.m30) + m.m13 * (m.m20 * m.m32 - m.m22 * m.m30);\
	_m.m20 = m.m10 * (m.m21 * m.m33 - m.m23 * m.m31) - m.m11 * (m.m20 * m.m33 - m.m23 * m.m30) + m.m13 * (m.m20 * m.m31 - m.m21 * m.m30);\
	_m.m30 = m.m10 * (m.m21 * m.m32 - m.m22 * m.m31) - m.m11 * (m.m20 * m.m32 - m.m22 * m.m30) + m.m12 * (m.m20 * m.m31 - m.m21 * m.m30);\
 	_m.m01 = m.m01 * (m.m22 * m.m33 - m.m23 * m.m32) - m.m02 * (m.m21 * m.m33 - m.m23 * m.m31) + m.m03 * (m.m21 * m.m32 - m.m22 * m.m31);\
 	_m.m11 = m.m00 * (m.m22 * m.m33 - m.m23 * m.m32) - m.m02 * (m.m20 * m.m33 - m.m23 * m.m30) + m.m03 * (m.m20 * m.m32 - m.m22 * m.m30);\
 	_m.m21 = m.m00 * (m.m21 * m.m33 - m.m23 * m.m31) - m.m01 * (m.m20 * m.m33 - m.m23 * m.m30) + m.m03 * (m.m20 * m.m31 - m.m21 * m.m30);\
 	_m.m31 = m.m00 * (m.m21 * m.m32 - m.m22 * m.m31) - m.m01 * (m.m20 * m.m32 - m.m22 * m.m30) + m.m02 * (m.m20 * m.m31 - m.m21 * m.m30);\
	_m.m02 = m.m01 * (m.m12 * m.m33 - m.m13 * m.m32) - m.m02 * (m.m11 * m.m33 - m.m13 * m.m31) + m.m03 * (m.m11 * m.m32 - m.m12 * m.m31);\
	_m.m12 = m.m00 * (m.m12 * m.m33 - m.m13 * m.m32) - m.m02 * (m.m10 * m.m33 - m.m13 * m.m30) + m.m03 * (m.m10 * m.m32 - m.m12 * m.m30);\
	_m.m22 = m.m00 * (m.m11 * m.m33 - m.m13 * m.m31) - m.m01 * (m.m10 * m.m33 - m.m13 * m.m30) + m.m03 * (m.m10 * m.m31 - m.m11 * m.m30);\
	_m.m32 = m.m00 * (m.m11 * m.m32 - m.m12 * m.m31) - m.m01 * (m.m10 * m.m32 - m.m12 * m.m30) + m.m02 * (m.m10 * m.m31 - m.m11 * m.m30);\
	_m.m03 = m.m01 * (m.m12 * m.m23 - m.m13 * m.m22) - m.m02 * (m.m11 * m.m23 - m.m13 * m.m21) + m.m03 * (m.m11 * m.m22 - m.m12 * m.m21);\
	_m.m13 = m.m00 * (m.m12 * m.m23 - m.m13 * m.m22) - m.m02 * (m.m10 * m.m23 - m.m13 * m.m20) + m.m03 * (m.m10 * m.m22 - m.m12 * m.m20);\
	_m.m23 = m.m00 * (m.m11 * m.m23 - m.m13 * m.m21) - m.m01 * (m.m10 * m.m23 - m.m13 * m.m20) + m.m03 * (m.m10 * m.m21 - m.m11 * m.m20);\
	_m.m33 = m.m00 * (m.m11 * m.m22 - m.m12 * m.m21) - m.m01 * (m.m10 * m.m22 - m.m12 * m.m20) + m.m02 * (m.m10 * m.m21 - m.m11 * m.m20);\
	_m.m01 = -_m.m01 * inverse_det;\
	_m.m02 *= inverse_det;\
	_m.m03 = -_m.m03 * inverse_det;\
	_m.m10 *= inverse_det;\
	_m.m11 = -_m.m11 * inverse_det;\
	_m.m12 *= inverse_det;\
	_m.m13 = -_m.m13 * inverse_det;\
	_m.m20 *= inverse_det;\
	_m.m21 = -_m.m21 * inverse_det;\
	_m.m22 *= inverse_det;\
	_m.m23 = -_m.m23 * inverse_det;\
	_m.m30 *= inverse_det;\
	_m.m31 = -_m.m31 * inverse_det;\
	_m.m32 *= inverse_det;\
	_m.m33 = -_m.m33 * inverse_det;\
	return _m;\
}

// #define instantiate_implementation_mat4_rotation(T)\
// mat4_t(T) mat4_rotation(T)(T angle)\
// {\
// 	float cos_angle = cos(angle);\
// 	float sin_angle = sin(angle);\
// 	mat4_t(T) m;\
// 	m.m0 = cos_angle;\
// 	m.m1 = sin_angle;\
// 	m.m2 = -sin_angle;\
// 	m.m3 = cos_angle;\
// 	return m;\
// }

/*End: Template Definitions*/

#endif