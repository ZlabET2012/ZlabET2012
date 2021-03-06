#include "Motor.h"

Motor::Motor(){
}

Motor::Motor(MOTOR_PORT_T _outputPort)
{
	outputPort = _outputPort;
}

// 回転角度をリセットする
void Motor::resetAngle()
{
	return nxt_motor_set_count(outputPort, 0);
}

// 回転角度を得る
long Motor::getAngle()
{
	return nxt_motor_get_count(outputPort);
}

// 回転させる
void Motor::rotate(float pwm)
{
	nxt_motor_set_speed(outputPort, (int)pwm, 1);
} 
