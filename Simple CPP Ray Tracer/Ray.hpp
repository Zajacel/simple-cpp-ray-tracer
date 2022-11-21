#pragma once

#include <float.h>

#include "vector/Vector3.hpp"

struct Ray {
	Vector3 o;
	Vector3 d;

	Ray(v3 origin, v3 destination);
};
