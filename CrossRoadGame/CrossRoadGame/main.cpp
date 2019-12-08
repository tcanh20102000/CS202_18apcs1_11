#include "FrontEnd.h"
#include "DisplayBehavior.h"
#include "C_Game.h"
#include <future>
#include <condition_variable>

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}
int main()
{
	fixConsoleWindows();
	ShowConsoleCursor(false);
	CROSS_STREET_SLASH();
	system("cls");
	int choice = Menu();
	while (choice != 3)
	{
		game init;
		if (choice == 0)
		{
			int choice2 = init.movePlayer();
			if (choice2== 0)
				system("cls");
			else if (choice2 == 2)
			{
				system("cls");
				cout << "Congratulation" << endl;
				Sleep(800);
			}
			system("cls");
		}
		else if (choice == 1)
		{
			if (init.loadGame())
			{
				if (init.movePlayer() == 0)
					system("cls");
			}
			else system("cls");
		}
		else if (choice == 2)
			break;
		choice = Menu();
	}
	color(7);
	return 0;
}