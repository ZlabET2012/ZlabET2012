#include "Motor.h"

Motor::Motor(){
}

Motor::Motor(MOTOR_PORT_T _outputPort)
{
	outputPort = _outputPort;
}

// ‰ñ“]‚³‚¹‚é
void Motor::rotate(float pwm)
{
	nxt_motor_set_speed(outputPort, (int)pwm, 1);
} 
