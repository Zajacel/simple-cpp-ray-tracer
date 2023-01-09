#pragma once

#include "GeometricObject.hpp"

struct Scene {
	GeometricObject** objects;
	int currentObjectIndex;
	 //Light lights;

	Scene();
	void addObject(GeometricObject* obj);
};
