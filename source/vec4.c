
#include <hpml/vec4.h>

#include <hpml/exception/exception.h>
#include <math.h>
#include <stdarg.h>

HPML_API vec4_t __vec4_add(vec4_t v1, vec4_t v2) { return (vec4_t) { v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w }; }

HPML_API vec4_t vec4_add(u32 count, ...)
{
	vec4_t result = vec4_zero();
	va_list args;
	va_start(args, count);
	while(count > 0)
	{
		result = __vec4_add(result, va_arg(args, vec4_t));
		--count;
	}
	va_end(args);
	return result;
}

HPML_API vec4_t __vec4_sub(vec4_t v1, vec4_t v2) { return (vec4_t) { v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w }; }

HPML_API vec4_t vec4_sub(u32 count, ...)
{
	vec4_t result = vec4_zero();
	va_list args;
	va_start(args, count);
	while(count > 0)
	{
		result = __vec4_sub(result, va_arg(args, vec4_t));
		--count;
	}
	va_end(args);
	return result;
}

HPML_API vec4_t __vec4_mul(vec4_t v1, vec4_t v2) { return (vec4_t) { v1.x * v2.x, v1.y * v2.y, v1.z * v2.z, v1.w * v2.w }; }

HPML_API vec4_t vec4_mul(u32 count, ...)
{
	vec4_t result = vec4_zero();
	va_list args;
	va_start(args, count);
	while(count > 0)
	{
		result = __vec4_mul(result, va_arg(args, vec4_t));
		--count;
	}
	va_end(args);
	return result;
}

HPML_API vec4_t __vec4_div(vec4_t v1, vec4_t v2)
{
	EXCEPTION_BLOCK
	(
	if(vec4_is_null(v2))
		THROW_EXCEPTION(DIVIDE_BY_ZERO);
	)
	return (vec4_t) { v1.x / v2.x, v1.y / v2.y, v1.z / v2.z, v1.w / v2.w };
}

HPML_API vec4_t vec4_div(u32 count, ...)
{
	vec4_t result = vec4_one();
	va_list args;
	va_start(args, count);
	while(count > 0)
	{
		result = __vec4_div(result, va_arg(args, vec4_t));
		--count;
	}
	va_end(args);
	return result;
}

HPML_API vec4_t vec4_lerp(vec4_t from, vec4_t to, float t)
{
	float _t = 1 - t;
	return (vec4_t) { from.x * _t + to.x * t, from.y * _t + to.y * t, from.z * _t + to.z * t, from.w * _t + to.w * t };
}

HPML_API vec4_t vec4_slerp(vec4_t from, vec4_t to, float t)
{
	float angle = vec4_angle(from, to);
	EXCEPTION_BLOCK
	(
		if((angle == 0) || (angle == 3.145926f) || (angle == 2 * 3.145926f))
			THROW_EXCEPTION(DIVIDE_BY_ZERO);
	)
	float inv_sin_angle = 1 / sin(angle);
	float temp = t * angle;
	return vec4_add(2, vec4_scale(from, sin(angle - temp) * inv_sin_angle), vec4_scale(to, sin(temp)));
}

HPML_API vec4_t vec4_direction_ratios(vec4_t v)
{
	float inv_mag = 1 / vec4_magnitude(v);
	return vec4_scale(v, inv_mag);
}

HPML_API vec4_t vec4_external_division(vec4_t v1, vec4_t v2, float m, float n)
{
	float ratio_sum = m - n;
	if(ratio_sum == 0)
		return v2;
	return vec4_scale(vec4_sub(2, vec4_scale(v1, n), vec4_scale(v2, m)), 1 / ratio_sum);
}

HPML_API vec4_t vec4_internal_division(vec4_t v1, vec4_t v2, float m, float n)
{
	float ratio_sum = m + n;
	if(ratio_sum == 0)
		return v2;
	return vec4_scale(vec4_add(2, vec4_scale(v1, n), vec4_scale(v2, m)), 1 / ratio_sum);
}

HPML_API vec4_t vec4_scale(vec4_t v, float value) { return (vec4_t) { v.x * value, v.y * value, v.z * value, v.w * value }; }

HPML_API float vec4_magnitude(vec4_t v) { return sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w); }

HPML_API vec4_t vec4_normalize(vec4_t v)
{
	float inv_mag = 1 / vec4_magnitude(v);
	return (vec4_t) { v.x * inv_mag, v.y * inv_mag, v.z * inv_mag, v.w * inv_mag };
}

HPML_API float vec4_angle(vec4_t v1, vec4_t v2)
{
	float m1 = vec4_magnitude(v1);
	float m2 = vec4_magnitude(v2);
EXCEPTION_BLOCK
(
	if((m1 == 0) || (m2 == 0))
		throw_exception(DIVIDE_BY_ZERO);
)
	return acos(vec4_dot(v1, v2) / (m1 * m2));
}

HPML_API float vec4_unit_angle(vec4_t v1, vec4_t v2)
{
	return acos(vec4_dot(v1, v2));
}

HPML_API vec4_t vec4_rotate_x(vec4_t v, float angle)
{
	float c = cos(angle);
	float s = sin(angle);
	return (vec4_t) { v.x, v.y * c - s * v.z, v.y * s + v.z * c, v.w };
}

HPML_API vec4_t vec4_rotate_y(vec4_t v, float angle)
{
	float c = cos(angle);
	float s = sin(angle);
	return (vec4_t) { v.x * c + v.z * s, v.y, -v.x * s + v.z * c, v.w };
}

HPML_API vec4_t vec4_rotate_z(vec4_t v, float angle)
{
	float c = cos(angle);
	float s = sin(angle);
	return (vec4_t) { v.x * c - v.y * s, v.x * s + c * v.y, v.z, v.w };
}

HPML_API vec4_t vec4_rotate(vec4_t v, float x, float y, float z)
{
	return vec4_rotate_z(vec4_rotate_y(vec4_rotate_x(v, x), y), z);
}

HPML_API vec4_t vec4_axis_rotate(vec4_t v, float axisX, float axisY, float axisZ, float angle)
{
	vec4_t p = vec4_unit_project(v, (vec4_t) { axisX, axisY, axisZ, 0 });
 	vec4_t k = vec4_sub(2, v, p);
 	vec4_t j = vec4_cross((vec4_t) { axisX, axisY, axisZ, 0}, k);
 	return vec4_add(3 , vec4_scale(k, cos(angle)), vec4_scale(j, sin(angle)), p);
 }

HPML_API vec4_t vec4_project(vec4_t v, vec4_t a)
{
	vec4_t na = vec4_normalize(v);
	return vec4_scale(na, vec4_dot(v, na));
}

HPML_API vec4_t vec4_unit_project(vec4_t v, vec4_t a)
{
	return vec4_scale(a, vec4_dot(v, a));
}

HPML_API float vec4_box(vec4_t from, vec4_t to, vec4_t height)
{
	return vec4_dot(height, vec4_cross(from, to));
}

HPML_API float vec4_dot(vec4_t v1, vec4_t v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}

HPML_API vec4_t vec4_cross(vec4_t from, vec4_t to)
{
	vec4_t v = {
	from.y * to.z - from.z * to.y,
	from.x * to.z - from.z * to.x,
	from.x * to.y - from.y * to.x,
	};
	return v;
}

HPML_API bool vec4_is_null(vec4_t v)
{
	return (v.x == 0) && (v.y == 0) && (v.z == 0) && (v.w == 0);
}

HPML_API bool vec4_is_equal(vec4_t v1, vec4_t v2)
{
	return (v1.x == v2.x) && (v1.y == v2.y) && (v1.z == v2.z) && (v1.w == v2.w);
}

HPML_API void vec4_print(vec4_t v)
{
	printf("Vec4: (%f, %f, %f, %f)\n", v.x, v.y, v.z, v.w);
}