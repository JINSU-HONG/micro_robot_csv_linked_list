#include "linked_list.h"

using namespace std;

void CreateQueue(QUEUE** Queue)
{
	(*Queue) = (QUEUE*)malloc(sizeof(QUEUE));

	(*Queue)->Front = NULL;
	(*Queue)->Rear = NULL;
}

NODE* CreateNode(char Data[])
{
	NODE* NewNode = (NODE*)malloc(sizeof(NODE));

	strcpy_s(NewNode->Data, Data);
	NewNode->NextNode = NULL;

	return NewNode;
}


void Enqueue(QUEUE* Queue, char Data[])
{
	if (Queue->Front == NULL)
	{
		Queue->Front = CreateNode(Data);
		Queue->Rear = Queue->Front;
	}
	else
	{
		Queue->Rear->NextNode = CreateNode(Data);
		Queue->Rear = Queue->Rear->NextNode;
	}
}


NODE* Dequeue(QUEUE* Queue)
{
	NODE* FrontNode = Queue->Front;

	if (Queue->Front->NextNode == NULL)
	{
		Queue->Front = NULL;
		Queue->Rear = NULL;
	}
	else
	{
		Queue->Front = Queue->Front->NextNode;
	}

	return FrontNode;
}


void PrintQueue(NODE* PrintNode)
{
	printf("Queue: %s\n", PrintNode->Data);
	free(PrintNode);
}

int IsEmpty(QUEUE* Queue)
{
	return (Queue->Front == NULL);
}