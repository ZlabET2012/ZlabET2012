#include "Control.h"

Control::Control(){
}

Control::Control(Motor _leftMotor, Motor _rightMotor, Tail _tail){
	leftMotor = _leftMotor;
	rightMotor = _rightMotor;
	tail = _tail;
}

void Control::run(float forward, float tail_angle){
	// ‚µ‚Á‚Û‚ğ‰ñ“]‚³‚¹‚é
	tail.control(tail_angle);

	// ƒ‚[ƒ^‚ğ‰ñ“]‚³‚¹‚é
	leftMotor.rotate(forward);
	rightMotor.rotate(forward);
		
	/* ƒƒMƒ“ƒO */
	ecrobot_bt_data_logger(0, 0);
}
