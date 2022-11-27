#include "types.hpp"
#include "defines.hpp"
#include "RGB.hpp"
#include "CameraInfo.hpp"
#include "rotation.hpp"

RGB orthographicCamera(CameraInfo caminf, uint x, uint y) {
	Vector3 origin, destination;
	
	origin.X = (2 * caminf.pos.X - caminf.size.X + 2 * x * caminf.resolution.width) / 2;
	origin.Y = (2 * caminf.pos.Y - caminf.size.Y + 2 * y * caminf.resolution.width) / 2;
	origin.Z = caminf.pos.Z;

	origin.X = calculateRotationX(origin, caminf.rot);
	origin.Y = calculateRotationY(origin, caminf.rot);
	origin.Z = calculateRotationZ(origin, caminf.rot);

	destination = v3add(origin, EPSILON);

	return RGB(0, 0, 0);
}
