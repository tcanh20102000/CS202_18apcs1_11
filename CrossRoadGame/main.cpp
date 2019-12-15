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
void PauseBoard() {//new
	color(114);//Box color
	int x0 = 35;
	int y0 = 8;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 60; j++) {
			gotoxy(x0 + j, y0 + i); cout << " ";
		}
	}
	gotoxy(x0 + 2, y0 + 1);
	cout << "Please input your save file destination:" ;
	gotoxy(x0 + 2, y0 + 3); color(15);//Path color
	string a;
	cin.ignore(1000, '\n');
	getline(cin, a);
}

int main()
{
	thread t(run);
	game init;
	init.movePlayer();
	//PauseBoard();
	color(7);
	t.join();
	gotoxy(0, 40);
	system("pause");
	return 0;
}