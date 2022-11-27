#include <iostream>

#include "src/types.hpp"
#include "src/defines.hpp"
#include "src/bmp.hpp"
#include "src/Size.hpp"
#include "src/orthographicCamera.hpp"

int main()
{
	const uint X = WIDTH;
	const uint Y = HEIGHT;
	Size size = Size(X, Y);
	RGB* image = new RGB[X * Y];

	Scene scene;

	CameraInfo caminf;
	caminf.resolution = size;
	caminf.scene = scene;
	caminf.pos = Vector3(-1, 1, -5);


	for (uint y = 0; y < Y; y++)
		for (uint x = 0; x < X; x++)
			image[y * Y + x] = orthographicCamera(caminf, x, y);

	//exportPPMbin(image, size);
	exportBMP(image, size);
	return 0;
}
