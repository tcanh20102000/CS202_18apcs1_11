#pragma once
#ifndef FRONTEND_H_INCLUDED
#define FRONTEND_H_INCLUDED
#include <iostream>
#include <cwchar>
#include <windows.h>
#include <conio.h>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <Windows.h>
#include <thread>
#include <mutex>
#pragma comment(lib, "winmm.lib")

using namespace std;
void gotoxy(int x, int y);
void color(int x);
void Line();
void showLogoandMenu();
int Menu();
void fixConsoleWindows();
void CROSS_STREET_SLASH();
void CROSS_STREET();
#endif // FRONTEND_H_INCLUDED
