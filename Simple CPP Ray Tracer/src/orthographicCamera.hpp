#pragma once

#include "CameraInfo.hpp"
#include "types.hpp"
#include "RGB.hpp"

RGB orthographicCamera(CameraInfo caminf, uint x, uint y);

void computeOriginAndDestination(v3* origin, v3* destination, CameraInfo caminf, uint x, uint y);

void computePointPosition(v3* point, CameraInfo caminf, uint x, uint y);

void computeVectorRotation(v3* origin, v3* destination, v3* temp, CameraInfo caminf);

int findClosestColision(v3* origin, v3* destination, CameraInfo caminf);
