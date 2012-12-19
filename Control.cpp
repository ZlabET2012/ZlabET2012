#include "Control.h"

Control::Control(){
}

Control::Control(Motor _leftMotor, Motor _rightMotor, Tail _tail){
	leftMotor = _leftMotor;
	rightMotor = _rightMotor;
	tail = _tail;
}

void Control::run(float forward, float tail_angle){
	// �����ۂ���]������
	tail.control(tail_angle);

	// ���[�^����]������
	leftMotor.rotate(forward);
	rightMotor.rotate(forward);
		
	/* ���M���O */
	ecrobot_bt_data_logger(0, 0);
}
