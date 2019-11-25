#include "C_People.h"

user::user() {
	draw = new displayPlayer;
	xP = 45;
	yP = 5;
}
user::user(int x, int line)
{
	xP = x;
	yP = line;
	draw = new displayPlayer;
}
user::~user()
{
	delete draw;
}
void user::display()
{
	draw->display(xP,yP);
}
void user::move(int direct)
{
//	int xtmp = xP, ytmp=yP;
	if (direct == 0)
		yP -= 1;
	else if (direct == 1)
		yP += 1;
	else if (direct == 2)
		xP += 15;
	else
		xP -= 15;
	if (xP <= 10)
		xP = 90;
	else if (xP >= 90)
		xP = 10;
	if (yP < 2)
		yP = 1;
	else if (yP > 5)
		yP = 5;
}
bool user::isInter(int x)
{
	return false;
}