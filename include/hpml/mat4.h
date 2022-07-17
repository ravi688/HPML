#pragma once


#include <hpml/defines.h>

#include <math.h>           // for sin and cos
#include <stdarg.h>         // for variable arugments
#include <string.h>         // memcpy


typedef struct mat4_t
{
	union
	{
		// elements
		struct
		{
			float m00, m01, m02, m03;
			float m10, m11, m12, m13;
			float m20, m21, m22, m23;
			float m30, m31, m32, m33;
		};

		// sequential
		float values[16];

		// rows
		struct
		{
			float r1[4];
			float r2[4];
			float r3[4];
			float r4[4];
		};
	};
	float* data[4];
} mat4_t;

#define MAT4 (mat4_t)

#ifdef __cplusplus
    extern "C" {
#endif

/* mat4: mat4 contructor taking 16 parameter to initialize the components
 * float v00: element at [0, 0] -> [Row, Column]
 * float v01: element at [0, 1] -> [Row, Column]
 * float v02: element at [0, 2] -> [Row, Column]
 * float v03: element at [0, 3] -> [Row, Column]
 * float v10: element at [1, 0] -> [Row, Column]
 * float v11: element at [1, 1] -> [Row, Column]
 * float v12: element at [1, 2] -> [Row, Column]
 * float v13: element at [1, 3] -> [Row, Column]
 * float v20: element at [2, 0] -> [Row, Column]
 * float v21: element at [2, 1] -> [Row, Column]
 * float v22: element at [2, 2] -> [Row, Column]
 * float v23: element at [2, 3] -> [Row, Column]
 * float v30: element at [3, 0] -> [Row, Column]
 * float v31: element at [3, 1] -> [Row, Column]
 * float v32: element at [3, 2] -> [Row, Column]
 * float v33: element at [3, 3] -> [Row, Column]
 * returns: mat4_t initialized matrix
 */
static HPML_FORCE_INLINE mat4_t mat4(float v00, float v01, float v02, float v03,
                    float v10, float v11, float v12, float v13,
                    float v20, float v21, float v22, float v23,
                    float v30, float v31, float v32, float v33)
{
    return MAT4 
    {
        v00, v01, v02, v03,
        v10, v11, v12, v13,
        v20, v21, v22, v23,
        v30, v31, v32, v33
    };
}

/* mat4_data: returns a double pointer which points to the elements of the 4x4 matrix
 * m: lvalue mat4
 * returns: double pointer of type float
 */
#define mat4_data(m) __mat4_data(&(m))
HPML_API float* const* const __mat4_data(mat4_t* m);


/* mat4_copy: Performs a copy operation of 4x4 matrices
 * dest: destination mat4
 * src: source mat4
 * returns: nothing
 * NOTE: this function doesn't support rvalue src matrix; use mat4_move instead
 */
#define mat4_copy(dest, src) __mat4_copy(&(dest), &(src))
static HPML_FORCE_INLINE void __mat4_copy(mat4_t* const dest, const mat4_t* const src) 
{ 
	/*
		TODO: This should be like this: 
			memcpy(dest, src, COMPILE_TIME( 16 * sizeof(float) ));
	 */
	memcpy(dest, src, 16 * sizeof(float)); 
}

/* mat4_move: Performs a move operation of 4x4 matrices
 * dest: destination mat4
 * src: source mat4
 * returns: nothing
 */
#define mat4_move(dst, src) __mat4_move(&(dst), src)
static HPML_FORCE_INLINE void __mat4_move(mat4_t* const dest, const mat4_t src)
{
	__mat4_copy(dest, &src);
}

/* mat4_determinant: Calculates the determinant value of a 4x4 matrix
 * m: Input 4x4 matrix
 * returns: determinant value
 */
#define mat4_determinant mat4_det
HPML_API float mat4_det(mat4_t m);

/* mat4_mul: Multiplies two matrices [4x4 order] by Matrix-Multiplication-Rule
 * mat4_t m1: Left side matrix in multiplication
 * mat4_t m2: right side matrix in mulitplication
 * returns: mat4_t resultant matrix
 */
HPML_API mat4_t __mat4_mul(mat4_t m1, mat4_t m2);
HPML_API mat4_t mat4_mul(uint32_t count, ...);

/* mat4_build_cofactor: Creates a cofactor matrix of order 3x3 around pivot (row, column)
 * m: original matrix of order 4x4
 * cofactorMatrix: cofactor matrix buffer, able to old 3x3 elements [double pointer]
 * row: row index of the pivot element (zero based)
 * column: column index of the pivot element (zero based)
 * returns: nothing
 */
HPML_API void mat4_build_cofactor(mat4_t m, float* const* const cofactorMatrix, u32 row, u32 column);

/* mat4_identity: constructs a 4x4 identity matrix
 * returns: identity matrix of order 4x4
 */
static HPML_FORCE_INLINE mat4_t mat4_identity()
{
	return mat4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
}

/* mat4_null: Creates a null or zero matrix
 * returns: a 4x4 matrix having all entries equal to zero
 */
static HPML_FORCE_INLINE mat4_t mat4_null() { return mat4(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0); }
#define mat4_zero mat4_null


/* mat4_diagonal : Creates a 4x4 diagonal matrix having diagonal elements as x, y, z, w
 * float x: element at [0, 0]
 * float y: element at [1, 1]
 * float z: element at [2, 2]
 * float w: element at [3, 3]
 * returns: mat4_t 4x4 diagonal matrix
 */

static HPML_FORCE_INLINE mat4_t mat4_diagonal(float x, float y, float z, float w)
{
	return MAT4
	{
		x, 0, 0, 0,
		0, y, 0, 0,
		0, 0, z, 0,
		0, 0, 0, w
	};
}

/* mat4_trace: Calculates trace of 2x2 matrix 
 * mat4_t m: Matrix of which the trace to be calculated
 * returns: float trace value
 */
static HPML_FORCE_INLINE float mat4_trace(mat4_t m)
{
	return m.m00 + m.m11 + m.m22 + m.m33;
}

/* mat4_add: Adds a 4x4 matrix into another one [component-wise]
 * mat4_t m1: Addend matrix
 * mat4_t m2: Adder matrix
 * returns: mat4_t addition resultant matrix
 */
HPML_API mat4_t mat4_add(mat4_t m1, mat4_t m2);

/* mat4_sub: Subtracts a 4x4 matrix from another one [component-wise]
 * mat4_t m1: Subtractend matrix
 * mat4_t m2: Subtractor matrix
 * returns: mat4_t subtraction resultant matrix
 */
HPML_API mat4_t mat4_sub(mat4_t m1, mat4_t m2);

/* mat4_mul_scalar: Multiplies a 4x4 matrix with a scalar component wise
 * mat4_t m: Matrix to be multiplied for each components
 * float scalar: scalar value to be multiplied [float, double, char, and int etc.]
 * returns: mat4_t resultant matrix
 */
HPML_API mat4_t mat4_mul_scalar(mat4_t m, float scalar);

/* mat4_div: Divides two 4x4 matrices components
 * mat4_t m1: nominator matrix [Dividend]
 * mat4_t m2: denominator matrix [Divisor]
 * returns: mat4_t quotient matrix
 */
HPML_API mat4_t mat4_div(mat4_t m1, mat4_t m2);

/* TODO: Replace the equal to operator with some approximation [because of floating point errors]
 * mat4_is_null: Checks if the matrix is null or not
 * mat4_t m: matrix to be checked for null
 * returns: bool true if the matrix is null, otherwise false
 */
HPML_API bool mat4_is_null(mat4_t m);

/* TODO: Replace the equal to operator with some approximation [because of floating point errors]
 * mat4_is_equal: Checks if two mat4_t's are equal or not
 * mat4_t m1: first matrix to be checked against
 * mat4_t m2: second matrix to be checked against
 * returns: bool true if the two matrix are approximately equal, otherwise false
 */
HPML_API bool mat4_is_equal(mat4_t m1, mat4_t m2);

/* mat4_negate: Negates all the elements of 4x4 matrix
 * mat4_t m: matrix to be negated
 * returns: mat4_t negated matrix
 */
HPML_API mat4_t mat4_negate(mat4_t m);

/* mat4_mul_component_wise: Multiplies two matrices component wise
 * mat4_t m1: First matrix involved in the calculation
 * mat4_t m2: Second matrix involved in the calculation
 * returns: mat4_t resultant matrix
 */
HPML_API mat4_t mat4_mul_component_wise(mat4_t m1, mat4_t m2);

/* mat4_transpose: Transposes a 2x2 matrix
 * mat4_t m: Matrix to be transposed
 * returns: mat4_t transposed matrix
 */
HPML_API mat4_t mat4_transpose(mat4_t m);

/* mat4_lerp: Linearly interpolates each elements of 2x2 matrices
 * mat4_t m1: starting matrix
 * mat4_t m2: ending matrix
 * float lerp_value: linear interpolation value [0, 1]
 * returns: mat4_t interpolated matrix
 */
HPML_API mat4_t mat4_lerp(mat4_t m1, mat4_t m2, float lerp_value);

/* mat4_inverse: Inverts a 4x4 matrix 
 * mat4_t m: Matrix to be inverted
 * returns: mat4_t inverted 4x4 matrix
 */
HPML_API mat4_t mat4_inverse(mat4_t m);


/* For debugging purpose */

/* mat4_print */
HPML_API void mat4_print(mat4_t m);

#ifdef __cplusplus
     }
#endif // __cplusplus
