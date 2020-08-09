#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include "data_type.h"

using namespace std;

#define dataTypeInt 1
#define dataTypeFloat 2
#define dataTypeBool 3
#define dataTypeDummy 4

#define MAXDATANUM 1000


/*test frame*/
typedef struct testLog {
	int i1;
	int i2;
	float f1;
	bool b1;
	bool b2;
	int i3;
	float f2;
}TESTLOG;
/*end of test frame*/

typedef struct saveLogStruct {
	sys_status sysLog;
	c2s_DATA guiData_c2s;
	s2c_DATA guiData_s2c;
	Module_data mbData1;
	Module_data	mbData2;
	Module_data	mbData3;
	Module_data	mbData4;
}SAVE_LOG_STRUCT;

typedef struct tagNode {
	char* dataAdd;
	struct tagNode* NextNode;
}NODE;

typedef struct tagQueue {
	NODE* Front;
	NODE* Rear;
}QUEUE;

typedef struct data_log_init {
	string load_setting;
	string save_name_LQ;
	string save_name_CQ;
}DATA_LOG_INIT;


class save_log {

public:
	//save_log();
	//~save_log();

	DATA_LOG_INIT init;
	

	void begin(int initDataSize, int initCQsize, int initLQterm);
	void logginigInRam(char Data[]);
	void DataOut();

	

private:
	
	QUEUE* Queue_LQ;
	QUEUE* Queue_CQ;
	FILE* logFile_LQ;
	FILE* logFile_CQ;
	FILE* settingFile;

	void CreateQueue_LQ();
	NODE* CreateNode_LQ(char Data[]);
	void Enqueue_LQ(char Data[]);
	NODE* Dequeue_LQ();
	int IsEmpty_LQ();


	void CreateQueue_CQ();
	NODE* CreateNode_CQ();
	void InitNode_CQ();
	void Enqueue_CQ(char Data[]);
	NODE* Dequeue_CQ();
	int IsEmpty_CQ();
	int CQ_size = 10;
	int LQ_term = 10;

	void PrintQueue(NODE* PRINTNODE, FILE* logFile);

	int data_size;
	int data_num;
	int dummy_num;
	void csvinit();

	int data_type[MAXDATANUM];
	string data_name[MAXDATANUM];
};



