#include <iostream>

#include "src/types.hpp"
#include "src/defines.hpp"
#include "src/ppm.hpp"
#include "src/Size.hpp"

int main()
{
	const uint X = WIDTH;
	const uint Y = HEIGHT;
	Size size = Size(X, Y);
	RGB* image = new RGB[X * Y];

	for (uint y = 0; y < Y; y++)
		for (uint x = 0; x < X; x++) {
			RGB t = RGB(128, 128, 128);
			image[y * Y + x] = t;
		}

	exportPPMbin(image, size);
    return 0;
}
