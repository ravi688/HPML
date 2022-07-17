
/*
	
	Resources:

	https://en.wikipedia.org/wiki/Quaternion
	https://math.stackexchange.com/questions/2552/the-logarithm-of-quaternion
	https://en.wikipedia.org/wiki/Slerp
	https://web.mit.edu/2.998/www/QuaternionReport1.pdf
	https://en.wikipedia.org/wiki/Quaternions_and_spatial_rotation
	https://en.wikipedia.org/wiki/Conversion_between_quaternions_and_Euler_angles
	https://en.wikipedia.org/wiki/Rotation_formalisms_in_three_dimensions
	https://en.wikipedia.org/wiki/Three-dimensional_rotation_operator
	https://en.wikipedia.org/wiki/Euler%27s_rotation_theorem
	https://en.wikipedia.org/wiki/Axis%E2%80%93angle_representation
	https://en.wikipedia.org/wiki/Spherical_coordinate_system
	
	https://math.stackexchange.com/questions/939229/unit-quaternion-to-a-scalar-power

 */


#pragma once

#include <hpml/defines.h>

typedef struct quat_t
{
	/*
	 vector part = { x, y, z },
	 scalar part = { w }
	*/
	union
	{
		struct 
		{
			float x, y, z, w;
		};

		struct
		{
			float v[3];
			float s;
		};
	};
} quat_t;

#define QUAT (quat_t)

#ifdef __cplusplus
	extern "C" {
#endif

/* 	quat : constructs a quat_t instance 
	x, y, z, w : components of the quaternion
	returns: an initialized instance of quat_t struct
*/
static HPML_FORCE_INLINE quat_t quat(float x, float y, float z, float w) { return QUAT { x, y, z, w }; }

/*
	quat_identity : consturcts an identity quaternion instance
	returns: identity quaternion
 */
static HPML_FORCE_INLINE quat_t quat_identity() { return quat(0, 0, 0, 1); }

/*
 	quat_zero : constructs a null quaternion instance
 	returns : null quaternion
 */
static HPML_FORCE_INLINE quat_t quat_zero() { return quat(0, 0, 0, 0); }

/*	quat_add : adds variable number of quaternions into q (quat_t)
	count : number of variable quaternions to add
	q : first quaternion
	... : variable number of quaternions
	returns : result of the addition
*/
HPML_API quat_t quat_add(u32 count, quat_t q, ...);
HPML_API quat_t __quat_add(quat_t q1, quat_t q2);

/*	quat_sub : subtracts variable number of quaternions from q (quat_t)
	count : number of variable quaternions to add
	q : first quaternion
	... : variable number of quaternions
	returns : result of the subtraction
*/
HPML_API quat_t quat_sub(u32 count, quat_t q, ...);
HPML_API quat_t __quat_sub(quat_t q1, quat_t q2);

/*	quat_add : multiplies variable number of quaternions with q (quat_t)
	count : number of variable quaternions to multiply
	q : first quaternion
	... : variable number of quaternions
	returns : result of the multiplication
*/
HPML_API quat_t quat_mul(u32 count, quat_t q, ...);
HPML_API quat_t __quat_mul(quat_t q1, quat_t q2);

/*	quat_add : divides q (quat_t) by variable number of quaternions
	count : number of variable quaternions to divide with
	q : first quaternion
	... : variable number of quaternions
	returns : result of the division
*/
HPML_API quat_t quat_div(u32 count, quat_t q, ...);
HPML_API quat_t __quat_div(quat_t q1, quat_t q2);

/*
 	quat_mul_scalar : multiplies each component of the quaternion with a scalar value
 	q : original quaternion
 	s : scalar floating point value
 	returns : q * s
 */
static HPML_FORCE_INLINE quat_t quat_mul_scalar(quat_t q, float s) { return quat(q.x * s, q.y * s, q.z * s, q.w * s); }

/*	quat_difference : calculates the rotation difference between two quaternions q1 and q2
	q1 : first quaternion (final rotation)
	q2 : second quaternion (intial rotation)
	returns: quaternion equivalent to the difference of the two quaternions q1 and q2

NOTE: difference(q1, q0) = q1 * inverse(q0)

*/
HPML_API quat_t quat_difference(quat_t q1, quat_t q2);

/*
 	quat_inverse : calculates the inverse of a quaternion
 	q : original quaternion
 	returns: inverse of the quaterion 'q'
 */
HPML_API quat_t quat_inverse(quat_t q);

/*
 	quat_conjugate : calculates the conjugate of a quatenion
 	q : original quaternion
 	returns : conjugate of the quaterion 'q'
 */
static HPML_FORCE_INLINE quat_t quat_conjugate(quat_t q) { return quat(-q.x, -q.y, -q.z, q.w); }
#define quat_conj(x) quat_conjugate(x)

/*
	quat_reciprocal : calculates the reciprocal of a quaternion
	q : original quaternion
	returns: reciprocal of the quaternion 'q'

NOTE: 1 / q = conjugate(q) / (q * conjugate(q)) = conjugate(q) / sqrmagnitude(q);

 */
HPML_API quat_t quat_reciprocal(quat_t q);

/*
	quat_sqrt : calcualtes the square root of a quaternion
	q : original quaternion
	returns: square root of the quaternion 'q'
 */
HPML_API quat_t quat_sqrt(quat_t q);

/*
	quat_log : calculates the logarithm of a quaternion
	q : original quaternion
	base : scalar base
	returns: logarithm of the quaternion 'q'
 */
HPML_API quat_t quat_log(quat_t q, float base);

/*
	quat_pow : calculates power of a quaternion
	q : base quaternion
	t : exponent
	returns: power of the quaternion 'q'
 */
HPML_API quat_t quat_pow(quat_t q, float t);

/*
	quat_magnitude : calculates the magnitude of a quaternion
	q : quaternion
	returns: magnitude of the quaternion 'q'
 */
HPML_API float quat_magnitude(quat_t q);

/*
	quat_sqrmagnitude : calculates the squared magnitude of a quaternion, efficient than magnitude version
	q : quaternion
	returns: squared magnitude of the quaternion 'q'
 */
HPML_API float quat_sqrmagnitude(quat_t q);

/*
	quat_normalize : calculates a unit quaternion from a quaternion
	q : original quaternion
	returns: unit quaterion of the quaterion 'q'
 */
HPML_API quat_t quat_normalize(quat_t q);

/*
	quat_angle_axis : calculates a quaterion rotor with angle along an axis
	x : x coordinate of the axis
	y : y coordinate of the axis
	z : z coordinate of the axis
	angle : angle (in radians), +ve is anticlockwise, -ve is clockwise
	returns: quaterion rotor
 */
HPML_API quat_t quat_angle_axis(float x, float y, float z, float angle);

/*
	quat_versor : calculates a quaternion versor
	x : x coordiante of the imaginary part (r)
	y : y coordinate of the imaginary part (r)
	z : z coordinate of the imaginary part (r)
	angle : ange (in radians)

NOTE: 
	versor = exp(r * angle) = cos(angle) + sin(angle) * r;
 */
HPML_API quat_t quat_versor(float x, float y, float z, float angle);

/*
 	quat_angle : calculates an angle between two quaternions
 	q1 : first quaterion (from)
 	q2 : second quaterion (to)
 	returns: angle (in radians), +ve is anticlockwise, -ve is clockwise
 */
HPML_API float quat_angle(quat_t q1, quat_t q2);

/*
	quat_lerp : calculates a linearly interpolated quaternion
	from : initial quaternion
	to : final quaternion
	t : interpolation parameter
	returns: interpolated quaternion or { from * (1 - t) + to * t }
 */
HPML_API quat_t quat_lerp(quat_t from, quat_t to, float t);

/*
	quat_slerp : calculates a spherically interpolated quaternion
	from : intial quaternion
	to : final quaternion
	t : interpolation paramter
	returns : interpolated quaterion OR

NOTE:
	versor : q = exp(r * angle) = cos(angle * 0.5f) + r * sin(angle * 0.5f),
			where r * r = -1, which is a quaternion with zero scalar part and unit vector part

	slerp(q0, q1, t) = pow(q1 * inverse(q0), t) * q0
	OR
	slerp(q0, q1, t) = pow(quat_difference(q1, q0), t) * q0
 */
HPML_API quat_t quat_slerp(quat_t from, quat_t to, float t);

/*
	quat_sandwitch : calculates the sandwitched multiplication q * p * inverse(q), where q is a quaterion versor
	versor : quaternion q in the sandwitched multiplication
	p : quaternion p in the sandwitched multiplication
	returns: sandwitched product (q * p * inverse(q))
 */
HPML_API quat_t quat_sandwitch(quat_t versor, quat_t p);

/*
	 Comparison functions
 */

/*
	quat_equal : determines whether two quaternions are equal or not
	q1 : first quaternion
	q2 : quaternion to compare against
	returns: true if both are equal to each other; false otherwise.
 */
HPML_API bool quat_equal(quat_t q1, quat_t q2);

/* For debugging purpose */

HPML_API void quat_print(quat_t q);

#ifdef __cplusplus
 	}
#endif // __cplusplus