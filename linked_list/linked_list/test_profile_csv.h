#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include "data_type.h"

using namespace std;




typedef struct data_load_init {
	string load_setting;
	string load_file_name;
}DATA_LOAD_INIT;


class test_profile_load {

public:
	//save_log();
	//~save_log();

	DATA_LOAD_INIT init;
	

	void begin(int initDataSize);
	void loadInRam(char Data[]);
	int DataLoad(char data[]);

	

private:
	
	QUEUE* Queue_LQ;
	FILE* loadFile;
	FILE* settingFile;

	void CreateQueue_LQ();
	NODE* CreateNode_LQ(char Data[]);
	void Enqueue_LQ(char Data[]);
	NODE* Dequeue_LQ();
	int IsEmpty_LQ();

	int compDataType(string type);




	void PrintQueue(NODE* PRINTNODE, FILE* logFile);

	int data_size;
	int field_num;
	int data_num;
	int dummy_num;
	void csvinit();

	int data_type[MAXDATANUM];
};



