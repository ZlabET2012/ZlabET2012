#include "TouchSensor.h"
#include "Tail.h"
#include "UI.h"

extern "C"{
	#include "kernel.h"
	#include "kernel_id.h"
	#include "ecrobot_interface.h"
};

void ecrobot_device_initialize(){
	// �Z���T�A���[�^�Ȃǂ̊e�f�o�C�X�̏������֐���
	// �����Ŏ������邱�Ƃ��ł��܂�
	// �ˁ@���Z���T�ԐFLED��ON�ɂ���
	ecrobot_set_light_sensor_active(NXT_PORT_S1);
	// �ˁ@�����g�Z���T(I2C�ʐM)��������
	ecrobot_init_sonar_sensor(NXT_PORT_S3);
	
	if(ecrobot_get_bt_status() == BT_NO_INIT){
		ecrobot_set_bt_device_name("ET337");
	}
	
	ecrobot_init_bt_slave("unagipai");
}
	
void ecrobot_device_terminate(){
	// �Z���T�A���[�^�Ȃǂ̊e�f�o�C�X�̏I���֐���
	// �����Ŏ������邱�Ƃ��ł��܂��B
	// �ˁ@���Z���T�ԐFLED��OFF�ɂ���
	ecrobot_set_light_sensor_inactive(NXT_PORT_S1);
	// �ˁ@�����g�Z���T(I2C�ʐM)���I��
	ecrobot_term_sonar_sensor(NXT_PORT_S3 );
	
	ecrobot_term_bt_connection();
}
	
	// 1msec�������荞��(ISR�J�e�S��2)����N������郆�[�U�[�p�t�b�N�֐�
void user_1ms_isr_type2(void){
	// ����͉����s��Ȃ�
}

extern "C" TASK(TaskMain){
	TouchSensor *touchSensor = new TouchSensor(NXT_PORT_S4);
	Tail *tail = new Tail(NXT_PORT_B);
	UI *ui = new UI(*touchSensor, *tail);
	int count = 0;	

	if(ui->courseSelect() == 1){
		ui->waitStart(100);
	}
	else{
		ui->waitStart(50);
	}
}
