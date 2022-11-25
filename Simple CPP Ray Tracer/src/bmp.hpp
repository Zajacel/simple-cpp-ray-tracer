#pragma once

#include "types.hpp"
#include "RGB.hpp"
#include "Size.hpp"

struct BMPheader {
	ushort bmpType = 0x424D; // bitmap magic number
	uint imagesize; // amount of bytes
	uint empty = 0; // not describled in wiki
	uint offset = 0x36; // where pixel array starts

	//TODO: check what's going on with empty
};

struct DIBheader {
	// BITMAPINFOHEADER
	uint headerSize = 40; // constant, 40 bytes
	int width; // in pixels
	int height; // in pixels
	ushort numberOfColorPLanes = 1;
	ushort bitsPerPixel = 24; // power of 2
	uint compressionMethod = 0; // BI_RGB
	uint horizontalResolution = 0; // ¯\_(ツ)_/¯
	uint verticalResolution = 0; // ¯\_(ツ)_/¯
	uint colorsInPalete = 0; // 0 defaults to 2 to power of n
	uint importantColors = 0; // important colors used,usually ignored
};

void exportBMP(RGB* data, Size size);
BMPheader createCoreBMPHeader(Size size);