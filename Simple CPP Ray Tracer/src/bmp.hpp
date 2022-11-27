#pragma once

#include <array>

#include "types.hpp"
#include "RGB.hpp"
#include "Size.hpp"

#define BMP_CORE_HEADER_BYTES 14
#define BMP_DIB_HEADER_BYTES 40
#define BMP_ALL_HEADERS_BYTES BMP_CORE_HEADER_BYTES + BMP_DIB_HEADER_BYTES

#pragma pack(push, 1)
struct BMPheader {
	ushort bmpType = 0x424D; // bitmap magic number
	int imagesize = 0; // amount of bytes
	uint empty = 0; // not described in wiki
	uint offset = 0x36; // where pixel array starts

	//TODO: check what's going on with empty
};
#pragma pack(pop)

const char BMP_HEADER[14] = {0x42, 0x4D, 0, 0, 0, 0, 0, 0, 0, 0, 0x36};

#pragma pack(push, 1)
struct DIBheader {
	// BITMAPINFOHEADER
	int headerSize = 40; // constant, 40 bytes
	int width = 0; // in pixels
	int height = 0; // in pixels
	ushort numberOfColorPLanes = 1;
	ushort bitsPerPixel = 24; // power of 2
	uint compressionMethod = 0; // BI_RGB
	uint horizontalResolution = 0; // ¯\_(ツ)_/¯
	uint verticalResolution = 0; // ¯\_(ツ)_/¯
	uint colorsInPalete = 0; // 0 defaults to 2 to power of n
	uint importantColors = 0; // important colors used, usually ignored
};
#pragma pack(pop)

const char DIB_HEADER[40] = { 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0b1, 0, 0b11000 };

void exportBMP(RGB* data, Size size);
char* generateBMPHeaders(Size size);
