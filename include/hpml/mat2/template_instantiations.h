#ifndef __HPML_MAT2_TEMPLATE_INSTANTIATIONS_H__
#define __HPML_MAT2_TEMPLATE_INSTANTIATIONS_H__

#include <hpml/mat2/template_definitions.h>

/*Begin: Template Instantiations*/
instantiate_mat2_struct(int);
instantiate_declaration_mat2(int);
instantiate_declaration_mat2_add(int);
instantiate_declaration_mat2_sub(int);
instantiate_declaration_mat2_mul(int);
instantiate_declaration_mat2_div(int);
instantiate_declaration_mat2_mul_component_wise(int);
instantiate_declaration_mat2_lerp(int);
instantiate_declaration_mat2_print(int);
instantiate_declaration_mat2_is_null(int);
instantiate_declaration_mat2_is_equal(int);
instantiate_declaration_mat2_trace(int);
instantiate_declaration_mat2_negate(int);
instantiate_declaration_mat2_mul_with_scalar(int);
instantiate_declaration_mat2_transpose(int);
instantiate_declaration_mat2_inverse(int);

instantiate_mat2_struct(float);
instantiate_declaration_mat2(float);
instantiate_declaration_mat2_add(float);
instantiate_declaration_mat2_sub(float);
instantiate_declaration_mat2_mul(float);
instantiate_declaration_mat2_div(float);
instantiate_declaration_mat2_mul_component_wise(float);
instantiate_declaration_mat2_lerp(float);
instantiate_declaration_mat2_print(float);
instantiate_declaration_mat2_is_null(float);
instantiate_declaration_mat2_is_equal(float);
instantiate_declaration_mat2_trace(float);
instantiate_declaration_mat2_negate(float);
instantiate_declaration_mat2_mul_with_scalar(float);
instantiate_declaration_mat2_transpose(float);
instantiate_declaration_mat2_inverse(float);

/*End: Template Instantiations*/

#if defined(IMPLEMENTATION)
instantiate_implementation_mat2(int);
instantiate_implementation_mat2_add(int);
instantiate_implementation_mat2_sub(int);
instantiate_implementation_mat2_mul(int);
instantiate_implementation_mat2_div(int);
instantiate_implementation_mat2_mul_component_wise(int);
instantiate_implementation_mat2_lerp(int);
instantiate_implementation_mat2_is_null(int);
instantiate_implementation_mat2_is_equal(int);
instantiate_implementation_mat2_trace(int);
instantiate_implementation_mat2_negate(int);
instantiate_implementation_mat2_mul_with_scalar(int);
instantiate_implementation_mat2_transpose(int);
instantiate_implementation_mat2_inverse(int);

instantiate_implementation_mat2(float);
instantiate_implementation_mat2_add(float);
instantiate_implementation_mat2_sub(float);
instantiate_implementation_mat2_mul(float);
instantiate_implementation_mat2_div(float);
instantiate_implementation_mat2_mul_component_wise(float);
instantiate_implementation_mat2_lerp(float);
instantiate_implementation_mat2_is_null(float);
instantiate_implementation_mat2_is_equal(float);
instantiate_implementation_mat2_trace(float);
instantiate_implementation_mat2_negate(float);
instantiate_implementation_mat2_mul_with_scalar(float);
instantiate_implementation_mat2_transpose(float);
instantiate_implementation_mat2_inverse(float);

void mat2_print(float)(mat2_t(float) m)
{
	printf("mat2_t(float): { %f, %f, %f, %f }\n", m.m0, m.m1, m.m2, m.m3);
}
void mat2_print(int)(mat2_t(int) m)
{
	printf("mat2_t(int): { %d, %d, %d, %d }\n", m.m0, m.m1, m.m2, m.m3);
}
#endif

#endif