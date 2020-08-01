#include "linked_list.h"

using namespace std;

FILE *currentFile;
saveLogStruct data_x;

int main()
{
	QUEUE* Queue;

	CreateQueue(&Queue);

	Enqueue(Queue, "Â¥Àå¸é");
	Enqueue(Queue, "Â«»Í");

	PrintQueue(Dequeue(Queue));
	printf("\n");

	Enqueue(Queue, "±º¸¸µÎ");

	// ÀüÃ¼ ²¨³»±â
	while (0 == IsEmpty(Queue))
	{
		PrintQueue(Dequeue(Queue));
	}

	currentFile = fopen("current_result.csv", "w+");
	if (currentFile == NULL) printf("Error opening current result csv file.");

	printf("size : %d",sizeof(data_x));

	fprintf(currentFile, "123");

	while (1);

	return 0;
}


