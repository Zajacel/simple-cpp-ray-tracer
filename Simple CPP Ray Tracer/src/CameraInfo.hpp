#pragma once

#include "RotateableObject.hpp"
#include "Vector2.hpp"
#include "Size.hpp"
#include "Scene.hpp"

struct CameraInfo : RotateableObject {
	Vector2 size;
	Size resolution;
	Scene scene;
};
