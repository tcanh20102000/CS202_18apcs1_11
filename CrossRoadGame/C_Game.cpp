#include "C_Game.h"
void dangerzonemove(pair<int, int>&a, int step) {
		a.first += step;
		a.second += step;
	if (a.second > 93&&a.first<93) {
		a.second = a.first;
		a.first = 9;
	}
	else if (a.first > 93) {
		a.first = 9;
		a.second = 22;
	}
}

game::game() {
	x = 18;
	line = 1;
	speed = 350;
	vehicle* tmp = new car(18, 1);
	vehi.push_back(tmp);
	vehicle* tmp2 = new truck(18, 3);
	vehi.push_back(tmp2);
	vehicle* tmp3 = new bird(31, 3);
	vehi.push_back(tmp3);
	vehicle* tmp4 = new dino(31, 1);
	vehi.push_back(tmp4);
	danger1.first =danger2.first= 9;
	danger1.second =danger2.second= 31;
	player = new user;
}

game::~game() {
	if (vehi.size() > 0)
	{
		for (int i = 0; i < vehi.size(); ++i)
			delete vehi[i];
	}
	delete player;
	x = 18;
	line = 1;
	speed = 500;
}
void game::display()
{
	for (int i = 0; i < vehi.size(); ++i)
		vehi[i]->display();
}
void game::move()
{
	player->display();
	int step = 13;
	color(240);
	display();
	int j = 0;
	Line();
	while (j<25) {
		Sleep(speed);
		color(7);
		display();
		for (int i = 0; i < vehi.size(); ++i) {
			vehi[i]->move(step);
			dangerzonemove(danger1, step);
			dangerzonemove(danger2, step);
		}
		color(240);
		display();		
		if (!player->alive) cout << "Heo";
		else cout << ".";
		j++;
	}
	/*if (pos.second == 1) {
		if (pos.first > danger1.first&&pos.first < danger1.second) {
			player->alive = false;
		}
	}*/
	color(7);
}
void game::movePlayer() {
	//player->display();
	int m = _getch(); Sleep(speed);
	pos = player->pos();
	color(240);
	while (m != 13&&player->alive)
	{
		Sleep(100);
		color(7);
		player->display();
		if (m == 87 || m == 119)
			player->move(0); // go up
		else if (m == 83 || m == 115)
			player->move(1); //go down
		else if (m == 68 || m == 100)
			player->move(2); //go right
		else if (m == 65 || m == 97)
			player->move(3); //go left
		color(240);
		player->display();
		m = _getch();
		Sleep(speed);
	}
}
void game::SubThread() {
	int step = 13;
	while (1) {
		if (player->alive) {
			pos = player->pos();
		}
		Sleep(speed);
		color(7);
		display();
		for (int i = 0; i < vehi.size(); ++i) {
			vehi[i]->move(step);
			dangerzonemove(danger1, step);
			dangerzonemove(danger2, step);
		}
		color(240);
		display();
	}
}
