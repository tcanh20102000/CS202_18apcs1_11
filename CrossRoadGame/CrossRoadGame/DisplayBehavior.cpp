#include "DisplayBehavior.h"

void displayBird::display(int x, int line)
{
	//height = 2,width=18
	//bird 1;
	int y = line;
	gotoxy(x, y);
	cout << "   ";
	gotoxy(x + 6,y);
	cout << "   ";
	gotoxy(x + 3, y + 1);
	cout << "   ";
	//bird 2
	gotoxy(x + 9, y + 1);
	cout << "   ";
	gotoxy(x + 15, y + 1);
	cout << "   ";
	gotoxy(x + 12, y + 2);
	cout << "   ";
}
void displayDino::display(int x, int line)
{
	//height 3 line, width 5 - draw from top left angle
	int y = line;
	gotoxy(x + 2, y + 1);
	cout << "   ";
	gotoxy(x + 2, y + 2);
	cout << "  ";
	gotoxy(x, y + 3);
	cout << "    ";
}
void displayDino::displayRev(int x, int line)
{
	cout << "Reverse Direct Dinosaurr!" << endl;
}
void displayCar::display(int x, int line)
{
	//height = 3, width = 9
	int y = line;
	gotoxy(x + 3, y);
	cout << "    ";
	gotoxy(x, y + 1);
	cout << "          ";
	gotoxy(x, y + 2);
	cout << "          ";
}
void displayTruck::display(int x, int line)
{
	//height = 3, width = 9
	int y = line;
	gotoxy(x+4, y);
	cout << "     ";
	gotoxy(x, y+1);
	cout << "         ";
	gotoxy(x, y+2);
	cout << "         ";
}
void displayTruck::displayRev(int x, int line)
{
	cout << "This is Reverse Truck!" << endl;
}
void displayPlayer::display(int x, int line)
{
	color(7);
	int y = line;
	gotoxy(x + 1, y);
	cout << "|_|";
	gotoxy(x, y + 1);
	cout << "/|_|\\";
	gotoxy(x, y + 2);
	cout << " /  \\";
}
void displayPlayer::disAppear(int x, int line)
{
	gotoxy(x + 1, line);
	cout << "    ";
	gotoxy(x, line + 1);
	cout << "     ";
	gotoxy(x, line + 2);
	cout << "     ";
}

void displayLight::display(int x, int line) {
	gotoxy(95, line);
	color(840); //red
	cout << " ";
	color(7);
}
void displayLight::displayRev(int x, int line)
{
	gotoxy(95, line);
	color(940);
	cout << " ";
	color(7);
}




