#pragma once

#include "GeometricObject.hpp"
#include "Light.hpp"

struct Scene {
	GeometricObject** objects;
	Light** lights;
	int currentObjectIndex, currentLightIndex;

	Scene();
	void addObject(GeometricObject* obj);
	void addLight(Light* light);
};
