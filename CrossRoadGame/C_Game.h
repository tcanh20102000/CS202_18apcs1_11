#ifndef _C_Game_h_
#define _C_Game_h_

#include "C_Car.h"
#include "C_Truck.h"
#include "C_Bird.h"
#include "C_Dino.h"
#include "C_People.h"
#include <utility>
class game {
public:
	game();
	~game();
	game(int x, int lin, int speed);
	void display();
	void move();
	void movePlayer();
	void SubThread();
private:
	user* player;
	int speed;
	int x, line;
	vector<vehicle*> vehi;
	pair<int, int>danger1, danger2;
	pair<int, int>pos;
	//vector<pair<int, int>>dangerline;
};

#endif // !_C_Game_h_
