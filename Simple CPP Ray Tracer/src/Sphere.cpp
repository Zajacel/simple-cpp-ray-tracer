#include "Sphere.hpp"

#include <math.h>
#include <stdio.h>
#include "defines.hpp"

Sphere::Sphere(Vector3 center, double r, RGB c)
{
	this->pos = center;
	this->radius = r;
	this->color = c;
}

double Sphere::HitTest(Vector3 origin, Vector3 destination)
{
	v3 x = v3sub(origin, this->pos);
	double
		a = v3lenSq(destination),
		b = v3dot(x, destination) * 2,
		c = v3lenSq(x) - radius * radius,
		delta = b * b - 4 * a * c;

	if (delta < 0) return -1;
	
	double sqrtDelta = sqrt(delta);
	double t = (-b + sqrtDelta) / (2 * a);

	if (t > RT_EPSILON) return t;

	t = (-b - sqrtDelta) / (2 * a);
	if (t > RT_EPSILON) return t;

	return -1;
}
