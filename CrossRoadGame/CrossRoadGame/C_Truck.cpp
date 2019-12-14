#include "C_Truck.h"

truck::truck(int x, int y)
{
	xC = x;
	line = y;
//	light = new displayLight;
	draw = new displayTruck;
	type = 2;
}
truck::~truck()
{
	delete draw;
//	delete light;
	xC = 18;
	line = 0;
}
void truck::display()
{
	draw->display(xC, line);
//	light->display(xC, line);
}
void truck::move(int step)
{
	xC += step;
	if (xC > 85) xC = 5;
	else if (xC < 0) xC = 87;
}
int truck::lastPoint()
{
	return xC+9; // return last x-coordinate
}