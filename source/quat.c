
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

HPML_API quat_t __quat_add(quat_t q1, quat_t q2)
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
	quat_t q = __quat_mul(q1, quat_conj(q2));
	float sqrm = 1 / quat_sqrmagnitude(q2);
	return quat(q.x * sqrm, q.y * sqrm, q.z * sqrm, q.w * sqrm);
}

HPML_API quat_t quat_difference(quat_t q1, quat_t q2)
{
	// q1 * inverse(q2)
	return __quat_mul(q1, quat_inverse(q2));
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
	/*
		1 / q = conj(q) / { conj(q) * q };
		1 / q = conj(q) / sqr_mag(q);
	 */
	return quat_mul_scalar(quat_conjugate(q), 1 / quat_sqrmagnitude(q));
}

HPML_API quat_t quat_sqrt(quat_t q)
{
	/*	  ___
		\/ q  = sqrt(q)

		let 	\/(x, y, z, w) = (a, b, c, d)
		then 	(x, y, z, w) = mul((a, b, c, d), (a, b, c, d))
				(x, y, z, w) = (a ^ 2 - b ^ 2 - c ^ 2 - d ^ 2, 2ab, 2ac, 2ad)
				x = a ^ 2 - b ^ 2 - c ^ 2 - d ^ 2 					equation 1
				y = 2ab 											equation 2
				z = 2ac												equation 3
				w = 2ad												equation 4
		solving 1, 2, 3, 4 we will get the value of a ^ 2 = something
		so for each value of a we have two values of b and so on ...
		therefore, total solution = 2 ^ 4 = 32 solutions

	 */
	return quat_identity(); 		// TO BE IMPLEMENTED
}

HPML_API quat_t quat_log(quat_t q, float base)
{
	/*
		logarithm of a complex number:
		------------------------------

		let log(x + iy) = a + ib
		or
			log(x, y) = (a, b)

		since complex number are also numbers (much like real numbers)
			(x, y) = exp(a, b)
		=>  (x, y) = exp(a) * exp(ib)

		by applying euler's identity
			(x, y) = exp(a) * (cos(b) + isin(b))
			(x, y) = exp(a) * (cos(b), sin(b))
			(x, y) = (exp(a)cos(b), exp(a)sin(b))
		=> 	x = exp(a)cos(b), 		- (1)
		and y = exp(a)sin(b)		- (2)

		solving (1) and (2)

		we get 												   _________
			log(x + iy) = (0.5 * log(x^2 + y^2)) + iacos(x / \/ x^2 + y^2)

		logarithm of a general quaternion:
		---------------------------

		let log(x + iy + jz + kw) = a + ib + jc + kd
		or
			log(x, y, z, w) = (a, b, c, d)

		lets treat quaternions just like complex numbers
			(x, y, z, w) = exp(a, b, c, d)
						 = exp(a) * exp(b, c, d)
		applying euler's identity for quaternions
			(x, y, z, w) = exp(a) * (cos(mag(b, c, d)) + norm(b, c, d)sin(mag(b, c, d)))
		- Not solved


		logarithm of a unit quaternion:
		-------------------------------

		let q = cos($) + n * sin($), where n is a unit vector and mag(q) = 1

		log(q) = log(exp(n * $)) = n * $ = (0, n * $)

		likewise, logarithm of a general quaternion should be:

		log q = s + v

		log(q) = log( mag(v) * exp(unit(v) * acos(s / mag(v))) )
			   = log( mag(v) ) + log( exp(unit(v) * acos(a / mag(v))) )
			   = log( mag(v) ) + (0, n * $)
			   = (log( mag (v) ), n * $)

	 */
	return quat_identity(); 	// TO BE IMPLEMENTED
}

//https://math.stackexchange.com/questions/939229/unit-quaternion-to-a-scalar-power
HPML_API quat_t quat_pow(quat_t q, float t)
{

	/* 
		raising to a power a quaternion:

		Let q be a unit quaterion exp(n * $), where mag(n) = 1
		
		exp(n * $) ^ t = exp(n * $ * t) = cos($*t) + sin($*t)n

	*/
	return quat_identity(); 		// TO BE IMPLEMENTED
}

HPML_API float quat_magnitude(quat_t q)
{
	return sqrt(q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w);
}

HPML_API float quat_sqrmagnitude(quat_t q)
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

HPML_API bool quat_equal(quat_t q1, quat_t q2)
{
	return (q1.x == q2.x) && (q1.y == q2.y) && (q1.z == q2.z) && (q1.w == q2.w);
}


HPML_API void quat_print(quat_t q)
{
	printf("Quat: (%f, %f, %f, %f)\n", q.x, q.y, q.z, q.w);
}

