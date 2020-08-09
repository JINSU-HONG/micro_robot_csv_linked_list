#include "linked_list.h"

using namespace std;

void log_data_gen();

SAVE_LOG_STRUCT x;
bool y;
float t;
int r;



int main()
{
	save_log log;

	log.init.save_name_LQ = "log/current_result1.csv";
	log.init.save_name_CQ = "log/current_result2.csv";
	log.init.load_setting = "log/log_setting.csv";
	
	log.begin(sizeof(x),100,10);



	for (int a = 0; a < 1000; a++) {

		log_data_gen();
		log.logginigInRam((char*)&x);
	}

	// data logging
	log.DataOut();



	while (1);

	return 0;
}

void log_data_gen() {
	static int a = 0;
	static float j = 0.5;
	static float k = 4.7;
	
	k += 0.1;

	a++;


	x.sysLog.state = a % 4;
	x.sysLog.clock = a;
	x.sysLog.mb1_connected = 1;
	x.sysLog.mb2_connected = 0;
	x.sysLog.mb3_connected = 1;
	x.sysLog.mb4_connected = 1;
	x.sysLog.GUI_connected = 0;


	x.guiData_c2s.READY = 1;
	x.guiData_c2s.FAULT = 1;
	x.guiData_c2s.B_act = j;

	x.guiData_s2c.RUN = 1;
	x.guiData_s2c.FAULT_RESET = 0;
	x.guiData_s2c.pos_x = 3.4;
	x.guiData_s2c.pos_y = k;
	x.guiData_s2c.pos_z = k;
	x.guiData_s2c.Bref_x =j;
	x.guiData_s2c.Bref_y = k;
	x.guiData_s2c.Bref_z = j;
	x.guiData_s2c.B_mag = j;


	x.mbData1.c_bits.c_bits_spec.run_A = 1;
	x.mbData1.c_bits.c_bits_spec.stop_A = 1;
	x.mbData1.c_bits.c_bits_spec.run_B = 0;
	x.mbData1.c_bits.c_bits_spec.stop_B = 1;
	x.mbData1.c_bits.c_bits_spec.fault_reset = 1;
	x.mbData1.c_bits.c_bits_spec.coil_overheat = 1;

	x.mbData1.d_inputs.d_inputs_spec.sys_ready = 0;
	x.mbData1.d_inputs.d_inputs_spec.sys_fault = 1;
	x.mbData1.d_inputs.d_inputs_spec.sys_A_run = 1;
	x.mbData1.d_inputs.d_inputs_spec.sys_B_run = 1;
	x.mbData1.d_inputs.d_inputs_spec.commun = 0;
	x.mbData1.d_inputs.d_inputs_spec.precharge_Main = 1;
	x.mbData1.d_inputs.d_inputs_spec.precharge_Aux = 1;

	x.mbData1.d_inputs.d_inputs_spec.emerg_sw_on = 1;
	x.mbData1.d_inputs.d_inputs_spec.overheat = 0;
	x.mbData1.d_inputs.d_inputs_spec.A_fault = 1;
	x.mbData1.d_inputs.d_inputs_spec.B_fault = 1;
	x.mbData1.d_inputs.d_inputs_spec.DCL_undervoltage = 1;
	x.mbData1.d_inputs.d_inputs_spec.DCL_overvoltage = 0;
	x.mbData1.d_inputs.d_inputs_spec.A_overcurrent = 1;
	x.mbData1.d_inputs.d_inputs_spec.B_overcurrent = 1;
	x.mbData1.d_inputs.d_inputs_spec.coil_overheat = 1;

	x.mbData1.i_regs.i_regs_spec.current_A.f = j;
	x.mbData1.i_regs.i_regs_spec.current_B.f = k;
	x.mbData1.i_regs.i_regs_spec.temperature.f = j;

	x.mbData1.h_regs.h_regs_spec.current_A_ref.f = k;
	x.mbData1.h_regs.h_regs_spec.current_B_ref.f = j;



	x.mbData2.c_bits.c_bits_spec.run_A = 0;
	x.mbData2.c_bits.c_bits_spec.stop_A = 1;
	x.mbData2.c_bits.c_bits_spec.run_B = 1;
	x.mbData2.c_bits.c_bits_spec.stop_B = 0;
	x.mbData2.c_bits.c_bits_spec.fault_reset = 0;
	x.mbData2.c_bits.c_bits_spec.coil_overheat = 1;

	x.mbData2.d_inputs.d_inputs_spec.sys_ready = 1;
	x.mbData2.d_inputs.d_inputs_spec.sys_fault = 0;
	x.mbData2.d_inputs.d_inputs_spec.sys_A_run = 0;
	x.mbData2.d_inputs.d_inputs_spec.sys_B_run = 1;
	x.mbData2.d_inputs.d_inputs_spec.commun = 1;
	x.mbData2.d_inputs.d_inputs_spec.precharge_Main = 0;
	x.mbData2.d_inputs.d_inputs_spec.precharge_Aux = 0;

	x.mbData2.d_inputs.d_inputs_spec.emerg_sw_on = 1;
	x.mbData2.d_inputs.d_inputs_spec.overheat = 1;
	x.mbData2.d_inputs.d_inputs_spec.A_fault = 0;
	x.mbData2.d_inputs.d_inputs_spec.B_fault = 0;
	x.mbData2.d_inputs.d_inputs_spec.DCL_undervoltage = 1;
	x.mbData2.d_inputs.d_inputs_spec.DCL_overvoltage = 1;
	x.mbData2.d_inputs.d_inputs_spec.A_overcurrent = 0;
	x.mbData2.d_inputs.d_inputs_spec.B_overcurrent = 0;
	x.mbData2.d_inputs.d_inputs_spec.coil_overheat = 1;

	x.mbData2.i_regs.i_regs_spec.current_A.f = j;
	x.mbData2.i_regs.i_regs_spec.current_B.f = k;
	x.mbData2.i_regs.i_regs_spec.temperature.f = k;

	x.mbData2.h_regs.h_regs_spec.current_A_ref.f = j;
	x.mbData2.h_regs.h_regs_spec.current_B_ref.f = k;



	x.mbData3.c_bits.c_bits_spec.run_A = 1;
	x.mbData3.c_bits.c_bits_spec.stop_A = 1;
	x.mbData3.c_bits.c_bits_spec.run_B = 0;
	x.mbData3.c_bits.c_bits_spec.stop_B = 0;
	x.mbData3.c_bits.c_bits_spec.fault_reset = 1;
	x.mbData3.c_bits.c_bits_spec.coil_overheat = 1;

	x.mbData3.d_inputs.d_inputs_spec.sys_ready = 0;
	x.mbData3.d_inputs.d_inputs_spec.sys_fault = 0;
	x.mbData3.d_inputs.d_inputs_spec.sys_A_run = 1;
	x.mbData3.d_inputs.d_inputs_spec.sys_B_run = 1;
	x.mbData3.d_inputs.d_inputs_spec.commun = 0;
	x.mbData3.d_inputs.d_inputs_spec.precharge_Main = 0;
	x.mbData3.d_inputs.d_inputs_spec.precharge_Aux = 1;

	x.mbData3.d_inputs.d_inputs_spec.emerg_sw_on = 1;
	x.mbData3.d_inputs.d_inputs_spec.overheat = 0;
	x.mbData3.d_inputs.d_inputs_spec.A_fault = 0;
	x.mbData3.d_inputs.d_inputs_spec.B_fault = 1;
	x.mbData3.d_inputs.d_inputs_spec.DCL_undervoltage = 1;
	x.mbData3.d_inputs.d_inputs_spec.DCL_overvoltage = 0;
	x.mbData3.d_inputs.d_inputs_spec.A_overcurrent = 0;
	x.mbData3.d_inputs.d_inputs_spec.B_overcurrent = 1;
	x.mbData3.d_inputs.d_inputs_spec.coil_overheat = 1;

	x.mbData3.i_regs.i_regs_spec.current_A.f = k;
	x.mbData3.i_regs.i_regs_spec.current_B.f = k;
	x.mbData3.i_regs.i_regs_spec.temperature.f = j;

	x.mbData3.h_regs.h_regs_spec.current_A_ref.f = j;
	x.mbData3.h_regs.h_regs_spec.current_B_ref.f = k;


	x.mbData4.c_bits.c_bits_spec.run_A = 0;
	x.mbData4.c_bits.c_bits_spec.stop_A = 1;
	x.mbData4.c_bits.c_bits_spec.run_B = 0;
	x.mbData4.c_bits.c_bits_spec.stop_B = 1;
	x.mbData4.c_bits.c_bits_spec.fault_reset = 0;
	x.mbData4.c_bits.c_bits_spec.coil_overheat = 1;

	x.mbData4.d_inputs.d_inputs_spec.sys_ready = 0;
	x.mbData4.d_inputs.d_inputs_spec.sys_fault = 1;
	x.mbData4.d_inputs.d_inputs_spec.sys_A_run = 0;
	x.mbData4.d_inputs.d_inputs_spec.sys_B_run = 1;
	x.mbData4.d_inputs.d_inputs_spec.commun = 0;
	x.mbData4.d_inputs.d_inputs_spec.precharge_Main = 1;
	x.mbData4.d_inputs.d_inputs_spec.precharge_Aux = 0;

	x.mbData4.d_inputs.d_inputs_spec.emerg_sw_on = 1;
	x.mbData4.d_inputs.d_inputs_spec.overheat = 0;
	x.mbData4.d_inputs.d_inputs_spec.A_fault = 1;
	x.mbData4.d_inputs.d_inputs_spec.B_fault = 0;
	x.mbData4.d_inputs.d_inputs_spec.DCL_undervoltage = 1;
	x.mbData4.d_inputs.d_inputs_spec.DCL_overvoltage = 0;
	x.mbData4.d_inputs.d_inputs_spec.A_overcurrent = 1;
	x.mbData4.d_inputs.d_inputs_spec.B_overcurrent = 0;
	x.mbData4.d_inputs.d_inputs_spec.coil_overheat = 1;

	x.mbData4.i_regs.i_regs_spec.current_A.f = j;
	x.mbData4.i_regs.i_regs_spec.current_B.f = j;
	x.mbData4.i_regs.i_regs_spec.temperature.f = k;

	x.mbData4.h_regs.h_regs_spec.current_A_ref.f = k;
	x.mbData4.h_regs.h_regs_spec.current_B_ref.f = k;



}

