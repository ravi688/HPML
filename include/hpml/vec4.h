
#pragma once

#ifdef VEC4_ENABLE_SIMD_ACCELERATION
#warning "VEC4_ENABLE_SIMD_ACCELERATION switch is enabled but SIMD acceleration isn't supported!"
#endif

#include <hpml/defines.h>

/*DATA*/
/*vec4_t struct*/
typedef union
{
	struct
	{
		float x, y, z, w;
	};

	struct
	{
		float r, g, b, a;
	};

	float v[4];
} vec4_t;


#define VEC4 (vec4_t)

#ifdef __cplusplus
	extern "C" {
#endif // __cplusplus

/*CONSTRUCTOR*/
/*vec4*/
static HPML_FORCE_INLINE vec4_t vec4(float x, float y, float z, float w) { return VEC4 { x, y, z, w }; }

/* vec4_zero: Creates a vector3 object in memory having x = 0, y = 0, z = 0, and w = 0
 * returns: vec4_t vector having x = 0, y = 0, z = 0, w = 0
 */
static HPML_FORCE_INLINE vec4_t vec4_zero() { return vec4(0, 0, 0, 0); }

/* vec4_up: Returns the up direction vector (vector4)
 * returns: vec4_t up direction, i.e. Vector4.up [+ve y axis direction]
 */
static HPML_FORCE_INLINE vec4_t vec4_up() { return vec4(0, 1, 0, 0);  }

/* vec4_down: Returns the down direction vector (vector4)
 * returns: vec4_t down direction, i.e. Vector4.down [-ve y axis direction]
 */
static HPML_FORCE_INLINE vec4_t vec4_down() { return vec4(0, -1, 0, 0); }

/* vec4_right: Returns the right direction vector (vector4)
 * returns: vec4_t right direction, i.e. Vector4.right [+ve x axis direction]
 */
static HPML_FORCE_INLINE vec4_t vec4_right() { return vec4(1, 0, 0, 0); }

/* vec4_left: Returns the left direction vector (vector4)
 * returns: vec4_t left direction, i.e. Vector4.right [-ve x axis direction]
 */
static HPML_FORCE_INLINE vec4_t vec4_left() { return vec4(-1, 0, 0, 0); }

/* vec4_forward: Returns the forward direction vector (vector4)
 * returns: vec4_t forward direction, i.e. Vector4.forward [+ve z axis direction]
 */
static HPML_FORCE_INLINE vec4_t vec4_forward() { return vec4(0, 0, 1, 0); }

/* vec4_back: Return the backward direction vector (vector4)
 * returns: vec4_t backward direction, i.e. Vector4.back [-ve z axis direction]
 */
static HPML_FORCE_INLINE vec4_t vec4_back() { return vec4(0, 0, -1, 0); }

/*vec4_one*/
static HPML_FORCE_INLINE vec4_t vec4_one() { return vec4(1, 1, 1, 1); }


/*ARITHMETIC*/

/* vec4_add: Adds the rest of the vectors to the first vector in the variable arguments list
 * u32 count: number of vectors involved in the addition
 * ... : variable number of vectors
 * returns: vec4_t resulting vector3 vector
 */
HPML_API vec4_t __vec4_add(vec4_t v1, vec4_t v2);
HPML_API vec4_t vec4_add(u32 count, ...);

/* vec4_sub: Subtracts the rest of the vectors from the first vector in the variable arguments list
 * u32 count: number of vectors involved in the subtraction
 * ... : variable number of vectors
 * returns: vec4_t resulting vector3 vector
 */
HPML_API vec4_t __vec4_sub(vec4_t v1, vec4_t v2);
HPML_API vec4_t vec4_sub(u32 count, ...);

/* vec4_mul: Multiplies the first vector by the rest of the vectors in the variable arguments list
 * u32 count: number of vectors involved in the multiplication
 * ... : variable number of vectors
 * returns: vec4_t resulting vector3 vector
 */
HPML_API vec4_t __vec4_mul(vec4_t v1, vec4_t v2);
HPML_API vec4_t vec4_mul(u32 count, ...);

/* vec4_div: Divides the first vector by the rest of the vectors in the variable arguments list
 * u32 count: number of vectors involved in the division
 * ... : variable number of vectors
 * returns: vec4_t resulting vector3 vector
 * exceptions: throws DIVIDE_BY_ZERO exception if any of the vectors are null except the first vector in the variable arguments list
 */
HPML_API vec4_t __vec4_div(vec4_t v1, vec4_t v2);
HPML_API vec4_t vec4_div(u32 count, ...);

/*INTERPOLATION*/

/* vec4_lerp: Calculates an interpolated vector from vector v1 to vector v2, having interpolation value 'interpolation_value'
 * vec4_t v1: from vector
 * vec4_t v2: to vector
 * float interpolation_value: interpolation value [Range (0, 1)], inclusive of 0 and 1
 * returns: vec4_t interpolated vector
 */
HPML_API vec4_t vec4_lerp(vec4_t from, vec4_t to, float t);

/* vec4_slerp: Calculates spherical linear interpolation value in-between the vector v1 and v2
 * vec4_t v1: First vector [from]
 * vec4_t v2: Second vector [to]
 * float slerp_value: interpolation parameter
 * returns: vec4_t spherically interpolated value
 */
HPML_API vec4_t vec4_slerp(vec4_t from, vec4_t to, float t);

/*ALGEBRA*/

/* vec4_direction_ratios: Calculates the direction ratios of the vector
 * v: vector
 * returns: (vec4_t), cos(alpha) = x, cos(beta) = y, cos(gamma) = z, cos(eeta) = w
 */
HPML_API vec4_t vec4_direction_ratios(vec4_t v);

/* vec4_external_division: Calculates external division vector
 * vec4_t v1: first or left vector
 * vec4_t v2: second or right vector
 * float m: left value of the ratio or numerator
 * float n: right value of the ratio or denominator
 * NOTE: if m - n = 0 then it will return second vector
 */
HPML_API vec4_t vec4_external_division(vec4_t v1, vec4_t v2, float m, float n);

/* vec4_internal_division: Calculates internal division vector
 * vec4_t v1: first or left vector
 * vec4_t v2: second or right vector
 * float m: left value of the ratio or numerator
 * float n: right value of the ratio or denominator
 * NOTE: if m + n = 0 then it will return second vector
 */
HPML_API vec4_t vec4_internal_division(vec4_t v1, vec4_t v2, float m, float n);

/* vec4_scale: Calculates a scaled vector by amount 'scalar_value'
 * vec4_t v: vector3 vector to be scaled
 * float scalar_value: scalar value to be multiplied with components of v vector
 * returns: vec4_t scaled vector
 */
HPML_API vec4_t vec4_scale(vec4_t v, float value);

/* vec4_magnitude: Calculates the magnitude of vector3
 * vec4_t v: vector of which magnitude to be calculated
 * returns: float magnitude of vector4 v
 */
HPML_API float vec4_magnitude(vec4_t v);

/* vec4_magnitude: Calculates the squared magnitude of vector3
 * vec4_t v: vector of which squared magnitude to be calculated
 * returns: float squared magnitude of vector4 v
 */
static HPML_FORCE_INLINE float vec4_sqrmagnitude(vec4_t v) { return v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w; }

/* vec4_normalize: Normalizes a vector3
 * vec4_t v: vector to be normalized
 * returns: vec4_t normalized vector
 */
HPML_API vec4_t vec4_normalize(vec4_t v);

/* vec4_angle: Calculates the angle between two vector3 vectors
 * vec4_t v1: first vector involved in the angle calculation
 * vec4_t v2: second vector involved in the angle calculation
 * returns: float +ve angle always
 */
HPML_API float vec4_angle(vec4_t v1, vec4_t v2);

/* vec4_unit_angle: Calculates the angle between two vector3 vectors
 * vec4_t v1: first unit vector involved in the angle calculation
 * vec4_t v2: second unit vector involved in the angle calculation
 * returns: float +ve angle always
 * NOTE: v1 and v2 must be unit vectors; this function is faster than vec4_angle
 */
HPML_API float vec4_unit_angle(vec4_t v1, vec4_t v2);

/* vec4_negate: Negates a vector
 * v: vector to be negated
 * returns: negated vector
 */
static HPML_FORCE_INLINE vec4_t vec4_negate(vec4_t v) { return VEC4 { -v.x, -v.y, -v.z, -v.w }; }

/* vec4_rotate_x: rotates a vector along x axis
 * v: vector to be rotated
 * angle: angle in radians
 * returns: rotated vector along x axis by 'angle'
 */
HPML_API vec4_t vec4_rotate_x(vec4_t v, float angle);

/* vec4_rotate_y: rotates a vector along y axis
 * v: vector to be rotated
 * angle: angle in radians
 * returns: rotated vector along y axis by 'angle'
 */
HPML_API vec4_t vec4_rotate_y(vec4_t v, float angle);

/* vec4_rotate_z: rotates a vector along z axis
 * v: vector to be rotated
 * angle: angle in radians
 * returns: rotated vector along z axis by 'angle'
 */
HPML_API vec4_t vec4_rotate_z(vec4_t v, float angle);

/* vec4_rotate: rotates a vector along a given axis (x, y, z)
 * v: vector to be rotated
 * angle: angle in radians
 * returns: rotated vector along the axis (x, y, z)
 */
HPML_API vec4_t vec4_rotate(vec4_t v, float x, float y, float z);

/*vec4_axis_rotate*/
/*
 let axis = a; 
 let vector = v; 
 let angle = r;

 k =  v - (v.a)a
 j = a X k
 f = k * cos(r) + j * sin(r)
 result = f + (v.a)a
 result = k * cos(r) + j * sin(r) + (v.a)a
 result = (v - (v.a)a) * cos(r) + (a x k) * sin(r) + (v.a)a
 result = (v - (v.a)a) * cos(r) + a x (v - (v.a)a) * sin(r) + (v.a)a
 result = (v - (v.a)a) * cos(r) + a x v * sin(r) + (v.a)a
 result = (v.a)a * (1 - cos(r)) + a x v * sin(r) + v * cos(r)
*/
HPML_API vec4_t vec4_axis_rotate(vec4_t v, float axisX, float axisY, float axisZ, float angle);

/* vec4_project: Projects vector "v" over a unit vector "a"
 * v : vector to be projected
 * a : vector on which "v" has to be projected
 * returns: a project vector of v in the direction of a
 */
HPML_API vec4_t vec4_project(vec4_t v, vec4_t a);

/* vec4_unit_project: Projects vector "v" over a unit vector "a"
 * v : vector to be projected
 * a : unit vector on which "v" has to be projected
 * returns: a project vector of v in the direction of a
 * NOTE: this function is faster than vec4_project because it doesn't calculate unit vector of 'a'
 */
HPML_API vec4_t vec4_unit_project(vec4_t v, vec4_t a);

/* vec4_box: Calculates the box product of three vectors
 * from: base start vector
 * to: base end vector
 * height: height vector
 * returns: box product (signed volume of the parallel piped solid)
 */
HPML_API float vec4_box(vec4_t from, vec4_t to, vec4_t height);

/* vec4_dot: Calculates the dot product of two vectors
 * v1 : first vector
 * v2 : second vector
 * returns: dot product "magnitude(v1) * magnitude(v2) * cos(angle(v1, v2))"
 */
HPML_API float vec4_dot(vec4_t v1, vec4_t v2);

/* vec4_cross: Calculates the cross product of two vectors
 * from: start vector
 * to : end vector
 * returns: pseudo vector perpendicular to "from" and "to"
 */
HPML_API vec4_t vec4_cross(vec4_t from, vec4_t to);

/*MISC*/

/* vec4_is_null: Checks if passed vector3 is null or not
 * vec4_t v: vector3 to be checked for
 * returns: true if vector3 is null vector, otherwise false [boolean]
 */
HPML_API bool vec4_is_null(vec4_t v);

/* vec4_is_equal: Checks whether the two vectors are equal or not
 * vec4_t v1: First vector to be checked against
 * vec4_t v2: Second vector to be checked against
 * returns: bool true if both vectors are approximetly equal, otherwise false
 */
HPML_API bool vec4_is_equal(vec4_t v1, vec4_t v2);

/*DEBUGGING*/

/*vec4_print*/
HPML_API void vec4_print(vec4_t v);


#ifdef __cplusplus
	}
#endif // __cplusplus
