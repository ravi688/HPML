
#pragma once

#include <hpml/vec4/template_definitions.h>

#ifdef __cplusplus
extern "C" {
#endif
 
/*Begin: Template Instantiations*/
instantiate_vec4_struct(int);
instantiate_declaration_vec4(int);
instantiate_declaration_vec4_zero(int);
instantiate_declaration_vec4_one(int);
instantiate_declaration_vec4_add(int);
instantiate_declaration_vec4_sub(int);
instantiate_declaration_vec4_mul(int);
instantiate_declaration_vec4_div(int);
instantiate_declaration_vec4_lerp(int);
instantiate_declaration_vec4_slerp(int);
instantiate_declaration_vec4_rotate(int);
instantiate_declaration_vec4_negate(int);
instantiate_declaration_vec4_up(int);
instantiate_declaration_vec4_down(int);
instantiate_declaration_vec4_left(int);
instantiate_declaration_vec4_right(int);
instantiate_declaration_vec4_forward(int);
instantiate_declaration_vec4_back(int);
instantiate_declaration_vec4_is_null(int);
instantiate_declaration_vec4_is_equal(int);

instantiate_declaration_vec4_print(int);
instantiate_declaration_vec4_normalize(int);
instantiate_declaration_vec4_magnitude(int);
instantiate_declaration_vec4_sqrmagnitude(int);
instantiate_declaration_vec4_angle(int);
instantiate_declaration_vec4_unit_angle(int);
instantiate_declaration_vec4_scale(int);
instantiate_declaration_vec4_dot(int);
instantiate_declaration_vec4_cross(int);
instantiate_declaration_vec4_rotate_x(int);
instantiate_declaration_vec4_rotate_y(int);
instantiate_declaration_vec4_rotate_z(int);
instantiate_declaration_vec4_axis_rotate(int);
instantiate_declaration_vec4_box(int);
instantiate_declaration_vec4_project(int);
instantiate_declaration_vec4_unit_project(int);

instantiate_vec4_struct(float);
instantiate_declaration_vec4(float);
instantiate_declaration_vec4_zero(float);
instantiate_declaration_vec4_one(float);
instantiate_declaration_vec4_add(float);
instantiate_declaration_vec4_sub(float);
instantiate_declaration_vec4_mul(float);
instantiate_declaration_vec4_div(float);
instantiate_declaration_vec4_lerp(float);
instantiate_declaration_vec4_slerp(float);
instantiate_declaration_vec4_rotate(float);
instantiate_declaration_vec4_negate(float);
instantiate_declaration_vec4_up(float);
instantiate_declaration_vec4_down(float);
instantiate_declaration_vec4_left(float);
instantiate_declaration_vec4_right(float);
instantiate_declaration_vec4_forward(float);
instantiate_declaration_vec4_back(float);
instantiate_declaration_vec4_is_null(float);
instantiate_declaration_vec4_is_equal(float);

instantiate_declaration_vec4_print(float);
instantiate_declaration_vec4_normalize(float);
instantiate_declaration_vec4_magnitude(float);
instantiate_declaration_vec4_sqrmagnitude(float);
instantiate_declaration_vec4_angle(float);
instantiate_declaration_vec4_unit_angle(float);
instantiate_declaration_vec4_scale(float);
instantiate_declaration_vec4_dot(float);
instantiate_declaration_vec4_cross(float);
instantiate_declaration_vec4_rotate_x(float);
instantiate_declaration_vec4_rotate_y(float);
instantiate_declaration_vec4_rotate_z(float);
instantiate_declaration_vec4_axis_rotate(float);
instantiate_declaration_vec4_box(float);
instantiate_declaration_vec4_project(float);
instantiate_declaration_vec4_unit_project(float);

#if defined(IMPLEMENTATION)
instantiate_implementation_vec4(int);
instantiate_implementation_vec4_zero(int);
instantiate_implementation_vec4_one(int);
instantiate_implementation_vec4_add(int);
instantiate_implementation_vec4_sub(int);
instantiate_implementation_vec4_mul(int);
instantiate_implementation_vec4_div(int);
instantiate_implementation_vec4_lerp(int);
instantiate_implementation_vec4_slerp(int);
instantiate_implementation_vec4_rotate(int);
instantiate_implementation_vec4_negate(int);
instantiate_implementation_vec4_up(int);
instantiate_implementation_vec4_down(int);
instantiate_implementation_vec4_left(int);
instantiate_implementation_vec4_right(int);
instantiate_implementation_vec4_forward(int);
instantiate_implementation_vec4_back(int);
instantiate_implementation_vec4_is_null(int);
instantiate_implementation_vec4_is_equal(int);

HPML_API void vec4_print(int)(vec4_t(int) v) { printf("vec4_t(int): { %d, %d, %d, %d }\n", v.x, v.y, v.z, v.w); }
instantiate_implementation_vec4_normalize(int);
instantiate_implementation_vec4_magnitude(int);
instantiate_implementation_vec4_sqrmagnitude(int);
instantiate_implementation_vec4_angle(int);
instantiate_implementation_vec4_unit_angle(int);
instantiate_implementation_vec4_scale(int);
instantiate_implementation_vec4_dot(int);
instantiate_implementation_vec4_cross(int);
instantiate_implementation_vec4_rotate_x(int);
instantiate_implementation_vec4_rotate_y(int);
instantiate_implementation_vec4_rotate_z(int);
instantiate_implementation_vec4_axis_rotate(int);
instantiate_implementation_vec4_box(int);
instantiate_implementation_vec4_project(int);
instantiate_implementation_vec4_unit_project(int);

instantiate_implementation_vec4(float);
instantiate_implementation_vec4_zero(float);
instantiate_implementation_vec4_one(float);
instantiate_implementation_vec4_add(float);
instantiate_implementation_vec4_sub(float);
instantiate_implementation_vec4_mul(float);
instantiate_implementation_vec4_div(float);
instantiate_implementation_vec4_lerp(float);
instantiate_implementation_vec4_slerp(float);
instantiate_implementation_vec4_rotate(float);
instantiate_implementation_vec4_negate(float);
instantiate_implementation_vec4_up(float);
instantiate_implementation_vec4_down(float);
instantiate_implementation_vec4_left(float);
instantiate_implementation_vec4_right(float);
instantiate_implementation_vec4_forward(float);
instantiate_implementation_vec4_back(float);
instantiate_implementation_vec4_is_null(float);
instantiate_implementation_vec4_is_equal(float);

HPML_API void vec4_print(float)(vec4_t(float) v) { printf("vec4_t(float): { %f, %f, %f, %f }\n", v.x, v.y, v.z, v.w); }
instantiate_implementation_vec4_normalize(float);
instantiate_implementation_vec4_magnitude(float);
instantiate_implementation_vec4_sqrmagnitude(float);
instantiate_implementation_vec4_angle(float);
instantiate_implementation_vec4_unit_angle(float);
instantiate_implementation_vec4_scale(float);
instantiate_implementation_vec4_dot(float);
instantiate_implementation_vec4_cross(float);
instantiate_implementation_vec4_rotate_x(float);
instantiate_implementation_vec4_rotate_y(float);
instantiate_implementation_vec4_rotate_z(float);
instantiate_implementation_vec4_axis_rotate(float);
instantiate_implementation_vec4_box(float);
instantiate_implementation_vec4_project(float);
instantiate_implementation_vec4_unit_project(float);
/*End: Template Instantiations*/

#endif /*IMPLEMENTATION*/


#ifdef __cplusplus
}
#endif/*__cplusplus*/
