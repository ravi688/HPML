
#pragma once

#include <hpml/defines.h>

#include <stdarg.h>
#include <math.h>

/*DATA*/
/*vec3_t struct*/
typedef union
{
	struct
	{
		float x, y, z;
	};

	struct 
	{
		float r, g, b;
	};
} vec3_t;

#ifdef __cplusplus
	extern "C" {
#endif // __cplusplus

/*CONSTRUCTOR*/
/*vec3*/
HPML_FORCE_INLINE vec3_t vec3(float x, float y, float z) { return (vec3_t) { x, y, z }; }

/* vec3_zero: Creates a vector3 object in memory having x = 0, and y = 0
 * returns: vec3_t vector having x = 0, y = 0
 */
HPML_FORCE_INLINE vec3_t vec3_zero() { return (vec3_t) { 0, 0, 0 }; }

/* vec3_up: Returns the up direction vector (vector3)
 * returns: vec3_t up direction, i.e. Vector4.up [+ve y axis direction]
 */
HPML_FORCE_INLINE vec3_t vec3_up() { return (vec3_t) { 0, 1, 0 }; }

/* vec3_down: Returns the down direction vector (vector3)
 * returns: vec3_t down direction, i.e. Vector4.down [-ve y axis direction]
 */
HPML_FORCE_INLINE vec3_t vec3_down() { return (vec3_t) { 0, -1, 0 }; }

/* vec3_right: Returns the right direction vector (vector3)
 * returns: vec3_t right direction, i.e. Vector4.right [+ve x axis direction]
 */
HPML_FORCE_INLINE vec3_t vec3_right() { return (vec3_t) { 1, 0, 0 }; }

/*vec3_left*/
HPML_FORCE_INLINE vec3_t vec3_left() { return (vec3_t) { -1, 0, 0 }; }

/* vec3_forward: Returns the forward direction vector (vector3)
 * returns: vec3_t forward direction, i.e. Vector4.forward [+ve z axis direction]
 */
HPML_FORCE_INLINE vec3_t vec3_forward() { return (vec3_t) { 0, 0, 1 }; }

/* vec3_back: Return the backward direction vector (vector3)
 * returns: vec3_t backward direction, i.e. Vector4.back [-ve z axis direction]
 */
HPML_FORCE_INLINE vec3_t vec3_back() { return (vec3_t) { 0, 0, 1 }; }

/*vec3_one*/
HPML_FORCE_INLINE vec3_t vec3_one() { return (vec3_t) { 1, 1, 1 }; }


/*ARITHMETIC*/

/* vec3_add: Adds the rest of the vectors to the first vector in the variable arguments list
 * u32 count: number of vectors involved in the addition
 * ... : variable number of vectors
 * returns: vec3_t resulting vector3 vector
 */
HPML_API vec3_t __vec3_add(vec3_t v1, vec3_t v2);
HPML_API vec3_t vec3_add(u32 count, ...);

/* vec3_sub: Subtracts the rest of the vectors from the first vector in the variable arguments list
 * u32 count: number of vectors involved in the subtraction
 * ... : variable number of vectors
 * returns: vec3_t resulting vector3 vector
 */
HPML_API vec3_t __vec3_sub(vec3_t v1, vec3_t v2);
HPML_API vec3_t vec3_sub(u32 count, ...);

/* vec3_mul: Multiplies the first vector by the rest of the vectors in the variable arguments list
 * u32 count: number of vectors involved in the multiplication
 * ... : variable number of vectors
 * returns: vec3_t resulting vector3 vector
 */
HPML_API vec3_t __vec3_mul(vec3_t v1, vec3_t v2);
HPML_API vec3_t vec3_mul(u32 count, ...);

/* vec3_div: Divides the first vector by the rest of the vectors in the variable arguments list
 * u32 count: number of vectors involved in the division
 * ... : variable number of vectors
 * returns: vec3_t resulting vector3 vector
 * exceptions: throws DIVIDE_BY_ZERO exception if any of the vectors are null except the first vector in the variable arguments list
 */
HPML_API vec3_t __vec3_div(vec3_t v1, vec3_t v2);
HPML_API vec3_t vec3_div(u32 count, ...);

/*INTERPOLATION*/

/* vec3_lerp: Calculates an interpolated vector from vector v1 to vector v2, having interpolation value 'interpolation_value'
 * vec3_t v1: from vector
 * vec3_t v2: to vector
 * float interpolation_value: interpolation value [Range (0, 1)], inclusive of 0 and 1
 * returns: vec3_t interpolated vector
 */
HPML_API vec3_t vec3_lerp(vec3_t from, vec3_t to, float t);

/* vec3_slerp: Calculates spherical interpolation value in-between the vector v1 and v2
 * vec3_t v1: First vector [from]
 * vec3_t v2: Second vector [to]
 * float slerp_value: interpolation parameter
 * returns: vec3_t spherically interpolated value
 */
HPML_API vec3_t vec3_slerp(vec3_t from, vec3_t to, float t);

/*ALGEBRA*/

/*vec3_direction_ratios*/
HPML_API vec3_t vec3_direction_ratios(vec3_t v);

/* vec3_external_division: Calculates external division vector
 * vec3_t v1: first or left vector
 * vec3_t v2: second or right vector
 * float m: left value of the ratio or numerator
 * float n: right value of the ratio or denominator
 * NOTE: if m - n = 0 then it will return second vector
 */
HPML_API vec3_t vec3_external_division(vec3_t v1, vec3_t v2, float m, float n);

/* vec3_internal_division: Calculates internal division vector
 * vec3_t v1: first or left vector
 * vec3_t v2: second or right vector
 * float m: left value of the ratio or numerator
 * float n: right value of the ratio or denominator
 * NOTE: if m + n = 0 then it will return second vector
 */
HPML_API vec3_t vec3_internal_division(vec3_t v1, vec3_t v2, float m, float n);

/* vec3_scale: Calculates a scaled vector by amount 'scalar_value'
 * vec3_t v: vector3 vector to be scaled
 * float scalar_value: scalar value to be multiplied with components of v vector
 * returns: vec3_t scaled vector
 */
HPML_API vec3_t vec3_scale(vec3_t v, float value);

/* vec3_magnitude: Calculates the magnitude of vector3
 * vec3_t v: vector of which magnitude to be calculated
 * returns: float magnitude of vector3 v
 */
HPML_API float vec3_magnitude(vec3_t v);

/* vec3_sqrmagnitude: Calculates the squared magnitude of vector3
 * vec3_t v: vector of which squared magnitude to be calculated
 * returns: float squared magnitude of vector3 v
 */
HPML_API float vec3_sqrmagnitude(vec3_t v);

/* vec3_normalize: Normalizes a vector3
 * vec3_t v: vector to be normalized
 * returns: vec3_t normalized vector
 */
HPML_API vec3_t vec3_normalize(vec3_t v);

/* vec3_angle: Calculates the angle between two vector3 vectors
 * vec3_t v1: first vector involved in the angle calculation
 * vec3_t v2: second vector involved in the angle calculation
 * returns: float +ve angle always
 */
HPML_API float vec3_angle(vec3_t v1, vec3_t v2);

/* vec3_unit_angle: Calculates the angle between two vector3 vectors
 * vec3_t v1: first unit vector involved in the angle calculation
 * vec3_t v2: second unit vector involved in the angle calculation
 * returns: float +ve angle always
 * NOTE: v1 and v2 must be unit vectors; this function is faster than vec3_angle
 */
HPML_API float vec3_unit_angle(vec3_t v1, vec3_t v2);

/* vec3_negate: Negates a vector
 * v: vector to be negated
 * returns: negated vector
 */
HPML_API vec3_t vec3_negate(vec3_t v);

/* vec3_rotate_x: rotates a vector along x axis
 * v: vector to be rotated
 * angle: angle in radians
 * returns: rotated vector along x axis by 'angle'
 */
HPML_API vec3_t vec3_rotate_x(vec3_t v, float angle);

/* vec3_rotate_y: rotates a vector along y axis
 * v: vector to be rotated
 * angle: angle in radians
 * returns: rotated vector along y axis by 'angle'
 */
HPML_API vec3_t vec3_rotate_y(vec3_t v, float angle);

/* vec4_rotate_z: rotates a vector along z axis
 * v: vector to be rotated
 * angle: angle in radians
 * returns: rotated vector along z axis by 'angle'
 */
HPML_API vec3_t vec3_rotate_z(vec3_t v, float angle);

/* vec4_rotate: rotates a vector along a given axis (x, y, z)
 * v: vector to be rotated
 * angle: angle in radians
 * returns: rotated vector along the axis (x, y, z)
 */
HPML_API vec3_t vec3_rotate(vec3_t v, float x, float y, float z);

/*vec3_axis_rotate*/
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
HPML_API vec3_t vec3_axis_rotate(vec3_t v, float axisX, float axisY, float axisZ, float angle);

/* vec3_project: Projects vector "v" over a unit vector "a"
 * v : vector to be projected
 * a : vector on which "v" has to be projected
 * returns: a project vector of v in the direction of a
 */
HPML_API vec3_t vec3_project(vec3_t v, vec3_t a);

/* vec3_unit_project: Projects vector "v" over a unit vector "a"
 * v : vector to be projected
 * a : unit vector on which "v" has to be projected
 * returns: a project vector of v in the direction of a
 * NOTE: this function is faster than vec4_project because it doesn't calculate unit vector of 'a'
 */
HPML_API vec3_t vec3_unit_project(vec3_t v, vec3_t a);

/* vec3_box: Calculates the box product of three vectors
 * from: base start vector
 * to: base end vector
 * height: height vector
 * returns: box product (signed volume of the parallel piped solid)
 */
HPML_API float vec3_box(vec3_t from, vec3_t to, vec3_t height);

/* vec3_dot: Calculates the dot product of two vectors
 * v1 : first vector
 * v2 : second vector
 * returns: dot product "magnitude(v1) * magnitude(v2) * cos(angle(v1, v2))"
 */
HPML_API float vec3_dot(vec3_t v1, vec3_t v2);

/* vec3_cross: Calculates the cross product of two vectors
 * from: start vector
 * to : end vector
 * returns: pseudo vector perpendicular to "from" and "to"
 */
HPML_API vec3_t vec3_cross(vec3_t from, vec3_t to);

/*MISC*/

/* vec3_is_null: Checks if passed vector3 is null or not
 * vec3_t v: vector3 to be checked for
 * returns: true if vector3 is null vector, otherwise false [boolean]
 */
HPML_API bool vec3_is_null(vec3_t v);

/* vec3_is_equal: Checks whether the two vectors are equal or not
 * vec3_t v1: First vector to be checked against
 * vec3_t v2: Second vector to be checked against
 * returns: bool true if both vectors are approximetly equal, otherwise false
 */
HPML_API bool vec3_is_equal(vec3_t v1, vec3_t v2);

/*DEBUGGING*/

/*vec3_print*/
HPML_API void vec3_print(vec3_t v);


#ifdef __cplusplus
	}
#endif // __cplusplus
