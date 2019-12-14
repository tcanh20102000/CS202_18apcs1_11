#include "FrontEnd.h"
void gotoxy(int x, int y) {
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}
void fixConsoleWindows() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void color(int x)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, x);
}

void CROSS_STREET_SLASH() {
	color(240);
	int delay = 400;
	//Line 2
	gotoxy(3, 2); cout << "           ";
	gotoxy(3, 2); cout << "    ";
	gotoxy(64, 2); cout << "           ";
	Sleep(delay);
	//Line 3
	gotoxy(3, 3); cout << "    ";
	gotoxy(64, 3); cout << "   ";
	gotoxy(79, 3); cout << "   ";
	gotoxy(116, 3); cout << "   ";
	Sleep(delay);
	//Line 4
	gotoxy(3, 4); cout << "    ";
	gotoxy(16, 4); cout << "        ";
	gotoxy(15, 4); cout << "   ";
	gotoxy(25, 4); cout << "         ";
	gotoxy(33, 4); cout << "   ";
	gotoxy(37, 4); cout << "        ";
	gotoxy(46, 4); cout << "        ";
	gotoxy(64, 4); cout << "   ";
	gotoxy(76, 4); cout << "         ";
	gotoxy(79, 4); cout << "   ";
	gotoxy(86, 4); cout << "        ";
	gotoxy(95, 4); cout << "        ";
	gotoxy(104, 4); cout << "        ";
	gotoxy(113, 4); cout << "         ";
	gotoxy(116, 4); cout << "   ";
	Sleep(delay);
	//Line 5
	gotoxy(3, 5); cout << "    ";
	gotoxy(15, 5); cout << "   ";
	gotoxy(25, 5); cout << "   ";
	gotoxy(33, 5); cout << "   ";
	gotoxy(37, 5); cout << "   ";
	gotoxy(46, 5); cout << "   ";
	gotoxy(64, 5); cout << "           ";
	gotoxy(79, 5); cout << "   ";
	gotoxy(86, 5); cout << "   ";
	gotoxy(95, 5); cout << "   ";
	gotoxy(104, 5); cout << "   ";
	gotoxy(116, 5); cout << "   ";
	Sleep(delay);
	//Line 6
	gotoxy(3, 6); cout << "    ";
	gotoxy(15, 6); cout << "   ";
	gotoxy(25, 6); cout << "   ";
	gotoxy(33, 6); cout << "   ";
	gotoxy(37, 6); cout << "        ";
	gotoxy(46, 6); cout << "        ";
	gotoxy(72, 6); cout << "   ";
	gotoxy(79, 6); cout << "   ";
	gotoxy(86, 6); cout << "   ";
	gotoxy(95, 6); cout << "        ";
	gotoxy(104, 6); cout << "        ";
	gotoxy(116, 6); cout << "   ";
	Sleep(delay);
	//Line 7
	gotoxy(3, 7); cout << "    ";
	gotoxy(15, 7); cout << "   ";
	gotoxy(25, 7); cout << "   ";
	gotoxy(33, 7); cout << "   ";
	gotoxy(42, 7); cout << "   ";
	gotoxy(51, 7); cout << "   ";
	gotoxy(72, 7); cout << "   ";
	gotoxy(79, 7); cout << "   ";
	gotoxy(86, 7); cout << "   ";
	gotoxy(95, 7); cout << "   ";
	gotoxy(104, 7); cout << "   ";
	gotoxy(116, 7); cout << "   ";
	Sleep(delay);
	//Line 8
	gotoxy(3, 8); cout << "           ";
	gotoxy(16, 8); cout << "  ";
	gotoxy(15, 8); cout << "   ";
	gotoxy(25, 8); cout << "         ";
	gotoxy(33, 8); cout << "   ";
	gotoxy(37, 8); cout << "        ";
	gotoxy(46, 8); cout << "        ";
	gotoxy(64, 8); cout << "           ";
	gotoxy(79, 8); cout << "   ";
	gotoxy(86, 8); cout << "   ";
	gotoxy(95, 8); cout << "        ";
	gotoxy(104, 8); cout << "        ";
	gotoxy(116, 8); cout << "   ";
}
void CROSS_STREET() {
	gotoxy(3, 2);
	color(240);//Set the color of the title 
	//C
	cout << "           ";
	gotoxy(3, 8);
	cout << "           ";
	for (int i = 0; i < 6; i++) {
		gotoxy(3, 2 + i);
		cout << "    ";
	}
	//R
	gotoxy(16, 4);
	cout << "        ";
	gotoxy(16, 8);
	cout << "  ";
	for (int i = 0; i < 5; i++) {
		gotoxy(15, 4 + i);
		cout << "   ";
	}
	//O
	gotoxy(25, 4); cout << "         ";
	gotoxy(25, 8); cout << "         ";
	for (int i = 0; i < 5; i++) {
		gotoxy(25, 4 + i);
		cout << "   ";
		gotoxy(33, 4 + i);
		cout << "   ";
	}
	//S
	gotoxy(37, 4); cout << "        ";
	gotoxy(37, 5); cout << "   ";
	gotoxy(37, 6); cout << "        ";
	gotoxy(42, 7); cout << "   ";
	gotoxy(37, 8); cout << "        ";
	//S
	gotoxy(46, 4); cout << "        ";
	gotoxy(46, 5); cout << "   ";
	gotoxy(46, 6); cout << "        ";
	gotoxy(51, 7); cout << "   ";
	gotoxy(46, 8); cout << "        ";

	//STREET
	//S
	gotoxy(64, 2); cout << "           ";
	gotoxy(64, 3); cout << "   ";
	gotoxy(64, 4); cout << "   ";
	gotoxy(64, 5); cout << "           ";
	gotoxy(72, 6); cout << "   ";
	gotoxy(72, 7); cout << "   ";
	gotoxy(64, 8); cout << "           ";
	//T
	gotoxy(76, 4); cout << "         ";
	for (int i = 0; i < 6; i++) {
		gotoxy(79, 3 + i); cout << "   ";
	}
	//R
	gotoxy(86, 4);
	cout << "        ";
	for (int i = 0; i < 5; i++) {
		gotoxy(86, 4 + i);
		cout << "   ";
	}
	//E
	gotoxy(95, 4);
	cout << "        ";
	gotoxy(95, 6);
	cout << "        ";
	gotoxy(95, 8);
	cout << "        ";
	for (int i = 0; i < 5; i++) {
		gotoxy(95, 4 + i);
		cout << "   ";
	}
	//E
	gotoxy(104, 4);
	cout << "        ";
	gotoxy(104, 6);
	cout << "        ";
	gotoxy(104, 8);
	cout << "        ";
	for (int i = 0; i < 5; i++) {
		gotoxy(104, 4 + i);
		cout << "   ";
	}
	//T
	gotoxy(113, 4); cout << "         ";
	for (int i = 0; i < 6; i++) {
		gotoxy(116, 3 + i); cout << "   ";
	}
}
int Menu() {
	int choosen = 14;//Highlight choosen path
	int nor = 11;
	vector<string>Menu;
	Menu.push_back("New game"); Menu.push_back("Load game"); Menu.push_back("Settings");
	color(choosen); gotoxy(50, 4); cout << Menu[0];
	color(nor); gotoxy(50, 6); cout << Menu[1];
	gotoxy(50, 8); cout << Menu[2];
	while (1) {
		if (_kbhit())
		{
			int pointpos = 4;
			gotoxy(50, pointpos);
			char ch = _getch();
			while (ch != 13) {
				//Choose a feature and highlight it
				if (ch == 119 && pointpos != 4)
				{
					gotoxy(50, pointpos); color(nor);
					cout << Menu[(pointpos - 4) / 2];
					pointpos -= 2;
					gotoxy(50, pointpos);
					color(choosen); cout << Menu[(pointpos - 4) / 2];
				}
				else if (ch == 115 && pointpos != 8) {
					gotoxy(50, pointpos); color(nor);
					cout << Menu[(pointpos - 4) / 2];
					pointpos += 2;
					gotoxy(50, pointpos);
					color(choosen); cout << Menu[(pointpos - 4) / 2];
				}
				ch = _getch();
			}
			if (ch == 13) {
				if (pointpos == 4)
					return 0;//New game
				if (pointpos == 6)
					return 1;//Load game
				if (pointpos == 8)
					return 2;//Setting
			}
		}
	}
}
void showLogoandMenu() {
	CROSS_STREET_SLASH();
	color(11);
	gotoxy(48, 10); cout << "Press Enter to continue";
	while (1) {
		if (_kbhit())
		{
			char ch = _getch();
			if (ch == 13) {
				system("cls");
				Menu();
				system("cls");
				color(11);
				cout << "Goodbye" << endl;
				return;
			}
		}
	}
}
void Line() {
	int y = 2;
	color(9);
	gotoxy(4, y); printf("%c", 218);
	//print Line
	for (int x = 5; x < 94; x++) {
		gotoxy(x, y); printf("%c", 196);
	}
	gotoxy(94, y); printf("%c", 191);
	color(7);
	for (int i = 0; i < 4; i++) {
		y += 5;
		for (int x = 4; x < 94; x++) {
			gotoxy(x, y); printf("%c", 196);
		}
	}
	color(9);
	y += 5;
	gotoxy(4, y); printf("%c", 192);
	for (int x = 5; x < 94; x++) {
		gotoxy(x, y); printf("%c", 196);
	}
	gotoxy(94, y); printf("%c", 217);
	//
	y = 2;
	color(9);
	//	printvertical(4, y);
	//	printvertical(94, y);
		//Instruction
	color(11);
	gotoxy(96, y); cout << "Press L to save game";
	gotoxy(96, y + 5); cout << "Press T to load save game";
	gotoxy(96, y + 10); cout << "Press W,A,S,D to move the char";
}