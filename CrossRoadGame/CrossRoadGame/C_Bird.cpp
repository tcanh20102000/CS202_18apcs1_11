#include "C_Bird.h"

bird::bird(int x, int y)
{
	xC = x;
	line = y;
	type = 3;
	draw = new displayBird;
}
bird::~bird()
{
	delete draw;
	xC = 18;
	line = 0;
}
void bird::display()
{
	draw->display(xC, line);
}
void bird::move(int step)
{
	xC += step;
	if (xC > 74 && xC < 76) xC = 4;
	else if (xC >= 75) xC = 11;
	else if (xC < 0) xC = 75;
}
int bird::lastPoint()
{
	return xC + 11; // return last x-coordinate
}
