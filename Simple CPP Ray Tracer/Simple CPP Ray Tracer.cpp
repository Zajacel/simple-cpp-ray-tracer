#include <iostream>

#include "src/types.hpp"
#include "src/defines.hpp"
#include "src/bmp.hpp"
#include "src/ppm.hpp"
#include "src/Size.hpp"
#include "src/orthographicCamera.hpp"
#include "src/pinholeCamera.hpp"
#include "src/Sphere.hpp"

int main()
{
	Size res = Size(WIDTH, HEIGHT);
	RGB* image = new RGB[WIDTH * HEIGHT];

	Scene scene;
	scene.addObject(new Sphere(
		v3(0, 0, 8),
		2,
		RGB(200, 30, 30)
	));

	scene.addObject(new Sphere(
		v3(-1.75, 0, 11),
		2,
		RGB(30, 200, 30)
	));

	scene.addObject(new Sphere(
		v3(1.75, 0, 5),
		2,
		RGB(30, 30, 200)
	));

	CameraInfo caminf;
	caminf.resolution = res;
	caminf.scene = scene;
	caminf.pos = Vector3(0, 0, 0);
	caminf.rot = Vector3(0, 0, 0);
	caminf.size = Vector2(10, 10);
	caminf.skyboxColor = RGB(47, 159, 245);

	for (uint y = 0; y < HEIGHT; y++)
		for (uint x = 0; x < WIDTH; x++)
			image[y * HEIGHT + x] = orthographicCamera(caminf, x, y);

	exportBMP(image, res);
	exportPPMbin(image, res);
	exportPPMtxt(image, res);

	delete scene.objects, image;
	return 0;
}
