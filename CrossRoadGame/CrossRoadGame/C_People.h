#ifndef _C_People_h
#define _C_People_h

#include "DisplayBehavior.h"

class user {
public:
	user();
	~user();
	user(int x, int line);
	bool isInter(int x);
	void move(int direct); // 0: up, 1: down, 2: right, 3: left
	void display();
private:
	int xP, yP;
	displayB* draw;
};

#endif