#pragma once

#include "RotateableObject.hpp"
#include "Vector2.hpp"
#include "Size.hpp"
#include "Scene.hpp"
#include "RGB.hpp"

struct CameraInfo : public RotateableObject {
	Vector2 size;
	Size resolution;
	Scene scene;
	RGB skyboxColor;
};
