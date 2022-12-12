#pragma once

#include "GeometricObject.hpp"
#include "RGB.hpp"

struct Sphere : public GeometricObject {
	double radius;

	Sphere(Vector3 pos, double r, RGB c);
	double HitTest(Vector3 origin, Vector3 destination);
};
