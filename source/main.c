

#include <hpml/memory/header_config.h>
#include <hpml/memory/memory.h>

#include <hpml/mat4/header_config.h>
#include <hpml/mat4/mat4.h>

#include <hpml/vec4/header_config.h>
#include <hpml/vec4/vec4.h>

#include <hpml/affine_transformation/header_config.h>
#include <hpml/affine_transformation/affine_transformation.h>

#include <hpml/mat4/header_config.h>
#include <hpml/mat4/mat4.h>

#include <stdio.h>

int main()
{
	vec4_t(float) v = vec4_zero(float)();
	vec4_print(float)(v);

	vec4_t(float) v1 = vec4(float)(1, 3, 5, 100);
	vec4_print(float)(v1);

	vec4_print(float)(vec4_add(float)(2, v1, vec4(float)(3.4f, -5.6f, 0.0f, 1.2f)));
	puts("Hello World");


	mat4_t(float) mat =
	{
		0, 1, 2, 3,
		1, 0, 4, 5,
		5, 5, 0, 5,
		7, 2, 4, 0
	};

	printf("Determinant: %f\n", mat4_det(float)(mat));
	return 0;
}