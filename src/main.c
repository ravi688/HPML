
/*Implemented*/
#include <vec2/header_config.h>
#include <vec2/vec2.h>

/*Implemented*/
#include <mat22/header_config.h>
#include <mat22/mat22.h>

/*Implemented*/
#include <mat44/header_config.h>
#include <mat44/mat44.h>

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
	mat44_t(float) m1 = mat44(float)(
		1, 2, 123, 4,
		5, 6, 7, 8,
		9, 10, 11, 12,
		13, 12, 15, 19);
	mat44_print(float)(m1);

	mat44_t(float) m2 = 
	{
		-1, -2, -3, -4, 
		-5, -6, -7, -8,
		-9, -10, -11, -12,
		-13, -14, -15, -16
	}; 

	mat44_print(float)(mat44_add(float)(m1, m2));
	mat44_print(float)(mat44_sub(float)(m1, m2));
	mat44_print(float)(mat44_mul(float)(m1, m2)); 
	mat44_print(float)(mat44_transpose(float)(m1)); 
	mat44_print(float)(mat44_transpose(float)(m2)); 
	mat44_print(float)(mat44_inverse(float)(m1));

	mat44_t(float) shear_mat = mat44_shear(float)(0.123f, 0.453f, 0.1287f, 0.345f, 0.986f, 0.321f);
	puts("Shear Matrix: ");
	mat44_print(float)(shear_mat);


	mat44_t(float) null_matrix = 
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 1, 0
	};
	if(mat44_is_null(float)(null_matrix))
		puts("matrix is null"); 
	else puts("matrix is not null"); 


	return 0;
}