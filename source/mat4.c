
#include <hpml/mat4.h>

#include <hpml/exception/exception.h> 	// for exceptions

HPML_API float* const* const __mat4_data(mat4_t* m)
{
	IGNORE_CONST(float*,m->data[0]) = &m->m00;
	IGNORE_CONST(float*,m->data[1]) = &m->m10;
	IGNORE_CONST(float*,m->data[2]) = &m->m20;
	IGNORE_CONST(float*,m->data[3]) = &m->m30;
	return (float* const* const)m->data;
}

HPML_API float mat4_det(mat4_t m)
{
	return m.m00 * (m.m11 * (m.m22 * m.m33 - m.m23 * m.m32) - m.m12 * (m.m21 * m.m33 - m.m23 * m.m31) + m.m13 * (m.m21 * m.m32 - m.m22 * m.m31)) -
	m.m01 * (m.m10 * (m.m22 * m.m33 - m.m23 * m.m32) - m.m12 * (m.m20 * m.m33 - m.m23 * m.m30) + m.m13 * (m.m20 * m.m32 - m.m22 * m.m30)) +
	m.m02 * (m.m10 * (m.m21 * m.m33 - m.m23 * m.m31) - m.m11 * (m.m20 * m.m33 - m.m23 * m.m30) + m.m13 * (m.m20 * m.m31 - m.m21 * m.m30)) -
	m.m03 * (m.m10 * (m.m21 * m.m32 - m.m22 * m.m31) - m.m11 * (m.m20 * m.m32 - m.m22 * m.m30) + m.m12 * (m.m20 * m.m31 - m.m21 * m.m30));
}

HPML_API mat4_t __mat4_mul(mat4_t m1, mat4_t m2)
{
	return MAT4
	{
		m1.m00 * m2.m00 + m1.m01 * m2.m10 + m1.m02 * m2.m20 + m1.m03 * m2.m30,
		m1.m00 * m2.m01 + m1.m01 * m2.m11 + m1.m02 * m2.m21 + m1.m03 * m2.m31,
		m1.m00 * m2.m02 + m1.m01 * m2.m12 + m1.m02 * m2.m22 + m1.m03 * m2.m32,
		m1.m00 * m2.m03 + m1.m01 * m2.m13 + m1.m02 * m2.m23 + m1.m03 * m2.m33,
		m1.m10 * m2.m00 + m1.m11 * m2.m10 + m1.m12 * m2.m20 + m1.m13 * m2.m30,
		m1.m10 * m2.m01 + m1.m11 * m2.m11 + m1.m12 * m2.m21 + m1.m13 * m2.m31,
		m1.m10 * m2.m02 + m1.m11 * m2.m12 + m1.m12 * m2.m22 + m1.m13 * m2.m32,
		m1.m10 * m2.m03 + m1.m11 * m2.m13 + m1.m12 * m2.m23 + m1.m13 * m2.m33,
		m1.m20 * m2.m00 + m1.m21 * m2.m10 + m1.m22 * m2.m20 + m1.m23 * m2.m30,
		m1.m20 * m2.m01 + m1.m21 * m2.m11 + m1.m22 * m2.m21 + m1.m23 * m2.m31,
		m1.m20 * m2.m02 + m1.m21 * m2.m12 + m1.m22 * m2.m22 + m1.m23 * m2.m32,
		m1.m20 * m2.m03 + m1.m21 * m2.m13 + m1.m22 * m2.m23 + m1.m23 * m2.m33,
		m1.m30 * m2.m00 + m1.m31 * m2.m10 + m1.m32 * m2.m20 + m1.m33 * m2.m30,
		m1.m30 * m2.m01 + m1.m31 * m2.m11 + m1.m32 * m2.m21 + m1.m33 * m2.m31,
		m1.m30 * m2.m02 + m1.m31 * m2.m12 + m1.m32 * m2.m22 + m1.m33 * m2.m32,
		m1.m30 * m2.m03 + m1.m31 * m2.m13 + m1.m32 * m2.m23 + m1.m33 * m2.m33
	};
}

HPML_API mat4_t mat4_mul(uint32_t count, ...)
{
	mat4_t result = mat4_identity();
	va_list args;
	va_start(args, count);
	while(count > 0)
	{
		mat4_move(result, __mat4_mul(result, va_arg(args, mat4_t)));
		--count;
	}
	va_end(args);
	return result;
}

HPML_API void mat4_build_cofactor(mat4_t m, float* const* const cofactorMatrix, u32 row, u32 column)
{
	float* const* const baseMatrix = mat4_data(m);
	for(u32 i = 0, g = 0; i < 3; i++, g++)
	{
		if(g == row) g++;
		for(u32 j = 0, h = 0; j < 3; j++, h++)
		{
			if(h == column) h++;
			cofactorMatrix[i][j] = baseMatrix[g][h];
		}
	}
}

HPML_API mat4_t mat4_add(mat4_t m1, mat4_t m2)
{
	return MAT4
	{
		m1.m00 + m2.m00,
		m1.m01 + m2.m01,
		m1.m02 + m2.m02,
		m1.m03 + m2.m03,
		m1.m10 + m2.m10,
		m1.m11 + m2.m11,
		m1.m12 + m2.m12,
		m1.m13 + m2.m13,
		m1.m20 + m2.m20,
		m1.m21 + m2.m21,
		m1.m22 + m2.m22,
		m1.m23 + m2.m23,
		m1.m30 + m2.m30,
		m1.m31 + m2.m31,
		m1.m32 + m2.m32,
		m1.m33 + m2.m33
	};
}

HPML_API mat4_t mat4_sub(mat4_t m1, mat4_t m2)
{
	return MAT4 
	{
		m1.m00 - m2.m00,
		m1.m01 - m2.m01,
		m1.m02 - m2.m02,
		m1.m03 - m2.m03,
		m1.m10 - m2.m10,
		m1.m11 - m2.m11,
		m1.m12 - m2.m12,
		m1.m13 - m2.m13,
		m1.m20 - m2.m20,
		m1.m21 - m2.m21,
		m1.m22 - m2.m22,
		m1.m23 - m2.m23,
		m1.m30 - m2.m30,
		m1.m31 - m2.m31,
		m1.m32 - m2.m32,
		m1.m33 - m2.m33
	};
}

HPML_API mat4_t mat4_mul_scalar(mat4_t m, float scalar)
{
	m.values[0] *= scalar;
	m.values[1] *= scalar;
	m.values[2] *= scalar;
	m.values[3] *= scalar;
	m.values[4] *= scalar;
	m.values[5] *= scalar;
	m.values[6] *= scalar;
	m.values[7] *= scalar;
	m.values[8] *= scalar;
	m.values[9] *= scalar;
	m.values[10] *= scalar;
	m.values[11] *= scalar;
	m.values[12] *= scalar;
	m.values[13] *= scalar;
	m.values[14] *= scalar;
	m.values[15] *= scalar;
	return m;
}

HPML_API mat4_t mat4_div(mat4_t m1, mat4_t m2)
{
	EXCEPTION_BLOCK(
		if(mat4_is_null(m2))
			THROW_EXCEPTION(DIVIDE_BY_ZERO);
	)
	m1.values[0]  = m1.values[0] / m2.values[0] ;
	m1.values[1]  = m1.values[1] / m2.values[1] ;
	m1.values[2]  = m1.values[2] / m2.values[2] ;
	m1.values[3]  = m1.values[3] / m2.values[3] ;
	m1.values[4]  = m1.values[4] / m2.values[4] ;
	m1.values[5]  = m1.values[5] / m2.values[5] ;
	m1.values[6]  = m1.values[6] / m2.values[6] ;
	m1.values[7]  = m1.values[7] / m2.values[7] ;
	m1.values[8]  = m1.values[8] / m2.values[8] ;
	m1.values[9]  = m1.values[9] / m2.values[9] ;
	m1.values[10] = m1.values[10]/ m2.values[10];
	m1.values[11] = m1.values[11]/ m2.values[11];
	m1.values[12] = m1.values[12]/ m2.values[12];
	m1.values[13] = m1.values[13]/ m2.values[13];
	m1.values[14] = m1.values[14]/ m2.values[14];
	m1.values[15] = m1.values[15]/ m2.values[15];
	return m1;
}

HPML_API bool mat4_is_null(mat4_t m)
{
	return (m.values[0] == 0) &&
		   (m.values[1] == 0) &&
		   (m.values[2] == 0) &&
		   (m.values[3] == 0) &&
		   (m.values[4] == 0) &&
		   (m.values[5] == 0) &&
		   (m.values[6] == 0) &&
		   (m.values[7] == 0) &&
		   (m.values[8] == 0) &&
		   (m.values[9] == 0) &&
		   (m.values[10] == 0) &&
		   (m.values[11] == 0) &&
		   (m.values[12] == 0) &&
		   (m.values[13] == 0) &&
		   (m.values[14] == 0) &&
		   (m.values[15] == 0);
}

HPML_API bool mat4_is_equal(mat4_t m1, mat4_t m2)
{
		return (m1.values[0]  == m2.values[0] ) &&
		   	   (m1.values[1]  == m2.values[1] ) &&
		   	   (m1.values[2]  == m2.values[2] ) &&
		   	   (m1.values[3]  == m2.values[3] ) &&
		   	   (m1.values[4]  == m2.values[4] ) &&
		   	   (m1.values[5]  == m2.values[5] ) &&
		   	   (m1.values[6]  == m2.values[6] ) &&
		   	   (m1.values[7]  == m2.values[7] ) &&
		   	   (m1.values[8]  == m2.values[8] ) &&
		   	   (m1.values[9]  == m2.values[9] ) &&
		   	   (m1.values[10] == m2.values[10]) &&
		   	   (m1.values[11] == m2.values[11]) &&
		   	   (m1.values[12] == m2.values[12]) &&
		   	   (m1.values[13] == m2.values[13]) &&
		   	   (m1.values[14] == m2.values[14]) &&
		   	   (m1.values[15] == m2.values[15]);
}

HPML_API mat4_t mat4_negate(mat4_t m)
{
	m.values[0]  = -m.values[0] ;
	m.values[1]  = -m.values[1] ;
	m.values[2]  = -m.values[2] ;
	m.values[3]  = -m.values[3] ;
	m.values[4]  = -m.values[4] ;
	m.values[5]  = -m.values[5] ;
	m.values[6]  = -m.values[6] ;
	m.values[7]  = -m.values[7] ;
	m.values[8]  = -m.values[8] ;
	m.values[9]  = -m.values[9] ;
	m.values[10] = -m.values[10];
	m.values[11] = -m.values[11];
	m.values[12] = -m.values[12];
	m.values[13] = -m.values[13];
	m.values[14] = -m.values[14];
	m.values[15] = -m.values[15];
	return m;
}

HPML_API mat4_t mat4_mul_component_wise(mat4_t m1, mat4_t m2)
{
	m1.values[0]  *= m2.values[0] ;
	m1.values[1]  *= m2.values[1] ;
	m1.values[2]  *= m2.values[2] ;
	m1.values[3]  *= m2.values[3] ;
	m1.values[4]  *= m2.values[4] ;
	m1.values[5]  *= m2.values[5] ;
	m1.values[6]  *= m2.values[6] ;
	m1.values[7]  *= m2.values[7] ;
	m1.values[8]  *= m2.values[8] ;
	m1.values[9]  *= m2.values[9] ;
	m1.values[10] *= m2.values[10];
	m1.values[11] *= m2.values[11];
	m1.values[12] *= m2.values[12];
	m1.values[13] *= m2.values[13];
	m1.values[14] *= m2.values[14];
	m1.values[15] *= m2.values[15];
	return m1;
}

HPML_API mat4_t mat4_transpose(mat4_t m)
{
	mat4_t _m = m;
	_m.m01 = m.m10;
	_m.m02 = m.m20;
	_m.m03 = m.m30;
	_m.m10 = m.m01;
	_m.m12 = m.m21;
	_m.m13 = m.m31;
	_m.m20 = m.m02;
	_m.m21 = m.m12;
	_m.m23 = m.m32;
	_m.m30 = m.m03;
	_m.m31 = m.m13;
	_m.m32 = m.m23;
	return _m;
}

HPML_API mat4_t mat4_lerp(mat4_t m1, mat4_t m2, float lerp_value)
{
	float _lerp_value = 1 - lerp_value;
	m1.values[0]  = _lerp_value * m1.values[0]  + lerp_value * m2.values[0] ;
	m1.values[1]  = _lerp_value * m1.values[1]  + lerp_value * m2.values[1] ;
	m1.values[2]  = _lerp_value * m1.values[2]  + lerp_value * m2.values[2] ;
	m1.values[3]  = _lerp_value * m1.values[3]  + lerp_value * m2.values[3] ;
	m1.values[4]  = _lerp_value * m1.values[4]  + lerp_value * m2.values[4] ;
	m1.values[5]  = _lerp_value * m1.values[5]  + lerp_value * m2.values[5] ;
	m1.values[6]  = _lerp_value * m1.values[6]  + lerp_value * m2.values[6] ;
	m1.values[7]  = _lerp_value * m1.values[7]  + lerp_value * m2.values[7] ;
	m1.values[8]  = _lerp_value * m1.values[8]  + lerp_value * m2.values[8] ;
	m1.values[9]  = _lerp_value * m1.values[9]  + lerp_value * m2.values[9] ;
	m1.values[10] = _lerp_value * m1.values[10] + lerp_value * m2.values[10];
	m1.values[11] = _lerp_value * m1.values[11] + lerp_value * m2.values[11];
	m1.values[12] = _lerp_value * m1.values[12] + lerp_value * m2.values[12];
	m1.values[13] = _lerp_value * m1.values[13] + lerp_value * m2.values[13];
	m1.values[14] = _lerp_value * m1.values[14] + lerp_value * m2.values[14];
	m1.values[15] = _lerp_value * m1.values[15] + lerp_value * m2.values[15];
	return m1;
}

HPML_API mat4_t mat4_inverse(mat4_t m)
{
	float det = mat4_det(m);
	EXCEPTION_BLOCK(
		if(det == 0)
			THROW_EXCEPTION(INVERSION_OF_SINGULAR_MATRIX);
	)
	float inverse_det = 1 / det;
	mat4_t _m;
	_m.m00 = m.m11 * (m.m22 * m.m33 - m.m23 * m.m32) - m.m12 * (m.m21 * m.m33 - m.m23 * m.m31) + m.m13 * (m.m21 * m.m32 - m.m22 * m.m31);
	_m.m10 = m.m10 * (m.m22 * m.m33 - m.m23 * m.m32) - m.m12 * (m.m20 * m.m33 - m.m23 * m.m30) + m.m13 * (m.m20 * m.m32 - m.m22 * m.m30);
	_m.m20 = m.m10 * (m.m21 * m.m33 - m.m23 * m.m31) - m.m11 * (m.m20 * m.m33 - m.m23 * m.m30) + m.m13 * (m.m20 * m.m31 - m.m21 * m.m30);
	_m.m30 = m.m10 * (m.m21 * m.m32 - m.m22 * m.m31) - m.m11 * (m.m20 * m.m32 - m.m22 * m.m30) + m.m12 * (m.m20 * m.m31 - m.m21 * m.m30);
 	_m.m01 = m.m01 * (m.m22 * m.m33 - m.m23 * m.m32) - m.m02 * (m.m21 * m.m33 - m.m23 * m.m31) + m.m03 * (m.m21 * m.m32 - m.m22 * m.m31);
 	_m.m11 = m.m00 * (m.m22 * m.m33 - m.m23 * m.m32) - m.m02 * (m.m20 * m.m33 - m.m23 * m.m30) + m.m03 * (m.m20 * m.m32 - m.m22 * m.m30);
 	_m.m21 = m.m00 * (m.m21 * m.m33 - m.m23 * m.m31) - m.m01 * (m.m20 * m.m33 - m.m23 * m.m30) + m.m03 * (m.m20 * m.m31 - m.m21 * m.m30);
 	_m.m31 = m.m00 * (m.m21 * m.m32 - m.m22 * m.m31) - m.m01 * (m.m20 * m.m32 - m.m22 * m.m30) + m.m02 * (m.m20 * m.m31 - m.m21 * m.m30);
	_m.m02 = m.m01 * (m.m12 * m.m33 - m.m13 * m.m32) - m.m02 * (m.m11 * m.m33 - m.m13 * m.m31) + m.m03 * (m.m11 * m.m32 - m.m12 * m.m31);
	_m.m12 = m.m00 * (m.m12 * m.m33 - m.m13 * m.m32) - m.m02 * (m.m10 * m.m33 - m.m13 * m.m30) + m.m03 * (m.m10 * m.m32 - m.m12 * m.m30);
	_m.m22 = m.m00 * (m.m11 * m.m33 - m.m13 * m.m31) - m.m01 * (m.m10 * m.m33 - m.m13 * m.m30) + m.m03 * (m.m10 * m.m31 - m.m11 * m.m30);
	_m.m32 = m.m00 * (m.m11 * m.m32 - m.m12 * m.m31) - m.m01 * (m.m10 * m.m32 - m.m12 * m.m30) + m.m02 * (m.m10 * m.m31 - m.m11 * m.m30);
	_m.m03 = m.m01 * (m.m12 * m.m23 - m.m13 * m.m22) - m.m02 * (m.m11 * m.m23 - m.m13 * m.m21) + m.m03 * (m.m11 * m.m22 - m.m12 * m.m21);
	_m.m13 = m.m00 * (m.m12 * m.m23 - m.m13 * m.m22) - m.m02 * (m.m10 * m.m23 - m.m13 * m.m20) + m.m03 * (m.m10 * m.m22 - m.m12 * m.m20);
	_m.m23 = m.m00 * (m.m11 * m.m23 - m.m13 * m.m21) - m.m01 * (m.m10 * m.m23 - m.m13 * m.m20) + m.m03 * (m.m10 * m.m21 - m.m11 * m.m20);
	_m.m33 = m.m00 * (m.m11 * m.m22 - m.m12 * m.m21) - m.m01 * (m.m10 * m.m22 - m.m12 * m.m20) + m.m02 * (m.m10 * m.m21 - m.m11 * m.m20);
	_m.m00 *= inverse_det;
	_m.m01 *= -inverse_det;
	_m.m02 *= inverse_det;
	_m.m03 *= -inverse_det;
	_m.m10 *= -inverse_det;
	_m.m11 *= inverse_det;
	_m.m12 *= -inverse_det;
	_m.m13 *= inverse_det;
	_m.m20 *= inverse_det;
	_m.m21 *= -inverse_det;
	_m.m22 *= inverse_det;
	_m.m23 *= -inverse_det;
	_m.m30 *= -inverse_det;
	_m.m31 *= inverse_det;
	_m.m32 *= -inverse_det;
	_m.m33 *= inverse_det;
	return _m;
}

void mat4_print(mat4_t m)
{
	printf(	"mat4_t(float):\n"
			"{ %f, %f, %f, %f }\n"
			"{ %f, %f, %f, %f }\n"
			"{ %f, %f, %f, %f }\n"
			"{ %f, %f, %f, %f }\n",
			m.m00, m.m01, m.m02, m.m03,
			m.m10, m.m11, m.m12, m.m13,
			m.m20, m.m21, m.m22, m.m23,
			m.m30, m.m31, m.m32, m.m33);
}
