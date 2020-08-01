#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "data_type.h"

typedef struct saveLogStruct {
	sys_status sysLog;
	c2s_DATA guiData_c2s;
	s2c_DATA guiData_s2c;
	Module_data mbData1;
	Module_data	mbData2;
	Module_data	mbData3;
	Module_data	mbData4;
};

typedef struct tagNode {
	char Data[20];
	saveLogStruct Data_save;
	struct tagNode* NextNode;
}NODE;

typedef struct tagQueue {
	NODE* Front;
	NODE* Rear;
}QUEUE;

void CreateQueue(QUEUE** Queue);

NODE* CreateNode(char Data[]);

void Enqueue(QUEUE* Queue, char Data[]);

NODE* Dequeue(QUEUE* Queue);

void PrintQueue(NODE* PrintNode);

int IsEmpty(QUEUE* Queue);

