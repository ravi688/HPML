
/*Implemented*/
#include <vec2/header_config.h>
#include <vec2/vec2.h>

/*Implemented*/
#include <mat22/header_config.h>
#include <mat22/mat22.h>

/*Implemented*/
#include <mat4/header_config.h>
#include <mat4/mat4.h>

/*In-Progress*/
#include <affine_transformation/header_config.h>
#include <affine_transformation/affine_transformation.h>

/*To be started*/
#include <quat/header_config.h>
#include <quat/quat.h>

#include <stdio.h>
#include <tests.h>
#include <exception/exception.h>

int main(int argc, char** argv)
{
	mat4_t(float) m1 = mat4(float)(
		1, 2, 123, 4,
		5, 6, 7, 8,
		9, 10, 11, 12,
		13, 12, 15, 19);
	mat4_print(float)(m1);

	mat4_t(float) m2 = 
	{
		-1, -2, -3, -4, 
		-5, -6, -7, -8,
		-9, -10, -11, -12,
		-13, -14, -15, -16
	}; 

	mat4_print(float)(mat4_add(float)(m1, m2));
	mat4_print(float)(mat4_sub(float)(m1, m2));
	mat4_print(float)(mat4_mul(float)(m1, m2)); 
	mat4_print(float)(mat4_transpose(float)(m1)); 
	mat4_print(float)(mat4_transpose(float)(m2)); 
	mat4_print(float)(mat4_inverse(float)(m1));

	mat4_t(float) shear_mat = mat4_shear(float)(0.123f, 0.453f, 0.1287f, 0.345f, 0.986f, 0.321f);
	puts("Shear Matrix: ");
	mat4_print(float)(shear_mat);


	mat4_t(float) null_matrix = 
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 1, 0
	};
	if(mat4_is_null(float)(null_matrix))
		puts("matrix is null"); 
	else puts("matrix is not null"); 


	return 0;
}