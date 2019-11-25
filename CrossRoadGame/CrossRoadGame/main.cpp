#include "FrontEnd.h"
#include "DisplayBehavior.h"
#include "C_Game.h"

mutex x;
void run() {
	x.lock();
	game start;
	start.move();
	x.unlock();
}
int main()
{
	thread t(run);
/*	t.join();
	if (_getch() == 13)
	{
		gotoxy(0, 50);
		cout << "Enter" << endl;
	}*/
	game init;
	init.movePlayer();
	color(7);
	t.join();
	gotoxy(0, 50);
	return 0;
}