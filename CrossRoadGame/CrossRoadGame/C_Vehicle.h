#ifndef _C_Vehicle_h_
#define _C_Vehicle_h_

#include "DisplayBehavior.h"

class vehicle {
public:
	vehicle() {
		xC = 18;
		line = 0;
	}
	virtual void display() = 0;
	virtual void move(int step) = 0;
	virtual int lastPoint() = 0;
protected:
	int xC, line;
	displayB* draw;
};


#endif