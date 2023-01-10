#include "OrthonormalBasis.hpp"

OrthonormalBasis::OrthonormalBasis(v3 eye, v3 lookAt, v3 up)
{
	w = v3norm(v3sub(eye, lookAt));
	u = v3norm(v3cross(up, w));
	v = v3cross(w, u);
}

v3 onbMul(onb onb, v3 v)
{
	v3
		t1 = v3mul(onb.u, v.X),
		t2 = v3mul(onb.v, v.Y),
		t3 = v3mul(onb.w, v.Z);

	return v3add(t1, v3add(t2, t3));
}
