#include "ArrayStack.h"

void AS_CreateStack(ArrayStack** Stack, int Capacity)
{
	/* ������ ���� ����ҿ� ���� */
	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));

	/* �Էµ� Capacity��ŭ�� ��带 ���� ����ҿ� ���� */
	(*Stack)->Nodes = (Node*)malloc(sizeof(Node) * Capacity);

	/* Capacity �� Top �ʱ�ȭ */
	(*Stack)->Capacity = Capacity;
	(*Stack)->Top = 0;
}

void AS_DestroyStack(ArrayStack* Stack)
{
	/* ��带 ���� ����ҿ��� ���� */
	free(Stack->Nodes);

	/* ���ø� ���� ����ҿ��� ����*/
	free(Stack);
}

/*
�̰͸��� �˰��ô�. 2�� ���� 2.
AS_Push() �Լ��� ������ �뷮�� ��� �����Ǿ��� �� ���� �뷮�� 30%��ŭ�� ���ø����� �����ϼ���.
*/
void AS_Push(ArrayStack* Stack, ElementType Data)
{
	int Position = Stack->Top;

	if (Position >= Stack->Capacity)
	{
		int OldCapacity = Stack->Capacity;
		Stack->Capacity = (int)(OldCapacity * 1.3);
		Node* NewNodes = (Node*)malloc(sizeof(Node) * Stack->Capacity);

		for (int i = 0; i < OldCapacity; i++)
		{
			NewNodes[i].Data = Stack->Nodes[i].Data;
		}

		free(Stack->Nodes);
		Stack->Nodes = NewNodes;
		printf("\nChange Capacity : %d -> %d \n", OldCapacity, Stack->Capacity);
	}

	Stack->Nodes[Position].Data = Data;
	Stack->Top++;
}

/*
�̰͸��� �˰��ô�. 2�� ���� 3.
������ AS_Pop() �Լ��� ��뷮�� ���� �뷮�� 70% �̸����� �������� �뷮�� ���̵��� �����ϴ� ���Դϴ�
*/
ElementType AS_Pop(ArrayStack* Stack)
{
	int Position = --(Stack->Top);
	
	if (Stack->Top < (int)(Stack->Capacity * 0.7))
	{
		int OldCapacity = Stack->Capacity;
		Stack->Capacity = (int)(OldCapacity * 0.7);
		Node* NewNodes = (Node*)malloc(sizeof(Node) * Stack->Capacity);

		for (int i = 0; i < Stack->Capacity; i++)
		{
			NewNodes[i].Data = Stack->Nodes[i].Data;
		}

		free(Stack->Nodes);
		Stack->Nodes = NewNodes;
		printf("\nChange Capacity : %d -> %d \n", OldCapacity, Stack->Capacity);
	}
	
	return Stack->Nodes[Position].Data;
}

ElementType AS_Top(ArrayStack* Stack)
{
	int Position = Stack->Top - 1;

	return Stack->Nodes[Position].Data;
}

int AS_GetSize(ArrayStack* Stack)
{
	return Stack->Top;
}

int AS_IsEmpty(ArrayStack* Stack)
{
	return (Stack->Top == 0);
}
