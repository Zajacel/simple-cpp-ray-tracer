#pragma once

struct Vector3 {
	double X = 0, Y = 0, Z = 0;

	Vector3(double x = 0, double y = 0, double z = 0);
};

typedef Vector3 v3;

v3 v3add(v3 a, v3 b);

v3 v3sub(v3 a, v3 b);

v3 v3mul(v3 a, double b);

v3 v3cross(v3 a, v3 b);
double v3dot(v3 a, v3 b);

double v3len(v3 a);
