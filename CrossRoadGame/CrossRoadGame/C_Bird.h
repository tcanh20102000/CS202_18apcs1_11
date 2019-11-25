#ifndef _C_Bird_h
#define _C_Bird_h

#include "C_Vehicle.h"

class bird :public vehicle {
public:
	~bird();
	bird(int x, int y);
	void display();
	void move(int step);
	int lastPoint();
};


#endif // !_C_Bird_h
