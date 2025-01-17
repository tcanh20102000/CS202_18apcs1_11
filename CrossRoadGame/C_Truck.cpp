#include "C_Truck.h"

truck::truck(int x, int y)
{
	xC = x;
	line = y;
}
truck::~truck()
{
	delete draw;
	xC = 18;
	line = 0;
}
void truck::display()
{
	draw = new displayTruck;
	draw->display(xC, line);
}
void truck::move(int step)
{
	xC += step;
	if (xC > 93) xC = 18;
	else if (xC < 0) xC = 93;
}
int truck::lastPoint()
{
	return xC+9; // return last x-coordinate
}