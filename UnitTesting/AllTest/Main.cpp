#include "TouchSensor.h"
#include "Motor.h"
#include "Tail.h"
#include "UI.h"
#include "Control.h"

extern "C"{
	#include "kernel.h"
	#include "kernel_id.h"
	#include "ecrobot_interface.h"
};

void ecrobot_device_initialize(){
	// センサ、モータなどの各デバイスの初期化関数を
	// ここで実装することができます
	// ⇒　光センサ赤色LEDをONにする
	ecrobot_set_light_sensor_active(NXT_PORT_S1);
	// ⇒　超音波センサ(I2C通信)を初期化
	ecrobot_init_sonar_sensor(NXT_PORT_S3);
	
	if(ecrobot_get_bt_status() == BT_NO_INIT){
		ecrobot_set_bt_device_name("ET337");
	}
	
	ecrobot_init_bt_slave("unagipai");
}
	
void ecrobot_device_terminate(){
	// センサ、モータなどの各デバイスの終了関数を
	// ここで実装することができます。
	// ⇒　光センサ赤色LEDをOFFにする
	ecrobot_set_light_sensor_inactive(NXT_PORT_S1);
	// ⇒　超音波センサ(I2C通信)を終了
	ecrobot_term_sonar_sensor(NXT_PORT_S3 );
	
	ecrobot_term_bt_connection();
}
	
	// 1msec周期割り込み(ISRカテゴリ2)から起動されるユーザー用フック関数
void user_1ms_isr_type2(void){
	// 今回は何も行わない
}

extern "C" TASK(TaskMain){
	TouchSensor *touchSensor = new TouchSensor(NXT_PORT_S4);
	Motor *rightMotor = new Motor(NXT_PORT_A);
	Tail *tail = new Tail(NXT_PORT_B);
	Motor *leftMotor = new Motor(NXT_PORT_C);
	UI *ui = new UI(*touchSensor, *tail);
	Control *control = new Control(*leftMotor, *rightMotor, *tail);
	int count = 0;

	if(ui->courseSelect() == 1){
		ui->waitStart(100);
		while(1){
			control->run(50, 100);
			/* ロギング */
			ecrobot_bt_data_logger(0, 0);
		
			count++;
		
			if(count >= 2500){
				break;
			}
			systick_wait_ms(4);
		}
	}
	else{
		ui->waitStart(100);
		while(1){
			control->run(-50, 100);
			/* ロギング */
			ecrobot_bt_data_logger(0, 0);
		
			count++;
		
			if(count >= 2500){
				break;
			}
			systick_wait_ms(4);
		}
	}
}
