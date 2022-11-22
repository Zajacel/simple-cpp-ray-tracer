#pragma once

#include "RotateableObject.hpp"

struct GeometricObject : RotateableObject {
	bool HitTest(Vector3 origin, Vector3 direction);
};
