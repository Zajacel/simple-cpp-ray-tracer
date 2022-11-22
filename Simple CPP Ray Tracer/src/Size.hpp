#pragma once

#include "types.hpp"

struct Size {
	uint width, height;

	Size(uint w, uint h);
	Size(int w, int h);
};
