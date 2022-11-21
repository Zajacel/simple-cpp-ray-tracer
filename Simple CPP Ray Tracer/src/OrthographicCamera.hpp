#pragma once

#include "Camera.hpp"
#include "Vector3.hpp"
#include "RGB.hpp"

struct OrthographicCamera : Camera {
	Vector3 size;
	Vector3 resolution;

	RGB shootRay(uint x, uint y);
};
