#include "C_Car.h"

car::car(int x, int y)
{
	xC = x;
	line = y;
	length = 9;
	type = 1;
}
car::~car()
{
	delete draw;
	xC = 18;
	line = 0;
}
void car::display()
{
	draw = new displayCar;
	draw->display(xC, line);
}
void car::move(int step)
{
	xC += step;
	if (xC > 96) xC = 18;
	else if (xC < 0) xC = 96;
}
int car::lastPoint()
{
	return xC + 9; // return last x-coordinate
}