#ifndef __HPML_AFFINE_TRANSFORMATION_TEMPLATE_DEFINITION_H__
#define __HPML_AFFINE_TRANSFORMATION_TEMPLATE_DEFINITION_H__

#include <template_system.h>
#include <no_compile_header.h>

#include <math.h>

/*Begin: Template Definitions*/

/*		Begin: template signatures*/
#define mat4_mul_vec4(T) template(mat4_mul_vec4, T)
#define mat4_translation(T) template(mat4_translation, T)
#define mat4_scale(T) template(mat4_scale, T)
#define mat4_axis_rotation(T) template(mat4_axis_rotation, T)

/*mat4_rotation*/
#define mat4_rotation(T) template(mat4_rotation, T)
#define instantiate_declaration_mat4_rotation(T) mat4_t(T) mat4_rotation(T)(T x, T y, T z)
#define instantiate_implementation_mat4_rotation(T) mat4_t(T) mat4_rotation(T)(T x, T y, T z)\
{\
	return mat4_mul(T)(3, mat4_rotation_x(T)(x), mat4_rotation_y(T)(y), mat4_rotation_z(T)(z));\
}

/*mat4_ortho_projection*/
#define mat4_ortho_projection(T) template(mat4_ortho_projection, T)
#define instantiate_declaration_mat4_ortho_projection(T) mat4_t(T) mat4_ortho_projection(T)(float nearClipPlane, float farClipPlane, float height, float aspectRatio)
#define instantiate_implementation_mat4_ortho_projection(T) mat4_t(T) mat4_ortho_projection(T)(float nearClipPlane, float farClipPlane, float height, float aspectRatio)\
{\
	float box_x = farClipPlane - nearClipPlane;\
	float box_y = height;\
	float box_z = aspectRatio * height;\
EXCEPTION_BLOCK\
(\
	if((box_x == 0) || (box_y == 0) || (box_z == 0))\
		throw_exception(DIVIDE_BY_ZERO);\
	if((box_x < 0) || (box_y < 0) || (box_z < 0))\
		throw_exception(NEGATIVE_VALUE);\
)\
	return mat4_scale(T)(1 / box_x, 2 / box_y, 2 / box_z );\
}

/*mat4_persp_projection*/
#define mat4_persp_projection(T) template(mat4_persp_projection, T)
#define instantiate_declaration_mat4_persp_projection(T) mat4_t(T) mat4_persp_projection(T)(float nearClipPlane, float farClipPlane, float fieldOfView, float aspectRatio)
#define instantiate_implementation_mat4_persp_projection(T) mat4_t(T) mat4_persp_projection(T)(float nearClipPlane, float farClipPlane, float fieldOfView, float aspectRatio)\
{\
EXCEPTION_BLOCK\
(\
	if((farClipPlane < nearClipPlane) || (fieldOfView < 0))\
		throw_exception(NEGATIVE_VALUE);\
	if((farClipPlane == nearClipPlane) || (fieldOfView == 0))\
		throw_exception(DIVIDE_BY_ZERO);\
)\
	float depth = 1 / (farClipPlane - nearClipPlane);\
	float temp = 2 / tan(fieldOfView * 0.5f);\
	return (mat4_t(T))\
	{\
		depth, 0, 0, 0,\
		0, aspectRatio * temp, 0, 0,\
		0, 0, temp, 0,\
		1, 0, 0, 0,\
	};\
}

#define mat4_shear(T) template(mat4_shear, T)
#define mat4_reflection(T) template(mat4_reflection, T)
#define mat4_shear_xy(T) template(mat4_shear_xy, T)
#define mat4_shear_yx(T) template(mat4_shear_yx, T)
#define mat4_shear_zx(T) template(mat4_shear_zx, T)
#define mat4_shear_xz(T) template(mat4_shear_xz, T)
#define mat4_shear_yz(T) template(mat4_shear_yz, T)
#define mat4_shear_zy(T) template(mat4_shear_zy, T)
#define mat4_rotation_x(T) template(mat4_rotation_x, T)
#define mat4_rotation_y(T) template(mat4_rotation_y, T)
#define mat4_rotation_z(T) template(mat4_rotation_z, T)
/*		End: template signatures*/


/*		Begin: template declarations*/
#define instantiate_declaration_mat4_mul_vec4(T) vec4_t(T) mat4_mul_vec4(T)(mat4_t(T) mat, T x, T y, T z, T w)
#define instantiate_declaration_mat4_translation(T) mat4_t(T) mat4_translation(T)(T x, T y, T z)
#define instantiate_declaration_mat4_scale(T) mat4_t(T) mat4_scale(T)(T x, T y, T z)
#define instantiate_declaration_mat4_axis_rotation(T) mat4_t(T) mat4_axis_rotation(T)(T angle, T x, T y, T z)
#define instantiate_declaration_mat4_shear(T) mat4_t(T) mat4_shear(T)(T xy_angle, T yx_angle, T zx_angle, T xz_angle, T yz_angle, T zy_angle)
#define instantiate_declaration_mat4_reflection(T) mat4_t(T) mat4_reflection(T)(T nx, T ny, T nz)
#define instantiate_declaration_mat4_shear_xy(T) mat4_t(T) mat4_shear_xy(T)(T angle)
#define instantiate_declaration_mat4_shear_yx(T) mat4_t(T) mat4_shear_yx(T)(T angle)
#define instantiate_declaration_mat4_shear_zx(T) mat4_t(T) mat4_shear_zx(T)(T angle)
#define instantiate_declaration_mat4_shear_xz(T) mat4_t(T) mat4_shear_xz(T)(T angle)
#define instantiate_declaration_mat4_shear_yz(T) mat4_t(T) mat4_shear_yz(T)(T angle)
#define instantiate_declaration_mat4_shear_zy(T) mat4_t(T) mat4_shear_zy(T)(T angle)
#define instantiate_declaration_mat4_rotation_x(T) mat4_t(T) mat4_rotation_x(T)(T angle)
#define instantiate_declaration_mat4_rotation_y(T) mat4_t(T) mat4_rotation_y(T)(T angle)
#define instantiate_declaration_mat4_rotation_z(T) mat4_t(T) mat4_rotation_z(T)(T angle)
/*		End: template declarations*/


/* 		Begin: template implementations*/

/* mat4_mul_with_vect4(T): Multiplies a vector4 components with matrix 4x4
 * mat4_t(T) mat: 4x4 matrix involved in the multiplication
 * T x: x-component of the vector4
 * T y: y-component of the vector4
 * T z: z-component of the vector4
 * T w: w-component of the vector4
 * returns: vec4_t(T) resultant vector4
 */
#define instantiate_implementation_mat4_mul_vec4(T)\
vec4_t(T) mat4_mul_vec4(T)(mat4_t(T) mat, T x, T y, T z, T w)\
{\
	vec4_t(T) _mat =\
	{\
		mat.m00 * x + mat.m01 * y + mat.m02 * z +  mat.m03 * w,\
		mat.m10 * x + mat.m11 * y + mat.m12 * z +  mat.m13 * w,\
		mat.m20 * x + mat.m21 * y + mat.m22 * z +  mat.m23 * w,\
		mat.m30 * x + mat.m31 * y + mat.m32 * z +  mat.m33 * w\
	};\
	return _mat;\
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
/* mat4_reflection(T): Creates a 4x4 reflection matrix for the plane passing through origin (0, 0, 0) having normal as (nx, ny, nz)
 * T nx: x-component of the normal of the plane
 * T ny: y-component of the normal of the plane
 * T nz: z-component of the normal of the plane
 * returns: mat4_t(T) 4x4 reflection matrix
 */
#define instantiate_implementation_mat4_reflection(T)\
mat4_t(T) mat4_reflection(T)(T nx, T ny, T nz)\
{\
	mat4_t(T) N = mat4_diagonal(T)(nx, ny, nz, 0);\
	mat4_t(T) M = \
	{\
		nx, ny, nz, 0,\
		nx, ny, nz, 0,\
		nx, ny, nz, 0,\
		nx, ny, nz, 0,\
	};\
	return mat4_sub(T)(mat4_identity(T)(), mat4_mul_scalar(T)(mat4_mul(T)(2, N, M), 2));\
}

/* mat4_rotation_x(T): Creates a 4x4 rotation matrix along x axis [ in yz plane]
 * T angle: angle of rotation
 * returns: mat4_t(T) 4x4 rotation matrix
 */
#define instantiate_implementation_mat4_rotation_x(T)\
mat4_t(T) mat4_rotation_x(T)(T angle)\
{\
	T cos_angle = cos(angle);\
	T sin_angle = sin(angle);\
	mat4_t(T) mat =\
	{\
		1, 		   0,		   0, 0,\
		0, cos_angle, -sin_angle, 0,\
		0, sin_angle, cos_angle,  0,\
		0,   	   0, 		   0, 1\
	};\
	return mat;\
}

/* mat4_rotation_y(T): Creates a 4x4 rotation matrix along y axis [ in zx plane]
 * T angle: angle of rotation
 * returns: mat4_t(T) 4x4 rotation matrix
 */
#define instantiate_implementation_mat4_rotation_y(T)\
mat4_t(T) mat4_rotation_y(T)(T angle)\
{\
	T cos_angle = cos(angle);\
	T sin_angle = sin(angle);\
	mat4_t(T) mat =\
	{\
		cos_angle, 0, sin_angle, 0,\
		0, 		   1, 		  0, 0,\
		-sin_angle,0, cos_angle, 0,\
		0, 		   0, 		  0, 1\
	};\
	return mat;\
}

/* mat4_rotation_z(T): Creates a 4x4 rotation matrix along z axis [ in xy plane]
 * T angle: angle of rotation
 * returns: mat4_t(T) 4x4 rotation matrix
 */
#define instantiate_implementation_mat4_rotation_z(T)\
mat4_t(T) mat4_rotation_z(T)(T angle)\
{\
	T cos_angle = cos(angle);\
	T sin_angle = sin(angle);\
	mat4_t(T) mat =\
	{\
		cos_angle, -sin_angle, 0, 0,\
		sin_angle, cos_angle,  0, 0,\
		0, 			0, 		   1, 0,\
		0, 			0, 		   0, 1\
	};\
	return mat;\
}

/*
 * Shear along the x axis in XY plane
 * | 1 tan(0) 0 |
 * | 0   1	  0 | = S(XY)
 * | 0 	 0 	  1 |
 *
 * mat4_scale_xy(T): Calculates a shear 4x4 matrix along x axis in xy plane
 * T angle: displacement angle in xy plane
 * returns: mat4_t(T) shear matrix along x axis in xy plane
 */
#define instantiate_implementation_mat4_shear_xy(T)\
mat4_t(T) mat4_shear_xy(T)(T angle)\
{\
	mat4_t(T) mat =\
	{\
		1, tan(angle), 0, 0,\
		0, 			1, 0, 0,\
		0, 			0, 1, 0,\
		0, 			0, 0, 1\
	};\
	return mat;\
}

/*
 * Shear along the y axis in XY plane
 * | 1	 	0  0 |
 * | tan(0) 1  0 | = S(YX)
 * | 0 	 	0  1 |
 *
 * mat4_scale_yx(T): Calculates a shear 4x4 matrix along y axis in xy plane
 * T angle: displacement angle in xy plane
 * returns: mat4_t(T) shear matrix along y axis in xy plane
 */
#define instantiate_implementation_mat4_shear_yx(T)\
mat4_t(T) mat4_shear_yx(T)(T angle)\
{\
	mat4_t(T) mat =\
	{\
		1, 			0, 0, 0,\
		tan(angle), 1, 0, 0,\
		0, 			0, 1, 0,\
		0, 			0, 0, 1\
	};\
	return mat;\
}

/*
 * Shear along the z axis in ZX plane
 * | 1	 	0  0 |
 * | 0		1  0 | = S(ZX)
 * | tan(0) 0  1 |
 *
 * mat4_scale_zx(T): Calculates a shear 4x4 matrix along z axis in zx plane
 * T angle: displacement angle in zx plane
 * returns: mat4_t(T) shear matrix along z axis in zx plane
 */
#define instantiate_implementation_mat4_shear_zx(T)\
mat4_t(T) mat4_shear_zx(T)(T angle)\
{\
	mat4_t(T) mat =\
	{\
		1,			0, 0, 0,\
		0,			1, 0, 0,\
		tan(angle), 1, 0, 0,\
		0, 		 	0, 0, 1\
	};\
	return mat;\
}

/*
 * Shear along the x axis in XZ plane
 * | 1  0  tan(0) |
 * | 0  1	  	0 | = S(XZ)
 * | 0  0 	    1 |
 *
 * mat4_scale_xz(T): Calculates a shear 4x4 matrix along x axis in xz plane
 * T angle: displacement angle in xz plane
 * returns: mat4_t(T) shear matrix along x axis in xz plane
 */
#define instantiate_implementation_mat4_shear_xz(T)\
mat4_t(T) mat4_shear_xz(T)(T angle)\
{\
	mat4_t(T) mat =\
	{\
		1, 0, tan(angle), 0,\
		0, 1, 		   0, 0,\
		0, 0, 		   1, 0,\
		0, 0,		   0, 1\
	};\
	return mat;\
}

/*
 * Shear along the y axis in YZ plane
 * | 1  0  		0 |
 * | 0  1  tan(0) | = S(YZ)
 * | 0  0 	    1 |
 *
 * mat4_scale_yz(T): Calculates a shear 4x4 matrix along y axis in yz plane
 * T angle: displacement angle in yz plane
 * returns: mat4_t(T) shear matrix along y axis in yz plane
 */
#define instantiate_implementation_mat4_shear_yz(T)\
mat4_t(T) mat4_shear_yz(T)(T angle)\
{\
	mat4_t(T) mat =\
	{\
		1, 0, 		   0, 0,\
		0, 1, tan(angle), 0,\
		0, 0, 		   1, 0,\
		0, 0, 		   0, 1\
	};\
	return mat;\
}

/*
 * Shear along the z axis in ZY plane
 * | 1  0  		0 |
 * | 0  1  		0 | = S(ZY)
 * | 0  tan(0)  1 |
 *
 * mat4_scale_zy(T): Calculates a shear 4x4 matrix along y axis in zy plane
 * T angle: displacement angle in zy plane
 * returns: mat4_t(T) shear matrix along y axis in zy plane
 */
#define instantiate_implementation_mat4_shear_zy(T)\
mat4_t(T) mat4_shear_zy(T)(T angle)\
{\
	mat4_t(T) mat =\
	{\
		1, 			0, 0, 0,\
		0, 			1, 0, 0,\
		0, tan(angle), 1, 0,\
		0, 			0, 0, 1\
	};\
	return mat;\
}

/*
 * mat4_translation(T): Calculates a translation 4x4 matrix having vec3(x, y, z) displacement
 * T x: x-component of the displacement vector
 * T y: y-component of the displacement vector
 * T z: z-component of the displacement vector
 * returns: mat4_t(T) translation matrix having vec3(x, y, z) displacement
 */
#define instantiate_implementation_mat4_translation(T)\
mat4_t(T) mat4_translation(T)(T x, T y, T z)\
{\
	mat4_t(T) mat = \
	{\
		1, 0, 0, x,\
		0, 1, 0, y,\
		0, 0, 1, z,\
		0, 0, 0, 1\
	};\
	return mat;\
}

/*
 * mat4_scale(T): Calculates a scale 4x4 matrix having the scale factors as x [in x dir], y [in y dir], and z [in z dir]
 * T x: scale factor in x direction
 * T y: scale factor in y direction
 * T z: scale factor in z direction
 * returns: mat4_t(T) scale matrix having (x, y, z) scale factors
 */
#define instantiate_implementation_mat4_scale(T)\
mat4_t(T) mat4_scale(T)(T x, T y, T z)\
{\
	mat4_t(T) mat =\
	{\
		x, 0, 0, 0,\
		0, y, 0, 0,\
		0, 0, z, 0,\
		0, 0, 0, 1\
	};\
	return mat;\
}

/*
 * mat4_axis_rotation(T): Calculates a 4x4 rotation matrix having angle of rotation 'angle' around the unit axis '(x, y, z)'
 * T angle: angle of rotation in radians
 * T x: x-component of the unit axis vector
 * T y: y-component of the unit axis vector
 * T z: z-component of the unit axis vector
 * returns: mat4_t(T) resultant rotation matrix
 */
#define instantiate_implementation_mat4_axis_rotation(T)\
mat4_t(T) mat4_axis_rotation(T)(T angle, T x, T y, T z)\
{\
	EXCEPTION_BLOCK(\
		if((x == 0) && (y == 0) && (z == 0))\
			throw_exception(DIVIDE_BY_ZERO);\
	)\
	T yangle = atan2(z, x);\
	T zangle = atan2(y, x);\
	mat4_t(T) ymat = mat4_rotation_y(T)(-yangle);\
	mat4_t(T) zmat = mat4_rotation_z(T)(-zangle);\
	mat4_t(T) xmat = mat4_rotation_x(T)(angle);\
	mat4_t(T) izmat = mat4_inverse(T)(zmat);\
	mat4_t(T) iymat = mat4_inverse(T)(ymat);\
	return mat4_mul(T)(5, iymat, izmat, xmat, zmat, ymat);\
}

/*
 * mat4_shear(T): Calculates a shear 4x4 matrix in 3D space [XY plane, ZX plane, and YZ plane]
 * T xy_angle: angle for the shear in x direction in xy plane
 * T yx_angle: angle for the shear in y direction in xy plane
 * T zx_angle: angle for the shear in z direction in zx plane
 * T xz_angle: angle for the shear in x direction in xz plane
 * T yz_angle: angle for the shear in y direction in yz plane
 * T zy_angle: angle for the shear in z direction in zy plane
 * returns: mat4_t(T) shear matrix in 3D space
 */
#define instantiate_implementation_mat4_shear(T)\
mat4_t(T) mat4_shear(T)(T xy_angle, T yx_angle, T zx_angle, T xz_angle, T yz_angle, T zy_angle)\
{\
	mat4_t(T) xy_mat = mat4_shear_xy(T)(xy_angle);\
	mat4_t(T) yx_mat = mat4_shear_yx(T)(yx_angle);\
	mat4_t(T) zx_mat = mat4_shear_zx(T)(zx_angle);\
	mat4_t(T) xz_mat = mat4_shear_xz(T)(xz_angle);\
	mat4_t(T) yz_mat = mat4_shear_yz(T)(yz_angle);\
	mat4_t(T) zy_mat = mat4_shear_zy(T)(zy_angle);\
	return mat4_mul(T)(6, xy_mat, yx_mat, zx_mat, xz_mat, yz_mat, zy_mat);\
}
/*		End: template implementations*/

/*End: Template Definitions*/

#endif /*__HPML_AFFINE_TRANSFORMATION_TEMPLATE_DEFINITION_H__*/