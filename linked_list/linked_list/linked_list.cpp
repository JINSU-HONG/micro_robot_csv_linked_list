#include "linked_list.h"

using namespace std;


void save_log::begin(int initDataSize, int initCQsize, int initLQterm) {
	data_size = initDataSize;
	CQ_size = initCQsize;
	LQ_term =initLQterm;
	CreateQueue_LQ();
	CreateQueue_CQ();
	InitNode_CQ();
	csvinit();
	
}

void save_log::CreateQueue_LQ()
{
	Queue_LQ = (QUEUE*)malloc(sizeof(QUEUE));

	Queue_LQ->Front = NULL;
	Queue_LQ->Rear = NULL;
}


NODE* save_log::CreateNode_LQ(char* Data)
{
	NODE* NewNode = (NODE*)malloc(sizeof(NODE));
	char* NewData = (char*)malloc(data_size);
	NewNode->dataAdd = NewData;

	memcpy(NewNode->dataAdd, Data, data_size);
	NewNode->NextNode = NULL;

	return NewNode;
}


void save_log::Enqueue_LQ(char* Data)
{
	if (Queue_LQ->Front == NULL)
	{
		Queue_LQ->Front = CreateNode_LQ(Data);
		Queue_LQ->Rear = Queue_LQ->Front;
	}
	else
	{
		Queue_LQ->Rear->NextNode = CreateNode_LQ(Data);
		Queue_LQ->Rear = Queue_LQ->Rear->NextNode;
	}
}


NODE* save_log::Dequeue_LQ()
{
	NODE* FrontNode = Queue_LQ->Front;

	if (Queue_LQ->Front->NextNode == NULL)
	{
		Queue_LQ->Front = NULL;
		Queue_LQ->Rear = NULL;
	}
	else
	{
		Queue_LQ->Front = Queue_LQ->Front->NextNode;
	}

	return FrontNode;
}


int save_log::IsEmpty_LQ()
{
	return (Queue_LQ->Front == NULL);
}


void save_log::csvinit()
{
	int a = 0;
	char field[100];
	char field1[50];
	char field2[50];
	char* sep;
	string typeInt = "int";
	string typeFloat = "float";
	string typeBool = "bool";
	string typeDummy = "dummy";
	string type;

	logFile_LQ = fopen(init.save_name_LQ.c_str(), "w+");
	if (logFile_LQ == NULL) printf("Error opening %s file.", init.save_name_LQ.c_str());

	logFile_CQ = fopen(init.save_name_CQ.c_str(), "w+");
	if (logFile_CQ == NULL) printf("Error opening %s file.", init.save_name_CQ.c_str());
	


	settingFile = fopen(init.load_setting.c_str(), "r");
	if (settingFile == NULL) printf("Error opening %s file.", init.load_setting.c_str());

	for (int i = 0; i < MAXDATANUM; i++) {
		int k=0, j = 0;
		if (fscanf(settingFile, "%d,%s", &a, field) == EOF) {
			break;
		}
		sep = field;

		while (*sep != ',') {
			field1[k++] = field[j++];
			sep++;
		}
		field1[k] = '\0';
		k = 0;
		j++;
		sep++;
		while (*sep != '\0') {
			field2[k++] = field[j++];
			sep++;
		}
		field2[k] = '\0';

		type = field1;
		if (type.compare(typeInt)==0) {
			data_type[i] = dataTypeInt;
			data_num++;
		}
		else if (type.compare(typeFloat) == 0) {
			data_type[i] = dataTypeFloat;
			data_num++;
		}
		else if (type.compare(typeBool) == 0) {
			data_type[i] = dataTypeBool;
			data_num++;
		}
		else if (type.compare(typeDummy) == 0) {
			data_type[i] = dataTypeDummy;
			dummy_num++;
		}
		data_name[i] = field2;
	}



	for (int i = 0; i < data_num; i++) {
		printf("%d\n", data_type[i]);
	}

	printf("data_num = %d\n", data_num);

	fclose(logFile_LQ);
	fclose(logFile_CQ);
	fclose(settingFile);

}

void save_log::logginigInRam(char data[]) {
	static int num = 0;

	num++;
	
	if(num== LQ_term){
		Enqueue_LQ(data);
		num = 0;
	}
	Enqueue_CQ(data);
}


void save_log::DataOut() {
	logFile_LQ = fopen(init.save_name_LQ.c_str(), "w+");
	logFile_CQ = fopen(init.save_name_CQ.c_str(), "w+");

	for (int i = 0; i < data_num + dummy_num; i++) {
		if (data_type[i] != dataTypeDummy) {
			printf("%s\n", data_name[i].c_str());
			fprintf(logFile_LQ, "%s,", data_name[i].c_str());
			fprintf(logFile_CQ, "%s,", data_name[i].c_str());
		}
	}
	fprintf(logFile_LQ, "\n");
	fprintf(logFile_CQ, "\n");

	printf("Logging start\n");
	while (0 == IsEmpty_LQ())
	{
		PrintQueue(Dequeue_LQ(), logFile_LQ);
	}

	for(int i=0;i<CQ_size;i++)
	{
		PrintQueue(Dequeue_CQ(), logFile_CQ);
	}

	printf("Logging finish\n");
	fclose(logFile_LQ);
	fclose(logFile_CQ);
}




void save_log::CreateQueue_CQ()
{
	Queue_CQ = (QUEUE*)malloc(sizeof(QUEUE));

	Queue_CQ->Front = NULL;
	Queue_CQ->Rear = NULL;
}


NODE* save_log::CreateNode_CQ()
{
	NODE* NewNode = (NODE*)malloc(sizeof(NODE));
	char* NewData = (char*)malloc(data_size);
	NewNode->dataAdd = NewData;

	NewNode->NextNode = NULL;

	return NewNode;
}

void save_log::InitNode_CQ()
{
	if (Queue_CQ->Front == NULL)
	{
		Queue_CQ->Front = CreateNode_CQ();
		Queue_CQ->Rear = Queue_CQ->Front;
	}

	for (int i = 0; i < CQ_size-1; i++) {
		Queue_CQ->Rear->NextNode = CreateNode_CQ();
		Queue_CQ->Rear = Queue_CQ->Rear->NextNode;
	}

	Queue_CQ->Rear->NextNode = Queue_CQ->Front;//Circulating

}


void save_log::Enqueue_CQ(char* Data)
{
	Queue_CQ->Rear = Queue_CQ->Front;
	Queue_CQ->Front = Queue_CQ->Front->NextNode;
	memcpy(Queue_CQ->Rear->dataAdd, Data, data_size);
	

}


NODE* save_log::Dequeue_CQ()
{
	NODE* FrontNode = Queue_CQ->Front;

	if (Queue_CQ->Front->NextNode == NULL)
	{
		Queue_CQ->Front = NULL;
		Queue_CQ->Rear = NULL;
	}
	else
	{
		Queue_CQ->Front = Queue_CQ->Front->NextNode;
	}

	return FrontNode;
}


void save_log::PrintQueue(NODE* PRINTNODE,FILE* logFile)
{
	char* logging;
	int aligned4byte = 0;
	logging = PRINTNODE->dataAdd;


	for (int i = 0; i < data_num + dummy_num; i++) {

		if (data_type[i] == dataTypeInt) {
			while (aligned4byte % 4) {
				logging++;
				aligned4byte++;
			}
			fprintf(logFile, "%i,", *((int*)(logging)));
			logging += 4;
			aligned4byte += 4;
		}
		else if (data_type[i] == dataTypeFloat) {
			while (aligned4byte % 4) {
				aligned4byte++;
			}
			fprintf(logFile, "%f,", *((float*)(logging)));
			logging += 4;
			aligned4byte += 4;
		}
		else if (data_type[i] == dataTypeBool) {
			int num = (int)(*logging);
			fprintf(logFile, "%i,", num);
			logging++;
			aligned4byte++;
		}
		else if (data_type[i] == dataTypeDummy) {
			logging++;
			aligned4byte++;
		}


	}

	fprintf(logFile, "\n");

	free(PRINTNODE->dataAdd);
	free(PRINTNODE);
}

int save_log::IsEmpty_CQ()
{
	return (Queue_CQ->Front == Queue_CQ->Rear);
}