
#include <hpml/vec3.h>

#include <hpml/exception/exception.h>

HPML_API vec3_t __vec3_add(vec3_t v1, vec3_t v2) { return (vec3_t) { v1.x + v2.x, v1.y + v2.y, v1.z + v2.z }; }
HPML_API vec3_t vec3_add(u32 count, ...)
{
	va_list args;
	va_start(args, count);
	vec3_t result = va_arg(args, vec3_t);
	--count;
	while(count > 0)
	{
		result = __vec3_add(result, va_arg(args, vec3_t));
		--count;
	}
	va_end(args);
	return result;
}

HPML_API vec3_t __vec3_sub(vec3_t v1, vec3_t v2) { return (vec3_t) { v1.x - v2.x, v1.y - v2.y, v1.z - v2.z }; }
HPML_API vec3_t vec3_sub(u32 count, ...)
{
	va_list args;
	va_start(args, count);
	vec3_t result = va_arg(args, vec3_t);
	--count;
	while(count > 0)
	{
		result = __vec3_sub(result, va_arg(args, vec3_t));
		--count;
	}
	va_end(args);
	return result;
}

HPML_API vec3_t __vec3_mul(vec3_t v1, vec3_t v2) { return (vec3_t) { v1.x * v2.x, v1.y * v2.y, v1.z * v2.z }; }
HPML_API vec3_t vec3_mul(u32 count, ...)
{
	va_list args;
	va_start(args, count);
	vec3_t result = va_arg(args, vec3_t);
	--count;
	while(count > 0)
	{
		result = __vec3_mul(result, va_arg(args, vec3_t));
		--count;
	}
	va_end(args);
	return result;
}

HPML_API vec3_t __vec3_div(vec3_t v1, vec3_t v2)
{
	EXCEPTION_BLOCK
	(
	if(vec3_is_null(v2))
		THROW_EXCEPTION(DIVIDE_BY_ZERO);
	)
	return (vec3_t) { v1.x / v2.x, v1.y / v2.y, v1.z / v2.z };
}

HPML_API vec3_t vec3_div(u32 count, ...)
{
	va_list args;
	va_start(args, count);
	vec3_t result = va_arg(args, vec3_t);
	--count;
	while(count > 0)
	{
		result = __vec3_div(result, va_arg(args, vec3_t));
		--count;
	}
	va_end(args);
	return result;
}

HPML_API vec3_t vec3_lerp(vec3_t from, vec3_t to, float t)
{
	float _t = 1 - t;
	return (vec3_t) { from.x * _t + to.x * t, from.y * _t + to.y * t, from.z * _t + to.z * t };
}

HPML_API vec3_t vec3_slerp(vec3_t from, vec3_t to, float t)
{
	float angle = vec3_angle(from, to);
	EXCEPTION_BLOCK
	(
		if((angle == 0) || (angle == 3.145926f) || (angle == 2 * 3.145926f))
			THROW_EXCEPTION(DIVIDE_BY_ZERO);
	)
	float inv_sin_angle = 1 / sin(angle);
	float temp = t * angle;
	return vec3_add(2, vec3_scale(from, sin(angle - temp) * inv_sin_angle), vec3_scale(to, sin(temp)));
}

HPML_API vec3_t vec3_direction_ratios(vec3_t v)
{
	float inv_mag = 1 / vec3_magnitude(v);
	return vec3_scale(v, inv_mag);
}

HPML_API vec3_t vec3_external_division(vec3_t v1, vec3_t v2, float m, float n)
{
	float ratio_sum = m - n;
	if(ratio_sum == 0)
		return v2;
	return vec3_scale(vec3_sub(2, vec3_scale(v1, n), vec3_scale(v2, m)), ratio_sum);
}

HPML_API vec3_t vec3_internal_division(vec3_t v1, vec3_t v2, float m, float n)
{
	float ratio_sum = m + n;
	if(ratio_sum == 0)
		return v2;
	return vec3_scale(vec3_add(2, vec3_scale(v1, n), vec3_scale(v2, m)), ratio_sum);
}

HPML_API vec3_t vec3_scale(vec3_t v, float value) { return (vec3_t) { v.x * value, v.y * value, v.z * value }; }

HPML_API float vec3_magnitude(vec3_t v) { return sqrt(v.x * v.x + v.y * v.y + v.z * v.z); }

HPML_API float vec3_sqrmagnitude(vec3_t v) { return (v.x * v.x + v.y * v.y + v.z * v.z); }

HPML_API vec3_t vec3_normalize(vec3_t v)
{
	float inv_mag = 1 / vec3_magnitude(v);
	return (vec3_t) { v.x * inv_mag, v.y * inv_mag, v.z * inv_mag };
}

HPML_API float vec3_angle(vec3_t v1, vec3_t v2)
{
	float m1 = vec3_magnitude(v1);
	float m2 = vec3_magnitude(v2);
EXCEPTION_BLOCK
(
	if((m1 == 0) || (m2 == 0))
		throw_exception(DIVIDE_BY_ZERO);
)
	return acos(vec3_dot(v1, v2) / (m1 * m2));
}

HPML_API float vec3_unit_angle(vec3_t v1, vec3_t v2)
{
	return acos(vec3_dot(v1, v2));
}

HPML_API vec3_t vec3_negate(vec3_t v) { return (vec3_t) { -v.x, -v.y, -v.z }; }

HPML_API vec3_t vec3_rotate_x(vec3_t v, float angle)
{
	float c = cos(angle);
	float s = sin(angle);
	return (vec3_t) { v.x, v.y * c - s * v.z, v.y * s + v.z * c };
}

HPML_API vec3_t vec3_rotate_y(vec3_t v, float angle)
{
	float c = cos(angle);
	float s = sin(angle);
	return (vec3_t) { v.x * c + v.z * s, v.y, -v.x * s + v.z * c };
}

HPML_API vec3_t vec3_rotate_z(vec3_t v, float angle)
{
	float c = cos(angle);
	float s = sin(angle);
	return (vec3_t) { v.x * c - v.y * s, v.x * s + c * v.y, v.z };
}

HPML_API vec3_t vec3_rotate(vec3_t v, float x, float y, float z)
{
	return vec3_rotate_z(vec3_rotate_y(vec3_rotate_x(v, x), y), z);
}

HPML_API vec3_t vec3_axis_rotate(vec3_t v, float axisX, float axisY, float axisZ, float angle)
{
	vec3_t p = vec3_unit_project(v, (vec3_t) { axisX, axisY, axisZ });
 	vec3_t k = vec3_sub(2, v, p);
 	vec3_t j = vec3_cross((vec3_t) { axisX, axisY, axisZ }, k);
 	return vec3_add(3 , vec3_scale(k, cos(angle)), vec3_scale(j, sin(angle)), p);
}

HPML_API vec3_t vec3_project(vec3_t v, vec3_t a)
{
	vec3_t na = vec3_normalize(v);
	return vec3_scale(na, vec3_dot(v, na));
}

HPML_API vec3_t vec3_unit_project(vec3_t v, vec3_t a)
{
	return vec3_scale(a, vec3_dot(v, a));
}

HPML_API float vec3_box(vec3_t from, vec3_t to, vec3_t height)
{
	return vec3_dot(height, vec3_cross(from, to));
}

HPML_API float vec3_dot(vec3_t v1, vec3_t v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

HPML_API vec3_t vec3_cross(vec3_t from, vec3_t to)
{
	vec3_t v = {
	from.y * to.z - from.z * to.y,
	from.x * to.z - from.z * to.x,
	from.x * to.y - from.y * to.x,
	};
	return v;
}

HPML_API bool vec3_is_null(vec3_t v)
{
	return (v.x == 0) && (v.y == 0) && (v.z == 0);
}

HPML_API bool vec3_is_equal(vec3_t v1, vec3_t v2)
{
	return (v1.x == v2.x) && (v1.y == v2.y) && (v1.z == v2.z);
}

HPML_API void vec3_print(vec3_t v) { printf("vec3_t(float): { %f, %f, %f }\n", v.x, v.y, v.z); }
