#ifndef __HPML_MAT4_TEMPLATE_INSTANTIATIONS_H__
#define __HPML_MAT4_TEMPLATE_INSTANTIATIONS_H__

#include <mat4/template_definitions.h>

/*Begin: Template Instantiations*/
instantiate_mat4_struct(int);
instantiate_declaration_mat4(int);
instantiate_declaration_mat4_add(int);
instantiate_declaration_mat4_sub(int);
instantiate_declaration_mat4_mul(int);
instantiate_declaration_mat4_div(int);
instantiate_declaration_mat4_mul_component_wise(int);
instantiate_declaration_mat4_lerp(int);
instantiate_declaration_mat4_print(int);
instantiate_declaration_mat4_is_null(int);
instantiate_declaration_mat4_is_equal(int);
instantiate_declaration_mat4_trace(int);
instantiate_declaration_mat4_negate(int);
instantiate_declaration_mat4_mul_with_scalar(int);
instantiate_declaration_mat4_transpose(int);
instantiate_declaration_mat4_inverse(int);
instantiate_declaration_mat4_diagonal(int);

instantiate_mat4_struct(float);
instantiate_declaration_mat4(float);
instantiate_declaration_mat4_add(float);
instantiate_declaration_mat4_sub(float);
instantiate_declaration_mat4_mul(float);
instantiate_declaration_mat4_div(float);
instantiate_declaration_mat4_mul_component_wise(float);
instantiate_declaration_mat4_lerp(float);
instantiate_declaration_mat4_print(float);
instantiate_declaration_mat4_is_null(float);
instantiate_declaration_mat4_is_equal(float);
instantiate_declaration_mat4_trace(float);
instantiate_declaration_mat4_negate(float);
instantiate_declaration_mat4_mul_with_scalar(float);
instantiate_declaration_mat4_transpose(float);
instantiate_declaration_mat4_inverse(float);
instantiate_declaration_mat4_diagonal(float);

/*End: Template Instantiations*/

#if defined(IMPLEMENTATION)
instantiate_implementation_mat4(int);
instantiate_implementation_mat4_add(int);
instantiate_implementation_mat4_sub(int);
instantiate_implementation_mat4_mul(int);
instantiate_implementation_mat4_div(int);
instantiate_implementation_mat4_mul_component_wise(int);
instantiate_implementation_mat4_lerp(int);
instantiate_implementation_mat4_is_null(int);
instantiate_implementation_mat4_is_equal(int);
instantiate_implementation_mat4_trace(int);
instantiate_implementation_mat4_negate(int);
instantiate_implementation_mat4_mul_with_scalar(int);
instantiate_implementation_mat4_transpose(int);
instantiate_implementation_mat4_inverse(int);
instantiate_implementation_mat4_diagonal(int);

instantiate_implementation_mat4(float);
instantiate_implementation_mat4_add(float);
instantiate_implementation_mat4_sub(float);
instantiate_implementation_mat4_mul(float);
instantiate_implementation_mat4_div(float);
instantiate_implementation_mat4_mul_component_wise(float);
instantiate_implementation_mat4_lerp(float);
instantiate_implementation_mat4_is_null(float);
instantiate_implementation_mat4_is_equal(float);
instantiate_implementation_mat4_trace(float);
instantiate_implementation_mat4_negate(float);
instantiate_implementation_mat4_mul_with_scalar(float);
instantiate_implementation_mat4_transpose(float);
instantiate_implementation_mat4_inverse(float);
instantiate_implementation_mat4_diagonal(float);

void mat4_print(float)(mat4_t(float) m)
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
void mat4_print(int)(mat4_t(int) m)
{
	printf(	"mat4_t(int):\n"
		"{ %d, %d, %d, %d }\n"
		"{ %d, %d, %d, %d }\n"
		"{ %d, %d, %d, %d }\n"
		"{ %d, %d, %d, %d }\n",
		m.m00, m.m01, m.m02, m.m03,
		m.m10, m.m11, m.m12, m.m13,
		m.m20, m.m21, m.m22, m.m23,
		m.m30, m.m31, m.m32, m.m33);
}
#endif

#endif