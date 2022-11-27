#include "bmp.hpp"

char* generateBMPHeaders(Size size)
{
	char *bmp_headers = new char[BMP_ALL_HEADERS_BYTES];
	int fileSize = size.height * size.width * 3 + BMP_ALL_HEADERS_BYTES;

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

	char* bmp_headers = generateBMPHeaders(size);

	fwrite(bmp_headers, BMP_ALL_HEADERS_BYTES, 1, file);

	for (uint y = 0; y < size.height; y++)
		for (uint x = 0; x <= size.width; x++) {
			RGB t = data[y * (int)size.height + x];
			fprintf(file, "%c%c%c", t.B, t.G, t.R);
		}

	fclose(file);
	delete[] bmp_headers;
}
