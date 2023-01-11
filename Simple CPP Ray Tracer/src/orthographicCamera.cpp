#include "orthographicCamera.hpp"

#include "defines.hpp"
#include "rotation.hpp"
#include <stdio.h>
#include <stdlib.h>

RGB orthographicCamera(CameraInfo caminf, uint x, uint y) {
	Vector3 origin, direction;

	computeOriginAndDirection(&origin, &direction, caminf, x, y);

	auto hittedObjectIndex = findClosestColision(&origin, &direction, caminf);
	if (hittedObjectIndex == -1) return caminf.skyboxColor;
	return caminf.scene.objects[hittedObjectIndex]->color;
}

void computeOriginAndDirection(v3 *origin, v3 *direction, CameraInfo caminf, uint x, uint y) {
	Vector3 temp;

	computePointPosition(&temp, caminf, x, y);
	computeVectorRotation(origin, direction, &temp, caminf);
}

void computePointPosition(v3* point, CameraInfo caminf, uint x, uint y) {
	double
		cellHalfWidth = caminf.size.X / caminf.resolution.width,
		cellHalfHeight = caminf.size.Y / caminf.resolution.height;

	point->X = cellHalfWidth / 2 + caminf.pos.X - caminf.size.X / 2 + x * cellHalfWidth;
	point->Y = cellHalfHeight / 2 + caminf.pos.Y - caminf.size.Y / 2 + y * cellHalfHeight;
	point->Z = caminf.pos.Z;
}

void computeVectorRotation(v3* origin, v3* direction, v3* temp, CameraInfo caminf) {
	*direction = v3(0, 0, 1);
	*origin = calculateRotation(*temp, caminf.rot);
	*direction = v3norm(calculateRotation(*direction, caminf.rot));
	*origin = *temp;
}

int findClosestColision(v3 *origin, v3 *direction, CameraInfo caminf) {
	double smallestDistance = RT_HUGE;
	int closestObjectIndex = -1;

	for (int i = 0; i < caminf.scene.currentObjectIndex; i++) {
		GeometricObject* t = caminf.scene.objects[i];
		double distance = t->HitTest(*origin, *direction);

		if (distance > 0 && distance < smallestDistance) {
			smallestDistance = distance;
			closestObjectIndex = i;
		}
	}

	return smallestDistance >= RT_HUGE ? -1 : closestObjectIndex;
}
