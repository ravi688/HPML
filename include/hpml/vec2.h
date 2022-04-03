#pragma once

#include <hpml/defines.h>

typedef struct vec2_t
{
	float x;
	float y;
} vec2_t;

#define VEC2 (vec2_t)

/* vec2: Creates vector2 object in memory taking two arguments
 * x: x-component
 * y: y-component
 * returns: vec_t vector having x, y
 */
static HPML_API HPML_FORCE_INLINE vec2_t vec2(float x, float y) { return VEC2 { x, y }; }

/* vec2_right: Returns the right direction vector (vector2)
 * returns: vec2_t right direction, i.e. Vector2.right [+ve x axis direction]
 */
static HPML_API HPML_FORCE_INLINE vec2_t vec2_right() { return vec2(1, 0); }

/* vec2_left: Returns the left direction vector (vector2)
 * returns: vec2_t left direction, i.e. Vector2.left [-ve x axis direction]
 */
static HPML_API HPML_FORCE_INLINE vec2_t vec2_left() { return vec2(-1, 0); }

/* vec2_down: Returns the down direction vector (vector2)
 * returns: vec2_t down direction, i.e. Vector2.down [-ve y axis direction]
 */
static HPML_API HPML_FORCE_INLINE vec2_t vec2_down() { return vec2(0, -1); }

/* vec2_up: Returns the up direction vector (vector2)
 * returns: vec2_t up direction, i.e. Vector2.up [+ve y axis direction]
 */
static HPML_API HPML_FORCE_INLINE vec2_t vec2_up() { return vec2(0, 1); }


/* vec2_slerp: Calculates the spherical interpolation value in between vector v1 and v2
 * vec2_t v1: First vector [from]
 * vec2_t v2: Second vector [to]
 * returns: vec2_t spherically interpolated value
 */
HPML_API vec2_t vec2_slerp(vec2_t v1, vec2_t v2, float slerp_value);

/* vec2_scale: Calculates a scaled vector by amount 'scalar_value'
 * vec2_t v: vector2 vector to be scaled
 * float scalar_value: scalar value to be multiplied with components of v vector
 * returns: vec2_t scaled vector
 */
HPML_API vec2_t vec2_scale(vec2_t v, float scalar_value);

/* vec2_normal_anticlockwise: Calculates a normal vector to vector v in anticlockwise sense
 * vec2_t v: base vector to the normal to be calculated
 * returns: vec2_t normal vector in anticlockwise sense
 */
HPML_API vec2_t vec2_normal_anticlockwise(vec2_t v);

/* vec2_normal_clockwise: Calculates a normal vector to vector v in clockwise sense
 * vec2_t v: base vector to the normal to be calculated
 * returns: vec2_t normal vector in clockwise sense
 */
HPML_API vec2_t vec2_normal_clockwise(vec2_t v);

/* vec2_internal_division: Calculates internal division vector
 * vec2_t v1: first or left vector
 * vec2_t v2: second or right vector
 * float m: left value of the ratio or numerator
 * float n: right value of the ratio or denominator
 * NOTE: if m + n = 0 then it will return first vector
 */
HPML_API vec2_t vec2_internal_division(vec2_t v1, vec2_t v2, float m, float n);

/* vec2_external_division: Calculates external division vector
 * vec2_t v1: first or left vector
 * vec2_t v2: second or right vector
 * float m: left value of the ratio or numerator
 * float n: right value of the ratio or denominator
 * NOTE: if m - n = 0 then it will return second vector
 */
HPML_API vec2_t vec2_external_division(vec2_t v1, vec2_t v2, float m, float n);

/* vec2_lerp: Calculates an interpolated vector from vector v1 to vector v2, having interpolation value 'interpolation_value'
 * vec2_t v1: from vector
 * vec2_t v2: to vector
 * float interpolation_value: interpolation value [Range (0, 1)], inclusive of 0 and 1
 * returns: vec2_t interpolated vector
 */
HPML_API vec2_t vec2_lerp(vec2_t v1, vec2_t v2, float interpolation_value);

/* vec2_project: Calculates a projection vector of v1 in the direction of v2 vector
 * vec2_t v1: vector2 vector which is projected on v1 vector
 * vec2_t v2: direction vector on which v1 vector is projected
 * returns: vec2_t projected vector in the direction of vector v1
 */
HPML_API vec2_t vec2_project(vec2_t v1, vec2_t v2);

/* vec2_abs: Calculates the absolute value of each component of the vector2 v
 * vec2_t v: input vector2 vector
 * returns: vec2_t vector having absolute value components
 */
HPML_API vec2_t vec2_abs(vec2_t v);

/* vec2_angle: Calculates the angle between two vector2 vectors
 * vec2_t v1: first vector involved in the angle calculation
 * vec2_t v2: second vector involved in the angle calculation
 * returns: float +ve angle always
 */
HPML_API float vec2_angle(vec2_t v1, vec2_t v2);

/* vec2_rotate: Rotates a vector2 by angle 'angle'
 * vec2_t v: vector to be rotated
 * float angle: angle by which to rotate, +ve angle means anticlockwise rotation, -ve angle means clockwise rotation
 * returns: vec2_t rotated vector
 */
HPML_API vec2_t vec2_rotate(vec2_t v, float angle);

/* vec2_normalize: Normalizes a vector2
 * vec2_t v: vector to be normalized
 * returns: vec2_t normalized vector
 */
HPML_API vec2_t vec2_normalize(vec2_t v);

/* vec2_negate: Negates a vector2
 * vec2_t v: vector to be negated
 * returns: vec2_t negated vector
 */
HPML_API vec2_t vec2_negate(vec2_t v);

/* vec2_magnitude: Calculates the magnitude of vector2
 * vec2_t v: vector of which magnitude to be calculated
 * returns: float magnitude of vector2 v
 */
HPML_API float vec2_magnitude(vec2_t v);

/* vec2_sqrmagnitude: Calculates the squared magnitude of vector2
 * vec2_t v: vector of which squared magnitude to be calculated
 * returns: float squared magnitude of vector2 v
 */
HPML_API float vec2_sqrmagnitude(vec2_t v);

/* vec_dot: Calculates the dot product of two vector2's
 * vec2_t v1: first vector involved in the dot product calculation
 * vec2_t v2: second vector involved in the dot product calculation
 * returns: float dot product of v1 and v2
 */
HPML_API float vec2_dot(vec2_t v1, vec2_t v2);

/* See: vec2_null
 */
 
/* vec2_null: Creates a vector2 object in memory having x = 0, and y = 0
 * returns: vec2_t vector having x = 0, y = 0
 */
static HPML_API HPML_FORCE_INLINE vec2_t vec2_null() { return vec2(0, 0); }

/* vec2_is_null: Checks if passed vector2 is null or not
 * vec2_t v: vector2 to be checked for
 * returns: true if vector2 is null vector, otherwise false [boolean]
 */
HPML_API bool vec2_is_null(vec2_t v);

/* TODO: Make approximate calculation, not exact [with floating point numbers]
 * vec2_is_equal: Checks if passed vectors are equal or not
 * vec2_t v1: first vector to be checked against
 * vec2_t v2: second vector to be checked against
 * returns: true if v2 approximately equals to v1, otherwise false
 */
HPML_API bool vec2_is_equal(vec2_t v1, vec2_t v2);

/* vec2_add: Adds two vector2 vectors component wise, i.e. v1 + v2
 * vec2_t v1: first vector involved in addition calculation
 * vec2_t v2: second vector involved in addition calculation
 * returns: vec2_t resulting vector2 vector
 */
HPML_API vec2_t vec2_add(vec2_t v1, vec2_t v2);

/* vec2_sub: Subtracts second vector (v2) from first vector (v1) component wise, i.e. v1 - v2
 * vec2_t v1: first vector involved in subtraction calculation
 * vec2_t v2: second vector involved in subtraction calculation
 * returns: vec2_t resulting vector2 vector
 */
HPML_API vec2_t vec2_sub(vec2_t v1, vec2_t v2);

/* vec2_mul: Multiplies two vector2 vectors v1 and v2 component wise
 * vec2_t v1: first vector involved in multiplication calculation
 * vec2_t v2: second vector involved in multiplication calculation
 * returns: vec2_t resulting vector2 vector
 */
HPML_API vec2_t vec2_mul(vec2_t v1, vec2_t v2);

/* vec2_div: Divides first vector (v1) by second vector (v2), i.e. v1 / v2
 * vec2_t v1: first vector involved in division calculation
 * vec2_t v2: second vector involved in division calculation
 * returns: vec2_t resulting vector2 vector
 * exceptions: throws DIVIDE_BY_ZERO exception if v2 is a null vector
 */
HPML_API vec2_t vec2_div(vec2_t v1, vec2_t v2);


/* For debugging purpose */
HPML_API void vec2_print(vec2_t v);
