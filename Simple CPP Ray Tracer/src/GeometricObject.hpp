#pragma once

#include "RotateableObject.hpp"
#include "RGB.hpp"

struct GeometricObject : public RotateableObject {
	RGB color;

	virtual double HitTest(Vector3 origin, Vector3 destination)=0;
};
