#include "PriorityQueue.h"

void PrintNode(PQNode* Node)
{
	printf("�۾��� : %s (�켱���� : %d)\n", Node->Data, Node->Priority);
}

int main(void)
{
	PriorityQueue* PQ = PQ_Create(3);
	PQNode Popped;

	PQNode Node[7] =
	{
		{34, (void*)"�ڵ�"},
		{12, (void*)"������"},
		{87, (void*)"Ŀ��Ÿ��"},
		{45, (void*)"�����ۼ�"},
		{35, (void*)"�����"},
		{66, (void*)"�̴۱�"},
	};

	PQ_Enqueue(PQ, Node[0]);
	PQ_Enqueue(PQ, Node[1]);
	PQ_Enqueue(PQ, Node[2]);
	PQ_Enqueue(PQ, Node[3]);
	PQ_Enqueue(PQ, Node[4]);
	PQ_Enqueue(PQ, Node[5]);

	printf("ť�� ���� �ִ� �۾��� �� : %d \n", PQ->UsedSize);

	while (!PQ_IsEmpty(PQ))
	{
		PQ_Dequeue(PQ, &Popped);
		PrintNode(&Popped);
	}

	return 0;
}