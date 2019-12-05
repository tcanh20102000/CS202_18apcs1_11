#ifndef _C_Game_h_
#define _C_Game_h_

#include "C_Car.h"
#include "C_Truck.h"
#include "C_Bird.h"
#include "C_Dino.h"
#include "C_People.h"

class game {
public:
	game();
	game(string a);
	~game();
	game(int x, int lin, int speed);
	int pauseLane();
	void display();
	void move();
	int movePlayer();
	int pauseGame();
	void gamePlay();
	bool check_Intersec();
	void SaveGame();
	void nextRound();
private:
	int round;
	user* player;
	int speed;
	int x, line;
	vector<vehicle*> vehi;
//	bool isGreen;
};

#endif // !_C_Game_h_
