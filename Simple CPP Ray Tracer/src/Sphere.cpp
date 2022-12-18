#include "Sphere.hpp"

#include <math.h>
#include <stdio.h>

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
		b = v3dot(v3mul(x, 2), destination),
		c = v3lenSq(x) - radius * radius,
		delta = b * b - 4 * a * c;

	//printf("%f,%f,%f,%f\n", a, b, c, delta);

	if (delta < 0) return -1;
	else if (delta > 0) {
		double t1 = (-b - sqrt(delta)) / (2 * a);
		double t2 = (-b + sqrt(delta)) / (2 * a);

		return t1 < t2 ? t1 : t2;
	}
	else return (-b) / (2 * a);
}
