#ifndef CONTROL_H
#define CONTROL_H

#include "Motor.h"
#include "Tail.h"

extern "C"{
	#include "kernel.h"
};

class Control{
private:
	Motor leftMotor;
	Motor rightMotor;
	Tail tail;
public:
	Control();
	Control(Motor _leftMotor, Motor _rightMotor, Tail _tail);
	void run(float forward, float tail_angle);
};

#endif
