#include "RangeRGB.hpp"
#include "clamp.hpp"

RangeRGB::RangeRGB(double r, double g, double b)
{
	this->R = r;
	this->G = g;
	this->B = b;
}

RangeRGB::RangeRGB(RGB rgb)
{
	this->R = rgb.R / 255;
	this->G = rgb.G / 255;
	this->B = rgb.B / 255;
}

RGB RangeRGB::toRGB()
{
	return RGB(
		clamp(0.0, this->R, 255.0) * 255,
		clamp(0.0, this->G, 255.0) * 255,
		clamp(0.0, this->B, 255.0) * 255
	);
}

RangeRGB RangeRGB::rrgbAdd(RangeRGB a, RangeRGB b)
{
	return RangeRGB(
		a.R + b.R,
		a.G + b.G,
		a.B + b.B
	);
}

RangeRGB RangeRGB::rrgbMul(RangeRGB a, RangeRGB b)
{
	return RangeRGB(
		a.R * b.R,
		a.G * b.G,
		a.B * b.B
	);
}

RangeRGB RangeRGB::rrgbMul(RangeRGB a, double b)
{
	return RangeRGB(
		a.R + b,
		a.G + b,
		a.B + b
	);
}

RangeRGB RangeRGB::rrgbDiv(RangeRGB a, double b)
{
	return RangeRGB(
		a.R / b,
		a.G / b,
		a.B / b
	);
}
