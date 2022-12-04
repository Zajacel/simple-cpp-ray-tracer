#include "orthographicCamera.hpp"

#include "defines.hpp"
#include "rotation.hpp"

RGB orthographicCamera(CameraInfo caminf, uint x, uint y) {
	Vector3 origin, temp, destination;
	
	auto cellHalfWidth = caminf.size.X / caminf.resolution.width;
	auto cellHalfHeight = caminf.size.Y / caminf.resolution.height;

	temp.X = cellHalfWidth/2 + caminf.pos.X - caminf.size.X / 2 + x * cellHalfWidth;
	temp.Y = cellHalfHeight/2 + caminf.pos.Y - caminf.size.Y / 2 + y * cellHalfHeight;
	temp.Z = caminf.pos.Z;


	destination = v3add(temp, v3(0, 0, RT_EPSILON));
	origin = calculateRotation(temp, caminf.rot);
	temp = destination;
	destination = calculateRotation(temp, caminf.rot);
	

	return RGB(0, 0, 0);
}
