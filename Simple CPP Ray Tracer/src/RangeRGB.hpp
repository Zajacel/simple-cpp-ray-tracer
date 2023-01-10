#pragma once

#include "RGB.hpp"

struct RangeRGB {
	double R, G, B;

	RangeRGB(double r, double g, double b);
	RangeRGB(RGB rgb);

	RGB toRGB();

	RangeRGB rrgbAdd(RangeRGB a, RangeRGB b);

	RangeRGB rrgbMul(RangeRGB a, RangeRGB b);
	RangeRGB rrgbMul(RangeRGB a, double b);

	RangeRGB rrgbDiv(RangeRGB a, double b);
};
