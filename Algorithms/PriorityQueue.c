#include "PriorityQueue.h"

PriorityQueue* PQ_Create(int InitialSize)
{
	PriorityQueue* NewPQ = (PriorityQueue*)malloc(sizeof(PriorityQueue));
	NewPQ->Capacity = InitialSize;
	NewPQ->UsedSize = 0;
	NewPQ->Nodes = (PQNode*)malloc(sizeof(PQNode) * NewPQ->Capacity);

return NewPQ;
}

void PQ_Destroy(PriorityQueue* PQ)
{
	free(PQ->Nodes);
	free(PQ);
}

void PQ_Enqueue(PriorityQueue* PQ, PQNode NewNode)
{
	int CurrentPosition = PQ->UsedSize;
	int ParentPosition = PQ_GetParent(CurrentPosition);

	if (PQ->UsedSize == PQ->Capacity)
	{
		if (PQ->Capacity == 0)
			PQ->Capacity = 1;

		PQ->Capacity *= 2;
		PQ->Nodes = (PQNode*)realloc(PQ->Nodes, sizeof(PQNode) * PQ->Capacity);
	}

	PQ->Nodes[CurrentPosition] = NewNode;

	/* �ļ� ó�� */
	while (CurrentPosition > 0 &&
		PQ->Nodes[CurrentPosition].Priority < PQ->Nodes[ParentPosition].Priority)
	{
		PQ_SwapNodes(PQ, CurrentPosition, ParentPosition);

		CurrentPosition = ParentPosition;
		ParentPosition = PQ_GetParent(CurrentPosition);
	}

	PQ->UsedSize++;
}

void PQ_SwapNodes(PriorityQueue* PQ, int Index1, int Index2)
{
	int CopySize = sizeof(PQNode);
	PQNode* Temp = (PQNode*)malloc(CopySize);

	memcpy(Temp, &PQ->Nodes[Index1], CopySize);
	memcpy(&PQ->Nodes[Index1], &PQ->Nodes[Index2], CopySize);
	memcpy(&PQ->Nodes[Index2], Temp, CopySize);

	free(Temp);
}

void PQ_Dequeue(PriorityQueue* PQ, PQNode* Root)
{
	int ParentPosition = 0;
	int LeftPosition = 0;
	int RightPositon = 0;

	memcpy(Root, &PQ->Nodes[0], sizeof(PQNode));
	memset(&PQ->Nodes[0], 0, sizeof(PQNode));

	PQ->UsedSize--;
	PQ_SwapNodes(PQ, 0, PQ->UsedSize);

	LeftPosition = PQ_GetLeftChild(0);
	RightPositon = LeftPosition + 1;

	while (1)
	{
		int SelectChild = 0;

		if (LeftPosition >= PQ->UsedSize)
			break;

		if (RightPositon >= PQ->UsedSize)
		{
			SelectChild = LeftPosition;
		}
		else
		{
			if (PQ->Nodes[LeftPosition].Priority >
				PQ->Nodes[RightPositon].Priority)
				SelectChild = RightPositon;
			else
				SelectChild = LeftPosition;
		}

		if (PQ->Nodes[SelectChild].Priority <
			PQ->Nodes[ParentPosition].Priority)
		{
			PQ_SwapNodes(PQ, ParentPosition, SelectChild);
			ParentPosition = SelectChild;
		}
		else
			break;

		LeftPosition = PQ_GetLeftChild(ParentPosition);
		RightPositon = LeftPosition + 1;
	}

	if (PQ->UsedSize < (PQ->Capacity) / 2)
	{
		PQ->Capacity /= 2;
		PQ->Nodes = (PQNode*)realloc(PQ->Nodes, sizeof(PQNode) * PQ->Capacity);
	}
}

int PQ_GetParent(int Index)
{
	return (int)((Index - 1) / 2);
}

int PQ_GetLeftChild(int Index)
{
	return (2 * Index) + 1;
}


int PQ_IsEmpty(PriorityQueue* PQ)
{
	return (PQ->UsedSize == 0);
}
