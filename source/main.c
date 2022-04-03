

#include <hpml/mat4.h>
#include <hpml/vec4.h>
#include <hpml/affine_transformation.h>

#include <hpml/quat.h> 	// quaternions
#include <hpml/constants.h>

#include <stdio.h>

void quaternion_test()
{
	puts("-------------- Quaternion Tests ----------------");

	quat_t q = quat(4, 5, 6, 7);
	quat_t rotor = quat_angle_axis(0, 1, 0, PI * 0.3f);
	quat_print(rotor);

	quat_t q1 = quat_angle_axis(0, 1, 0, PI * 0.3f);
	quat_t q2 = quat_angle_axis(0, 1, 0, PI * 0.6f);

	quat_print(quat_slerp(q1, q2, 0.5f));

	puts("--------------- Success ------------------------");
}

int main()
{
	// Perform quaternion tests
	quaternion_test();


	vec4_t v = vec4_zero();
	vec4_print(v);

	vec4_t v1 = vec4(1, 3, 5, 100);
	vec4_print(v1);

	vec4_print(vec4_add(2, v1, vec4(3.4f, -5.6f, 0.0f, 1.2f)));
	puts("Hello World");


	mat4_t mat =
	{
		0, 1, 2, 3,
		1, 0, 4, 5,
		5, 5, 0, 5,
		7, 2, 4, 0
	};

	printf("Determinant: %f\n", mat4_det(mat));
	return 0;
}