#include "Sphere.hpp"

#include <math.h>

Sphere::Sphere(Vector3 center, double r, RGB c)
{
	this->pos = center;
	this->radius = r;
	this->color = c;
}

double Sphere::HitTest(Vector3 origin, Vector3 destination)
{
	v3 t = v3sub(origin, pos);
	double
		a = v3dot(destination, destination),
		b = 2 * v3dot(destination, t),
		c = v3dot(t, t) - radius * radius,
		delta = b * b - 4 * a * c;

	if (delta < 0) return -1;
	else if (delta > 0) {
		double t1 = (-b - sqrt(delta)) / (2 * a);
		double t2 = (-b + sqrt(delta)) / (2 * a);

		return t1 < t2 ? t1 : t2;
	}
	else return (-b) / (2 * a);
}
