#include "Ray.hpp"

Ray::Ray(v3 origin, v3 destination)
{
	o = origin;
	d = v3norm(destination);
}
