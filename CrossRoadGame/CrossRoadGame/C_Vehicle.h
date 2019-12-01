#ifndef _C_Vehicle_h_
#define _C_Vehicle_h_

#include "DisplayBehavior.h"

class vehicle {
public:
	vehicle() {};
	virtual void display() = 0;
	virtual void move(int step) = 0;
	virtual int lastPoint() = 0;
	void getCor(int& x, int& y) {
		x = xC;
		y = line;
	}
protected:
	int xC, line;
	displayB* draw;
};


#endif