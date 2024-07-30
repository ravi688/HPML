#pragma once

#include <hpml/mat4.h>      // mat4_t
#include <hpml/vec4.h>      // vec4_t

#ifdef __cplusplus
    extern "C" {
#endif

/* mat4_rotation: Creates a euler angles rotation matrix
 * x: angle of rotation around x-axis in radians
 * y: angle of rotation around y-axis in radians
 * z: angle of rotation around z-axis in radians
 * returns: a rotation matrix of order 4x4 (alpha, beta, gamma) euler angles
 */
HPML_API mat4_t mat4_rotation(float x, float y, float z);

/* mat4_ortho_projection: Creates a orthographic projection matrix
 * nearClipPlane: position of the near clip plane relative to the camera, +ve means front and -ve means back
 * farClipPlane: position of the far clip plane relative to the camera, +ve means front and -ve means back
 * height: height of the canonical view volume
 * aspectRatio: aspect ratio of the screen window
 */
HPML_API mat4_t mat4_ortho_projection(float nearClipPlane, float farClipPlane, float height, float aspectRatio);

HPML_API mat4_t mat4_ortho_projection2(float nearClipPlane, float farClipPlane, float height, float aspectRatio);

/* mat4_persp_projection: Creates a perspective projection matrix
 * nearClipPlane: position of the near clip plane relative to the camera, +ve means front and -ve means back
 * farClipPlane: position of the far clip plane relative to the camera, +ve means front and -ve means back
 * fieldOfView: vertical angle of the view frustm (canoncial volume)
 * aspectRatio: aspect ratio of the screen window
 */
HPML_API mat4_t mat4_persp_projection(float nearClipPlane, float farClipPlane, float fieldOfView, float aspectRatio);


/* mat4_mul_with_vect4: Multiplies a vector4 components with matrix 4x4
 * mat4_t mat: 4x4 matrix involved in the multiplication
 * float x: x-component of the vector4
 * float y: y-component of the vector4
 * float z: z-component of the vector4
 * float w: w-component of the vector4
 * returns: vec4_t resultant vector4
 */
HPML_API vec4_t mat4_mul_vec4(mat4_t mat, float x, float y, float z, float w);

/* mat4_reflection: Creates a 4x4 reflection matrix for the plane passing through origin (0, 0, 0) having normal as (nx, ny, nz)
 * float nx: x-component of the normal of the plane
 * float ny: y-component of the normal of the plane
 * float nz: z-component of the normal of the plane
 * returns: mat4_t 4x4 reflection matrix
 */
HPML_API mat4_t mat4_reflection(float nx, float ny, float nz);

/* mat4_rotation_x: Creates a 4x4 rotation matrix along x axis [ in yz plane]
 * float angle: angle of rotation
 * returns: mat4_t 4x4 rotation matrix
 */
HPML_API mat4_t mat4_rotation_x(float angle);

/* mat4_rotation_y: Creates a 4x4 rotation matrix along y axis [ in zx plane]
 * float angle: angle of rotation
 * returns: mat4_t 4x4 rotation matrix
 */
HPML_API mat4_t mat4_rotation_y(float angle);

/* mat4_rotation_z: Creates a 4x4 rotation matrix along z axis [ in xy plane]
 * float angle: angle of rotation
 * returns: mat4_t 4x4 rotation matrix
 */
HPML_API mat4_t mat4_rotation_z(float angle);

/*
 * Shear along the x axis in XY plane
 * | 1 tan(0) 0 |
 * | 0   1	  0 | = S(XY)
 * | 0 	 0 	  1 |
 *
 * mat4_scale_xy: Calculates a shear 4x4 matrix along x axis in xy plane
 * float angle: displacement angle in xy plane
 * returns: mat4_t shear matrix along x axis in xy plane
 */
HPML_API mat4_t mat4_shear_xy(float angle);

/*
 * Shear along the y axis in XY plane
 * | 1	 	0  0 |
 * | tan(0) 1  0 | = S(YX)
 * | 0 	 	0  1 |
 *
 * mat4_scale_yx: Calculates a shear 4x4 matrix along y axis in xy plane
 * float angle: displacement angle in xy plane
 * returns: mat4_t shear matrix along y axis in xy plane
 */
HPML_API mat4_t mat4_shear_yx(float angle);

/*
 * Shear along the z axis in ZX plane
 * | 1	 	0  0 |
 * | 0		1  0 | = S(ZX)
 * | tan(0) 0  1 |
 *
 * mat4_scale_zx: Calculates a shear 4x4 matrix along z axis in zx plane
 * float angle: displacement angle in zx plane
 * returns: mat4_t shear matrix along z axis in zx plane
 */
HPML_API mat4_t mat4_shear_zx(float angle);

/*
 * Shear along the x axis in XZ plane
 * | 1  0  tan(0) |
 * | 0  1	  	0 | = S(XZ)
 * | 0  0 	    1 |
 *
 * mat4_scale_xz: Calculates a shear 4x4 matrix along x axis in xz plane
 * float angle: displacement angle in xz plane
 * returns: mat4_t shear matrix along x axis in xz plane
 */
HPML_API mat4_t mat4_shear_xz(float angle);

/*
 * Shear along the y axis in YZ plane
 * | 1  0  		0 |
 * | 0  1  tan(0) | = S(YZ)
 * | 0  0 	    1 |
 *
 * mat4_scale_yz: Calculates a shear 4x4 matrix along y axis in yz plane
 * float angle: displacement angle in yz plane
 * returns: mat4_t shear matrix along y axis in yz plane
 */
HPML_API mat4_t mat4_shear_yz(float angle);

/*
 * Shear along the z axis in ZY plane
 * | 1  0  		0 |
 * | 0  1  		0 | = S(ZY)
 * | 0  tan(0)  1 |
 *
 * mat4_scale_zy: Calculates a shear 4x4 matrix along y axis in zy plane
 * float angle: displacement angle in zy plane
 * returns: mat4_t shear matrix along y axis in zy plane
 */
HPML_API mat4_t mat4_shear_zy(float angle);

/*
 * mat4_translation: Calculates a translation 4x4 matrix having vec3(x, y, z) displacement
 * float x: x-component of the displacement vector
 * float y: y-component of the displacement vector
 * float z: z-component of the displacement vector
 * returns: mat4_t translation matrix having vec3(x, y, z) displacement
 */
HPML_API mat4_t mat4_translation(float x, float y, float z);
static HPML_FORCE_INLINE mat4_t mat4_translation_v(vec3_t disp_vector) { return mat4_translation(disp_vector.x, disp_vector.y, disp_vector.z); }

/*
 * mat4_scale: Calculates a scale 4x4 matrix having the scale factors as x [in x dir], y [in y dir], and z [in z dir]
 * float x: scale factor in x direction
 * float y: scale factor in y direction
 * float z: scale factor in z direction
 * returns: mat4_t scale matrix having (x, y, z) scale factors
 */
HPML_API mat4_t mat4_scale(float x, float y, float z);

/*
 * mat4_axis_rotation: Calculates a 4x4 rotation matrix having angle of rotation 'angle' around the unit axis '(x, y, z)'
 * float angle: angle of rotation in radians
 * float x: x-component of the unit axis vector
 * float y: y-component of the unit axis vector
 * float z: z-component of the unit axis vector
 * returns: mat4_t resultant rotation matrix
 */
HPML_API mat4_t mat4_axis_rotation(float angle, float x, float y, float z);

/*
 * mat4_shear: Calculates a shear 4x4 matrix in 3D space [XY plane, ZX plane, and YZ plane]
 * float xy_angle: angle for the shear in x direction in xy plane
 * float yx_angle: angle for the shear in y direction in xy plane
 * float zx_angle: angle for the shear in z direction in zx plane
 * float xz_angle: angle for the shear in x direction in xz plane
 * float yz_angle: angle for the shear in y direction in yz plane
 * float zy_angle: angle for the shear in z direction in zy plane
 * returns: mat4_t shear matrix in 3D space
 */
HPML_API mat4_t mat4_shear(float xy_angle, float yx_angle, float zx_angle, float xz_angle, float yz_angle, float zy_angle);

#ifdef __cplusplus
 }
#endif
