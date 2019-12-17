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
	~game();
	game(int x, int lin, int speed);
	int rand_Range(int min, int max);
	void display();
	void move();
//	int move(bool isD, int lin, int& wait);
	int movePlayer();
	int pauseGame();
	void gamePlay();
//	bool check_Intersec();
	bool check_Intersec(bool& isDead);
	void nextRound();
	int SaveGame();
	bool loadGame();
private:
	int round;
	user* player;
	int speed;
	int x, line;
	vector<vehicle*> vehi;
	displayB* light, *light2;
};

#endif // !_C_Game_h_
