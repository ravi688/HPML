
#pragma once

#if defined(IMPLEMENTATION)
#include <exception/exception.h>
#include <math.h>
#endif

#include <hpml/template_system.h>
#include <hpml/no_compile_header.h>
#include <hpml/defines.h>

#include <stdarg.h>
#include <stdbool.h>

/*DATA*/
/*vec3_t(T) struct*/
#define vec3_t(T) c_template(vec3_t, T)
#define instantiate_vec3_struct(T)\
typedef struct\
{\
	T x;\
	T y;\
	T z;\
} vec3_t(T)

/*CONSTRUCTOR*/
/*vec3*/
#define vec3(T) c_template(vec3, T)
#define instantiate_declaration_vec3(T) HPML_API vec3_t(T) vec3(T)(T x, T y, T z)
#define instantiate_implementation_vec3(T) HPML_API vec3_t(T) vec3(T)(T x, T y, T z) { return (vec3_t(T)) { x, y, z }; }

/* vec3_zero: Creates a vector3 object in memory having x = 0, and y = 0
 * returns: vec3_t(T) vector having x = 0, y = 0
 */
#define vec3_zero(T) c_template(vec3_zero, T)
#define instantiate_declaration_vec3_zero(T) HPML_API vec3_t(T) vec3_zero(T)()
#define instantiate_implementation_vec3_zero(T) HPML_API vec3_t(T) vec3_zero(T)() { return (vec3_t(T)) { 0, 0, 0 }; }

/* vec3_up: Returns the up direction vector (vector4)
 * returns: vec3_t(T) up direction, i.e. Vector4.up [+ve y axis direction]
 */
#define vec3_up(T) c_template(vec3_up, T)
#define instantiate_declaration_vec3_up(T) HPML_API vec3_t(T) vec3_up(T)()
#define instantiate_implementation_vec3_up(T) HPML_API vec3_t(T) vec3_up(T)() { return (vec3_t(T)) { 0, 1, 0 }; }

/* vec3_down: Returns the down direction vector (vector4)
 * returns: vec3_t(T) down direction, i.e. Vector4.down [-ve y axis direction]
 */
#define vec3_down(T) c_template(vec3_down, T)
#define instantiate_declaration_vec3_down(T) HPML_API vec3_t(T) vec3_down(T)()
#define instantiate_implementation_vec3_down(T) HPML_API vec3_t(T) vec3_down(T)() { return (vec3_t(T)) { 0, -1, 0 }; }

/* vec3_right: Returns the right direction vector (vector4)
 * returns: vec3_t(T) right direction, i.e. Vector4.right [+ve x axis direction]
 */
#define vec3_right(T) c_template(vec3_right, T)
#define instantiate_declaration_vec3_right(T) HPML_API vec3_t(T) vec3_right(T)()
#define instantiate_implementation_vec3_right(T) HPML_API vec3_t(T) vec3_right(T)() { return (vec3_t(T)) { 1, 0, 0 }; }

/*vec3_left*/
#define vec3_left(T) c_template(vec3_left, T)
#define instantiate_declaration_vec3_left(T) HPML_API vec3_t(T) vec3_left(T)()
#define instantiate_implementation_vec3_left(T) HPML_API vec3_t(T) vec3_left(T)() { return (vec3_t(T)) { -1, 0, 0 }; }

/* vec3_forward: Returns the forward direction vector (vector4)
 * returns: vec3_t(T) forward direction, i.e. Vector4.forward [+ve z axis direction]
 */
#define vec3_forward(T) c_template(vec3_forward, T)
#define instantiate_declaration_vec3_forward(T) HPML_API vec3_t(T) vec3_forward(T)()
#define instantiate_implementation_vec3_forward(T) HPML_API vec3_t(T) vec3_forward(T)() { return (vec3_t(T)) { 0, 0, 1 }; }

/* vec3_back: Return the backward direction vector (vector4)
 * returns: vec3_t(T) backward direction, i.e. Vector4.back [-ve z axis direction]
 */
#define vec3_back(T) c_template(vec3_back, T)
#define instantiate_declaration_vec3_back(T) HPML_API vec3_t(T) vec3_back(T)()
#define instantiate_implementation_vec3_back(T) HPML_API vec3_t(T) vec3_back(T)() { return (vec3_t(T)) { 0, 0, 1 }; }

/*vec3_one*/
#define vec3_one(T) c_template(vec3_one, T)
#define instantiate_declaration_vec3_one(T) HPML_API vec3_t(T) vec3_one(T)()
#define instantiate_implementation_vec3_one(T) HPML_API vec3_t(T) vec3_one(T)() { return (vec3_t(T)) { 1, 1, 1 }; }


/*ARITHMETIC*/

/* vec3_add: Adds the rest of the vectors to the first vector in the variable arguments list
 * u32 count: number of vectors involved in the addition
 * ... : variable number of vectors
 * returns: vec3_t(T) resulting vector3 vector
 */
#define __vec3_add(T) c_template(__vec3_add, T)
#define vec3_add(T) c_template(vec3_add, T)
#define instantiate_declaration_vec3_add(T)\
HPML_API vec3_t(T) __vec3_add(T)(vec3_t(T) v1, vec3_t(T) v2);\
HPML_API vec3_t(T) vec3_add(T)(u32 count, ...)
#define instantiate_implementation_vec3_add(T)\
HPML_API vec3_t(T) __vec3_add(T)(vec3_t(T) v1, vec3_t(T) v2) { return (vec3_t(T)) { v1.x + v2.x, v1.y + v2.y, v1.z + v2.z }; }\
HPML_API vec3_t(T) vec3_add(T)(u32 count, ...)\
{\
	va_list args;\
	va_start(args, count);\
	vec3_t(T) result = va_arg(args, vec3_t(T));\
	--count;\
	while(count > 0)\
	{\
		result = __vec3_add(T)(result, va_arg(args, vec3_t(T)));\
		--count;\
	}\
	va_end(args);\
	return result;\
}

/* vec3_sub: Subtracts the rest of the vectors from the first vector in the variable arguments list
 * u32 count: number of vectors involved in the subtraction
 * ... : variable number of vectors
 * returns: vec3_t(T) resulting vector3 vector
 */
#define __vec3_sub(T) c_template(__vec3_sub, T)
#define vec3_sub(T) c_template(vec3_sub, T)
#define instantiate_declaration_vec3_sub(T)\
HPML_API vec3_t(T) __vec3_sub(T)(vec3_t(T) v1, vec3_t(T) v2);\
HPML_API vec3_t(T) vec3_sub(T)(u32 count, ...)
#define instantiate_implementation_vec3_sub(T)\
HPML_API vec3_t(T) __vec3_sub(T)(vec3_t(T) v1, vec3_t(T) v2) { return (vec3_t(T)) { v1.x - v2.x, v1.y - v2.y, v1.z - v2.z }; }\
HPML_API vec3_t(T) vec3_sub(T)(u32 count, ...)\
{\
	va_list args;\
	va_start(args, count);\
	vec3_t(T) result = va_arg(args, vec3_t(T));\
	--count;\
	while(count > 0)\
	{\
		result = __vec3_sub(T)(result, va_arg(args, vec3_t(T)));\
		--count;\
	}\
	va_end(args);\
	return result;\
}

/* vec3_mul: Multiplies the first vector by the rest of the vectors in the variable arguments list
 * u32 count: number of vectors involved in the multiplication
 * ... : variable number of vectors
 * returns: vec3_t(T) resulting vector3 vector
 */
#define __vec3_mul(T) c_template(__vec3_mul, T)
#define vec3_mul(T) c_template(vec3_mul, T)
#define instantiate_declaration_vec3_mul(T)\
HPML_API vec3_t(T) __vec3_mul(T)(vec3_t(T) v1, vec3_t(T) v2);\
HPML_API vec3_t(T) vec3_mul(T)(u32 count, ...)
#define instantiate_implementation_vec3_mul(T)\
HPML_API vec3_t(T) __vec3_mul(T)(vec3_t(T) v1, vec3_t(T) v2) { return (vec3_t(T)) { v1.x * v2.x, v1.y * v2.y, v1.z * v2.z }; }\
HPML_API vec3_t(T) vec3_mul(T)(u32 count, ...)\
{\
	va_list args;\
	va_start(args, count);\
	vec3_t(T) result = va_arg(args, vec3_t(T));\
	--count;\
	while(count > 0)\
	{\
		result = __vec3_mul(T)(result, va_arg(args, vec3_t(T)));\
		--count;\
	}\
	va_end(args);\
	return result;\
}

/* vec3_div: Divides the first vector by the rest of the vectors in the variable arguments list
 * u32 count: number of vectors involved in the division
 * ... : variable number of vectors
 * returns: vec3_t(T) resulting vector3 vector
 * exceptions: throws DIVIDE_BY_ZERO exception if any of the vectors are null except the first vector in the variable arguments list
 */
#define __vec3_div(T) c_template(__vec3_div, T)
#define vec3_div(T) c_template(vec3_div, T)
#define instantiate_declaration_vec3_div(T)\
HPML_API vec3_t(T) __vec3_div(T)(vec3_t(T) v1, vec3_t(T) v2);\
HPML_API vec3_t(T) vec3_div(T)(u32 count, ...)
#define instantiate_implementation_vec3_div(T)\
HPML_API vec3_t(T) __vec3_div(T)(vec3_t(T) v1, vec3_t(T) v2)\
{\
	EXCEPTION_BLOCK\
	(\
	if(vec3_is_null(T)(v2))\
		THROW_EXCEPTION(DIVIDE_BY_ZERO);\
	)\
	return (vec3_t(T)) { v1.x / v2.x, v1.y / v2.y, v1.z / v2.z };\
}\
HPML_API vec3_t(T) vec3_div(T)(u32 count, ...)\
{\
	va_list args;\
	va_start(args, count);\
	vec3_t(T) result = va_arg(args, vec3_t(T));\
	--count;\
	while(count > 0)\
	{\
		result = __vec3_div(T)(result, va_arg(args, vec3_t(T)));\
		--count;\
	}\
	va_end(args);\
	return result;\
}

/*INTERPOLATION*/

/* vec3_lerp: Calculates an interpolated vector from vector v1 to vector v2, having interpolation value 'interpolation_value'
 * vec3_t(T) v1: from vector
 * vec3_t(T) v2: to vector
 * float interpolation_value: interpolation value [Range (0, 1)], inclusive of 0 and 1
 * returns: vec3_t(T) interpolated vector
 */
#define vec3_lerp(T) c_template(vec3_lerp, T)
#define instantiate_declaration_vec3_lerp(T) HPML_API vec3_t(T) vec3_lerp(T)(vec3_t(T) from, vec3_t(T) to, float t)
#define instantiate_implementation_vec3_lerp(T) HPML_API vec3_t(T) vec3_lerp(T)(vec3_t(T) from, vec3_t(T) to, float t)\
{\
	float _t = 1 - t;\
	return (vec3_t(T)) { from.x * _t + to.x * t, from.y * _t + to.y * t, from.z * _t + to.z * t };\
}

/* vec3_slerp(T): Calculates spherical interpolation value in-between the vector v1 and v2
 * vec3_t(T) v1: First vector [from]
 * vec3_t(T) v2: Second vector [to]
 * T slerp_value: interpolation parameter
 * returns: vec3_t(T) spherically interpolated value
 */
#define vec3_slerp(T) c_template(vec3_slerp, T)
#define instantiate_declaration_vec3_slerp(T) HPML_API vec3_t(T) vec3_slerp(T)(vec3_t(T) from, vec3_t(T) to, float t)
#define instantiate_implementation_vec3_slerp(T) HPML_API vec3_t(T) vec3_slerp(T)(vec3_t(T) from, vec3_t(T) to, float t)\
{\
	float angle = vec3_angle(T)(from, to);\
	EXCEPTION_BLOCK\
	(\
		if((angle == 0) || (angle == 3.145926f) || (angle == 2 * 3.145926f))\
			THROW_EXCEPTION(DIVIDE_BY_ZERO);\
	)\
	float inv_sin_angle = 1 / sin(angle);\
	float temp = t * angle;\
	return vec3_add(T)(2, vec3_scale(T)(from, sin(angle - temp) * inv_sin_angle), vec3_scale(T)(to, sin(temp)));\
}

/*ALGEBRA*/

/*vec3_direction_ratios*/
#define vec3_direction_ratios(T) c_template(vec3_direction_ratios, T)
#define instantiate_declaration_vec3_direction_ratios(T) HPML_API vec3_t(T) vec3_direction_ratios(T)(vec3_t(T))
#define instantiate_implementation_vec3_direction_ratios(T) HPML_API vec3_t(T) vec3_direction_ratios(T)(vec3_t(T) v)\
{\
	float inv_mag = 1 / vec3_magnitude(T)(v);\
	return vec3_scale(T)(v, inv_mag);\
}

/* vec3_external_division: Calculates external division vector
 * vec3_t(T) v1: first or left vector
 * vec3_t(T) v2: second or right vector
 * float m: left value of the ratio or numerator
 * float n: right value of the ratio or denominator
 * NOTE: if m - n = 0 then it will return second vector
 */
#define vec3_external_division(T) c_template(vec3_external_division, T)
#define instantiate_declaration_vec3_external_division(T) HPML_API vec3_t(T) vec3_internal_division(T)(vec3_t)
#define instantiate_implementation_vec3_external_division(T)\
HPML_API vec3_t(T) vec3_external_division(T)(vec3_t(T) v1, vec3_t(T) v2, float m, float n)\
{\
	float ratio_sum = m - n;\
	if(ratio_sum == 0)\
		return v2;\
	return vec3_sub(T)(vec3_scale(T)(v1, n), vec3_scale(T)(v2, m)) / ratio_sum;\
}

/* vec3_internal_division: Calculates internal division vector
 * vec3_t(T) v1: first or left vector
 * vec3_t(T) v2: second or right vector
 * float m: left value of the ratio or numerator
 * float n: right value of the ratio or denominator
 * NOTE: if m + n = 0 then it will return second vector
 */
#define vec3_internal_division(T) c_template(vec3_internal_division, T)
#define instantiate_declaration_vec3_internal_division(T) HPML_API vec3_t(T) vec3_internal_division(T)(vec3_t)
#define instantiate_implementation_vec3_internal_division(T)\
HPML_API vec3_t(T) vec3_internal_division(T)(vec3_t(T) v1, vec3_t(T) v2, float m, float n)\
{\
	float ratio_sum = m + n;\
	if(ratio_sum == 0)\
		return v2;\
	return vec3_add(T)(vec3_scale(T)(v1, n), vec3_scale(T)(v2, m)) / ratio_sum;\
}

/* vec3_scale: Calculates a scaled vector by amount 'scalar_value'
 * vec3_t(T) v: vector3 vector to be scaled
 * float scalar_value: scalar value to be multiplied with components of v vector
 * returns: vec3_t(T) scaled vector
 */
#define vec3_scale(T) c_template(vec3_scale, T)
#define instantiate_declaration_vec3_scale(T) HPML_API vec3_t(T) vec3_scale(T)(vec3_t(T) v, T value)
#define instantiate_implementation_vec3_scale(T) HPML_API vec3_t(T) vec3_scale(T)(vec3_t(T) v, T value) { return (vec3_t(T)) { v.x * value, v.y * value, v.z * value }; }

/* vec3_magnitude: Calculates the magnitude of vector3
 * vec3_t(T) v: vector of which magnitude to be calculated
 * returns: float magnitude of vector3 v
 */
#define vec3_magnitude(T) c_template(vec3_magnitude, T)
#define instantiate_declaration_vec3_magnitude(T) HPML_API float vec3_magnitude(T)(vec3_t(T))
#define instantiate_implementation_vec3_magnitude(T) HPML_API float vec3_magnitude(T)(vec3_t(T) v) { return sqrt(v.x * v.x + v.y * v.y + v.z * v.z); }

/* vec3_sqrmagnitude: Calculates the squared magnitude of vector3
 * vec3_t(T) v: vector of which squared magnitude to be calculated
 * returns: float squared magnitude of vector3 v
 */
#define vec3_sqrmagnitude(T) c_template(vec3_sqrmagnitude, T)
#define instantiate_declaration_vec3_sqrmagnitude(T) HPML_API float vec3_sqrmagnitude(T)(vec3_t(T))
#define instantiate_implementation_vec3_sqrmagnitude(T) HPML_API float vec3_sqrmagnitude(T)(vec3_t(T) v) { return (v.x * v.x + v.y * v.y + v.z * v.z); }

/* vec3_normalize: Normalizes a vector3
 * vec3_t(T) v: vector to be normalized
 * returns: vec3_t(T) normalized vector
 */
#define vec3_normalize(T) c_template(vec3_normalize, T)
#define instantiate_declaration_vec3_normalize(T) HPML_API vec3_t(T) vec3_normalize(T)(vec3_t(T))
#define instantiate_implementation_vec3_normalize(T) HPML_API vec3_t(T) vec3_normalize(T)(vec3_t(T) v)\
{\
	float inv_mag = 1 / vec3_magnitude(T)(v);\
	return (vec3_t(T)) { v.x * inv_mag, v.y * inv_mag, v.z * inv_mag };\
}

/* vec3_angle: Calculates the angle between two vector3 vectors
 * vec3_t(T) v1: first vector involved in the angle calculation
 * vec3_t(T) v2: second vector involved in the angle calculation
 * returns: float +ve angle always
 */
#define vec3_angle(T) c_template(vec3_angle, T)
#define instantiate_declaration_vec3_angle(T) HPML_API float vec3_angle(T)(vec3_t(T) v1, vec3_t(T) v2)
#define instantiate_implementation_vec3_angle(T) HPML_API float vec3_angle(T)(vec3_t(T) v1, vec3_t(T) v2)\
{\
	float m1 = vec3_magnitude(T)(v1);\
	float m2 = vec3_magnitude(T)(v2);\
EXCEPTION_BLOCK\
(\
	if((m1 == 0) || (m2 == 0))\
		throw_exception(DIVIDE_BY_ZERO);\
)\
	return acos(vec3_dot(T)(v1, v2) / (m1 * m2));\
}

/*vec3_unit_angle*/
#define vec3_unit_angle(T) c_template(vec3_unit_angle, T)
#define instantiate_declaration_vec3_unit_angle(T) HPML_API float vec3_unit_angle(T)(vec3_t(T) v1, vec3_t(T) v2)
#define instantiate_implementation_vec3_unit_angle(T) HPML_API float vec3_unit_angle(T)(vec3_t(T) v1, vec3_t(T) v2)\
{\
	return acos(vec3_dot(T)(v1, v2));\
}

/*vec3_negate*/
#define vec3_negate(T) c_template(vec3_negate, T)
#define instantiate_declaration_vec3_negate(T) HPML_API vec3_t(T) vec3_negate(T)(vec3_t(T))
#define instantiate_implementation_vec3_negate(T) HPML_API vec3_t(T) vec3_negate(T)(vec3_t(T) v) { return (vec3_t(T)) { -v.x, -v.y, -v.z }; }

/*vec3_rotate_x*/
#define vec3_rotate_x(T) c_template(vec3_rotate_x, T)
#define instantiate_declaration_vec3_rotate_x(T) HPML_API vec3_t(T) vec3_rotate_x(T)(vec3_t(T) v, float angle)
#define instantiate_implementation_vec3_rotate_x(T) HPML_API vec3_t(T) vec3_rotate_x(T)(vec3_t(T) v, float angle)\
{\
	float c = cos(angle);\
	float s = sin(angle);\
	return (vec3_t(T)) { v.x, v.y * c - s * v.z, v.y * s + v.z * c };\
}

/*vec3_rotate_y*/
#define vec3_rotate_y(T) c_template(vec3_rotate_y, T)
#define instantiate_declaration_vec3_rotate_y(T) HPML_API vec3_t(T) vec3_rotate_y(T)(vec3_t(T) v, float angle)
#define instantiate_implementation_vec3_rotate_y(T) HPML_API vec3_t(T) vec3_rotate_y(T)(vec3_t(T) v, float angle)\
{\
	float c = cos(angle);\
	float s = sin(angle);\
	return (vec3_t(T)) { v.x * c + v.z * s, v.y, -v.x * s + v.z * c };\
}

/*vec3_rotate_z*/
#define vec3_rotate_z(T) c_template(vec3_rotate_z, T)
#define instantiate_declaration_vec3_rotate_z(T) HPML_API vec3_t(T) vec3_rotate_z(T)(vec3_t(T) v, float angle)
#define instantiate_implementation_vec3_rotate_z(T) HPML_API vec3_t(T) vec3_rotate_z(T)(vec3_t(T) v, float angle)\
{\
	float c = cos(angle);\
	float s = sin(angle);\
	return (vec3_t(T)) { v.x * c - v.y * s, v.x * s + c * v.y, v.z };\
}

/*vec3_rotate*/
#define vec3_rotate(T) c_template(vec3_rotate, T)
#define instantiate_declaration_vec3_rotate(T) HPML_API vec3_t(T) vec3_rotate(T)(vec3_t(T) v, float x, float y, float z)
#define instantiate_implementation_vec3_rotate(T) HPML_API vec3_t(T) vec3_rotate(T)(vec3_t(T) v, float x, float y, float z)\
{\
	return vec3_rotate_z(T)(vec3_rotate_y(T)(vec3_rotate_x(T)(v, x), y), z);\
}

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
#define vec3_axis_rotate(T) c_template(vec3_axis_rotate, T)
#define instantiate_declaration_vec3_axis_rotate(T) HPML_API vec3_t(T) vec3_axis_rotate(T)(vec3_t(T) v, float axisX, float axisY, float axisZ, float angle)
#define instantiate_implementation_vec3_axis_rotate(T) HPML_API vec3_t(T) vec3_axis_rotate(T)(vec3_t(T) v, float axisX, float axisY, float axisZ, float angle)\
{\
	vec3_t(T) p = vec3_unit_project(T)(v, (vec3_t(T)) { axisX, axisY, axisZ });\
 	vec3_t(T) k = vec3_sub(T)(2, v, p);\
 	vec3_t(T) j = vec3_cross(T)((vec3_t(T)) { axisX, axisY, axisZ }, k);\
 	return vec3_add(T)(3 , vec3_scale(T)(k, cos(angle)), vec3_scale(T)(j, sin(angle)), p);\
 }


/*vec3_project*/
#define vec3_project(T) c_template(vec3_project, T)
#define instantiate_declaration_vec3_project(T) HPML_API vec3_t(T) vec3_project(T)(vec3_t(T) v, vec3_t(T) a)
#define instantiate_implementation_vec3_project(T) HPML_API vec3_t(T) vec3_project(T)(vec3_t(T) v, vec3_t(T) a)\
{\
	vec3_t(T) na = vec3_normalize(T)(v);\
	return vec3_scale(T)(na, vec3_dot(T)(v, na));\
}

/*vec3_unit_project*/
#define vec3_unit_project(T) c_template(vec3_unit_project, T)
#define instantiate_declaration_vec3_unit_project(T) HPML_API vec3_t(T) vec3_unit_project(T)(vec3_t(T) v, vec3_t(T) a)
#define instantiate_implementation_vec3_unit_project(T) HPML_API vec3_t(T) vec3_unit_project(T)(vec3_t(T) v, vec3_t(T) a)\
{\
	return vec3_scale(T)(a, vec3_dot(T)(v, a));\
}

/*vec3_box*/
#define vec3_box(T) c_template(vec3_box, T)
#define instantiate_declaration_vec3_box(T) HPML_API float vec3_box(T)(vec3_t(T) from, vec3_t(T) to, vec3_t(T) height)
#define instantiate_implementation_vec3_box(T) HPML_API float vec3_box(T)(vec3_t(T) from, vec3_t(T) to, vec3_t(T) height)\
{\
	return vec3_dot(T)(height, vec3_cross(T)(from, to));\
}

/*vec3_dot*/
#define vec3_dot(T) c_template(vec3_dot, T)
#define instantiate_declaration_vec3_dot(T) HPML_API T vec3_dot(T)(vec3_t(T) v1, vec3_t(T) v2)
#define instantiate_implementation_vec3_dot(T) HPML_API T vec3_dot(T)(vec3_t(T) v1, vec3_t(T) v2)\
{\
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;\
}

/*vec3_cross*/
#define vec3_cross(T) c_template(vec3_cross, T)
#define instantiate_declaration_vec3_cross(T) HPML_API vec3_t(T) vec3_cross(T)(vec3_t(T) from, vec3_t(T) to)
#define instantiate_implementation_vec3_cross(T) HPML_API vec3_t(T) vec3_cross(T)(vec3_t(T) from, vec3_t(T) to)\
{\
	vec3_t(T) v = {\
	from.y * to.z - from.z * to.y,\
	from.x * to.z - from.z * to.x,\
	from.x * to.y - from.y * to.x,\
	};\
	return v;\
}

/*MISC*/

/* vec3_is_null: Checks if passed vector3 is null or not
 * vec3_t(T) v: vector3 to be checked for
 * returns: true if vector3 is null vector, otherwise false [boolean]
 */
#define vec3_is_null(T) c_template(vec3_is_null, T)
#define instantiate_declaration_vec3_is_null(T) HPML_API bool vec3_is_null(T)(vec3_t(T) v)
#define instantiate_implementation_vec3_is_null(T) HPML_API bool vec3_is_null(T)(vec3_t(T) v)\
{\
	return (v.x == 0) && (v.y == 0) && (v.z == 0);\
}

/* vec3_is_equal(T): Checks whether the two vectors are equal or not
 * vec3_t(T) v1: First vector to be checked against
 * vec3_t(T) v2: Second vector to be checked against
 * returns: bool true if both vectors are approximetly equal, otherwise false
 */
#define vec3_is_equal(T) c_template(vec3_is_equal, T)
#define instantiate_declaration_vec3_is_equal(T) HPML_API bool vec3_is_equal(T)(vec3_t(T) v1, vec3_t(T) v2)
#define instantiate_implementation_vec3_is_equal(T) HPML_API bool vec3_is_equal(T)(vec3_t(T) v1, vec3_t(T) v2)\
{\
	return (v1.x == v2.x) && (v1.y == v2.y) && (v1.z == v2.z);\
}

/*DEBUGGING*/

/*vec3_print*/
#define vec3_print(T) c_template(vec3_print, T)
#define instantiate_declaration_vec3_print(T) HPML_API void vec3_print(T)(vec3_t(T) v)
#define instantiate_implementation_vec3_print(T) /*specialized*/
