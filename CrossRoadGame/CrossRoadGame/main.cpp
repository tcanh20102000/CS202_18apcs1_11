#include "FrontEnd.h"
#include "DisplayBehavior.h"
#include "C_Game.h"


bool isPlaying = true;
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
	game init;
	color(7);
	t.join();
	gotoxy(0, 30);
	return 0;
}