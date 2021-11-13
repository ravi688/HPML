

#include <tests.h>

#include <vec2/header_config.h>
#include <vec2/vec2.h>
#include <mat2/header_config.h>
#include <mat2/mat2.h>

#include <stdio.h>

void vec2_test()
{
	/*test for vec2 constructor, vec2_add, and vec2_print*/
	puts("[TEST] vec2(), vec2_add(), and vec2_print()");
	vec2_t(float) v1 = vec2(float)(1.0f, 1.0f); 
	vec2_t(float) v2 = vec2(float)(2.0f, 2.0f);
	vec2_t(float) result = vec2_add(float)(v1, v2);
	if(vec2_is_equal(float)(result, vec2(float)(3.0f, 3.0f)))
		puts("Passed"); 
	else puts("Failed");

	/*test for vec2_sub*/
	puts("[TEST] vec2_sub()");
	result = vec2_sub(float)(v1, v2);
	if(vec2_is_equal(float)(result, vec2(float)(-1.0f, -1.0f)))
		puts("Passed");
	else puts("Failed");

	/*test for vec2_mul*/
	puts("[TEST] vec2_mul()");
	result = vec2_mul(float)(v1, v2);
	if(vec2_is_equal(float)(result, vec2(float)(2.0f, 2.0f)))
		puts("Passed");
	else puts("Failed");

	/*test for vec2_div*/
	puts("[TEST] vec2_div()"); 
	result = vec2_div(float)(v1, v2);
	if(vec2_is_equal(float)(result, vec2(float)(0.5f, 0.5f)))
		puts("Passed");
	else puts("Failed");

	/*test for vec2_is_null()*/
	puts("[TEST] vec2_is_null()");
	vec2_t(float) null_vector = vec2_null(float)();
	result = vec2_mul(float)(vec2(float)(1.0f, 1.0f), null_vector);
	if(vec2_is_equal(float)(result, null_vector))
		puts("Passed");
	else
		puts("Failed");

	/*test for vec2_is_equal()*/
	puts("[TEST] vec2_is_equal()");
	if(vec2_is_equal(float)(vec2(float)(3.4f, 3.4f), vec2(float)(3.4f, 3.4f)))
		puts("Passed");
	else puts("Failed");

	/*test for vec2_dot()*/
	float dot_product = vec2_dot(float)(vec2_up(float)(), vec2_right(float)());
	if(dot_product == 0.0f)
		puts("Passed"); 
	else puts("Failed");

	/*test for vec2_magnitude()*/
	float magnitude = vec2_magnitude(float)(vec2(float)(1.0f, 0.0f));
	if(magnitude == 1.0f)
		puts("P"); 
	else puts("F"); 

	/*test for vec2_sqrmagnitude()*/
	float sqr_magnitude = vec2_sqrmagnitude(float)(vec2(float)(1.0f, 1.0f)); 
	if(sqr_magnitude == 2.0f)
		puts("P"); 
	else puts("F");

	/*test for vec2_negate()*/
	if(vec2_is_equal(float)(vec2_negate(float)(vec2(float)(1.0f, 2.0f)), vec2(float)(-1.0f, -2.0f)))
		puts("P"); 
	else puts("F");

	/*test for vec2_magnitude()*/
	if(vec2_magnitude(float)(vec2_normalize(float)(vec2(float)(1.0f, 2.0f))) == 1.0f)
		puts("P"); 
	else puts("F");

	/*test for vec2_rotate()*/
	vec2_t(float) rotated_vector = vec2_rotate(float)(vec2_up(float)(), 1.57f); 
	float angle = vec2_angle(float)(rotated_vector, vec2_up(float)()); 
	if((angle >= 1.40f) && (angle <= 1.70f))
		puts("P"); 
	else puts("F"); 
}

void mat2_test()
{
		mat2_t(float) m1 = mat2(float)(1.0f, 2.0f, 3.0f, 4.0f); 
	mat2_print(float)(m1);
	mat2_t(float) m2 = mat2(float)(-1.0f, -2.0f, -3.0f, -4.0f); 
	mat2_print(float)(m2); 

	puts("mat2_add()");
	mat2_print(float)(mat2_add(float)(m1, m2)); 
	puts("mat2_sub()");
	mat2_print(float)(mat2_sub(float)(m1, m2)); 
	puts("mat2_mul()");
	mat2_print(float)(mat2_mul(float)(m1, m2)); 
	puts("mat2_mul_component_wise()");
	mat2_print(float)(mat2_mul_component_wise(float)(m1, m2)); 
	puts("mat2_div()");
	mat2_print(float)(mat2_div(float)(m1, m2)); 
	puts("mat2_trace()"); 
	printf("Trace of {1.0f, 2.0f, 3.0f, 4.0f }: %f\n", mat2_trace(float)(m1));
	puts("mat2_null()"); 
	puts("mat2_identity()"); 
	mat2_print(float)(mat2_identity(float)); 
	puts("mat2_negate()"); 
	mat2_print(float)(mat2(float)(1.0f, 1.0f, 1.0f, 1.0f)); 
	mat2_print(float)(mat2_negate(float)(mat2(float)(1.0f, 1.0f, 1.0f, 1.0f)));
	puts("mat2_lerp()"); 
	mat2_t(float) m3 = mat2(float)(1.0f, 1.0f, 1.0f, 1.0f); 
	mat2_t(float) m4 = mat2(float)(3.0f, 3.0f, 3.0f, 3.0f); 
	mat2_t(float) lerp_m = mat2_lerp(float)(m3, m4, 0.5f); 
	mat2_print(float)(lerp_m);
	puts("mat2_mul_scalar()"); 
	mat2_print(float)(mat2_mul_with_scalar(float)(mat2(float)(1.0f, 1.0f, 1.0f, 1.0f), 5.0f)); 


	puts("mat2_transpose()");
	mat2_t(float) m5 = 
	{
		1.0f, 2.0f,
		3.0f, 4.0f
	};
	mat2_print(float)(m5);
	mat2_print(float)(mat2_transpose(float)(m5));

	puts("mat2_inverse()"); 
	mat2_print(float)(m5);
	mat2_print(float)(mat2_inverse(float)(mat2_null(float)));
	mat2_print(float)(mat2_inverse(float)(mat2_inverse(float)(m5))); 

}