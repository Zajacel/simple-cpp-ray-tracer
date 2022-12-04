#include "rotation.hpp"

#include <math.h>

double calculateRotationX(Vector3 p, Vector3 r) {
	return
		p.Y * sin(r.X) * sin(r.Y) * cos(r.Z)
		- p.Z * cos(r.X) * sin(r.Y) * cos(r.Z)
		+ p.Y * cos(r.X) * sin(r.Z)
		+ p.Z * sin(r.X) * sin(r.Z)
		+ p.X * cos(r.Y) * cos(r.Z);
}

double calculateRotationY(Vector3 p, Vector3 r) {
	return
		p.Y * cos(r.X) * cos(r.Z)
		+ p.Z * sin(r.X) * cos(r.Z)
		- p.Y * sin(r.X) * sin(r.Y) * sin(r.Z)
		+ p.Z * cos(r.X) * sin(r.Y) * sin(r.Z)
		- p.X * cos(r.Y) * sin(r.Z);
}

double calculateRotationZ(Vector3 p, Vector3 r) {
	return
		p.Z * cos(r.X) * cos(r.Y)
		- p.Y * sin(r.X) * cos(r.Y)
		+ p.X * sin(r.Y);
}

Vector3 calculateRotation(Vector3 p, Vector3 r) {
	return Vector3(
		calculateRotationX(p, r),
		calculateRotationY(p, r),
		calculateRotationZ(p, r)
	);
}
