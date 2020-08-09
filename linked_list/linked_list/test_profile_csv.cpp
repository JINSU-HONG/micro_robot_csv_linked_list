#include "test_profile_csv.h"

using namespace std;


void test_profile_load::begin(int initDataSize) {
	data_size = initDataSize;
	CreateQueue_LQ();
	csvinit();
	
}

void test_profile_load::CreateQueue_LQ()
{
	Queue_LQ = (QUEUE*)malloc(sizeof(QUEUE));

	Queue_LQ->Front = NULL;
	Queue_LQ->Rear = NULL;
}


NODE* test_profile_load::CreateNode_LQ(char* Data)
{
	NODE* NewNode = (NODE*)malloc(sizeof(NODE));
	char* NewData = (char*)malloc(data_size);
	NewNode->dataAdd = NewData;

	memcpy(NewNode->dataAdd, Data, data_size);
	NewNode->NextNode = NULL;

	return NewNode;
}


void test_profile_load::Enqueue_LQ(char* Data)
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


NODE* test_profile_load::Dequeue_LQ()
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


int test_profile_load::IsEmpty_LQ()
{
	return (Queue_LQ->Front == NULL);
}


void test_profile_load::csvinit()
{
	int a = 0;
	int k = 0, j = 0, num = 0;;
	char field[5000];
	char field1[50];
	char* sep;

	string type;
	string data;

	char* NewData;
	char* buf;

	loadFile = fopen(init.load_file_name.c_str(), "r");
	if (loadFile == NULL) printf("Error opening %s file.", init.load_file_name.c_str());

	fscanf(loadFile, "%d,%s", &a, field);//delete first low

	fscanf(loadFile, "%d,%s", &a, field);
	sep = field;

	while (*sep != '\0') {
		if (*sep == ',') {
			field1[k] = '\0';
			k = 0;
			j++;
			type = field1;
			data_type[field_num++] = compDataType(type);
		}
		else {
			field1[k++] = field[j++];
		}
		sep++;
	}

	field1[k] = '\0';
	type = field1;
	data_type[field_num++] = compDataType(type);

	

	for (int i = 0; i < MAXLOADDATANUM; i++) {
		k = 0;j = 0; num = 0;
		NewData = (char*)malloc(data_size);
		buf = NewData;
		if (fscanf(loadFile, "%d,%s", &a, field) == EOF) {
			break;
		}
		data_num++;
		sep = field;
		while (*sep != '\0') {
			if (*sep == ',') {
				field1[k] = '\0';
				k = 0;
				j++;
				data = field1;
				if (data_type[num] == dataTypeFloat) {
					float tempFloat = stof(data);
					memcpy(buf, (char*)(&tempFloat), 4);
					buf += 4;
				}
				else if (data_type[num] == dataTypeInt) {
					int tempInt = stoi(data);
					memcpy(buf, (char*)(&tempInt), 4);
					buf += 4;
				}
				else if (data_type[num] == dataTypeBool) {
					char tempChar = (char)(stoi(data));
					memcpy(buf, (char*)(&tempChar), 1);
					buf++;
				}
				else if (data_type[num] == dataTypeDummy) {
					char tempChar = (char)(stoi(data));
					memcpy(buf, (char*)(&tempChar), 1);
					buf++;
				}
				num++;
			}
			else {
				field1[k++] = field[j++];
			}
			sep++;
		}
		field1[k] = '\0';
		data = field1;
		if (data_type[num] == dataTypeFloat) {
			float tempFloat = stof(data);
			memcpy(buf, (char*)(&tempFloat), 4);
			buf += 4;
		}
		else if (data_type[num] == dataTypeInt) {
			int tempInt = stoi(data);
			memcpy(buf, (char*)(&tempInt), 4);
			buf += 4;
		}
		else if (data_type[num] == dataTypeBool) {
			char tempChar = (char)(stoi(data));
			memcpy(buf, (char*)(&tempChar), 1);
			buf++;
		}
		else if (data_type[num] == dataTypeDummy) {
			char tempChar = (char)(stoi(data));
			memcpy(buf, (char*)(&tempChar), 1);
			buf++;
		}
		Enqueue_LQ(NewData);
		free(NewData);
	}

	fclose(loadFile);

}


int test_profile_load::DataLoad(char data[]) {
	NODE* nowNode;
	if (IsEmpty_LQ()) {
		return 0;
	}
	else {
		nowNode = Dequeue_LQ();
		memcpy(data, nowNode->dataAdd, data_size);
		free(nowNode);
		return 1;
	}
	
}

int test_profile_load::compDataType(string type) {
	string typeInt = "int";
	string typeFloat = "float";
	string typeBool = "bool";
	string typeDummy = "dummy";
	if (type.compare(typeInt) == 0) {
		return dataTypeInt;
	}
	else if (type.compare(typeFloat) == 0) {
		return dataTypeFloat;
	}
	else if (type.compare(typeBool) == 0) {
		return dataTypeBool;
	}
	else if (type.compare(typeDummy) == 0) {
		return dataTypeDummy;
	}
}