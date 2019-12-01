#include "C_Game.h"

game::game() {
	x = 18;
	line = 1;
	speed = 350;
	vehicle* tmp = new car(18, 1);
	vehi.push_back(tmp);
	vehicle* tmp2 = new truck(18, 2);
	vehi.push_back(tmp2);
	vehicle* tmp3 = new bird(31, 3);
	vehi.push_back(tmp3);
	vehicle* tmp4 = new dino(31, 4);
	vehi.push_back(tmp4);
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
int game::pauseLane()
{
	srand((int)time(0));
	return (rand() % (3 + 1));
}
void game::move()
{
	int step = 13;
	color(240);
	display();
	int j = 0;
	int lin = pauseLane();
	while (j < 20) {
		Sleep(speed);
		color(7);
		display();
		if (j < 5)
		{
			for (int i = 0; i < vehi.size(); ++i)
			{
				if(i != lin)
					vehi[i]->move(step);
			}
		}
		else
		{
			for (int i = 0; i < vehi.size(); ++i)
				vehi[i]->move(step);
		}
		color(240);
		display();
		++j;
	}
	color(7);
}
void game::movePlayer() {
	int m = _getch();
	color(240);
	player->display();
	while (m != 13)
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
	}
}

vector<int> game::pauseGame()
{
	vector<int> store;
	int x, line;
	for (int i = 0; i < vehi.size(); ++i)
	{
		vehi[i]->getCor(x, line);
		store.push_back(x);
		store.push_back(line);
	}
	player->getCor(x, line);
	store.push_back(x);
	store.push_back(line);
	return store;
}
void game::gamePlay()
{
	move();

}
bool game::check_Intersec()
{
	int xP, yP;
	player->getCor(xP, yP);
	for (int i = 0; i < vehi.size(); ++i)
	{
		int xtmp, ytmp;
		vehi[i]->getCor(xtmp, ytmp);
		if (yP == ytmp)
			return false;
	}
	return true;
}