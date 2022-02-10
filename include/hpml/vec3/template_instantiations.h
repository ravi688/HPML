
#pragma once

#include <hpml/vec3/template_definitions.h>

#ifdef __cplusplus
extern "C" {
#endif
 
/*Begin: Template Instantiations*/
instantiate_vec3_struct(int);
instantiate_declaration_vec3(int);
instantiate_declaration_vec3_zero(int);
instantiate_declaration_vec3_one(int);
instantiate_declaration_vec3_add(int);
instantiate_declaration_vec3_sub(int);
instantiate_declaration_vec3_mul(int);
instantiate_declaration_vec3_div(int);
instantiate_declaration_vec3_lerp(int);
instantiate_declaration_vec3_slerp(int);
instantiate_declaration_vec3_rotate(int);
instantiate_declaration_vec3_negate(int);
instantiate_declaration_vec3_up(int);
instantiate_declaration_vec3_down(int);
instantiate_declaration_vec3_left(int);
instantiate_declaration_vec3_right(int);
instantiate_declaration_vec3_forward(int);
instantiate_declaration_vec3_back(int);
instantiate_declaration_vec3_is_null(int);
instantiate_declaration_vec3_is_equal(int);

instantiate_declaration_vec3_print(int);
instantiate_declaration_vec3_normalize(int);
instantiate_declaration_vec3_magnitude(int);
instantiate_declaration_vec3_sqrmagnitude(int);
instantiate_declaration_vec3_angle(int);
instantiate_declaration_vec3_unit_angle(int);
instantiate_declaration_vec3_scale(int);
instantiate_declaration_vec3_dot(int);
instantiate_declaration_vec3_cross(int);
instantiate_declaration_vec3_rotate_x(int);
instantiate_declaration_vec3_rotate_y(int);
instantiate_declaration_vec3_rotate_z(int);
instantiate_declaration_vec3_axis_rotate(int);
instantiate_declaration_vec3_box(int);
instantiate_declaration_vec3_project(int);
instantiate_declaration_vec3_unit_project(int);

instantiate_vec3_struct(float);
instantiate_declaration_vec3(float);
instantiate_declaration_vec3_zero(float);
instantiate_declaration_vec3_one(float);
instantiate_declaration_vec3_add(float);
instantiate_declaration_vec3_sub(float);
instantiate_declaration_vec3_mul(float);
instantiate_declaration_vec3_div(float);
instantiate_declaration_vec3_lerp(float);
instantiate_declaration_vec3_slerp(float);
instantiate_declaration_vec3_rotate(float);
instantiate_declaration_vec3_negate(float);
instantiate_declaration_vec3_up(float);
instantiate_declaration_vec3_down(float);
instantiate_declaration_vec3_left(float);
instantiate_declaration_vec3_right(float);
instantiate_declaration_vec3_forward(float);
instantiate_declaration_vec3_back(float);
instantiate_declaration_vec3_is_null(float);
instantiate_declaration_vec3_is_equal(float);

instantiate_declaration_vec3_print(float);
instantiate_declaration_vec3_normalize(float);
instantiate_declaration_vec3_magnitude(float);
instantiate_declaration_vec3_sqrmagnitude(float);
instantiate_declaration_vec3_angle(float);
instantiate_declaration_vec3_unit_angle(float);
instantiate_declaration_vec3_scale(float);
instantiate_declaration_vec3_dot(float);
instantiate_declaration_vec3_cross(float);
instantiate_declaration_vec3_rotate_x(float);
instantiate_declaration_vec3_rotate_y(float);
instantiate_declaration_vec3_rotate_z(float);
instantiate_declaration_vec3_axis_rotate(float);
instantiate_declaration_vec3_box(float);
instantiate_declaration_vec3_project(float);
instantiate_declaration_vec3_unit_project(float);

#if defined(IMPLEMENTATION)
instantiate_implementation_vec3(int);
instantiate_implementation_vec3_zero(int);
instantiate_implementation_vec3_one(int);
instantiate_implementation_vec3_add(int);
instantiate_implementation_vec3_sub(int);
instantiate_implementation_vec3_mul(int);
instantiate_implementation_vec3_div(int);
instantiate_implementation_vec3_lerp(int);
instantiate_implementation_vec3_slerp(int);
instantiate_implementation_vec3_rotate(int);
instantiate_implementation_vec3_negate(int);
instantiate_implementation_vec3_up(int);
instantiate_implementation_vec3_down(int);
instantiate_implementation_vec3_left(int);
instantiate_implementation_vec3_right(int);
instantiate_implementation_vec3_forward(int);
instantiate_implementation_vec3_back(int);
instantiate_implementation_vec3_is_null(int);
instantiate_implementation_vec3_is_equal(int);

HPML_API void vec3_print(int)(vec3_t(int) v) { printf("vec3_t(int): { %d, %d }\n", v.x, v.y); }
instantiate_implementation_vec3_normalize(int);
instantiate_implementation_vec3_magnitude(int);
instantiate_implementation_vec3_sqrmagnitude(int);
instantiate_implementation_vec3_angle(int);
instantiate_implementation_vec3_unit_angle(int);
instantiate_implementation_vec3_scale(int);
instantiate_implementation_vec3_dot(int);
instantiate_implementation_vec3_cross(int);
instantiate_implementation_vec3_rotate_x(int);
instantiate_implementation_vec3_rotate_y(int);
instantiate_implementation_vec3_rotate_z(int);
instantiate_implementation_vec3_axis_rotate(int);
instantiate_implementation_vec3_box(int);
instantiate_implementation_vec3_project(int);
instantiate_implementation_vec3_unit_project(int);

instantiate_implementation_vec3(float);
instantiate_implementation_vec3_zero(float);
instantiate_implementation_vec3_one(float);
instantiate_implementation_vec3_add(float);
instantiate_implementation_vec3_sub(float);
instantiate_implementation_vec3_mul(float);
instantiate_implementation_vec3_div(float);
instantiate_implementation_vec3_lerp(float);
instantiate_implementation_vec3_slerp(float);
instantiate_implementation_vec3_rotate(float);
instantiate_implementation_vec3_negate(float);
instantiate_implementation_vec3_up(float);
instantiate_implementation_vec3_down(float);
instantiate_implementation_vec3_left(float);
instantiate_implementation_vec3_right(float);
instantiate_implementation_vec3_forward(float);
instantiate_implementation_vec3_back(float);
instantiate_implementation_vec3_is_null(float);
instantiate_implementation_vec3_is_equal(float);

HPML_API void vec3_print(float)(vec3_t(float) v) { printf("vec3_t(float): { %f, %f, %f }\n", v.x, v.y, v.z); }
instantiate_implementation_vec3_normalize(float);
instantiate_implementation_vec3_magnitude(float);
instantiate_implementation_vec3_sqrmagnitude(float);
instantiate_implementation_vec3_angle(float);
instantiate_implementation_vec3_unit_angle(float);
instantiate_implementation_vec3_scale(float);
instantiate_implementation_vec3_dot(float);
instantiate_implementation_vec3_cross(float);
instantiate_implementation_vec3_rotate_x(float);
instantiate_implementation_vec3_rotate_y(float);
instantiate_implementation_vec3_rotate_z(float);
instantiate_implementation_vec3_axis_rotate(float);
instantiate_implementation_vec3_box(float);
instantiate_implementation_vec3_project(float);
instantiate_implementation_vec3_unit_project(float);
/*End: Template Instantiations*/

#endif /*IMPLEMENTATION*/


#ifdef __cplusplus
}
#endif/*__cplusplus*/
