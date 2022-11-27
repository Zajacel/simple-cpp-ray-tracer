#include <iostream>

#include "src/types.hpp"
#include "src/defines.hpp"
#include "src/bmp.hpp"
#include "src/Size.hpp"

int main()
{
	const uint X = WIDTH;
	const uint Y = HEIGHT;
	Size size = Size(X, Y);
	RGB* image = new RGB[X * Y];

	for (uint y = 0; y < Y; y++)
		for (uint x = 0; x < X; x++) {
			RGB t = RGB(255, 0, 0);
			image[y * Y + x] = t;
		}

	//exportPPMbin(image, size);
	exportBMP(image, size);
	return 0;
}
