#ifndef _C_Dino_h
#define _C_Dino_h

#include "C_Vehicle.h"

class dino :public vehicle {
public:
	~dino();
	dino(int x, int y);
	void display();
	void move(int step);
	int lastPoint();

};

#endif // !_C_Dino_h
