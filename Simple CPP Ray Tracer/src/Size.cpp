#include "Size.hpp"

Size::Size()
{
	this->width = 0;
	this->height = 0;
}

Size::Size(uint w, uint h)
{
	this->width = w;
	this->height = h;
}

Size::Size(int w, int h)
{
	this->width = w;
	this->height = h;
}
