#include "C_Game.h"

game::game() {
	x = rand_Range(18,105);
	line = 1;
	speed = 350;
	round = 1;
	player = new user;
	light = new displayLight;
	light2 = new displayLight;
}

game::~game() {
	if (vehi.size() > 0)
	{
		for (int i = 0; i < vehi.size(); ++i)
			delete vehi[i];
	}
	delete player;
	delete light;
	delete light2;
	x = 18;
	line = 1;
	speed = 500;
}
void game::display()
{
	for (int i = 0; i < vehi.size(); ++i)
		vehi[i]->display();
}
int game::rand_Range(int min, int max)
{
	srand((int)time(0));
	return (min + rand() % max);
}
void game::nextRound()
{
	srand((int)time(0));
	int xco = 6 + rand() % 85, y = 4;
	if (round == 4 || round == 5 || round == 5)
		if (xco > 94)
			xco = 4;
	if (vehi.size() != 0)
		vehi.clear();
	int dist = 11;
	if (round == 1)
	{
		vehicle* v1 = new car(xco, y);
		vehi.push_back(v1);
		vehicle* v2 = new truck(xco, y+5);
		vehi.push_back(v2);
		vehicle* v3 = new bird(xco, y+9);
		vehi.push_back(v3);
		vehicle* v4 = new dino(xco, y+14);
		vehi.push_back(v4);
		speed = 300;
	}
	else if (round == 2)
	{
		vehicle* v1 = new car(xco, y);
		vehi.push_back(v1);
		vehicle* v2 = new truck(xco, y+5);
		vehi.push_back(v2);
		vehicle* v3 = new bird(xco, y+9);
		vehi.push_back(v3);
		vehicle* v4 = new dino(xco, y+14);
		vehi.push_back(v4);
		speed = 200;
	}
	else if (round == 3)
	{
		vehicle* tmp = new car(xco + dist, y);
		vehi.push_back(tmp);
		vehicle* tmpC = new car(xco + 2 * dist, y);
		vehi.push_back(tmpC);
		vehicle* tmp2 = new truck(xco + dist, y+5);
		vehi.push_back(tmp2);
		vehicle* tmp2T = new truck(xco + 2 * dist,y+ 5);
		vehi.push_back(tmp2T);
		vehicle* tmp3 = new bird(xco + dist, y+9);
		vehi.push_back(tmp3);
		vehicle* tmp3B = new bird(xco + 2 * dist, y+9);
		vehi.push_back(tmp3B);
		vehicle* tmp4 = new dino(xco + dist, y+14);
		vehi.push_back(tmp4);
		vehicle* tmp4D = new dino(xco + 2 * dist,y+14);
		vehi.push_back(tmp4D);
		speed = 300;
	}
	else if (round == 4)
	{
		vehicle* tmp = new car(xco+dist, y);
		vehi.push_back(tmp);
		vehicle* tmpC = new car(xco+2*dist, y);
		vehi.push_back(tmpC);
		vehicle* tmp2 = new truck(xco+dist, y+5);
		vehi.push_back(tmp2);
		vehicle* tmp2T = new truck(xco+2*dist, y+5);
		vehi.push_back(tmp2T);
		vehicle* tmp3 = new bird(xco+dist, y+9);
		vehi.push_back(tmp3);
		vehicle* tmp3B = new bird(xco+2*dist, y+9);
		vehi.push_back(tmp3B);
		vehicle* tmp4 = new dino(xco+dist, y+14);
		vehi.push_back(tmp4);
		vehicle* tmp4D = new dino(xco+2*dist, y+14);
		vehi.push_back(tmp4D);
		speed = 150;
	}
	else if (round==5){
		speed = 50;
		vehicle* tmp = new car(xco + dist, y);
		vehi.push_back(tmp);
		vehicle* tmpC = new car(xco + 2 * dist, y);
		vehi.push_back(tmpC);
		vehicle* tmpC1 = new car(xco + 3 * dist, y);
		vehi.push_back(tmpC1);
		vehicle* tmp2 = new truck(xco + dist, y+5);
		vehi.push_back(tmp2);
		vehicle* tmp2T = new truck(xco + 2 * dist,y+5);
		vehi.push_back(tmp2T);
		vehicle* tmp2T1 = new truck(xco + 3 * dist, y+5);
		vehi.push_back(tmp2T1);
		vehicle* tmp3 = new bird(xco + dist, y+9);
		vehi.push_back(tmp3);
		vehicle* tmp3B = new bird(xco + 2 * dist, y+9);
		vehi.push_back(tmp3B);
		vehicle* tmp3B1 = new bird(xco + 2 * dist, y+9);
		vehi.push_back(tmp3B1);
		vehicle* tmp4 = new dino(xco + dist, y+14);
		vehi.push_back(tmp4);
		vehicle* tmp4D = new dino(xco + 2 * dist,y+14);
		vehi.push_back(tmp4D);
		vehicle* tmp4D1 = new dino(xco + 3 * dist, y+14);
		vehi.push_back(tmp4D1);
	}
}
/*int game::move(bool isD, int lin, int &wait)
{
	while (!_kbhit())
	{
		
		int step = 5;
		color(240);
		display();
		Line();
		player->display();
		color(7);
		display();
		Sleep(speed);
		if (lin == 1 && wait < 5)
		{
			light->display(93, 3);
			light2->displayRev(93, 8);
		}
		else if (lin == 2 && wait < 5)
		{
			light->displayRev(93, 3);
			light2->display(93, 8);
		}
		else {
			light->displayRev(93, 3);
			light2->displayRev(93, 8);
		}
		for (int i = 0; i < vehi.size(); ++i)
		{
			if (vehi[i]->Objtype() != lin)
				vehi[i]->move(step);
		}
		color(240);
		Line();
		display();
		color(7);
		if (!check_Intersec())
		{
			isD = true;
			return -1;
		}
		++wait;
	}
	return 0;
}*/
void game::move()
{
	int step = 5;
	color(240);
	display();
	Line();
	player->display();
	Sleep(speed);
	color(7);
	display();
	int lin = rand_Range(1, 2);
	if (lin == 1)
	{
		light->display(93, 3);
		light2->displayRev(93, 8);
	}
	else if (lin == 2)
	{
		light->displayRev(93, 3);
		light2->display(93, 8);
	}
	for (int i = 0; i < vehi.size(); ++i)
	{	
		if (vehi[i]->Objtype() != lin)
			vehi[i]->move(step);
	}
/*	color(240);
	Line();
	display();
	Sleep(speed);*/
}

int game::movePlayer() {
	system("cls");
	int m = 1;
	color(240);
	int xp, yp;
	bool isDead = false;
	nextRound();
	int wait = 0;
	while (!isDead)
	{
//		int lin = rand_Range(1, 2);
		while (!_kbhit())
		{
			move();
			if (!check_Intersec())
			{
				isDead = true;
				return -1;
			}
		}
		m = _getch();
		color(7);
		player->disAppear();
		if (m == 87 || m == 119)
		{
			player->move(0);
			player->getCor(xp, yp);
			if (!check_Intersec())
			{
				isDead = true;
				return -1;
			}
			if (yp < 4)
			{
				++round;
				if (round > 5) {
					return 2; // wingame return 0;
				}
				nextRound();
				system("cls");
				Sleep(700);
				player->move(1);
				player->move(1);
				player->move(1);
				player->move(1);
				player->move(1);
			}
		}
		else if (m == 83 || m == 115)
		{
			player->move(1);
			if (!check_Intersec())
			{
				isDead = true;
				return -1;
			}
		}
		else if (m == 68 || m == 100)
		{
			player->move(2);
			if (!check_Intersec())
			{
				isDead = true;
				return -1;
			}
		}
		else if (m == 65 || m == 97)
		{
			player->move(3);
			if (!check_Intersec())
			{
				isDead = true;
				return -1;
			}
		}
		else if (m == 'p' || m == 'P') {
			int tmp = pauseGame();
			if (tmp == 1)
				return 1; // save game and back to menu return 1;
		}
		else if (m == 27)
		{
			system("cls");
			cout << "Do You Want To Exit Game?(Y)?";
			int n = _getch();
			if (n == 'y' || n == 'Y')
			{
				isDead = true;
				return 0;
			}
			//Back to Menu
		}		
		color(240);
		player->display();
	}
	return 0;
}
int game::pauseGame()
{
	system("cls");
	cout << "<<<< Pause Game >>>>" << endl;
	cout << "Press 1: Save And Quit" << endl;
	cout << "Press 2: Back To Game" << endl;
	int m = _getch();
	if (m == 76 || m == 108)//save 
	{
		system("cls");
		SaveGame();
		system("cls");
	}
	else return 1;
	cout << "Do you want continue?(Y or N)";
	int n = _getch();
	system("cls");
	if (n == 89 || n == 121)
		return 2;
	else return 1;
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
	for (int i = 0; i < vehi.size(); ++i)
	{
		vehi[i]->getCor(xv, yv);
		if (vehi[i]->Objtype() == 1 || vehi[i]->Objtype() == 2)
		{
			if (((xu <= xv + 8 && xu >= xv) || (xv <= xu + 5 && xv >= xu)) && yv == yu)
				return false;
		}
		else if (vehi[i]->Objtype() == 3)
		{
			if (((xu <= xv + 19 && xu >= xv) || (xv <= xu + 5 && xv >= xu)) && yv == yu - 1)
				return false;
		}
		else if(vehi[i]->Objtype()==4)
		{
			if (((xu <= xv + 6 && xu >= xv) || (xv <= xu + 5 && xv >= xu)) && yu - 1 == yv)
				return false;
		}
	}
	return true;
}
void game::SaveGame() {
	system("cls");
	//cin.ignore(1000, '\n');
	string path;
	color(7);
	cout << "Input the destination path:"; getline(cin, path);
	string file_name;
	cout << "Enter File Name: "; getline(cin, file_name);
	path = path + "\\" + file_name + ".txt";
	ofstream fout;
	fout.open(path.c_str(), ios::trunc);
	fout << round << endl;//Save Round to file
	for (int i = 0; i < 4; i++) { //4 lines
		vector <pair<int, int>>ObjinLine;
		for (int j = 0; j < vehi.size(); j++) {
			int Xo, line;
			vehi[j]->getCor(Xo, line);
			if (line == i + 1) {
				pair<int, int>ObjInfo(Xo, vehi[j]->Objtype());
				ObjinLine.push_back(ObjInfo);
			}
		}
		fout << i + 1 << endl;//Save Line to file
		fout << ObjinLine.size() << endl;//Save amount of objs in one line to file
		for (int k = 0; k < ObjinLine.size(); k++) {
			fout << ObjinLine[k].first << " " << ObjinLine[k].second << endl;
		}
	}
	fout.close();
	cout << "Save file successfully" << endl;
	Sleep(1000);
	system("cls");
}
bool game::loadGame() {
	color(7);
	system("cls");
	if (vehi.size() != 0)
		vehi.clear();
	string path;
	cout << "Press E: Back To Menu" << endl;
	cout << "Please Enter Load File Path: ";
	int n = _getch();
	if (n == 'E' || n == 'e')
	{
		return false;
	}
	getline(cin, path);
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "File is not existed";
		Sleep(700);
		return false;
	}
	int line, amount;
	fin >> round;
	for (int i = 0; i < 4; i++) {//4 lines
		fin >> line >> amount;
		for (int j = 0; j < amount; j++) {
			int xC, type;
			fin >> xC >> type;
			vehicle* tmp;
			if (type == 1) {//car
				tmp = new car(xC, line);
			}
			else if (type == 2) {//truck
				tmp = new truck(xC, line);
			}
			else if (type == 3) {//bird
				tmp = new bird(xC, line);
			}
			else {//dinosaur
				tmp = new dino(xC, line);
			}
			vehi.push_back(tmp);
		}
	}
	delete player;
	player = new user;
	return true;
}