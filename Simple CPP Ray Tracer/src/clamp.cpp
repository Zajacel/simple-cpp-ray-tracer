#include "clamp.hpp"

double clamp(double min, double val, double max)
{
    if (val < min) return min;
    if (val > max) return max;
    return val;
}

int clamp(int min, int val, int max)
{
    if (val < min) return min;
    if (val > max) return max;
    return val;
}
