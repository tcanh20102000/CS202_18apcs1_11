#include "C_Bird.h"

bird::bird(int x, int y)
{
	xC = x;
	line = y;
}
bird::~bird()
{
	delete draw;
	xC = 18;
	line = 0;
}
void bird::display()
{
	draw = new displayBird;
	draw->display(xC, line);
}
void bird::move(int step)
{
	xC += step;
	if (xC > 93) xC = 18;
	else if (xC < 0) xC = 93;
}
int bird::lastPoint()
{
	return xC + 11; // return last x-coordinate
}
