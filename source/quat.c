
#pragma once

#include <hpml/quat.h>

HPML_API quat_t quat(float x, float y, float z, float w)
{
	return { x, y, z, w };
}

HPML_API quat_t quat_add(u32 count, quat_t q, ...);

HPML_APAI quat_t __quat_add(quat_t q1, quat_t q2)
{
	return { q1.x + q2.x, q1.y + q2.y, q1.z + q2.z, q1.w + q2.w };
}

HPML_API quat_t quat_sub(u32 count, quat_t q, ...);
HPML_API quat_t __quat_sub(quat_t q1, quat_t q2)
{
	return { q1.x - q2.x, q1.y - q2.y, q1.z - q2.z, q1.w - q2.w };
}

HPML_API quat_t quat_mul(u32 count, quat_t q, ...);
HPML_API quat_t __quat_mul(quat_t q1, quat_t q2)
{
	float x = q1.w * q2.x + q2.w * q1.x + cross(q1.v, q2.v).x;
	float y = q1.w * q2.y + q2.w * q1.y + cross(q1.v, q2.v).y;
	float z = q1.w * q2.z + q2.w * q1.z + cross(q1.v, q2.v).z;
	float w = q1.w * q2.w - (q1.x * q2.x + q1.y * q2.y + q1.z * q2.z);
	return { x, y, z, w };
}

HPML_API quat_t quat_div(u32 count, quat_t q, ...);
HPML_API quat_t __quat_div(quat_t q1, quat_t q2)
{
	quat_t q = quat_mul(q1, quat_conj(q2));
	float sqrm = 1 / quat_sqrmagnitude(q2);
	return { q.x * sqrm, q.y * sqrm, q.z * sqrm, q.w * sqrm };
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
	return { -q.x * sqrm, -q.y * sqrm, -q.z * sqrm, q.w * sqrm };
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
	float m = 1 / quat_magnitude(q);
	return { q.x * m, q.y * m, q.z * m, q.w * m };
}

HPML_API quat_t quat_angle_axis(float x, float y, float z, float angle)
{

}

HPML_API quat_t quat_angle(quat_t q1, quat_t q2)
{

}

HPML_API quat_t quat_lerp(quat_t from, quat_t to, float t)
{

}

HPML_API quat_t quat_slerp(quat_t from, quat_t to, float t)
{

}

