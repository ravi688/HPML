
#pragma once

#include <hpml/quat.h>
#include <math.h>

#include <stdarg.h>

static HPML_FORCE_INLINE void cross(const float* const from, const float* const to, float* const out)
{
	/*
	| i   j  k |
	| a1 a2 a3 |
	| b1 b2 b3 |

	i(a2 * b3 - a3 * b2) - j(a1 * b3 - a3 * b1) + k(a1 * b2 - a2 * b1)
	*/

	out[0] = from[1] * to[2] - from[2] * to[1];
	out[1] = from[0] * to[2] - from[2] * to[0];
	out[2] = from[0] * to[1] - from[1] * to[0];
}

static HPML_FORCE_INLINE float dot(const float* const from, const float* const to)
{
	return from[0] * to[0] + from[1] * to[1] + from[2] * to[2];
}

HPML_API quat_t quat_add(u32 count, quat_t q, ...)
{
	va_list args;
	va_start(args, q);

	while(count)
	{
		q = __quat_add(q, va_arg(args, quat_t));
		--count;
	}

	va_end(args);

	return q;
}

HPML_APAI quat_t __quat_add(quat_t q1, quat_t q2)
{
	return quat(q1.x + q2.x, q1.y + q2.y, q1.z + q2.z, q1.w + q2.w);
}

HPML_API quat_t quat_sub(u32 count, quat_t q, ...)
{
	va_list args;
	va_start(args, q);

	while(count)
	{
		q = __quat_sub(q, va_arg(args, quat_t));
		--count;
	}

	va_end(args);
	
	return q;
}

HPML_API quat_t __quat_sub(quat_t q1, quat_t q2)
{
	return quat(q1.x - q2.x, q1.y - q2.y, q1.z - q2.z, q1.w - q2.w);
}

HPML_API quat_t quat_mul(u32 count, quat_t q, ...)
{
	va_list args;
	va_start(args, q);

	while(count)
	{
		q = __quat_mul(q, va_arg(args, quat_t));
		--count;
	}

	va_end(args);
	
	return q;
}

HPML_API quat_t __quat_mul(quat_t q1, quat_t q2)
{
	float v[3];
	cross(q1.v, q2.v, v);
	float x = q1.s * q2.x + q2.s * q1.x + v[0];
	float y = q1.s * q2.y + q2.s * q1.y + v[1];
	float z = q1.s * q2.z + q2.s * q1.z + v[2];
	float s = q1.s * q2.s - (q1.x * q2.x + q1.y * q2.y + q1.z * q2.z);
	return quat(x, y, z, s);
}

HPML_API quat_t quat_div(u32 count, quat_t q, ...)
{
	va_list args;
	va_start(args, q);

	while(count)
	{
		q = __quat_div(q, va_arg(args, quat_t));
		--count;
	}

	va_end(args);
	
	return q;
}

HPML_API quat_t __quat_div(quat_t q1, quat_t q2)
{
	quat_t q = quat_mul(q1, quat_conj(q2));
	float sqrm = 1 / quat_sqrmagnitude(q2);
	return quat(q.x * sqrm, q.y * sqrm, q.z * sqrm, q.w * sqrm);
}

HPML_API quat_t quat_difference(quat_t q1, quat_t q2)
{
	// q1 * inverse(q2)
	return quat_mul(q1, quat_inverse(q2));
}

HPML_API quat_t quat_inverse(quat_t q)
{
	// q * conj(q) = sqr(magnitude(q))
	// implies => conj(q) / sqr(magnitude(q)) = inverse(q)
	float sqrm = 1 / quat_sqrmagnitude(q);
	return quat(-q.x * sqrm, -q.y * sqrm, -q.z * sqrm, q.w * sqrm);
}

HPML_API quat_t quat_reciprocal(quat_t q)
{
	return quat_identity(); 		// TO BE IMPLEMENTED
}

HPML_API quat_t quat_sqrt(quat_t q)
{
	return quat_identity(); 		// TO BE IMPLEMENTED
}

HPML_API quat_t quat_log(quat_t q, float base)
{
	return quat_identity(); 		// TO BE IMPLEMENTED
}

//https://math.stackexchange.com/questions/939229/unit-quaternion-to-a-scalar-power
HPML_API quat_t quat_pow(quat_t q, float t)
{
	return quat_identity(); 		// TO BE IMPLEMENTED
}

HPML_API quat_t quat_magnitude(quat_t q)
{
	return sqrt(q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w);
}

HPML_API quat_t quat_sqrmagnitude(quat_t q)
{
	return q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w;
}

HPML_API quat_t quat_normalize(quat_t q)
{
	return quat_mul_scalar(q, 1 / quat_magnitude(q));
}

HPML_API quat_t quat_angle_axis(float x, float y, float z, float angle)
{
	float ha = angle * 0.5f;
	float s = sin(ha);
	return quat(x * s, y * s, z * s, cos(ha));
}


HPML_API quat_t quat_versor(float x, float y, float z, float angle)
{
	float s = sin(angle);
	return quat(s * x, s * y, s * z, cos(angle));
}

HPML_API float quat_angle(quat_t q1, quat_t q2)
{
	/*
		q1 * q = q2
		implies => q = inverse(q) * q2;
	 */
	return acos(quat_difference(q1, q2).s) * 2.0f;
}

HPML_API quat_t quat_lerp(quat_t from, quat_t to, float t)
{
	return __quat_add(quat_mul_scalar(from, 1 - t), quat_mul_scalar(to, t));
}

HPML_API quat_t quat_slerp(quat_t from, quat_t to, float t)
{
	return __quat_mul(quat_pow(quat_difference(from, to), t), from);
}

HPML_API quat_t quat_sandwitch(quat_t versor, quat_t p)
{
	return quat_mul(2, versor, p, quat_inverse(versor));
}
