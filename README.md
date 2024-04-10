# Mathematics Library for Computer Graphics & Numerical Computing

- In-depth documention is embedded in the header files
- You can find overview of the library in **Getting Started**  section

<a href="https://www.buymeacoffee.com/raviprakashsingh" target="_blank"><img src="https://cdn.buymeacoffee.com/buttons/default-orange.png" alt="Buy Me A Coffee" height="41" width="174"></a>

#### Features

- Vector Mathematics
  
  - 2D vectors
  
  - 3D Vectors
  
  - 4D Vectors

- Matrix Mathematics
  
  - 2x2 Matrix operations
  
  - 3x3 Matrix operations [WIP]
  
  - 4x4 Matrix operations

- Quaternion Mathematics
  
  - Interpolations
  
  - Rotations
  
  - Conversion to euler angles [WIP]
  
  - Euler angles to Quaternion [WIP]

- Complex Mathematics [WIP]

#### Getting Started

###### Types

| Mathematical Type | Description            | HPML Type   |
| ----------------- | ---------------------- | ----------- |
| Vector 2D         | a 2 dimensional vector | `vec2_t`    |
| Vector 3D         | a 3 dimensional vector | `vec3_t`    |
| Vector 4D         | a 4 dimensional vector | `vec4_t`    |
| Quaternion        | a quaternion           | `quat_t`    |
| Matrix 2x2        | a 2x2 square matrix    | `mat2_t`    |
| Matrix 3x3        | a 3x3 square matrix    | `mat3_t `   |
| Matrix 4x4        | a 4x4 square matrix    | `mat4_t`    |
| Complex Number    | a complex number       | `complex_t` |

#### Vectors

2D Vectors

```c
vec2_t v = { 1.0f, 2.0f };              // initializer
vec2_t position = vec2(1.3f, 4.5f);     // constructor function

position = VEC2 { 4.5f, 3.2f };         // re-assigning th value

// constant vectors
vec2_t up = vec2_up(); // or vec2_down()
vec2_t left = vec2_left(); // or vec2_right()

vec2_t null_vector = vec2_null(); // or vec2_zero();

if(vec2_is_null(null_vector))            // checks if the vector is null
    printf("Vector is null\n");

// adding & subtracting vectors
vec2_t final_position = vec2_add(2, position, vec2_down());
vec2_t another_position = vec2_sub(2, position, vec2_up());

// adding & subtracting more than 2 vectors at once
final_position = vec2_add(3, position, vec2_down(), vec2_left());
another_position = vec2_sub(3, position, vec2_down(), vec2_left());

// printing on the console window for debugging purpose
vec2_print(final_position);        // final_position: (x, y)
vec2_print(another_position);      // another_position: (x, y)

// interpolations [linear interpolation, and spherical linear interpolation]
vec2_t interpolated_vector = vec2_lerp(vec2(1.0f, 2.0f), vec2(4.0f, 5.0f), 0.2f);
vec2_t slerped_vector = vec2_slerp(vec2(1.0f, 2.0f), vec2(4.0f, 5.0f), 0.2f);
vec2_print(interpolated_vector);
vec2_print(slerped_vector);

```



3D Vectors

```c
vec3_t v = { 1.0f, 2.0f, 3.0f };              // initializer
vec3_t position = vec3(1.3f, 4.5f, 3.4f);     // constructor function

position = VEC3 { 4.5f, 3.2f, 6.7f };         // re-assigning the value


// constant vectors
vec3_t up = vec3_up();     // or vec3_down()
vec3_t left = vec3_left(); // or vec3_right()

vec3_t null_vector = vec3_null(); // or vec3_zero()

if(vec3_is_null(null_vector))
    printf("Vector is null\n");         // checks if the vector is null


// adding & subtracting vectors
vec3_t final_position = vec3_add(2, position, vec3_down());
vec3_t another_position = vec3_sub(2, position, vec2_up());

// adding & subtracting more than 2 vectors at once
final_position = vec3_add(3, position, vec3_down(), vec3_left());
another_position = vec3_sub(3, position, vec3_down(), vec3_left());

// printing on the console window for debugging purpose
vec3_print(final_position);        // final_position: (x, y, z)
vec3_print(another_position);      // another_position: (x, y, z)

// interpolations [linear interpolation, and spherical linear interpolation]
vec3_t interpolated_vector = vec3_lerp(vec2(1.0f, 2.0f, 5.0f), vec2(4.0f, 5.0f, 2.0f), 0.2f);
vec3_t slerped_vector = vec3_slerp(vec2(1.0f, 2.0f, 5.0f), vec2(4.0f, 5.0f, 2.0f), 0.2f);
vec3_print(interpolated_vector);
vec3_print(slerped_vector);

```





#### Matrices

2x2 Matrices
```c
  mat2_t m = { 1.0f, 0.0f, 0.0f, 1.0f }; // initializer
  m = mat2_identity();                   // identity matrix of dimension 2x2
  mat2_t m1 = mat2(1.0f, 0.0f, 0.0f, 1.0f); // matrix constructor of dimension 2x2
  float t = mat2_trace(m1);   // trace calculation, i.e. sum of diagonal elements from left to right
  mat2_t m2 = mat2_add(m, m1); // addition
  mat2_t m3 = mat2_mul_with_scalar(m2, 5.0f) // multiply with scalar
  mat2_t lp = mat2_lerp(m2, m3, 0.7f); //  linear interpolation calculation for each elements of the matrices
  mat2_t rotation = mat2_rotation(1.57) // approx 90 degree anticlockwise 2D rotation matrix
  mat2_t opp_rot = mat2_inverse(rotation) // inverse of a 2x2 matrix
  mat2_print(opp_rot); // print the elements of 2x2 matrix to stdout
```

#### Quaternions [TODO]

#### Complex Numbers [TODO]



### About me

[Youtube](https://www.youtube.com/channel/UCWe_os3p4z3DBnQ4B5DUTfw/videos)

[LinkedIn](https://www.linkedin.com/in/ravi-prakash-095a271a8/)

[GitHub](https://github.com/ravi688)
