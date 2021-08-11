#include "ArrayStack.h"

void AS_CreateStack(ArrayStack** Stack, int Capacity)
{
	/* 스택을 자유 저장소에 생성 */
	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));

	/* 입력된 Capacity만큼의 노드를 자유 저장소에 생성 */
	(*Stack)->Nodes = (Node*)malloc(sizeof(Node) * Capacity);

	/* Capacity 및 Top 초기화 */
	(*Stack)->Capacity = Capacity;
	(*Stack)->Top = 0;
}

void AS_DestroyStack(ArrayStack* Stack)
{
	/* 노드를 자유 저장소에서 해제 */
	free(Stack->Nodes);

	/* 스택를 자유 저장소에서 해제*/
	free(Stack);
}

/*
이것만은 알고갑시다. 2장 문제 2.
AS_Push() 함수를 스택의 용량이 모두 소진되었을 때 현재 용량의 30%만큼을 더늘리도록 개선하세요.
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
이것만은 알고갑시다. 2장 문제 3.
다음의 AS_Pop() 함수를 사용량이 스택 용량의 70% 미만으로 내려가면 용량을 줄이도록 수정하는 것입니다
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
