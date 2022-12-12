#include <iostream>

#include "src/types.hpp"
#include "src/defines.hpp"
#include "src/bmp.hpp"
#include "src/Size.hpp"
#include "src/orthographicCamera.hpp"

int main()
{
	Size res = Size(WIDTH, HEIGHT);
	RGB* image = new RGB[WIDTH * HEIGHT];

	Scene scene;

	CameraInfo caminf;
	caminf.resolution = res;
	caminf.scene = scene;
	caminf.pos = Vector3(0, 0, 0);
	caminf.rot = Vector3(0, 0, 0);
	caminf.size = Vector2(100, 100);

	for (uint y = 0; y < HEIGHT; y++)
		for (uint x = 0; x < WIDTH; x++)
			image[y * HEIGHT + x] = orthographicCamera(caminf, x, y);

	//exportPPMbin(image, size);
	exportBMP(image, res);
	return 0;
}
