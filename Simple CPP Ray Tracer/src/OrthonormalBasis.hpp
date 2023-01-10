#pragma once

#include "Vector3.hpp"

struct OrthonormalBasis {
	Vector3 w, u, v;

	OrthonormalBasis(v3 eye, v3 lookAt, v3 up);
};

typedef OrthonormalBasis onb;

v3 onbMul(onb onb, v3 v);
