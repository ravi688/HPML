

#include <tests.h>

#include <vec2/header_config.h>
#include <vec2/vec2.h>
#include <mat22/header_config.h>
#include <mat22/mat22.h>

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

void mat22_test()
{
		mat22_t(float) m1 = mat22(float)(1.0f, 2.0f, 3.0f, 4.0f); 
	mat22_print(float)(m1);
	mat22_t(float) m2 = mat22(float)(-1.0f, -2.0f, -3.0f, -4.0f); 
	mat22_print(float)(m2); 

	puts("mat22_add()");
	mat22_print(float)(mat22_add(float)(m1, m2)); 
	puts("mat22_sub()");
	mat22_print(float)(mat22_sub(float)(m1, m2)); 
	puts("mat22_mul()");
	mat22_print(float)(mat22_mul(float)(m1, m2)); 
	puts("mat22_mul_component_wise()");
	mat22_print(float)(mat22_mul_component_wise(float)(m1, m2)); 
	puts("mat22_div()");
	mat22_print(float)(mat22_div(float)(m1, m2)); 
	puts("mat22_trace()"); 
	printf("Trace of {1.0f, 2.0f, 3.0f, 4.0f }: %f\n", mat22_trace(float)(m1));
	puts("mat22_null()"); 
	puts("mat22_identity()"); 
	mat22_print(float)(mat22_identity(float)); 
	puts("mat22_negate()"); 
	mat22_print(float)(mat22(float)(1.0f, 1.0f, 1.0f, 1.0f)); 
	mat22_print(float)(mat22_negate(float)(mat22(float)(1.0f, 1.0f, 1.0f, 1.0f)));
	puts("mat22_lerp()"); 
	mat22_t(float) m3 = mat22(float)(1.0f, 1.0f, 1.0f, 1.0f); 
	mat22_t(float) m4 = mat22(float)(3.0f, 3.0f, 3.0f, 3.0f); 
	mat22_t(float) lerp_m = mat22_lerp(float)(m3, m4, 0.5f); 
	mat22_print(float)(lerp_m);
	puts("mat22_mul_scalar()"); 
	mat22_print(float)(mat22_mul_with_scalar(float)(mat22(float)(1.0f, 1.0f, 1.0f, 1.0f), 5.0f)); 


	puts("mat22_transpose()");
	mat22_t(float) m5 = 
	{
		1.0f, 2.0f,
		3.0f, 4.0f
	};
	mat22_print(float)(m5);
	mat22_print(float)(mat22_transpose(float)(m5));

	puts("mat22_inverse()"); 
	mat22_print(float)(m5);
	mat22_print(float)(mat22_inverse(float)(mat22_null(float)));
	mat22_print(float)(mat22_inverse(float)(mat22_inverse(float)(m5))); 

}