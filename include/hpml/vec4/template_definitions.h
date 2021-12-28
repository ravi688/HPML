
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

/*DATA*/
/*vec4_t(T) struct*/
#define vec4_t(T) template(vec4_t, T)
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
#define vec4(T) template(vec4, T)
#define instantiate_declaration_vec4(T) vec4_t(T) vec4(T)(T x, T y, T z, T w)
#define instantiate_implementation_vec4(T) vec4_t(T) vec4(T)(T x, T y, T z, T w) { return (vec4_t(T)) { x, y, z, w }; }

/*vec4_zero*/
#define vec4_zero(T) template(vec4_zero, T)
#define instantiate_declaration_vec4_zero(T) vec4_t(T) vec4_zero(T)()
#define instantiate_implementation_vec4_zero(T) vec4_t(T) vec4_zero(T)() { return (vec4_t(T)) { 0, 0, 0, 0 }; }

/*vec4_up*/
#define vec4_up(T) template(vec4_up, T)
#define instantiate_declaration_vec4_up(T) vec4_t(T) vec4_up(T)()
#define instantiate_implementation_vec4_up(T) vec4_t(T) vec4_up(T)() { return (vec4_t(T)) { 0, 1, 0, 0 }; }

/*vec4_down*/
#define vec4_down(T) template(vec4_down, T)
#define instantiate_declaration_vec4_down(T) vec4_t(T) vec4_down(T)()
#define instantiate_implementation_vec4_down(T) vec4_t(T) vec4_down(T)() { return (vec4_t(T)) { 0, -1, 0, 0 }; }

/*vec4_right*/
#define vec4_right(T) template(vec4_right, T)
#define instantiate_declaration_vec4_right(T) vec4_t(T) vec4_right(T)()
#define instantiate_implementation_vec4_right(T) vec4_t(T) vec4_right(T)() { return (vec4_t(T)) { -1, 0, 0, 0 }; }

/*vec4_left*/
#define vec4_left(T) template(vec4_left, T)
#define instantiate_declaration_vec4_left(T) vec4_t(T) vec4_left(T)()
#define instantiate_implementation_vec4_left(T) vec4_t(T) vec4_left(T)() { return (vec4_t(T)) { -1, 0, 0, 0 }; }

/*vec4_forward*/
#define vec4_forward(T) template(vec4_forward, T)
#define instantiate_declaration_vec4_forward(T) vec4_t(T) vec4_forward(T)()
#define instantiate_implementation_vec4_forward(T) vec4_t(T) vec4_forward(T)() { return (vec4_t(T)) { 0, 0, 1, 0 }; }

/*vec4_back*/
#define vec4_back(T) template(vec4_back, T)
#define instantiate_declaration_vec4_back(T) vec4_t(T) vec4_back(T)()
#define instantiate_implementation_vec4_back(T) vec4_t(T) vec4_back(T)() { return (vec4_t(T)) { 0, 0, 1, 0 }; }


/*ARITHMETIC*/
/*vec4_add*/
#define __vec4_add(T) template(__vec4_add, T)
#define vec4_add(T) template(vec4_add, T)
#define instantiate_declaration_vec4_add(T)\
vec4_t(T) __vec4_add(T)(vec4_t(T) v1, vec4_t(T) v2);\
vec4_t(T) vec4_add(T)(u32 count, ...)
#define instantiate_implementation_vec4_add(T)\
vec4_t(T) __vec4_add(T)(vec4_t(T) v1, vec4_t(T) v2) { return (vec4_t(T)) { v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w }; }\
vec4_t(T) vec4_add(T)(u32 count, ...)\
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

/*vec4_sub*/
#define __vec4_sub(T) template(__vec4_sub, T)
#define vec4_sub(T) template(vec4_sub, T)
#define instantiate_declaration_vec4_sub(T)\
vec4_t(T) __vec4_sub(T)(vec4_t(T) v1, vec4_t(T) v2);\
vec4_t(T) vec4_sub(T)(u32 count, ...)
#define instantiate_implementation_vec4_sub(T)\
vec4_t(T) __vec4_sub(T)(vec4_t(T) v1, vec4_t(T) v2) { return (vec4_t(T)) { v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w }; }\
vec4_t(T) vec4_sub(T)(u32 count, ...)\
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

/*vec4_mul*/
#define __vec4_mul(T) template(__vec4_mul, T)
#define vec4_mul(T) template(vec4_mul, T)
#define instantiate_declaration_vec4_mul(T)\
vec4_t(T) __vec4_mul(T)(vec4_t(T) v1, vec4_t(T) v2);\
vec4_t(T) vec4_mul(T)(u32 count, ...)
#define instantiate_implementation_vec4_mul(T)\
vec4_t(T) __vec4_mul(T)(vec4_t(T) v1, vec4_t(T) v2) { return (vec4_t(T)) { v1.x * v2.x, v1.y * v2.y, v1.z * v2.z, v1.w * v2.w }; }\
vec4_t(T) vec4_mul(T)(u32 count, ...)\
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

/*vec4_div*/
#define __vec4_div(T) template(__vec4_div, T)
#define vec4_div(T) template(vec4_div, T)
#define instantiate_declaration_vec4_div(T)\
vec4_t(T) __vec4_div(T)(vec4_t(T) v1, vec4_t(T) v2);\
vec4_t(T) vec4_div(T)(u32 count, ...)
#define instantiate_implementation_vec4_div(T)\
vec4_t(T) __vec4_div(T)(vec4_t(T) v1, vec4_t(T) v2) { return (vec4_t(T)) { v1.x / v2.x, v1.y / v2.y, v1.z / v2.z, v1.w / v2.w }; }\
vec4_t(T) vec4_div(T)(u32 count, ...)\
{\
	vec4_t(T) result = vec4_zero(T)();\
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
/*vec4_lerp*/
#define vec4_lerp(T) template(vec4_lerp, T)
#define instantiate_declaration_vec4_lerp(T) vec4_t(T) vec4_lerp(T)(vec4_t(T) from, vec4_t(T) to, float t)
#define instantiate_implementation_vec4_lerp(T) vec4_t(T) vec4_lerp(T)(vec4_t(T) from, vec4_t(T) to, float t)\
{\
	float _t = 1 - t;\
	return (vec4_t(T)) { from.x * _t + to.x * t, from.y * _t + to.y * t, from.z * _t + to.z * t, from.w * _t + to.w * t };\
}

/*vec4_slerp*/
#define vec4_slerp(T) template(vec4_slerp, T)
#define instantiate_declaration_vec4_slerp(T) vec4_t(T) vec4_slerp(T)(vec4_t(T) from, vec4_t(T) to, float t)
#define instantiate_implementation_vec4_slerp(T) vec4_t(T) vec4_slerp(T)(vec4_t(T) from, vec4_t(T) to, float t)\
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

/*vec4_scale*/
#define vec4_scale(T) template(vec4_scale, T)
#define instantiate_declaration_vec4_scale(T) vec4_t(T) vec4_scale(T)(vec4_t(T) v, T value)
#define instantiate_implementation_vec4_scale(T) vec4_t(T) vec4_scale(T)(vec4_t(T) v, T value) { return (vec4_t(T)) { v.x * value, v.y * value, v.z * value, v.w * value }; }

/*vec4_magnitude*/
#define vec4_magnitude(T) template(vec4_magnitude, T)
#define instantiate_declaration_vec4_magnitude(T) float vec4_magnitude(T)(vec4_t(T))
#define instantiate_implementation_vec4_magnitude(T) float vec4_magnitude(T)(vec4_t(T) v) { return sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w); }

/*vec4_sqrmagnitude*/
#define vec4_sqrmagnitude(T) template(vec4_sqrmagnitude, T)
#define instantiate_declaration_vec4_sqrmagnitude(T) float vec4_sqrmagnitude(T)(vec4_t(T))
#define instantiate_implementation_vec4_sqrmagnitude(T) float vec4_sqrmagnitude(T)(vec4_t(T) v) { return sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w); }

/*vec4_normalize*/
#define vec4_normalize(T) template(vec4_normalize, T)
#define instantiate_declaration_vec4_normalize(T) vec4_t(T) vec4_normalize(T)(vec4_t(T))
#define instantiate_implementation_vec4_normalize(T) vec4_t(T) vec4_normalize(T)(vec4_t(T) v)\
{\
	float inv_mag = 1 / vec4_magnitude(T)(v);\
	return (vec4_t(T)) { v.x * inv_mag, v.y * inv_mag, v.z * inv_mag, v.w * inv_mag };\
}

/*vec4_angle*/
/*
v1 dot v2 = mag(v1) * mag(v2) * cos(angle)
angle = acos((v1 dot v2) / mag(v1)mag(v2))
*/
#define vec4_angle(T) template(vec4_angle, T)
#define instantiate_declaration_vec4_angle(T) float vec4_angle(T)(vec4_t(T) v1, vec4_t(T) v2)
#define instantiate_implementation_vec4_angle(T) float vec4_angle(T)(vec4_t(T) v1, vec4_t(T) v2)\
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
#define vec4_unit_angle(T) template(vec4_unit_angle, T)
#define instantiate_declaration_vec4_unit_angle(T) float vec4_unit_angle(T)(vec4_t(T) v1, vec4_t(T) v2)
#define instantiate_implementation_vec4_unit_angle(T) float vec4_unit_angle(T)(vec4_t(T) v1, vec4_t(T) v2)\
{\
	return acos(vec4_dot(T)(v1, v2));\
}

/*vec4_negate*/
#define vec4_negate(T) template(vec4_negate, T)
#define instantiate_declaration_vec4_negate(T) vec4_t(T) vec4_negate(T)(vec4_t(T))
#define instantiate_implementation_vec4_negate(T) vec4_t(T) vec4_negate(T)(vec4_t(T) v) { return (vec4_t(T)) { -v.x, -v.y, -v.z, -v.w }; }

/*vec4_rotate_x*/
#define vec4_rotate_x(T) template(vec4_rotate_x, T)
#define instantiate_declaration_vec4_rotate_x(T) vec4_t(T) vec4_rotate_x(T)(vec4_t(T) v, float angle)
#define instantiate_implementation_vec4_rotate_x(T) vec4_t(T) vec4_rotate_x(T)(vec4_t(T) v, float angle)\
{\
	float c = cos(angle);\
	float s = sin(angle);\
	return (vec4_t(T)) { v.x, v.y * c - s * v.z, v.y * s + v.z * c, v.w };\
}

/*vec4_rotate_y*/
#define vec4_rotate_y(T) template(vec4_rotate_y, T)
#define instantiate_declaration_vec4_rotate_y(T) vec4_t(T) vec4_rotate_y(T)(vec4_t(T) v, float angle)
#define instantiate_implementation_vec4_rotate_y(T) vec4_t(T) vec4_rotate_y(T)(vec4_t(T) v, float angle)\
{\
	float c = cos(angle);\
	float s = sin(angle);\
	return (vec4_t(T)) { v.x * c + v.z * s, v.y, -v.x * s + v.z * c, v.w };\
}

/*vec4_rotate_z*/
#define vec4_rotate_z(T) template(vec4_rotate_z, T)
#define instantiate_declaration_vec4_rotate_z(T) vec4_t(T) vec4_rotate_z(T)(vec4_t(T) v, float angle)
#define instantiate_implementation_vec4_rotate_z(T) vec4_t(T) vec4_rotate_z(T)(vec4_t(T) v, float angle)\
{\
	float c = cos(angle);\
	float s = sin(angle);\
	return (vec4_t(T)) { v.x * c - v.y * s, v.x * s + c * v.y, v.z, v.w };\
}

/*vec4_rotate*/
#define vec4_rotate(T) template(vec4_rotate, T)
#define instantiate_declaration_vec4_rotate(T) vec4_t(T) vec4_rotate(T)(vec4_t(T) v, float x, float y, float z)
#define instantiate_implementation_vec4_rotate(T) vec4_t(T) vec4_rotate(T)(vec4_t(T) v, float x, float y, float z)\
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
#define vec4_axis_rotate(T) template(vec4_axis_rotate, T)
#define instantiate_declaration_vec4_axis_rotate(T) vec4_t(T) vec4_axis_rotate(T)(vec4_t(T) v, float axisX, float axisY, float axisZ, float angle)
#define instantiate_implementation_vec4_axis_rotate(T) vec4_t(T) vec4_axis_rotate(T)(vec4_t(T) v, float axisX, float axisY, float axisZ, float angle)\
{\
	vec4_t(T) p = vec4_unit_project(T)(v, (vec4_t(T)) { axisX, axisY, axisZ, 0 });\
 	vec4_t(T) k = vec4_sub(T)(2, v, p);\
 	vec4_t(T) j = vec4_cross(T)((vec4_t(T)) { axisX, axisY, axisZ, 0}, k);\
 	return vec4_add(T)(3 , vec4_scale(T)(k, cos(angle)), vec4_scale(T)(j, sin(angle)), p);\
 }


/*vec4_project*/
#define vec4_project(T) template(vec4_project, T)
#define instantiate_declaration_vec4_project(T) vec4_t(T) vec4_project(T)(vec4_t(T) v, vec4_t(T) a)
#define instantiate_implementation_vec4_project(T) vec4_t(T) vec4_project(T)(vec4_t(T) v, vec4_t(T) a)\
{\
	vec4_t(T) na = vec4_normalize(T)(v);\
	return vec4_scale(T)(na, vec4_dot(T)(v, na));\
}

/*vec4_unit_project*/
#define vec4_unit_project(T) template(vec4_unit_project, T)
#define instantiate_declaration_vec4_unit_project(T) vec4_t(T) vec4_unit_project(T)(vec4_t(T) v, vec4_t(T) a)
#define instantiate_implementation_vec4_unit_project(T) vec4_t(T) vec4_unit_project(T)(vec4_t(T) v, vec4_t(T) a)\
{\
	return vec4_scale(T)(a, vec4_dot(T)(v, a));\
}

/*vec4_box*/
#define vec4_box(T) template(vec4_box, T)
#define instantiate_declaration_vec4_box(T) float vec4_box(T)(vec4_t(T) from, vec4_t(T) to, vec4_t(T) height)
#define instantiate_implementation_vec4_box(T) float vec4_box(T)(vec4_t(T) from, vec4_t(T) to, vec4_t(T) height)\
{\
	return vec4_dot(T)(height, vec4_cross(T)(from, to));\
}

/*vec4_dot*/
#define vec4_dot(T) template(vec4_dot, T)
#define instantiate_declaration_vec4_dot(T) T vec4_dot(T)(vec4_t(T) v1, vec4_t(T) v2)
#define instantiate_implementation_vec4_dot(T) T vec4_dot(T)(vec4_t(T) v1, vec4_t(T) v2)\
{\
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;\
}

/*vec4_cross*/
#define vec4_cross(T) template(vec4_cross, T)
#define instantiate_declaration_vec4_cross(T) vec4_t(T) vec4_cross(T)(vec4_t(T) from, vec4_t(T) to)
#define instantiate_implementation_vec4_cross(T) vec4_t(T) vec4_cross(T)(vec4_t(T) from, vec4_t(T) to)\
{\
	vec4_t(T) v = {\
	from.y * to.z - from.z * to.y,\
	from.x * to.z - from.z * to.x,\
	from.x * to.y - from.y * to.x,\
	};\
	return v;\
}

/*DEBUGGING*/

/*vec4_print*/
#define vec4_print(T) template(vec4_print, T)
#define instantiate_declaration_vec4_print(T) void vec4_print(T)(vec4_t(T) v)
#define instantiate_implementation_vec4_print(T) /*specialized*/
