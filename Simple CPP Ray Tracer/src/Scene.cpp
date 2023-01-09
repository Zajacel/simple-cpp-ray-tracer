#include "Scene.hpp"
#include "defines.hpp"

Scene::Scene()
{
	objects = new GeometricObject*[MAX_OBJECTS];
	currentObjectIndex = 0;
}

void Scene::addObject(GeometricObject* obj)
{
	objects[currentObjectIndex] = obj;
	currentObjectIndex++;
}
