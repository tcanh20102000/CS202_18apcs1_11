#include "C_Car.h"

car::car(int x, int y)
{
	xC = x;
	line = y;
	type = 1;
	draw = new displayCar;
}
car::~car()
{
	delete draw;
	xC = 18;
	line = 0;
}
void car::display()
{
	draw->display(xC, line);
}
void car::move(int step)
{
	xC += step;
	if (xC > 87) xC = 5;
	else if (xC < 0) xC = 87;
}
int car::lastPoint()
{
	return xC + 9; // return last x-coordinate
}