#include "orthographicCamera.hpp"

#include "defines.hpp"
#include "rotation.hpp"
#include "cameraUtils.hpp"

RGB orthographicCamera(CameraInfo caminf, uint x, uint y) {
	Vector3 origin, direction;

	double
		cellHalfWidth = caminf.size.X / caminf.resolution.width,
		cellHalfHeight = caminf.size.Y / caminf.resolution.height;

	origin.X = cellHalfWidth / 2 + caminf.pos.X - caminf.size.X / 2 + x * cellHalfWidth;
	origin.Y = cellHalfHeight / 2 + caminf.pos.Y - caminf.size.Y / 2 + y * cellHalfHeight;
	origin.Z = caminf.pos.Z;

	computeOriginAndDirection(&origin, &direction, caminf.rot);

	auto hittedObjectIndex = findClosestColision(&origin, &direction, caminf.scene);
	if (hittedObjectIndex == -1) return caminf.skyboxColor;
	return caminf.scene.objects[hittedObjectIndex]->color;
}
