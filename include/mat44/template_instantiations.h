#ifndef __HPML_MAT44_TEMPLATE_INSTANTIATIONS_H__
#define __HPML_MAT44_TEMPLATE_INSTANTIATIONS_H__

#include <mat44/template_definitions.h>

/*Begin: Template Instantiations*/
instantiate_mat44_struct(int);
instantiate_declaration_mat44(int);
instantiate_declaration_mat44_add(int);
instantiate_declaration_mat44_sub(int);
instantiate_declaration_mat44_mul(int);
instantiate_declaration_mat44_div(int);
instantiate_declaration_mat44_mul_component_wise(int);
instantiate_declaration_mat44_lerp(int);
instantiate_declaration_mat44_print(int);
instantiate_declaration_mat44_is_null(int);
instantiate_declaration_mat44_is_equal(int);
instantiate_declaration_mat44_trace(int);
instantiate_declaration_mat44_negate(int);
instantiate_declaration_mat44_mul_with_scalar(int);
instantiate_declaration_mat44_transpose(int);
instantiate_declaration_mat44_inverse(int);
instantiate_declaration_mat44_diagonal(int);

instantiate_mat44_struct(float);
instantiate_declaration_mat44(float);
instantiate_declaration_mat44_add(float);
instantiate_declaration_mat44_sub(float);
instantiate_declaration_mat44_mul(float);
instantiate_declaration_mat44_div(float);
instantiate_declaration_mat44_mul_component_wise(float);
instantiate_declaration_mat44_lerp(float);
instantiate_declaration_mat44_print(float);
instantiate_declaration_mat44_is_null(float);
instantiate_declaration_mat44_is_equal(float);
instantiate_declaration_mat44_trace(float);
instantiate_declaration_mat44_negate(float);
instantiate_declaration_mat44_mul_with_scalar(float);
instantiate_declaration_mat44_transpose(float);
instantiate_declaration_mat44_inverse(float);
instantiate_declaration_mat44_diagonal(float);

/*End: Template Instantiations*/

#if defined(IMPLEMENTATION)
instantiate_implementation_mat44(int);
instantiate_implementation_mat44_add(int);
instantiate_implementation_mat44_sub(int);
instantiate_implementation_mat44_mul(int);
instantiate_implementation_mat44_div(int);
instantiate_implementation_mat44_mul_component_wise(int);
instantiate_implementation_mat44_lerp(int);
instantiate_implementation_mat44_is_null(int);
instantiate_implementation_mat44_is_equal(int);
instantiate_implementation_mat44_trace(int);
instantiate_implementation_mat44_negate(int);
instantiate_implementation_mat44_mul_with_scalar(int);
instantiate_implementation_mat44_transpose(int);
instantiate_implementation_mat44_inverse(int);
instantiate_implementation_mat44_diagonal(int);

instantiate_implementation_mat44(float);
instantiate_implementation_mat44_add(float);
instantiate_implementation_mat44_sub(float);
instantiate_implementation_mat44_mul(float);
instantiate_implementation_mat44_div(float);
instantiate_implementation_mat44_mul_component_wise(float);
instantiate_implementation_mat44_lerp(float);
instantiate_implementation_mat44_is_null(float);
instantiate_implementation_mat44_is_equal(float);
instantiate_implementation_mat44_trace(float);
instantiate_implementation_mat44_negate(float);
instantiate_implementation_mat44_mul_with_scalar(float);
instantiate_implementation_mat44_transpose(float);
instantiate_implementation_mat44_inverse(float);
instantiate_implementation_mat44_diagonal(float);

void mat44_print(float)(mat44_t(float) m)
{
	printf(	"mat44_t(float):\n"
			"{ %f, %f, %f, %f }\n"
			"{ %f, %f, %f, %f }\n"
			"{ %f, %f, %f, %f }\n"
			"{ %f, %f, %f, %f }\n",
			m.m00, m.m01, m.m02, m.m03,
			m.m10, m.m11, m.m12, m.m13,
			m.m20, m.m21, m.m22, m.m23,
			m.m30, m.m31, m.m32, m.m33);
}
void mat44_print(int)(mat44_t(int) m)
{
	printf(	"mat44_t(int):\n"
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