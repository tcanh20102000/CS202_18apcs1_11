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
	int dist = rand_Range(12, 15);
	int xco = 6 + rand() % 85, y = 4;
	if (round == 4 || round == 3)
	{
		if (xco + 2 * dist > 94)
			xco = 4;
	}
	else if (round == 5)
	{
		if (xco + 3 * dist > 94)
			xco = 4;
	}
	if (vehi.size() != 0)
		vehi.clear();
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
		vehicle* tmpC = new car(xco+2*dist+2, y);
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
		speed = 100;
	}
	else if (round==5){
		speed = 100;
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
void game::move()
{
	int step = 3;
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
		while (!_kbhit())
		{
			move();
			if (!check_Intersec())
			{
				isDead = true;
				GameOver();
				PlaySound(TEXT("gameover.wav"), NULL, SND_FILENAME | SND_ASYNC);
				Sleep(3000);
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
//			PlaySound(TEXT("jump.wav"), NULL, SND_FILENAME | SND_ASYNC);
			if (!check_Intersec())
			{
				PlaySound(TEXT("dead.wav"), NULL, SND_FILENAME | SND_ASYNC);
				Sleep(700);
				GameOver();
				PlaySound(TEXT("gameover.wav"), NULL, SND_FILENAME | SND_ASYNC);
				Sleep(3000);
				isDead = true;
				return -1;
			}
			if (yp < 4)
			{
				++round;
				if (round > 5) {
					PlaySound(TEXT("champion.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
			else {
				PlaySound(TEXT("believer.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);//15/12 modify
				continue;
			}
//			system("cls");
		}
		else if (m == 27)
		{
			PlaySound(TEXT("mus_silence.wav"), NULL, SND_FILENAME | SND_ASYNC);//15/12 modify
			system("cls");
			PauseBoard();
			gotoxy(37, 9); cout << "Do You Want To Exit Game?(Y/N)?";
			color(7);
			int n = _getch();
			//Back to Menu
			while (1)
			{
				if (n == 'y' || n == 'Y')
				{
					isDead = true;
					return 0;
				}
				else if (n == 'n' || n == 'N')
				{
					system("cls");
					PlaySound(TEXT("believer.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);//15/12 modify
					break;
				}
				n = _getch();
			}
		}		
		color(240);
		player->display();
	}
	return 0;
}
int game::pauseGame()
{
	PlaySound(TEXT("mus_silence.wav"), NULL, SND_FILENAME | SND_ASYNC);//15/12 modify
	system("cls");
	PauseBoard();
	gotoxy(37, 9); cout << "<<<< Pause Game >>>>" << endl;
	gotoxy(37, 10); cout << "Press L: Save And Quit" << endl;
	gotoxy(37, 11); cout << "Press Esc: Back" << endl;
	color(7);
	int m = _getch();
	while (1)
	{
		if (m == 'L' || m == 'l')//save 
		{
			system("cls");
			int c = SaveGame();
			if (c == 1)
				return 2;
			else if (c == 2)
				return 1;
		}
		else if (m == 27)
		{
			system("cls");
			return 2;
		}
		m = _getch();
	}
//	return 1;
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
int game::SaveGame() {
	system("cls");
	//cin.ignore(1000, '\n');
	string path;
	PauseBoard();
	//ShowConsoleCursor(false);
	gotoxy(37,9) ; cout << "Press Esc: Back" ;
	gotoxy(37, 10); cout << "Input the destination path:";
	color(7);
	int m =_getch();
	if (m == 27)
	{
		system("cls");
		return 1;
	}
	getline(cin, path);
	string file_name;
	gotoxy(37, 10);  cout << "Enter File Name: "; getline(cin, file_name);
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
	PauseBoard();
	gotoxy(37, 9); cout << "Save file successfully" ;
	gotoxy(37, 10); cout << "Do you want continue?(Y or N)";
	int n = _getch();
//	system("cls");
	while (1)
	{
		if (n == 'Y' || n == 'y')
			return 2;
		else if (n == 'N' || n == 'n')
			return 1;
		n = _getch();
	}
	Sleep(1000);
	system("cls");
	clearBoard();
	return 2;
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