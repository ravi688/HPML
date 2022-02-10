
#pragma once

#ifdef VEC4_ENABLE_SIMD_ACCELERATION
#warning "VEC4_ENABLE_SIMD_ACCELERATION switch is enabled but SIMD acceleration isn't supported!"
#endif

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
/*vec4_t(T) struct*/
#define vec4_t(T) c_template(vec4_t, T)
#define instantiate_vec4_struct(T)\
typedef struct\
{\
	T x;\
	T y;\
	T z;\
	T w;\
} vec4_t(T)

/*CONSTRUCTOR*/
/*vec4*/
#define vec4(T) c_template(vec4, T)
#define instantiate_declaration_vec4(T) HPML_API vec4_t(T) vec4(T)(T x, T y, T z, T w)
#define instantiate_implementation_vec4(T) HPML_API vec4_t(T) vec4(T)(T x, T y, T z, T w) { return (vec4_t(T)) { x, y, z, w }; }

/* vec4_zero: Creates a vector3 object in memory having x = 0, and y = 0
 * returns: vec4_t(T) vector having x = 0, y = 0
 */
#define vec4_zero(T) c_template(vec4_zero, T)
#define instantiate_declaration_vec4_zero(T) HPML_API vec4_t(T) vec4_zero(T)()
#define instantiate_implementation_vec4_zero(T) HPML_API vec4_t(T) vec4_zero(T)() { return (vec4_t(T)) { 0, 0, 0, 0 }; }

/* vec4_up: Returns the up direction vector (vector4)
 * returns: vec4_t(T) up direction, i.e. Vector4.up [+ve y axis direction]
 */
#define vec4_up(T) c_template(vec4_up, T)
#define instantiate_declaration_vec4_up(T) HPML_API vec4_t(T) vec4_up(T)()
#define instantiate_implementation_vec4_up(T) HPML_API vec4_t(T) vec4_up(T)() { return (vec4_t(T)) { 0, 1, 0, 0 }; }

/* vec4_down: Returns the down direction vector (vector4)
 * returns: vec4_t(T) down direction, i.e. Vector4.down [-ve y axis direction]
 */
#define vec4_down(T) c_template(vec4_down, T)
#define instantiate_declaration_vec4_down(T) HPML_API vec4_t(T) vec4_down(T)()
#define instantiate_implementation_vec4_down(T) HPML_API vec4_t(T) vec4_down(T)() { return (vec4_t(T)) { 0, -1, 0, 0 }; }

/* vec4_right: Returns the right direction vector (vector4)
 * returns: vec4_t(T) right direction, i.e. Vector4.right [+ve x axis direction]
 */
#define vec4_right(T) c_template(vec4_right, T)
#define instantiate_declaration_vec4_right(T) HPML_API vec4_t(T) vec4_right(T)()
#define instantiate_implementation_vec4_right(T) HPML_API vec4_t(T) vec4_right(T)() { return (vec4_t(T)) { 1, 0, 0, 0 }; }

/*vec4_left*/
#define vec4_left(T) c_template(vec4_left, T)
#define instantiate_declaration_vec4_left(T) HPML_API vec4_t(T) vec4_left(T)()
#define instantiate_implementation_vec4_left(T) HPML_API vec4_t(T) vec4_left(T)() { return (vec4_t(T)) { -1, 0, 0, 0 }; }

/* vec4_forward: Returns the forward direction vector (vector4)
 * returns: vec4_t(T) forward direction, i.e. Vector4.forward [+ve z axis direction]
 */
#define vec4_forward(T) c_template(vec4_forward, T)
#define instantiate_declaration_vec4_forward(T) HPML_API vec4_t(T) vec4_forward(T)()
#define instantiate_implementation_vec4_forward(T) HPML_API vec4_t(T) vec4_forward(T)() { return (vec4_t(T)) { 0, 0, 1, 0 }; }

/* vec4_back: Return the backward direction vector (vector4)
 * returns: vec4_t(T) backward direction, i.e. Vector4.back [-ve z axis direction]
 */
#define vec4_back(T) c_template(vec4_back, T)
#define instantiate_declaration_vec4_back(T) HPML_API vec4_t(T) vec4_back(T)()
#define instantiate_implementation_vec4_back(T) HPML_API vec4_t(T) vec4_back(T)() { return (vec4_t(T)) { 0, 0, 1, 0 }; }

/*vec4_one*/
#define vec4_one(T) c_template(vec4_one, T)
#define instantiate_declaration_vec4_one(T) HPML_API vec4_t(T) vec4_one(T)()
#define instantiate_implementation_vec4_one(T) HPML_API vec4_t(T) vec4_one(T)() { return (vec4_t(T)) { 1, 1, 1, 1 }; }


/*ARITHMETIC*/

/* vec4_add: Adds the rest of the vectors to the first vector in the variable arguments list
 * u32 count: number of vectors involved in the addition
 * ... : variable number of vectors
 * returns: vec4_t(T) resulting vector3 vector
 */
#define __vec4_add(T) c_template(__vec4_add, T)
#define vec4_add(T) c_template(vec4_add, T)
#define instantiate_declaration_vec4_add(T)\
HPML_API vec4_t(T) __vec4_add(T)(vec4_t(T) v1, vec4_t(T) v2);\
HPML_API vec4_t(T) vec4_add(T)(u32 count, ...)
#define instantiate_implementation_vec4_add(T)\
HPML_API vec4_t(T) __vec4_add(T)(vec4_t(T) v1, vec4_t(T) v2) { return (vec4_t(T)) { v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w }; }\
HPML_API vec4_t(T) vec4_add(T)(u32 count, ...)\
{\
	vec4_t(T) result = vec4_zero(T)();\
	va_list args;\
	va_start(args, count);\
	while(count > 0)\
	{\
		result = __vec4_add(T)(result, va_arg(args, vec4_t(T)));\
		--count;\
	}\
	va_end(args);\
	return result;\
}

/* vec4_sub: Subtracts the rest of the vectors from the first vector in the variable arguments list
 * u32 count: number of vectors involved in the subtraction
 * ... : variable number of vectors
 * returns: vec4_t(T) resulting vector3 vector
 */
#define __vec4_sub(T) c_template(__vec4_sub, T)
#define vec4_sub(T) c_template(vec4_sub, T)
#define instantiate_declaration_vec4_sub(T)\
HPML_API vec4_t(T) __vec4_sub(T)(vec4_t(T) v1, vec4_t(T) v2);\
HPML_API vec4_t(T) vec4_sub(T)(u32 count, ...)
#define instantiate_implementation_vec4_sub(T)\
HPML_API vec4_t(T) __vec4_sub(T)(vec4_t(T) v1, vec4_t(T) v2) { return (vec4_t(T)) { v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w }; }\
HPML_API vec4_t(T) vec4_sub(T)(u32 count, ...)\
{\
	vec4_t(T) result = vec4_zero(T)();\
	va_list args;\
	va_start(args, count);\
	while(count > 0)\
	{\
		result = __vec4_sub(T)(result, va_arg(args, vec4_t(T)));\
		--count;\
	}\
	va_end(args);\
	return result;\
}

/* vec4_mul: Multiplies the first vector by the rest of the vectors in the variable arguments list
 * u32 count: number of vectors involved in the multiplication
 * ... : variable number of vectors
 * returns: vec4_t(T) resulting vector3 vector
 */
#define __vec4_mul(T) c_template(__vec4_mul, T)
#define vec4_mul(T) c_template(vec4_mul, T)
#define instantiate_declaration_vec4_mul(T)\
HPML_API vec4_t(T) __vec4_mul(T)(vec4_t(T) v1, vec4_t(T) v2);\
HPML_API vec4_t(T) vec4_mul(T)(u32 count, ...)
#define instantiate_implementation_vec4_mul(T)\
HPML_API vec4_t(T) __vec4_mul(T)(vec4_t(T) v1, vec4_t(T) v2) { return (vec4_t(T)) { v1.x * v2.x, v1.y * v2.y, v1.z * v2.z, v1.w * v2.w }; }\
HPML_API vec4_t(T) vec4_mul(T)(u32 count, ...)\
{\
	vec4_t(T) result = vec4_zero(T)();\
	va_list args;\
	va_start(args, count);\
	while(count > 0)\
	{\
		result = __vec4_mul(T)(result, va_arg(args, vec4_t(T)));\
		--count;\
	}\
	va_end(args);\
	return result;\
}

/* vec4_div: Divides the first vector by the rest of the vectors in the variable arguments list
 * u32 count: number of vectors involved in the division
 * ... : variable number of vectors
 * returns: vec4_t(T) resulting vector3 vector
 * exceptions: throws DIVIDE_BY_ZERO exception if any of the vectors are null except the first vector in the variable arguments list
 */
#define __vec4_div(T) c_template(__vec4_div, T)
#define vec4_div(T) c_template(vec4_div, T)
#define instantiate_declaration_vec4_div(T)\
HPML_API vec4_t(T) __vec4_div(T)(vec4_t(T) v1, vec4_t(T) v2);\
HPML_API vec4_t(T) vec4_div(T)(u32 count, ...)
#define instantiate_implementation_vec4_div(T)\
HPML_API vec4_t(T) __vec4_div(T)(vec4_t(T) v1, vec4_t(T) v2)\
{\
	EXCEPTION_BLOCK\
	(\
	if(vec4_is_null(T)(v2))\
		THROW_EXCEPTION(DIVIDE_BY_ZERO);\
	)\
	return (vec4_t(T)) { v1.x / v2.x, v1.y / v2.y, v1.z / v2.z, v1.w / v2.w };\
}\
HPML_API vec4_t(T) vec4_div(T)(u32 count, ...)\
{\
	vec4_t(T) result = vec4_one(T)();\
	va_list args;\
	va_start(args, count);\
	while(count > 0)\
	{\
		result = __vec4_div(T)(result, va_arg(args, vec4_t(T)));\
		--count;\
	}\
	va_end(args);\
	return result;\
}

/*INTERPOLATION*/

/* vec4_lerp: Calculates an interpolated vector from vector v1 to vector v2, having interpolation value 'interpolation_value'
 * vec4_t(T) v1: from vector
 * vec4_t(T) v2: to vector
 * float interpolation_value: interpolation value [Range (0, 1)], inclusive of 0 and 1
 * returns: vec4_t(T) interpolated vector
 */
#define vec4_lerp(T) c_template(vec4_lerp, T)
#define instantiate_declaration_vec4_lerp(T) HPML_API vec4_t(T) vec4_lerp(T)(vec4_t(T) from, vec4_t(T) to, float t)
#define instantiate_implementation_vec4_lerp(T) HPML_API vec4_t(T) vec4_lerp(T)(vec4_t(T) from, vec4_t(T) to, float t)\
{\
	float _t = 1 - t;\
	return (vec4_t(T)) { from.x * _t + to.x * t, from.y * _t + to.y * t, from.z * _t + to.z * t, from.w * _t + to.w * t };\
}

/* vec4_slerp(T): Calculates spherical interpolation value in-between the vector v1 and v2
 * vec4_t(T) v1: First vector [from]
 * vec4_t(T) v2: Second vector [to]
 * T slerp_value: interpolation parameter
 * returns: vec4_t(T) spherically interpolated value
 */
#define vec4_slerp(T) c_template(vec4_slerp, T)
#define instantiate_declaration_vec4_slerp(T) HPML_API vec4_t(T) vec4_slerp(T)(vec4_t(T) from, vec4_t(T) to, float t)
#define instantiate_implementation_vec4_slerp(T) HPML_API vec4_t(T) vec4_slerp(T)(vec4_t(T) from, vec4_t(T) to, float t)\
{\
	float angle = vec4_angle(T)(from, to);\
	EXCEPTION_BLOCK\
	(\
		if((angle == 0) || (angle == 3.145926f) || (angle == 2 * 3.145926f))\
			THROW_EXCEPTION(DIVIDE_BY_ZERO);\
	)\
	float inv_sin_angle = 1 / sin(angle);\
	float temp = t * angle;\
	return vec4_add(T)(2, vec4_scale(T)(from, sin(angle - temp) * inv_sin_angle), vec4_scale(T)(to, sin(temp)));\
}

/*ALGEBRA*/

/*vec4_direction_ratios*/
#define vec4_direction_ratios(T) c_template(vec4_direction_ratios, T)
#define instantiate_declaration_vec4_direction_ratios(T) HPML_API vec4_t(T) vec4_direction_ratios(T)(vec4_t(T))
#define instantiate_implementation_vec4_direction_ratios(T) HPML_API vec4_t(T) vec4_direction_ratios(T)(vec4_t(T) v)\
{\
	float inv_mag = 1 / vec4_magnitude(T)(v);\
	return vec4_scale(T)(v, inv_mag);\
}

/* vec4_external_division: Calculates external division vector
 * vec4_t(T) v1: first or left vector
 * vec4_t(T) v2: second or right vector
 * float m: left value of the ratio or numerator
 * float n: right value of the ratio or denominator
 * NOTE: if m - n = 0 then it will return second vector
 */
#define vec4_external_division(T) c_template(vec4_external_division, T)
#define instantiate_declaration_vec4_external_division(T) HPML_API vec4_t(T) vec4_internal_division(T)(vec4_t)
#define instantiate_implementation_vec4_external_division(T)\
HPML_API vec4_t(T) vec4_external_division(T)(vec4_t(T) v1, vec4_t(T) v2, float m, float n)\
{\
	float ratio_sum = m - n;\
	if(ratio_sum == 0)\
		return v2;\
	return vec4_sub(T)(vec4_scale(T)(v1, n), vec4_scale(T)(v2, m)) / ratio_sum;\
}

/* vec4_internal_division: Calculates internal division vector
 * vec4_t(T) v1: first or left vector
 * vec4_t(T) v2: second or right vector
 * float m: left value of the ratio or numerator
 * float n: right value of the ratio or denominator
 * NOTE: if m + n = 0 then it will return second vector
 */
#define vec4_internal_division(T) c_template(vec4_internal_division, T)
#define instantiate_declaration_vec4_internal_division(T) HPML_API vec4_t(T) vec4_internal_division(T)(vec4_t)
#define instantiate_implementation_vec4_internal_division(T)\
HPML_API vec4_t(T) vec4_internal_division(T)(vec4_t(T) v1, vec4_t(T) v2, float m, float n)\
{\
	float ratio_sum = m + n;\
	if(ratio_sum == 0)\
		return v2;\
	return vec4_add(T)(vec4_scale(T)(v1, n), vec4_scale(T)(v2, m)) / ratio_sum;\
}

/* vec4_scale: Calculates a scaled vector by amount 'scalar_value'
 * vec4_t(T) v: vector3 vector to be scaled
 * float scalar_value: scalar value to be multiplied with components of v vector
 * returns: vec4_t(T) scaled vector
 */
#define vec4_scale(T) c_template(vec4_scale, T)
#define instantiate_declaration_vec4_scale(T) HPML_API vec4_t(T) vec4_scale(T)(vec4_t(T) v, T value)
#define instantiate_implementation_vec4_scale(T) HPML_API vec4_t(T) vec4_scale(T)(vec4_t(T) v, T value) { return (vec4_t(T)) { v.x * value, v.y * value, v.z * value, v.w * value }; }

/* vec4_magnitude: Calculates the magnitude of vector3
 * vec4_t(T) v: vector of which magnitude to be calculated
 * returns: float magnitude of vector4 v
 */
#define vec4_magnitude(T) c_template(vec4_magnitude, T)
#define instantiate_declaration_vec4_magnitude(T) HPML_API float vec4_magnitude(T)(vec4_t(T))
#define instantiate_implementation_vec4_magnitude(T) HPML_API float vec4_magnitude(T)(vec4_t(T) v) { return sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w); }

/* vec4_magnitude: Calculates the squared magnitude of vector3
 * vec4_t(T) v: vector of which squared magnitude to be calculated
 * returns: float squared magnitude of vector4 v
 */
#define vec4_sqrmagnitude(T) c_template(vec4_sqrmagnitude, T)
#define instantiate_declaration_vec4_sqrmagnitude(T) HPML_API float vec4_sqrmagnitude(T)(vec4_t(T))
#define instantiate_implementation_vec4_sqrmagnitude(T) HPML_API float vec4_sqrmagnitude(T)(vec4_t(T) v) { return sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w); }

/* vec4_normalize: Normalizes a vector3
 * vec4_t(T) v: vector to be normalized
 * returns: vec4_t(T) normalized vector
 */
#define vec4_normalize(T) c_template(vec4_normalize, T)
#define instantiate_declaration_vec4_normalize(T) HPML_API vec4_t(T) vec4_normalize(T)(vec4_t(T))
#define instantiate_implementation_vec4_normalize(T) HPML_API vec4_t(T) vec4_normalize(T)(vec4_t(T) v)\
{\
	float inv_mag = 1 / vec4_magnitude(T)(v);\
	return (vec4_t(T)) { v.x * inv_mag, v.y * inv_mag, v.z * inv_mag, v.w * inv_mag };\
}

/* vec4_angle: Calculates the angle between two vector3 vectors
 * vec4_t(T) v1: first vector involved in the angle calculation
 * vec4_t(T) v2: second vector involved in the angle calculation
 * returns: float +ve angle always
 */
#define vec4_angle(T) c_template(vec4_angle, T)
#define instantiate_declaration_vec4_angle(T) HPML_API float vec4_angle(T)(vec4_t(T) v1, vec4_t(T) v2)
#define instantiate_implementation_vec4_angle(T) HPML_API float vec4_angle(T)(vec4_t(T) v1, vec4_t(T) v2)\
{\
	float m1 = vec4_magnitude(T)(v1);\
	float m2 = vec4_magnitude(T)(v2);\
EXCEPTION_BLOCK\
(\
	if((m1 == 0) || (m2 == 0))\
		throw_exception(DIVIDE_BY_ZERO);\
)\
	return acos(vec4_dot(T)(v1, v2) / (m1 * m2));\
}

/*vec4_unit_angle*/
#define vec4_unit_angle(T) c_template(vec4_unit_angle, T)
#define instantiate_declaration_vec4_unit_angle(T) HPML_API float vec4_unit_angle(T)(vec4_t(T) v1, vec4_t(T) v2)
#define instantiate_implementation_vec4_unit_angle(T) HPML_API float vec4_unit_angle(T)(vec4_t(T) v1, vec4_t(T) v2)\
{\
	return acos(vec4_dot(T)(v1, v2));\
}

/*vec4_negate*/
#define vec4_negate(T) c_template(vec4_negate, T)
#define instantiate_declaration_vec4_negate(T) HPML_API vec4_t(T) vec4_negate(T)(vec4_t(T))
#define instantiate_implementation_vec4_negate(T) HPML_API vec4_t(T) vec4_negate(T)(vec4_t(T) v) { return (vec4_t(T)) { -v.x, -v.y, -v.z, -v.w }; }

/*vec4_rotate_x*/
#define vec4_rotate_x(T) c_template(vec4_rotate_x, T)
#define instantiate_declaration_vec4_rotate_x(T) HPML_API vec4_t(T) vec4_rotate_x(T)(vec4_t(T) v, float angle)
#define instantiate_implementation_vec4_rotate_x(T) HPML_API vec4_t(T) vec4_rotate_x(T)(vec4_t(T) v, float angle)\
{\
	float c = cos(angle);\
	float s = sin(angle);\
	return (vec4_t(T)) { v.x, v.y * c - s * v.z, v.y * s + v.z * c, v.w };\
}

/*vec4_rotate_y*/
#define vec4_rotate_y(T) c_template(vec4_rotate_y, T)
#define instantiate_declaration_vec4_rotate_y(T) HPML_API vec4_t(T) vec4_rotate_y(T)(vec4_t(T) v, float angle)
#define instantiate_implementation_vec4_rotate_y(T) HPML_API vec4_t(T) vec4_rotate_y(T)(vec4_t(T) v, float angle)\
{\
	float c = cos(angle);\
	float s = sin(angle);\
	return (vec4_t(T)) { v.x * c + v.z * s, v.y, -v.x * s + v.z * c, v.w };\
}

/*vec4_rotate_z*/
#define vec4_rotate_z(T) c_template(vec4_rotate_z, T)
#define instantiate_declaration_vec4_rotate_z(T) HPML_API vec4_t(T) vec4_rotate_z(T)(vec4_t(T) v, float angle)
#define instantiate_implementation_vec4_rotate_z(T) HPML_API vec4_t(T) vec4_rotate_z(T)(vec4_t(T) v, float angle)\
{\
	float c = cos(angle);\
	float s = sin(angle);\
	return (vec4_t(T)) { v.x * c - v.y * s, v.x * s + c * v.y, v.z, v.w };\
}

/*vec4_rotate*/
#define vec4_rotate(T) c_template(vec4_rotate, T)
#define instantiate_declaration_vec4_rotate(T) HPML_API vec4_t(T) vec4_rotate(T)(vec4_t(T) v, float x, float y, float z)
#define instantiate_implementation_vec4_rotate(T) HPML_API vec4_t(T) vec4_rotate(T)(vec4_t(T) v, float x, float y, float z)\
{\
	return vec4_rotate_z(T)(vec4_rotate_y(T)(vec4_rotate_x(T)(v, x), y), z);\
}

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
#define vec4_axis_rotate(T) c_template(vec4_axis_rotate, T)
#define instantiate_declaration_vec4_axis_rotate(T) HPML_API vec4_t(T) vec4_axis_rotate(T)(vec4_t(T) v, float axisX, float axisY, float axisZ, float angle)
#define instantiate_implementation_vec4_axis_rotate(T) HPML_API vec4_t(T) vec4_axis_rotate(T)(vec4_t(T) v, float axisX, float axisY, float axisZ, float angle)\
{\
	vec4_t(T) p = vec4_unit_project(T)(v, (vec4_t(T)) { axisX, axisY, axisZ, 0 });\
 	vec4_t(T) k = vec4_sub(T)(2, v, p);\
 	vec4_t(T) j = vec4_cross(T)((vec4_t(T)) { axisX, axisY, axisZ, 0}, k);\
 	return vec4_add(T)(3 , vec4_scale(T)(k, cos(angle)), vec4_scale(T)(j, sin(angle)), p);\
 }


/*vec4_project*/
#define vec4_project(T) c_template(vec4_project, T)
#define instantiate_declaration_vec4_project(T) HPML_API vec4_t(T) vec4_project(T)(vec4_t(T) v, vec4_t(T) a)
#define instantiate_implementation_vec4_project(T) HPML_API vec4_t(T) vec4_project(T)(vec4_t(T) v, vec4_t(T) a)\
{\
	vec4_t(T) na = vec4_normalize(T)(v);\
	return vec4_scale(T)(na, vec4_dot(T)(v, na));\
}

/*vec4_unit_project*/
#define vec4_unit_project(T) c_template(vec4_unit_project, T)
#define instantiate_declaration_vec4_unit_project(T) HPML_API vec4_t(T) vec4_unit_project(T)(vec4_t(T) v, vec4_t(T) a)
#define instantiate_implementation_vec4_unit_project(T) HPML_API vec4_t(T) vec4_unit_project(T)(vec4_t(T) v, vec4_t(T) a)\
{\
	return vec4_scale(T)(a, vec4_dot(T)(v, a));\
}

/*vec4_box*/
#define vec4_box(T) c_template(vec4_box, T)
#define instantiate_declaration_vec4_box(T) HPML_API float vec4_box(T)(vec4_t(T) from, vec4_t(T) to, vec4_t(T) height)
#define instantiate_implementation_vec4_box(T) HPML_API float vec4_box(T)(vec4_t(T) from, vec4_t(T) to, vec4_t(T) height)\
{\
	return vec4_dot(T)(height, vec4_cross(T)(from, to));\
}

/*vec4_dot*/
#define vec4_dot(T) c_template(vec4_dot, T)
#define instantiate_declaration_vec4_dot(T) HPML_API T vec4_dot(T)(vec4_t(T) v1, vec4_t(T) v2)
#define instantiate_implementation_vec4_dot(T) HPML_API T vec4_dot(T)(vec4_t(T) v1, vec4_t(T) v2)\
{\
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;\
}

/*vec4_cross*/
#define vec4_cross(T) c_template(vec4_cross, T)
#define instantiate_declaration_vec4_cross(T) HPML_API vec4_t(T) vec4_cross(T)(vec4_t(T) from, vec4_t(T) to)
#define instantiate_implementation_vec4_cross(T) HPML_API vec4_t(T) vec4_cross(T)(vec4_t(T) from, vec4_t(T) to)\
{\
	vec4_t(T) v = {\
	from.y * to.z - from.z * to.y,\
	from.x * to.z - from.z * to.x,\
	from.x * to.y - from.y * to.x,\
	};\
	return v;\
}

/*MISC*/

/* vec4_is_null: Checks if passed vector3 is null or not
 * vec4_t(T) v: vector3 to be checked for
 * returns: true if vector3 is null vector, otherwise false [boolean]
 */
#define vec4_is_null(T) c_template(vec4_is_null, T)
#define instantiate_declaration_vec4_is_null(T) HPML_API bool vec4_is_null(T)(vec4_t(T) v)
#define instantiate_implementation_vec4_is_null(T) HPML_API bool vec4_is_null(T)(vec4_t(T) v)\
{\
	return (v.x == 0) && (v.y == 0) && (v.z == 0) && (v.w == 0);\
}

/* vec4_is_equal(T): Checks whether the two vectors are equal or not
 * vec4_t(T) v1: First vector to be checked against
 * vec4_t(T) v2: Second vector to be checked against
 * returns: bool true if both vectors are approximetly equal, otherwise false
 */
#define vec4_is_equal(T) c_template(vec4_is_equal, T)
#define instantiate_declaration_vec4_is_equal(T) HPML_API bool vec4_is_equal(T)(vec4_t(T) v1, vec4_t(T) v2)
#define instantiate_implementation_vec4_is_equal(T) HPML_API bool vec4_is_equal(T)(vec4_t(T) v1, vec4_t(T) v2)\
{\
	return (v1.x == v2.x) && (v1.y == v2.y) && (v1.z == v2.z) && (v1.w == v2.w);\
}

/*DEBUGGING*/

/*vec4_print*/
#define vec4_print(T) c_template(vec4_print, T)
#define instantiate_declaration_vec4_print(T) HPML_API void vec4_print(T)(vec4_t(T) v)
#define instantiate_implementation_vec4_print(T) /*specialized*/
