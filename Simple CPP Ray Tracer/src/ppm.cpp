#include "ppm.hpp"

#include <iostream>

/// <summary>
/// Export rendered image to PPM image file
/// </summary>
/// <param name="data">Raw data</param>
/// <param name="size">Image size in Vector3</param>
void exportPPMtxt(RGB *data, Size size)
{
	// File header, in order. Magic Number, width, height, max value
	printf("P%d\n%d %d\n%d\n", 3, size.width, size.height, 255);
	for (uint y = 0; y < size.height; y++)
		for (uint x = 0; x < size.width; x++) {
			RGB t = data[y * (int)size.height + x];
			printf("%d %d %d\n", t.R, t.G, t.B);
		}
}

void exportPPMbin(RGB* data, Size size)
{
	// File header, in order. Magic Number, width, height, max value
	printf("P%d\r%d %d\r%d\r", 6, size.width, size.height, 255);
	for (uint y = 0; y < size.height; y++)
		for (uint x = 0; x <= size.width; x++) {
			RGB t = data[y * (int)size.height + x];
			printf("%c%c%c", t.R, t.G, t.B);
		}
}
