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
//	PlaySound(TEXT("believer.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	while (choice != 3)
	{
		game init;
		if (choice == 0)
		{
//			PlaySound(TEXT("gameshow_theme.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			PlaySound(TEXT("believer.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
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
			if (init.loadGame()==true)
			{
				system("cls");
				PlaySound(TEXT("believer.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				if (init.movePlayer() == 0)
					system("cls");
			}
			else 
				system("cls");
		}
		else if (choice == 2)
			break;
		choice = Menu();
	}
	color(7);
	return 0;
}