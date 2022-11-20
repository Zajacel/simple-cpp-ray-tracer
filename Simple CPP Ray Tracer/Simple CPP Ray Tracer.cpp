#include <iostream>

#include "types.hpp"
#include "exporter/ppm.hpp"

#define WIDTH 4;
#define HEIGHT 4;

int main()
{
	const int X = WIDTH;
	const int Y = HEIGHT;
	auto image = new RGB[Y][X];

	for (unsigned int y = 0; y < Y; y++)
		for (unsigned int x = 0; x < X; x++) {
			RGB t = RGB(128, 128, 128);
			image[y][x] = t;
		}

	exportPPMbin(*image, v3(X, Y, 0));
    return 0;
}
