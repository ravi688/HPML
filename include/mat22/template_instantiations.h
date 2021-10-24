#ifndef __HPML_MAT22_TEMPLATE_INSTANTIATIONS_H__
#define __HPML_MAT22_TEMPLATE_INSTANTIATIONS_H__

#include <mat22/template_definitions.h>

/*Begin: Template Instantiations*/
instantiate_mat22_struct(int);
instantiate_declaration_mat22(int);
instantiate_declaration_mat22_add(int);
instantiate_declaration_mat22_sub(int);
instantiate_declaration_mat22_mul(int);
instantiate_declaration_mat22_div(int);
instantiate_declaration_mat22_mul_component_wise(int);
instantiate_declaration_mat22_lerp(int);
instantiate_declaration_mat22_print(int);
instantiate_declaration_mat22_is_null(int);
instantiate_declaration_mat22_is_equal(int);
instantiate_declaration_mat22_trace(int);
instantiate_declaration_mat22_negate(int);
instantiate_declaration_mat22_mul_with_scalar(int);
instantiate_declaration_mat22_transpose(int);
instantiate_declaration_mat22_inverse(int);

instantiate_mat22_struct(float);
instantiate_declaration_mat22(float);
instantiate_declaration_mat22_add(float);
instantiate_declaration_mat22_sub(float);
instantiate_declaration_mat22_mul(float);
instantiate_declaration_mat22_div(float);
instantiate_declaration_mat22_mul_component_wise(float);
instantiate_declaration_mat22_lerp(float);
instantiate_declaration_mat22_print(float);
instantiate_declaration_mat22_is_null(float);
instantiate_declaration_mat22_is_equal(float);
instantiate_declaration_mat22_trace(float);
instantiate_declaration_mat22_negate(float);
instantiate_declaration_mat22_mul_with_scalar(float);
instantiate_declaration_mat22_transpose(float);
instantiate_declaration_mat22_inverse(float);

/*End: Template Instantiations*/

#if defined(IMPLEMENTATION)
instantiate_implementation_mat22(int);
instantiate_implementation_mat22_add(int);
instantiate_implementation_mat22_sub(int);
instantiate_implementation_mat22_mul(int);
instantiate_implementation_mat22_div(int);
instantiate_implementation_mat22_mul_component_wise(int);
instantiate_implementation_mat22_lerp(int);
instantiate_implementation_mat22_is_null(int);
instantiate_implementation_mat22_is_equal(int);
instantiate_implementation_mat22_trace(int);
instantiate_implementation_mat22_negate(int);
instantiate_implementation_mat22_mul_with_scalar(int);
instantiate_implementation_mat22_transpose(int);
instantiate_implementation_mat22_inverse(int);

instantiate_implementation_mat22(float);
instantiate_implementation_mat22_add(float);
instantiate_implementation_mat22_sub(float);
instantiate_implementation_mat22_mul(float);
instantiate_implementation_mat22_div(float);
instantiate_implementation_mat22_mul_component_wise(float);
instantiate_implementation_mat22_lerp(float);
instantiate_implementation_mat22_is_null(float);
instantiate_implementation_mat22_is_equal(float);
instantiate_implementation_mat22_trace(float);
instantiate_implementation_mat22_negate(float);
instantiate_implementation_mat22_mul_with_scalar(float);
instantiate_implementation_mat22_transpose(float);
instantiate_implementation_mat22_inverse(float);

void mat22_print(float)(mat22_t(float) m)
{
	printf("mat22_t(float): { %f, %f, %f, %f }\n", m.m0, m.m1, m.m2, m.m3);
}
void mat22_print(int)(mat22_t(int) m)
{
	printf("mat22_t(int): { %d, %d, %d, %d }\n", m.m0, m.m1, m.m2, m.m3);
}
#endif

#endif