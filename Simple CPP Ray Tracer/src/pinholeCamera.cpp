#include "pinholeCamera.hpp"
#include "cameraUtils.hpp"

RGB pinholeCamera(CameraInfo caminf, uint x, uint y)
{
	onb onb = OrthonormalBasis(caminf.pos, caminf.rot, v3(0, 0, 1));

	v3 direction = onbMul(onb, v3(x, y, -1));

	auto hittedObjectIndex = findClosestColision(&caminf.pos, &direction, caminf.scene);
	if (hittedObjectIndex == -1) return caminf.skyboxColor;
	return caminf.scene.objects[hittedObjectIndex]->color;
	return RGB(0, 0, 0);
}
