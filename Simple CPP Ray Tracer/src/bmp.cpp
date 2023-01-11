#include "bmp.hpp"
#include <stdio.h>

char* generateBMPHeaders(Size size, uint padding)
{
	char *bmp_headers = new char[BMP_ALL_HEADERS_BYTES];
	int fileSize = size.height * size.width * 3 + padding + BMP_ALL_HEADERS_BYTES;

	memcpy(bmp_headers, &BMP_HEADER, sizeof BMP_HEADER);
	memcpy(bmp_headers + BMP_CORE_HEADER_BYTES, &DIB_HEADER, sizeof DIB_HEADER);

	memcpy(bmp_headers + 2, &fileSize, sizeof fileSize);

	memcpy(bmp_headers + BMP_CORE_HEADER_BYTES + 4, &size.width, sizeof size.width);
	memcpy(bmp_headers + BMP_CORE_HEADER_BYTES + 8, &size.height, sizeof size.height);

	return bmp_headers;
}

void exportBMP(RGB* data, Size size)
{
	FILE* file;
	fopen_s(&file, "image.bmp", "w");

	if (file == NULL)
	{
		fprintf(stderr, "\nError while opening file\n");
		exit(1);
	}

	// Bitmap requires scanline to use padding to 4 bytes
	uint padding = 4 - (size.width % 4);
	padding = padding == 4 ? 0 : padding;

	char* bmp_headers = generateBMPHeaders(size, padding);

	fwrite(bmp_headers, BMP_ALL_HEADERS_BYTES, 1, file);
	
	for (uint y = size.height; y > 0; y--) {
		for (uint x = 0; x < size.width; x++) {
			RGB pixel = data[y * size.width + x];
			fprintf(file, "%c%c%c", pixel.B, pixel.G, pixel.R);
		}
		for (uint t = 0; t < padding; t++)
			fprintf(file, "%c", 0);
	}

	fclose(file);
	delete[] bmp_headers;
}
