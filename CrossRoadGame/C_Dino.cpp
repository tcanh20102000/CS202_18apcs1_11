#include "C_Dino.h"


dino::dino(int x, int y)
{
	xC = x;
	line = y;
	length = 7;
	type = 4;
}
dino::~dino()
{
	delete draw;
	xC = 18;
	line = 0;
}
void dino::display()
{
	draw = new displayDino;
	draw->display(xC, line);
}
void dino::move(int step)
{
	xC += step;
	if (xC > 96) xC = 18;
	else if (xC < 0) xC = 96;
}
int dino::lastPoint()
{
	return xC + 7; // return last x-coordinate
}