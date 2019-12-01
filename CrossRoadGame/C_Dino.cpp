#include "C_Dino.h"


dino::dino(int x, int y)
{
	xC = x;
	line = y;
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
	if (xC > 93) xC = 18;
	else if (xC < 0) xC = 93;
}
int dino::lastPoint()
{
	return xC + 7; // return last x-coordinate
}