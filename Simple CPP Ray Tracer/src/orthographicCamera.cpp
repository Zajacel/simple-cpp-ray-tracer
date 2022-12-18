#include "orthographicCamera.hpp"

#include "defines.hpp"
#include "rotation.hpp"
#include <stdio.h>
#include <stdlib.h>

RGB orthographicCamera(CameraInfo caminf, uint x, uint y) {
	Vector3 origin, destination;

	computeOriginAndDestination(&origin, &destination, caminf, x, y);

	auto hittedObjectIndex = findClosestColision(&origin, &destination, caminf);
	if (hittedObjectIndex == -1) return caminf.skyboxColor;
	return caminf.scene.objects[hittedObjectIndex]->color;
}

void computeOriginAndDestination(v3 *origin, v3 *destination, CameraInfo caminf, uint x, uint y) {
	Vector3 temp;

	computePointPosition(&temp, caminf, x, y);
	computeVectorRotation(origin, destination, &temp, caminf);
}

void computePointPosition(v3* point, CameraInfo caminf, uint x, uint y) {
	double
		cellHalfWidth = caminf.size.X / caminf.resolution.width,
		cellHalfHeight = caminf.size.Y / caminf.resolution.height;

	point->X = cellHalfWidth / 2 + caminf.pos.X - caminf.size.X / 2 + x * cellHalfWidth;
	point->Y = cellHalfHeight / 2 + caminf.pos.Y - caminf.size.Y / 2 + y * cellHalfHeight;
	point->Z = caminf.pos.Z;
}

void computeVectorRotation(v3* origin, v3* destination, v3* temp, CameraInfo caminf) {
	*destination = v3add(*temp, v3(0, 0, RT_EPSILON));
	*origin = calculateRotation(*temp, caminf.rot);
	*temp = *destination;
	*destination = calculateRotation(*temp, caminf.rot);
}

int findClosestColision(v3 *origin, v3 *destination, CameraInfo caminf) {
	double smallestDistance = -1;
	int closestObjectIndex;

	for (int i = 0; i < caminf.scene.currentObjectIndex; i++) {
		auto t = caminf.scene.objects[i];
		auto distance = t->HitTest(*origin, *destination);

		if (smallestDistance == -1 || distance < smallestDistance) {
			smallestDistance = distance;
			closestObjectIndex = i;
		}
	}

	return smallestDistance < 0 ? -1 : closestObjectIndex;
}
