#include "C_Dino.h"


dino::dino(int x, int y)
{
	xC = x;
	line = y;
	type = 4;
	draw = new displayDino;
}
dino::~dino()
{
	delete draw;
	xC = 18;
	line = 0;
}
void dino::display()
{
	draw->display(xC, line);
}
void dino::move(int step)
{
	xC += step;
	if (xC > 85) xC = 5;
	else if (xC < 0) xC = 85;
}
int dino::lastPoint()
{
	return xC + 7; // return last x-coordinate
}