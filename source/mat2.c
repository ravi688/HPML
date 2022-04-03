#include <hpml/mat2.h>

#include <hpml/exception/exception.h>

HPML_API mat2_t mat2_add(mat2_t m1, mat2_t m2)
{
	return MAT2 
	{
		m1.m0 + m2.m0,
		m1.m1 + m2.m1,
		m1.m2 + m2.m2,
		m1.m3 + m2.m3
	};
}

HPML_API mat2_t mat2_sub(mat2_t m1, mat2_t m2)
{
	return MAT2
	{
		m1.m0 - m2.m0,
		m1.m1 - m2.m1,
		m1.m2 - m2.m2,
		m1.m3 - m2.m3
	};
}

HPML_API mat2_t mat2_mul(mat2_t m1, mat2_t m2)
{
	return MAT2 
	{
		m1.m0 * m2.m0 + m1.m1 * m2.m2,
		m1.m0 * m2.m1 + m1.m1 * m2.m3,
		m1.m2 * m2.m0 + m1.m3 * m2.m2,
		m1.m2 * m2.m1 + m1.m3 * m2.m3
	};
}

HPML_API mat2_t mat2_mul_with_scalar(mat2_t m, float scalar)
{
	m.m0 *= scalar;
	m.m1 *= scalar;
	m.m2 *= scalar;
	m.m3 *= scalar;
	return m;
}

HPML_API mat2_t mat2_div(mat2_t m1, mat2_t m2)
{
	EXCEPTION_BLOCK(
		if(mat2_is_null(m2))
			THROW_EXCEPTION(DIVIDE_BY_ZERO);
	)
	return MAT2
	{
		m1.m0 / m2.m0,
		m1.m1 / m2.m1,
		m1.m2 / m2.m2,
		m1.m3 / m2.m3
	};
}

HPML_API bool mat2_is_null(mat2_t m)
{
	return (m.m0 == 0) && (m.m1 == 0) && (m.m2 == 0) && (m.m3 == 0);
}

HPML_API bool mat2_is_equal(mat2_t m1, mat2_t m2)
{
	return (m1.m0 == m2.m0) && (m1.m1 == m2.m1) && (m1.m2 == m2.m2) && (m1.m3 == m2.m3);
}

HPML_API mat2_t mat2_negate(mat2_t m)
{
	m.m0 = -m.m0;
	m.m1 = -m.m1;
	m.m2 = -m.m2;
	m.m3 = -m.m3;
	return m;
}

HPML_API mat2_t mat2_mul_component_wise(mat2_t m1, mat2_t m2)
{
	m1.m0 *= m2.m0;
	m1.m1 *= m2.m1;
	m1.m2 *= m2.m2;
	m1.m3 *= m2.m3;
	return m1;
}

HPML_API mat2_t mat2_transpose(mat2_t m)
{
	mat2_t _m = m;
	_m.m1 = m.m2;
	_m.m2 = m.m1;
	return _m;
}

HPML_API mat2_t mat2_lerp(mat2_t m1, mat2_t m2, float lerp_value)
{
	mat2_t m;
	float _lerp_value = 1 - lerp_value;
	m.m0 = m1.m0 * _lerp_value + lerp_value * m2.m0;
	m.m1 = m1.m1 * _lerp_value + lerp_value * m2.m1;
	m.m2 = m1.m2 * _lerp_value + lerp_value * m2.m2;
	m.m3 = m1.m3 * _lerp_value + lerp_value * m2.m3;
	return m;
}

HPML_API mat2_t mat2_inverse(mat2_t m)
{
	float det = m.m0 * m.m1 - m.m2 * m.m3;
	EXCEPTION_BLOCK(
		if(det == 0)
			THROW_EXCEPTION(INVERSION_OF_SINGULAR_MATRIX);
	)
	float inverse_det = 1 / det;
	return MAT2 
	{
		m.m2 * inverse_det,
		m.m0 * inverse_det,
		-m.m3 * inverse_det,
		-m.m1 * inverse_det
	};
}


HPML_API mat2_t mat2_rotation(float angle)
{
	float cos_angle = cos(angle);
	float sin_angle = sin(angle);
	return MAT2
	{
		cos_angle,
		sin_angle,
		-sin_angle,
		cos_angle
	};
}

/* For debugging purpose */

void mat2_print(mat2_t m)
{
	printf("mat2_t(float): { %f, %f, %f, %f }\n", m.m0, m.m1, m.m2, m.m3);
}
