#pragma once

#include "Camera.hpp"
#include "vector/vector3.hpp"
#include "color/color.hpp"

struct OrthographicCamera : Camera {
	Vector3 size;
	Vector3 resolution;

	RGB shootRay(uint x, uint y);
};
