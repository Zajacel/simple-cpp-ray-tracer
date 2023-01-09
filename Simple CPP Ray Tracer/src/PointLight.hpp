#include "RGB.hpp"
#include "Light.hpp"

struct PointLight : public Light
{
	RGB color;
};