#include "C_People.h"

user::user() {
	draw = new displayPlayer;
	xP = 45;
	yP = 24;
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
	if (direct == 0)
		yP -= 5;
	else if (direct == 1)
		yP += 5;
	else if (direct == 2)
		xP += 5;
	else
		xP -= 5;
	if (xP <= 10)
		xP = 5;
	else if (xP >= 90)
		xP = 90;
	if (yP > 24)
		yP = 24;
}
void user::getCor(int &x, int &line)
{
	x = xP;
	line = yP;
}
void user::setCor(int x, int line) {
	xP = x;
	yP = line;
}
bool user::isInter(int x)
{
	return false;
}