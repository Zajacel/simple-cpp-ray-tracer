#include "ppm.hpp"

#include <iostream>

/// <summary>
/// Export rendered image to PPM image file
/// </summary>
/// <param name="data">Raw data</param>
/// <param name="size">Image size in Vector3</param>
void exportPPMtxt(RGB *data, v3 size)
{
	// File header, in order. Magic Number, width, height, max value
	printf("P%d\n%d %d\n%d\n", 3, (unsigned int)size.X, (unsigned int)size.Y, 255);
	for (unsigned int y = 0; y < size.Y; y++)
		for (unsigned int x = 0; x < size.X; x++) {
			RGB t = data[y * (int)size.Y + x];
			printf("%d %d %d\n", t.R, t.G, t.B);
		}
}

void exportPPMbin(RGB* data, v3 size)
{
	// File header, in order. Magic Number, width, height, max value
	printf("P%d\r%d %d\r%d\r", 6, (unsigned int)size.X, (unsigned int)size.Y, 255);
	for (unsigned int y = 0; y < size.Y; y++)
		for (unsigned int x = 0; x <= size.X; x++) {
			RGB t = data[y * (int)size.Y + x];
			printf("%c%c%c", 'a', 'b', 'c');
		}
}
