#pragma once

#include "Object.hpp"

struct GeometricObject : Object {
	Vector3 rot;

	bool hitScan(Vector3 origin, Vector3 direction);
};
