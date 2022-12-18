#include <iostream>

#include "src/types.hpp"
#include "src/defines.hpp"
#include "src/bmp.hpp"
#include "src/Size.hpp"
#include "src/orthographicCamera.hpp"
#include "src/Sphere.hpp"

int main()
{
	Size res = Size(WIDTH, HEIGHT);
	RGB* image = new RGB[WIDTH * HEIGHT];

	Scene scene;
	//for (int i = 0; i <= 5; i++) {
	//	auto p = Vector3(i, i, i);
	//	auto c = RGB(i * 50, i * 50, i * 50);
	//	scene.addObject(Sphere(p, i * 1.5, c));
	//}
	auto t = new Sphere(
		v3(6, 0, 0),
		2,
		RGB(200, 30, 30)
	);
	scene.addObject(t);

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

	//exportPPMbin(image, size);
	exportBMP(image, res);

	delete scene.objects, image;
	return 0;
}
