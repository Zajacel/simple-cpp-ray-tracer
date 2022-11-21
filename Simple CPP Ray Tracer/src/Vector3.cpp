#include "Vector3.hpp"

#include <math.h>

v3 v3init(double x, double y, double z)
{
	return v3(x, y, z);
}

v3 v3add(v3 a, v3 b)
{
	return v3(
		a.X + b.X,
		a.Y + b.Y,
		a.Z + b.Z
	);
}

v3 v3sub(v3 a, v3 b)
{
	return v3(
		a.X - b.X,
		a.Y - b.Y,
		a.Z - b.Z
	);
}

v3 v3mul(v3 a, double b)
{
	return v3(
		a.X * b,
		a.Y * b,
		a.Z * b
	);
}

v3 v3div(v3 a, double b)
{
	return v3(
		a.X / b,
		a.Y / b,
		a.Z / b
	);
}

v3 v3cross(v3 a, v3 b)
{
	return v3(
		a.Y * b.Z - a.Z * b.Y,
		a.Z * b.X - a.X * b.Z,
		a.X * b.Y - a.Y * b.X
	);
}

double v3dot(v3 a, v3 b)
{
	return a.X * b.X + a.Y * b.Y + a.Z * b.Z;
}

double v3len(v3 a)
{
	return sqrt(a.X * a.X + a.Y * a.Y + a.Z * a.Z);
}

v3 v3norm(v3 a)
{
	return v3div(a, v3len(a));
}

Vector3::Vector3(double x, double y, double z)
{
	this->X = x;
	this->Y = y;
	this->Z = z;
}
