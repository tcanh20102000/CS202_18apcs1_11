#include "DisplayBehavior.h"

void displayBird::display(int x, int line)
{
	int y = 5 + (line - 1) * 6;
	for (int j = 1; j < 5; j++) {
		if (x - j > 3) {
			gotoxy(x + 1 - j, y); cout << " ";
			if (x - j > 9) {
				gotoxy(x - j - 6, y); cout << " ";
			}
		}
	}
	for (int j = 3; j < 8; j++) {
		if (x - j > 4) {
			gotoxy(x - j, 1 + y); cout << " ";
		}
	}
}
void displayDino::display(int x, int line)
{
	int y = 4 + (line - 1) * 6;
	if (x > 4) {
		gotoxy(x, y); cout << " ";
		gotoxy(x, y - 1); cout << "   ";
	}
	if (x > 5) {
		gotoxy(x - 1, y); cout << "  ";
		gotoxy(x - 1, y + 1); cout << "  ";
		gotoxy(x - 1, y + 2); cout << "  ";
		gotoxy(x - 1, y + 3); cout << "  ";
	}
	if (x > 6) {
		gotoxy(x - 2, y + 1); cout << "  ";
		gotoxy(x - 2, y + 2); cout << "  ";
	}
	if (x > 7) {
		gotoxy(x - 3, y + 2); cout << "  ";
		gotoxy(x - 3, y + 3); cout << "  ";
	}
	if (x > 8) {
		gotoxy(x - 4, y + 2); cout << "  ";
		gotoxy(x - 4, y + 3); cout << "  ";
	}
}
void displayDino::displayRev(int x, int line)
{
	//cout << "Reverse Direct Dinosaurr!" << endl;
	int y = 4 + (line - 1) * 6;
	if (x > 8) {
		//gotoxy(x - 2, y); cout << " ";
		gotoxy(x - 4, y - 1); cout << "   ";
	}
	if (x > 5) {
		gotoxy(x - 2, y); cout << "  ";
		gotoxy(x - 2, y + 1); cout << "  ";
		gotoxy(x - 2, y + 2); cout << "  ";
		gotoxy(x - 2, y + 3); cout << "  ";
	}
	if (x > 6) {
		gotoxy(x - 1, y + 1); cout << "  ";
		gotoxy(x - 1, y + 2); cout << "  ";
	}
	if (x > 7) {
		gotoxy(x, y + 2); cout << "  ";
		gotoxy(x, y + 3); cout << "  ";
	}
	if (x > 8) {
		gotoxy(x + 1, y + 2); cout << "  ";
		gotoxy(x + 1, y + 3); cout << "  ";
	}
}
void displayCar::display(int x, int line)
{
	int y = 5 + (line - 1) * 6;
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 5; j++) {
			if (x - j > 9) {
				gotoxy(x - j - 2, i + y); cout << " ";
			}
		}
	}
	for (int i = 1; i < 3; i++)
	{
		for (int j = 0; j < 9; j++) {
			if (x - j > 4) {
				gotoxy(x - j, i + y); cout << " ";
			}
		}
	}
}
void displayTruck::display(int x, int line)
{
	int y = 4 + (line - 1) * 6;
	for (int i = 0; i < 1; i++) {

		for (int j = 0; j < 7; j++) {
			if (x - j > 9) {
				gotoxy(x - j, i + y); cout << " ";
			}
		}
	}
	for (int i = 1; i < 4; i++)
	{
		for (int j = 0; j < 9; j++) {
			if (x - j > 4) {
				gotoxy(x - j, i + y); cout << " ";
			}
		}
	}
}
void displayTruck::displayRev(int x, int line)
{
	cout << "This is Reverse Truck!" << endl;
	int y = 4 + (line - 1) * 6;
	for (int i = 0; i < 1; i++) {

		for (int j = 0; j < 7; j++) {
			if (x - j > 9) {
				gotoxy(x - 8 + j, i + y); cout << " ";
			}
		}
	}
	for (int i = 1; i < 4; i++)
	{
		for (int j = 0; j < 9; j++) {
			if (x - j > 4) {
				gotoxy(x - 8 + j, i + y); cout << " ";
			}
		}
	}
}

void displayPlayer::display(int x, int line)
{
	color(7);
/*	int y = 5 + (line - 1) * 6;
	gotoxy(x, y);
	int m = y - 4;
	int n1 = 42 - x;
	gotoxy(n1+1, m);
	cout << "   ";
	gotoxy(x, y + 1);
	gotoxy(n1, m + 1);
	cout << "    ";
	gotoxy(x, y + 2);
	gotoxy(n1, m + 2);
	cout << "    ";*/
	int y = 7 + (line - 1) * 6;
	//Legs
	gotoxy(x, y); std::cout << "/";
	gotoxy(x+2, y); std::cout << "\\";
	//Body
	gotoxy(x + 1, y - 1); printf("%c", 124);
	gotoxy(x, y - 1); printf("%c", 196);
	gotoxy(x + 2, y-1); printf("%c", 196);
	//head

	gotoxy(x + 1, y - 2); printf("%c", 220);
}






