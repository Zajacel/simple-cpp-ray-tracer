#pragma once

#include "Object.hpp"

struct GeometricObject : Object {
	Vector3 rot;

	bool HitTest(Vector3 origin, Vector3 direction);
};
