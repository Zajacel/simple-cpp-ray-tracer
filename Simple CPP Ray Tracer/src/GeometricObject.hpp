#pragma once

#include "RotateableObject.hpp"
//#include "RGB.hpp"
#include "Material.hpp"

struct GeometricObject : public RotateableObject {
	Material* material;

	virtual double HitTest(Vector3 origin, Vector3 destination)=0;
};
