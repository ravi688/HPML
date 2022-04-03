#pragma once

#include <hpml/defines.h>
#include <math.h>

typedef union mat2_t
{
	struct
	{
		float m0, m1, m2, m3;
	};

	struct
	{
		float x, y, z, w;
	};

	struct
	{
		float m00, m01;
		float m10, m11;
	};
} mat2_t;

#define MAT2 (mat2_t)

/* mat2_identity: Creates an identity matrix of order 2x2
   returns: 2x2 identity matrix
 */
static HPML_API HPML_FORCE_INLINE mat2_t mat2_identity() { return MAT2 { 1, 0, 0, 1 }; }

/* mat2: mat2 contructor taking four parameter to initialize the components
 * float v0: element at [0, 0] -> [Row, Column]
 * float v1: element at [0, 1] -> [Row, Column]
 * float v2: element at [1, 1] -> [Row, Column]
 * float v3: element at [1, 0] -> [Row, Column]
 * returns: mat2_t initialized matrix
 */
static HPML_API HPML_FORCE_INLINE mat2_t mat2(float v0, float v1, float v2, float v3)
{
	return MAT2 { v0, v1, v2, v3 };
}

/* mat2_trace: Calculates trace of 2x2 matrix 
 * mat2_t m: Matrix of which the trace to be calculated
 * returns: float trace value
 */
static HPML_API HPML_FORCE_INLINE float mat2_trace(mat2_t m)
{
	return m.m0 + m.m3;
}

/* mat2_add: Adds a 2x2 matrix into another one [component-wise]
 * mat2_t m1: Addend matrix
 * mat2_t m2: Adder matrix
 * returns: mat2_t addition resultant matrix
 */
HPML_API mat2_t mat2_add(mat2_t m1, mat2_t m2);

/* mat2_sub: Subtracts a 2x2 matrix from another one [component-wise]
 * mat2_t m1: Subtractend matrix
 * mat2_t m2: Subtractor matrix
 * returns: mat2_t subtraction resultant matrix
 */
HPML_API mat2_t mat2_sub(mat2_t m1, mat2_t m2);

/* mat2_mul: Multiplies two matrices [3x2 order] by Matrix-Multiplication-Rule
 * mat2_t m1: Left side matrix in multiplication
 * mat2_t m2: right side matrix in mulitplication
 * returns: mat2_t resultant matrix
 */
HPML_API mat2_t mat2_mul(mat2_t m1, mat2_t m2);

/* mat2_mul_with_scalar: Multiplies a 2x2 matrix with a scalar component wise
 * mat2_t m: Matrix to be multiplied for each components
 * float scalar: scalar value to be multiplied [float, double, char, and int etc.]
 * returns: mat2_t resultant matrix
 */
HPML_API mat2_t mat2_mul_with_scalar(mat2_t m, float scalar);

/* mat2_div: Divides two 2x2 matrices components
 * mat2_t m1: nominator matrix [Dividend]
 * mat2_t m2: denominator matrix [Divisor]
 * returns: mat2_t quotient matrix
 */
HPML_API mat2_t mat2_div(mat2_t m1, mat2_t m2);

/* TODO: Replace the equal to operator with some approximation [because of floating point errors]
 * mat2_is_null: Checks if the matrix is null or not
 * mat2_t m: matrix to be checked for null
 * returns: bool true if the matrix is null, otherwise false
 */
HPML_API bool mat2_is_null(mat2_t m);

/* TODO: Replace the equal to operator with some approximation [because of floating point errors]
 * mat2_is_equal: Checks if two mat2_t's are equal or not
 * mat2_t m1: first matrix to be checked against
 * mat2_t m2: second matrix to be checked against
 * returns: bool true if the two matrix are approximately equal, otherwise false
 */
HPML_API bool mat2_is_equal(mat2_t m1, mat2_t m2);

/* mat2_negate: Negates all the elements of 2x2 matrix
 * mat2_t m: matrix to be negated
 * returns: mat2_t negated matrix
 */
HPML_API mat2_t mat2_negate(mat2_t m);

/* mat2_mul_component_wise: Multiplies two matrices component wise
 * mat2_t m1: First matrix involved in the calculation
 * mat2_t m2: Second matrix involved in the calculation
 * returns: mat2_t resultant matrix
 */
HPML_API mat2_t mat2_mul_component_wise(mat2_t m1, mat2_t m2);

/* mat2_transpose: Transposes a 2x2 matrix
 * mat2_t m: Matrix to be transposed
 * returns: mat2_t transposed matrix
 */
HPML_API mat2_t mat2_transpose(mat2_t m);

/* mat2_lerp: Linearly interpolates each elements of 2x2 matrices
 * mat2_t m1: starting matrix
 * mat2_t m2: ending matrix
 * float lerp_value: linear interpolation value [0, 1]
 * returns: mat2_t interpolated matrix
 */
HPML_API mat2_t mat2_lerp(mat2_t m1, mat2_t m2, float lerp_value);

/* mat2_inverse: Inverts a 2x2 matrix 
 * mat2_t m: Matrix to be inverted
 * returns: mat2_t inverted 2x2 matrix
 */
HPML_API mat2_t mat2_inverse(mat2_t m);

/* mat2_rotation: Creates a rotation matrix of order 2x2
 * angle: +ve means anticlockwise, -ve means clockwise
 * returns: a rotation matrix of order 2x2
 */
HPML_API mat2_t mat2_rotation(float angle);

/* For debugging purpose */

/* mat2_print */
HPML_API void mat2_print(mat2_t m);
