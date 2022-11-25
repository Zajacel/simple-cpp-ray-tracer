#include "bmp.hpp"

void exportBMP(RGB* data, Size size)
{
	BMPheader bmpHeader = createCoreBMPHeader(size);
}

BMPheader createCoreBMPHeader(Size size)
{
	BMPheader header = BMPheader();
	header.imagesize = size.height * size.width;
}
