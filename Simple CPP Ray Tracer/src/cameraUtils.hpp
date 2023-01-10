#pragma once

#include "Vector3.hpp"
#include "Scene.hpp"

int findClosestColision(v3* origin, v3* direction, Scene scene);

void computeOriginAndDirection(v3* origin, v3* direction, v3 rot);
