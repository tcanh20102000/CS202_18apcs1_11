#include "C_Game.h"

game::game() {
	x = 18;
	line = 1;
	speed = 350;
	round = 1;
	vehicle* tmp = new car(18, 1);
	vehi.push_back(tmp);
	vehicle* tmp2 = new truck(18, 2);
	vehi.push_back(tmp2);
	vehicle* tmp3 = new bird(18, 3);
	vehi.push_back(tmp3);
	vehicle* tmp4 = new dino(18, 4);
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
	return (rand() % (4 + 1));
}
void game::nextRound()
{
	srand((int)time(0));
	int r = 1 + (rand() % (4 + 1 - 1));
	vector<int> line;
	line.push_back(1);
	line.push_back(2);
	line.push_back(3);
	line.push_back(4);
	for (int i = 0; i < line.size(); ++i)
		if (line[i] == r)
			line.erase(line.begin()+i);
	vehi.clear();
	vehicle* v1 = new car(18, 1);
	vehi.push_back(v1);
	vehicle* v2 = new truck(18, 2);
	vehi.push_back(v2);
	vehicle* v3 = new bird(18, 3);
	vehi.push_back(v3);
	vehicle* v4 = new dino(18, 4);
	vehi.push_back(v4);
	int dist = 14;
	if (round == 2)
		speed = 200;
	else if (round == 3)
	{
		vehicle* tmp = new car(18 + dist, r);
		vehi.push_back(tmp);
		vehicle* tmp2 = new truck(18 + dist, line[0]);
		vehi.push_back(tmp2);
		vehicle* tmp3 = new bird(18 + dist, line[1]);
		vehi.push_back(tmp3);
		vehicle* tmp4 = new dino(18 + dist, line[2]);
		vehi.push_back(tmp4);
		speed = 200;
	}
	else if (round == 4)
	{
		vehicle* tmp = new car(18+dist, r);
		vehi.push_back(tmp);
		vehicle* tmpC = new car(18+2*dist, r);
		vehi.push_back(tmpC);
		vehicle* tmp2 = new truck(18+dist, line[0]);
		vehi.push_back(tmp2);
		vehicle* tmp2T = new truck(18+2*dist, line[0]);
		vehi.push_back(tmp2T);
		vehicle* tmp3 = new bird(18+dist, line[1]);
		vehi.push_back(tmp3);
		vehicle* tmp3B = new bird(18+2*dist, line[1]);
		vehi.push_back(tmp3B);
		vehicle* tmp4 = new dino(18+dist, line[2]);
		vehi.push_back(tmp4);
		vehicle* tmp4D = new dino(18+2*dist, line[2]);
		vehi.push_back(tmp4D);
		speed = 100;
	}
	else if(round==5){
		speed = 40;
		vehicle* tmp = new car(18 + dist, r);
		vehi.push_back(tmp);
		vehicle* tmpC = new car(18 + 2 * dist, r);
		vehi.push_back(tmpC);
		vehicle* tmp2 = new truck(18 + dist, line[0]);
		vehi.push_back(tmp2);
		vehicle* tmp2T = new truck(18 + 2 * dist, line[0]);
		vehi.push_back(tmp2T);
		vehicle* tmp3 = new bird(18 + dist, line[1]);
		vehi.push_back(tmp3);
		vehicle* tmp3B = new bird(18 + 2 * dist, line[1]);
		vehi.push_back(tmp3B);
		vehicle* tmp4 = new dino(18 + dist, line[2]);
		vehi.push_back(tmp4);
		vehicle* tmp4D = new dino(18 + 2 * dist, line[2]);
		vehi.push_back(tmp4D);
	}
}
void game::move()
{
	int step = 5;
	color(240);
	display();
	player->display();
	int lin = pauseLane();
	Sleep(speed);
	color(7);
	display();
	for (int i = 0; i < vehi.size(); ++i)
	{
		int xv,yv;
		vehi[i]->getCor(xv, yv);
		if(yv != lin)
			vehi[i]->move(step);
	}
	color(240);
	display();
	color(7);
}

int game::movePlayer() {
	int m = 1;
	color(240);
	int xp, yp;
	while (1)
	{
		while (!_kbhit())
			move();
		m = _getch();
		color(7);
		player->disAppear();
		if (m == 87 || m == 119)
		{
			player->move(0);
			player->getCor(xp, yp);
			if (yp == 1)
			{
				++round;
				if (round > 5) {
					system("cls");
					cout << "Congratulation" << endl;
					return 1;
				}
				system("cls");
				Sleep(700);
				nextRound();
				player->move(1);
				player->move(1);
				player->move(1);
				player->move(1);
				player->move(1);
			}

		}
		else if (m == 83 || m == 115)
			player->move(1);
		else if (m == 68 || m == 100)
			player->move(2);
		else if (m == 65 || m == 97)
			player->move(3);
		else if (m == 'p' || m == 'P') {
			int tmp = pauseGame();
			if (tmp == 0)
				return -1;
		}
		else return -1;
		
		color(240);
		player->display();
		Sleep(100);
	}
	return 0;
}
int game::pauseGame()
{
	system("cls");
	cout << "This is Screen Pause" << endl;
	cout << "Press 1: Save And Quit" << endl;
	cout << "Press 2: Back To Game" << endl;
	if (_getch() == 50)
	{
		system("cls");
		return 1;
	}
	system("cls");
	return 0;
}
void game::gamePlay()
{
	int xu, yu;
	player->getCor(xu, yu);
	int xv, yv;
	movePlayer();
	for (int i = 0; i < vehi.size(); ++i)
	{
		vehi[i]->getCor(xv, yv);
		if (xu == xv && yu == yv)
		{
			cout << "Game Over" << endl;
			return;
		}
	}
}
bool game::check_Intersec()
{
	int xu, yu;
	player->getCor(xu, yu);
	int xv, yv;
	movePlayer();
	for (int i = 0; i < vehi.size(); ++i)
	{
		vehi[i]->getCor(xv, yv);
		if (xu == xv && yu == yv)
		{
			cout << "Game Over" << endl;
			return true;
		}
	}
	return false;
}