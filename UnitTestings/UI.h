#ifndef UI_H
#define UI_H

#include "TouchSensor.h"
#include "Tail.h"

extern "C"{
#include "kernel.h"
#include "ecrobot_interface.h"
};

class UI{
private:
	TouchSensor touchSensor;
	Tail tail;	
public:
	UI();
	UI(TouchSensor _touchSensor, Tail _tail);
	void waitStart(float angle);
	int courseSelect();
};

#endif
