#include "cameraUtils.hpp"
#include "defines.hpp"
#include "rotation.hpp"

int findClosestColision(v3* origin, v3* direction, Scene scene) {
	double smallestDistance = RT_HUGE;
	int closestObjectIndex = -1;

	for (int i = 0; i < scene.currentObjectIndex; i++) {
		auto t = scene.objects[i];
		auto distance = t->HitTest(*origin, *direction);

		if (distance > 0 && distance < smallestDistance) {
			smallestDistance = distance;
			closestObjectIndex = i;
		}
	}

	return smallestDistance >= RT_HUGE ? -1 : closestObjectIndex;
}

void computeOriginAndDirection(v3* origin, v3* direction, v3 rot)
{
	v3 temp;

	*origin = calculateRotation(*origin, rot);

	*direction = v3norm(calculateRotation(v3(0, 0, RT_EPSILON), rot));
}
