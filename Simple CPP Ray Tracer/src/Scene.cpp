#include "Scene.hpp"
#include "defines.hpp"

Scene::Scene()
{
	objects = new GeometricObject*[MAX_OBJECTS];
	currentObjectIndex = 0;

	lights = new Light * [MAX_LIGHTS];
	currentLightIndex = 0;
}

void Scene::addObject(GeometricObject* obj)
{
	objects[currentObjectIndex] = obj;
	currentObjectIndex++;
}

void Scene::addLight(Light* light)
{
	lights[currentObjectIndex] = light;
	currentLightIndex++;
}
