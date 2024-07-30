
#include <hpml/affine_transformation.h>

#include <hpml/exception/exception.h>

HPML_API mat4_t mat4_rotation(float x, float y, float z)
{
	return mat4_mul(3, mat4_rotation_x(x), mat4_rotation_y(y), mat4_rotation_z(z));
}

HPML_API mat4_t mat4_ortho_projection(float nearClipPlane, float farClipPlane, float height, float aspectRatio)
{
	float box_x = farClipPlane - nearClipPlane;
	float box_y;
	float box_z;
	if(aspectRatio < 1)
	{
		box_z = height;
		box_y = height / aspectRatio;
	}
	else
	{
		box_y = height;
		box_z = aspectRatio * height;
	}
EXCEPTION_BLOCK
(
	if((box_x == 0) || (box_y == 0) || (box_z == 0))
		throw_exception(DIVIDE_BY_ZERO);
	if((box_x < 0) || (box_y < 0) || (box_z < 0))
		throw_exception(NEGATIVE_VALUE);
)
	float t = 1 / box_x;
	return (mat4_t)
	{
		0, 0, 2 / box_z, 0,
		0, 2 / box_y, 0, 0,
		t, 0, 0, - nearClipPlane * t,
		0, 0, 0, 1
	};
}

HPML_API mat4_t mat4_ortho_projection2(float nearClipPlane, float farClipPlane, float height, float aspectRatio)
{
	float box_x = farClipPlane - nearClipPlane;
	float box_y;
	float box_z;
		box_y = height;
		box_z = aspectRatio * height;
EXCEPTION_BLOCK
(
	if((box_x == 0) || (box_y == 0) || (box_z == 0))
		throw_exception(DIVIDE_BY_ZERO);
	if((box_x < 0) || (box_y < 0) || (box_z < 0))
		throw_exception(NEGATIVE_VALUE);
)
	float t = 1 / box_x;
	return (mat4_t)
	{
		0, 0, 2 / box_z, 0,
		0, 2 / box_y, 0, 0,
		t, 0, 0, - nearClipPlane * t,
		0, 0, 0, 1
	};
}

HPML_API mat4_t mat4_persp_projection(float nearClipPlane, float farClipPlane, float fieldOfView, float aspectRatio)
{
EXCEPTION_BLOCK
(
	if((farClipPlane < nearClipPlane) || (fieldOfView < 0))
		throw_exception(NEGATIVE_VALUE);
	if((farClipPlane == nearClipPlane) || (fieldOfView == 0))
		throw_exception(DIVIDE_BY_ZERO);
)
	float temp = 1 / tan(fieldOfView * 0.5f);
	float m02, m11;
	if(aspectRatio < 1)
	{
		m02 = temp;
		m11 = temp * aspectRatio;
	}
	else
	{
		m02 = temp / aspectRatio;
		m11 = temp;
	}
	float t = farClipPlane / (farClipPlane - nearClipPlane);
	return (mat4_t)
	{
		0,   0, m02, 0,
		0, m11,   0, 0,
		t,   0,   0, -nearClipPlane * t,
		1,   0,   0, 0,
	};
}

HPML_API vec4_t mat4_mul_vec4(mat4_t mat, float x, float y, float z, float w)
{
	vec4_t _mat =
	{
		mat.m00 * x + mat.m01 * y + mat.m02 * z +  mat.m03 * w,
		mat.m10 * x + mat.m11 * y + mat.m12 * z +  mat.m13 * w,
		mat.m20 * x + mat.m21 * y + mat.m22 * z +  mat.m23 * w,
		mat.m30 * x + mat.m31 * y + mat.m32 * z +  mat.m33 * w
	};
	return _mat;
}

/*
 * | px | 									| nx |	  | nx |
 * | py | - 2 | px - ax, py - ay, pz - az | | ny |  * | ny |
 * | pz |									| nz |	  | nz |
 *
 *
 * | px | 										| nx |	  | nx |
 * | py | - 2 {| px, py, pz | - | ax, ay, az |} | ny |  * | ny |
 * | pz |										| nz |	  | nz |
 *
 *
 * | px | 					  | nx |				| nx |	  	| nx |
 * | py | - 2 {| px, py, pz | | ny |- | ax, ay, az || ny |}  * 	| ny |
 * | pz |					  | nz |				| nz |	  	| nz |
 *
 *
 * I x P - 2 * { transpose(P).N * N - transpose(A).N * N }
 *
 * I x P - 2 * transpose(N) X P * N - 2 * transpose(A).N * N
 *
 * | 1	0	0	0 | | px |					  	| px | | nx | 					   | nx | | nx |
 * | 0	1 	0 	0 | | py | - 2 * | nx ny nz 0 | | py | | ny | - 2 * | ax ay az 1 | | ny | | ny |
 * | 0 	0 	1 	0 | | pz |					 	| pz | | nz |					   | nz | | nz |
 * | 0 	0 	0 	1 | | 1  |						| 1  | | 0  |					   | 0  | | 0  |
 *
 * | 1	0 	0 	0 |   | px  0   0   0 | 	   | nx  0   0   0 |	| nx  ny   nz  0 |   | px  0   0   0 |      | nx  0   0   0 |   | nx  ny  nz  0 |   | ax  0   0   0 |
 * | 0	1	0	0 | X | 0   py  0   0 | -   2  | 0   ny  0   0 | X  | nx  ny   nz  0 | X | 0   py  0   0 |    2 | 0   ny  0   0 | X | nx  ny  nz  0 | X | 0   ay  0   0 |
 * | 0	0 	1 	0 |   | 0   0   pz  0 |	       | 0   0   nz  0 |    | nx  ny   nz  0 |   | 0   0   pz  0 |  -   | 0   0   nz  0 |   | nx  ny  nz  0 |   | 0   0   az  0 |
 * | 0	0	0	1 |   | 0   0   0   1 |	       | 0   0   0   0 |    | nx  ny   nz  0 |   | 0   0   0   1 |      | 0   0   0   0 |   | nx  ny  nz  0 |   | 0   0   0   1 |
 * 		I 					P 							N 					M 					P 					K -->
 *
 * I x P - 2 * N x M x P - K
 * I x P - 2 * N x transpose(transpose(P) x transpose(M)) - K
 * I x P - 2 * transpose(P x transpose(M) x transpose(N)) - K
 * I x P - 2 * transpose(P x transpose(M) x N) - K
 * P - 2 * transpose(P x transpose(M) x N) - K
 * transpose(P - 2 * P x transpose(M) x N) - K
 * transpose(P x (I - 2 * transpose(M) x N)) - K
 * transpose(I - 2 * transpose(M) x N) x P - K
 * (I - 2 * N x M) x P - K 
 *
 * Since we are just considering the plane passing through the origin (0, 0, 0), we can assume K = 0 (null matrix)
 * So, 
 * Reflection Matrix [transform] = I - 2 * N x M
 * Reflected Point = Reflection Matrix X P = (I - 2 * N x M) X P
 */
HPML_API mat4_t mat4_reflection(float nx, float ny, float nz)
{
	mat4_t N = mat4_diagonal(nx, ny, nz, 0);
	mat4_t M = 
	{
		nx, ny, nz, 0,
		nx, ny, nz, 0,
		nx, ny, nz, 0,
		nx, ny, nz, 0,
	};
	return mat4_sub(mat4_identity(), mat4_mul_scalar(mat4_mul(2, N, M), 2));
}

HPML_API mat4_t mat4_rotation_x(float angle)
{
	float cos_angle = cos(angle);
	float sin_angle = sin(angle);
	return MAT4
	{
		1, 		   0,		   0, 0,
		0, cos_angle, -sin_angle, 0,
		0, sin_angle, cos_angle,  0,
		0,   	   0, 		   0, 1
	};
}

HPML_API mat4_t mat4_rotation_y(float angle)
{
	float cos_angle = cos(angle);
	float sin_angle = sin(angle);
	return MAT4
	{
		cos_angle, 0, sin_angle, 0,
		0, 		   1, 		  0, 0,
		-sin_angle,0, cos_angle, 0,
		0, 		   0, 		  0, 1
	};
}

HPML_API mat4_t mat4_rotation_z(float angle)
{
	float cos_angle = cos(angle);
	float sin_angle = sin(angle);
	return MAT4
	{
		cos_angle, -sin_angle, 0, 0,
		sin_angle, cos_angle,  0, 0,
		0, 			0, 		   1, 0,
		0, 			0, 		   0, 1
	};
}

HPML_API mat4_t mat4_shear_xy(float angle)
{
	return MAT4
	{
		1, tan(angle), 0, 0,
		0, 			1, 0, 0,
		0, 			0, 1, 0,
		0, 			0, 0, 1
	};
}

HPML_API mat4_t mat4_shear_yx(float angle)
{
	return MAT4
	{
		1, 			0, 0, 0,
		tan(angle), 1, 0, 0,
		0, 			0, 1, 0,
		0, 			0, 0, 1
	};
}

HPML_API mat4_t mat4_shear_zx(float angle)
{
	return MAT4
	{
		1,			0, 0, 0,
		0,			1, 0, 0,
		tan(angle), 1, 0, 0,
		0, 		 	0, 0, 1
	};
}

HPML_API mat4_t mat4_shear_xz(float angle)
{
	return MAT4
	{
		1, 0, tan(angle), 0,
		0, 1, 		   0, 0,
		0, 0, 		   1, 0,
		0, 0,		   0, 1
	};
}

HPML_API mat4_t mat4_shear_yz(float angle)
{
	return MAT4
	{
		1, 0, 		   0, 0,
		0, 1, tan(angle), 0,
		0, 0, 		   1, 0,
		0, 0, 		   0, 1
	};
}

HPML_API mat4_t mat4_shear_zy(float angle)
{
	return MAT4
	{
		1, 			0, 0, 0,
		0, 			1, 0, 0,
		0, tan(angle), 1, 0,
		0, 			0, 0, 1
	};
}

HPML_API mat4_t mat4_translation(float x, float y, float z)
{
	return MAT4
	{
		1, 0, 0, x,
		0, 1, 0, y,
		0, 0, 1, z,
		0, 0, 0, 1
	};
}

HPML_API mat4_t mat4_scale(float x, float y, float z)
{
	return MAT4
	{
		x, 0, 0, 0,
		0, y, 0, 0,
		0, 0, z, 0,
		0, 0, 0, 1
	};
}

HPML_API mat4_t mat4_axis_rotation(float angle, float x, float y, float z)
{
	EXCEPTION_BLOCK(
		if((x == 0) && (y == 0) && (z == 0))
			throw_exception(DIVIDE_BY_ZERO);
	)
	float yangle = atan2(z, x);
	float zangle = atan2(y, x);
	mat4_t ymat = mat4_rotation_y(-yangle);
	mat4_t zmat = mat4_rotation_z(-zangle);
	mat4_t xmat = mat4_rotation_x(angle);
	mat4_t izmat = mat4_inverse(zmat);
	mat4_t iymat = mat4_inverse(ymat);
	return mat4_mul(5, iymat, izmat, xmat, zmat, ymat);
}

HPML_API mat4_t mat4_shear(float xy_angle, float yx_angle, float zx_angle, float xz_angle, float yz_angle, float zy_angle)
{
	mat4_t xy_mat = mat4_shear_xy(xy_angle);
	mat4_t yx_mat = mat4_shear_yx(yx_angle);
	mat4_t zx_mat = mat4_shear_zx(zx_angle);
	mat4_t xz_mat = mat4_shear_xz(xz_angle);
	mat4_t yz_mat = mat4_shear_yz(yz_angle);
	mat4_t zy_mat = mat4_shear_zy(zy_angle);
	return mat4_mul(6, xy_mat, yx_mat, zx_mat, xz_mat, yz_mat, zy_mat);
}
