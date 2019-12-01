#ifndef _C_Truck_h_
#define _C_Truck_h_

#include "C_Vehicle.h"

class truck : public vehicle {
public:
	truck(int x, int y);
	~truck();
	void display();
	void move(int step);
	int lastPoint();
};



#endif // !_C_Truck_h_
