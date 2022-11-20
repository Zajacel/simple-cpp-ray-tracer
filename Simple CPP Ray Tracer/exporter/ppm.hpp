#pragma once

#include "../color/color.hpp"
#include "../vector/vector3.hpp"

void exportPPMtxt(RGB* data, v3 size);
void exportPPMbin(RGB* data, v3 size);
