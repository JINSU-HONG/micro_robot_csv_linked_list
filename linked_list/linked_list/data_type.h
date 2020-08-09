#pragma once
#include <stdint.h>

/////////////QIT MODE_bus protocol

#define SYS_IDLE  0
#define SYS_CONNECTED  1
#define SYS_READY  2
#define SYS_RUN  3
#define SYS_STOP  4
#define SYS_END  5

#define NUM_COIL_BITS  6
#define NUM_DISCRETE_INPUTS  16
#define NUM_INPUT_REGS  6
#define TYPES_INPUT_REGS  3
#define NUM_HOLD_REGS  4
#define TYPES_HOLD_REGS  2
#define NUM_SERVERS  1

#define PROCESS_INTERVAL  50
#define MODULE_COMMUN_INTERVAL  500


#define dataTypeInt 1
#define dataTypeFloat 2
#define dataTypeBool 3
#define dataTypeDummy 4

#define MAXDATANUM 1000
#define MAXLOADDATANUM 50000

union float2int {
	uint16_t int_16[2];
	float f;
};

union coil_bits {
	bool c_bits_gen[NUM_COIL_BITS];
	struct {
		bool run_A;
		bool stop_A;
		bool run_B;
		bool stop_B;
		bool fault_reset;
		bool coil_overheat;
	}c_bits_spec;
};
union discrete_inputs {
	bool d_inputs_gen[NUM_DISCRETE_INPUTS];
	struct {
		// status
		bool sys_ready;
		bool sys_fault;
		bool sys_A_run;
		bool sys_B_run;
		bool commun;
		bool precharge_Main;
		bool precharge_Aux;
		// fault
		bool emerg_sw_on;
		bool overheat;
		bool A_fault;
		bool B_fault;
		bool DCL_undervoltage;
		bool DCL_overvoltage;
		bool A_overcurrent;
		bool B_overcurrent;
		bool coil_overheat;

	}d_inputs_spec;
};

union input_regs {
	float2int i_regs_gen[TYPES_INPUT_REGS];
	struct {
		float2int current_A;
		float2int current_B;
		float2int temperature;
	}i_regs_spec;
};

union holding_regs {
	float2int h_regs_gen[TYPES_HOLD_REGS];
	struct {
		float2int current_A_ref;
		float2int current_B_ref;
	}h_regs_spec;
};

struct Module_data {
	coil_bits c_bits;
	discrete_inputs d_inputs;
	input_regs i_regs;
	holding_regs h_regs;
};

///////////// END OF QIT MODE_bus protocol


///////////// GUI UDP_bus protocol

//to gui
struct c2s_DATA {
	bool READY;
	bool FAULT;
	float B_act;
};

//from gui
struct s2c_DATA {
	bool RUN;
	bool FAULT_RESET;
	float pos_x;
	float pos_y;
	float pos_z;
	float Bref_x;
	float Bref_y;
	float Bref_z;
	float B_mag;
};


///////////// END OF GUI UDP_bus protocol

///////////// SYSTEM STAUTS
struct sys_status {
	int state;
	int clock;
	bool mb1_connected;
	bool mb2_connected;
	bool mb3_connected;
	bool mb4_connected;
	bool GUI_connected;
};

///////////// END OF SYSTEM STAUTS

typedef struct tagNode {
	char* dataAdd;
	struct tagNode* NextNode;
}NODE;

typedef struct tagQueue {
	NODE* Front;
	NODE* Rear;
}QUEUE;