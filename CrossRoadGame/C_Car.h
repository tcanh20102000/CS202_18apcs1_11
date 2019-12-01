#ifndef _C_Car_h
#define _C_Car_h

#include "C_Vehicle.h"

class car : public vehicle {
public:
	~car();
	car(int x, int y);
	void display();
	void move(int step);
	int lastPoint();
};



#endif // _C_Car_h
