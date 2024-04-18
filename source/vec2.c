
#include <hpml/vec2.h>

#include <hpml/exception/exception.h>
#include <math.h>

HPML_API vec2_t vec2_slerp(vec2_t v1, vec2_t v2, float slerp_value)
{
	float angle = vec2_angle(v1, v2);
	float inverse_sin = 1 / sin(angle);
	float temp = slerp_value * angle;
	return vec2_add(vec2_scale(v1, sin(angle - temp) * inverse_sin), vec2_scale(v2, sin(temp) * inverse_sin));
}

HPML_API vec2_t vec2_scale(vec2_t v, float scalar_value)
{
	vec2_t scaled_v =  { v.x * scalar_value, v.y * scalar_value };
	return scaled_v;
}

HPML_API vec2_t vec2_normal_anticlockwise(vec2_t v)
{
	vec2_t normal;
	normal.x = -v.y;
	normal.y = v.x;
	return normal;
}

HPML_API vec2_t vec2_normal_clockwise(vec2_t v)
{
	vec2_t normal;
	normal.x = v.y;
	normal.y = -v.x;
	return normal;
}

HPML_API vec2_t vec2_internal_division(vec2_t v1, vec2_t v2, float m, float n)
{
	float ratio_sum = m + n;
	if(ratio_sum == 0)
		return v1;
	return vec2_scale(vec2_add(vec2_scale(v1, n), vec2_scale(v2, m)), 1 / ratio_sum);
}

HPML_API vec2_t vec2_external_division(vec2_t v1, vec2_t v2, float m, float n)
{
	float ratio_sum = m - n;
	if(ratio_sum == 0)
		return v2;
	return vec2_scale(vec2_sub(vec2_scale(v1, n), vec2_scale(v2, m)), 1 / (m - n));
}

HPML_API vec2_t vec2_lerp(vec2_t v1, vec2_t v2, float interpolation_value)
{
	return vec2_add(vec2_scale(v1, 1 - interpolation_value), vec2_scale(v2, interpolation_value));
}

HPML_API vec2_t vec2_project(vec2_t v1, vec2_t v2)
{
	vec2_t unit_dir = vec2_normalize(v2);
	float projection_value = vec2_dot(v1, unit_dir);
	return vec2_scale(unit_dir, projection_value);
}

HPML_API vec2_t vec2_abs(vec2_t v)
{
	return VEC2 
	{
		fabs(v.x),
		fabs(v.y)
	};
}

HPML_API float vec2_angle(vec2_t v1, vec2_t v2)
{
	if(!(vec2_is_null(v1) && vec2_is_null(v2)))
		return 0.0f;
	return acos(vec2_dot(v1, v2) / (vec2_magnitude(v1) * vec2_magnitude(v2)));
}

HPML_API vec2_t vec2_rotate(vec2_t v, float angle)
{
	vec2_t rot_v;
	float cos_angle = cos(angle);
	float sin_angle = sin(angle);
	rot_v.x = v.x * cos_angle - v.y * sin_angle;
	rot_v.y = v.x * sin_angle + v.y * cos_angle;
	return rot_v;
}

HPML_API vec2_t vec2_normalize(vec2_t v)
{
	if(vec2_is_null(v))
		return v;
	float inv_mag = (float)1 / vec2_magnitude(v);
	vec2_t unit_v;
	unit_v.x = v.x * inv_mag;
	unit_v.y = v.y * inv_mag;
	return unit_v;
}

HPML_API vec2_t vec2_negate(vec2_t v)
{
	vec2_t neg_v;
	neg_v.x = -v.x;
	neg_v.y = -v.y;
	return neg_v;
}

HPML_API float vec2_magnitude(vec2_t v)
{
	return sqrt(v.x * v.x + v.y * v.y);
}

HPML_API float vec2_sqrmagnitude(vec2_t v)
{
	return v.x * v.x + v.y * v.y;
}

HPML_API float vec2_dot(vec2_t v1, vec2_t v2)
{
	return v1.x * v2.x + v1.y * v2.y;
}


HPML_API bool vec2_is_null(vec2_t v)
{
	return (v.x == 0) && (v.y == 0);
}

HPML_API bool vec2_is_equal(vec2_t v1, vec2_t v2)
{
	return (v1.x == v2.x) && (v1.y == v2.y);
}

HPML_API vec2_t vec2_add(vec2_t v1, vec2_t v2)
{
	vec2_t result;
	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	return result;
}

HPML_API vec2_t vec2_sub(vec2_t v1, vec2_t v2)
{
	vec2_t result;
	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	return result;
}

HPML_API vec2_t vec2_mul(vec2_t v1, vec2_t v2)
{
	vec2_t result;
	result.x = v1.x * v2.x;
	result.y = v1.y * v2.y;
	return result;
}

HPML_API vec2_t vec2_div(vec2_t v1, vec2_t v2)
{
	EXCEPTION_BLOCK
	(
	if(vec2_is_null(v2))
		THROW_EXCEPTION(DIVIDE_BY_ZERO);
	)
	vec2_t result;
	result.x = v1.x / v2.x;
	result.y = v1.y / v2.y;
	return result;
}

void vec2_print(vec2_t v)
{
	printf("vec2_t(float):  { %f, %f }\n", v.x, v.y);
}
