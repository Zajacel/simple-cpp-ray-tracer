#pragma once

#include "RGB.hpp"
#include "Light.hpp"

struct Material {
	RGB Color;

	RGB Radiance(Light light);
};
