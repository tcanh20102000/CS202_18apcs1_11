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
void user::disAppear()
{
	draw->disAppear(xP,yP);
}
void user::move(int direct)
{
//	int xtmp = xP, ytmp=yP;
	if (direct == 0)
		yP -= 1;
	else if (direct == 1)
		yP += 1;
	else if (direct == 2)
		xP += 5;
	else
		xP -= 5;
	if (xP <= 10)
		xP = 90;
	else if (xP >= 90)
		xP = 10;
	if (yP > 5)
		yP = 5;
	else if (yP < 1)
		yP = 5;
}
void user::getCor(int &x, int &line)
{
	x = xP;
	line = yP;
}
bool user::isInter(int x)
{
	return false;
}