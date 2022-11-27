#include "ppm.hpp"

#include <iostream>

/// <summary>
/// Export rendered image to PPM image file
/// </summary>
/// <param name="data">Raw data</param>
/// <param name="size">Image size in Vector3</param>
void exportPPMtxt(RGB *data, Size size)
{
	FILE* file;
	fopen_s(&file, "image.bmp", "w");

	if (file == NULL)
	{
		fprintf(stderr, "\nError while opening file\n");
		exit(1);
	}

	// File header, in order. Magic Number, width, height, max value
	fprintf(file, "P%d\n%d %d\n%d\n", 3, size.width, size.height, 255);
	for (uint y = 0; y < size.height; y++)
		for (uint x = 0; x < size.width; x++) {
			RGB t = data[y * size.height + x];
			fprintf(file, "%d %d %d\n", t.R, t.G, t.B);
		}
}

void exportPPMbin(RGB* data, Size size)
{
	FILE* file;
	fopen_s(&file, "image.bmp", "w");

	if (file == NULL)
	{
		fprintf(stderr, "\nError while opening file\n");
		exit(1);
	}

	// File header, in order. Magic Number, width, height, max value
	fprintf(file, "P%d\r%d %d\r%d\r", 6, size.width, size.height, 255);
	for (uint y = 0; y < size.height; y++)
		for (uint x = 0; x <= size.width; x++) {
			RGB t = data[y * size.height + x];
			fprintf(file, "%c%c%c", t.R, t.G, t.B);
		}
}
