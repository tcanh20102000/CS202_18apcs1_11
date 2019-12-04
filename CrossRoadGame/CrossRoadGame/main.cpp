#include "FrontEnd.h"
#include "DisplayBehavior.h"
#include "C_Game.h"
#include <future>
#include <condition_variable>

class Stoppable
{
	promise<void> exitSignal;
	future<void> futureObj;
public:
	Stoppable() :
		futureObj(exitSignal.get_future())
	{

	}
	Stoppable(Stoppable&& obj) : exitSignal(std::move(obj.exitSignal)), futureObj(std::move(obj.futureObj))
	{
		std::cout << "Move Constructor is called" << std::endl;
	}
	Stoppable& operator=(Stoppable&& obj)
	{
		std::cout << "Move Assignment is called" << std::endl;
		exitSignal = std::move(obj.exitSignal);
		futureObj = std::move(obj.futureObj);
		return *this;
	}
	virtual void run(game &src) = 0;
/*	void operator()()
	{
		run();
	}*/
	bool stopRequested()
	{
		if (futureObj.wait_for(std::chrono::milliseconds(0)) == std::future_status::timeout)
			return false;
		return true;
	}
	void stop()
	{
		exitSignal.set_value();
	}
};
bool isDead = false;
class MyTask : public Stoppable
{
public:
	mutex x;
	void run(game &src)
	{
		x.lock();
		src.move();
		x.unlock();
	}
};

int main()
{
/*	MyTask task;
	game init;
	task.run(init);
	if (init.movePlayer() == 1)
		isDead = true;
	task.stop();*/
	game init;
	init.movePlayer();
	return 0;
}