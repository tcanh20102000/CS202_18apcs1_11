#ifndef _DisplayBehavior_h
#define _DisplayBehavior_h

#include "FrontEnd.h"

class displayB {
public:
	virtual void display(int x, int line) = 0;
	virtual void displayRev(int x, int line) {};
};
class displayBird : public displayB {
public:
	void display(int x, int line);
};
class displayDino : public displayB {
public:
	void display(int x, int line);
	void displayRev(int x, int line);
}; 
class displayCar : public displayB {
public:
	void display(int x, int line);
};
class displayTruck : public displayB {
public:
	void display(int x, int line);
	void displayRev(int x, int line);
};
class displayPlayer : public displayB {
public:
	void display(int x, int line);
};
#endif // !_DisplayBehavior_h
