#include "DoublyLinkedList.h"

/*  노드 생성 */
Node* DLL_CreateNode(ElementType NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;
    NewNode->PrevNode = NULL;
    NewNode->NextNode = NULL;

    return NewNode;
}

/*  노드 소멸 */
void DLL_DestroyNode(Node* Node)
{
    free(Node);
}

/*  노드 추가 */
void DLL_AppendNode(Node** Head, Node* NewNode)
{
    /*  헤드 노드가 NULL이라면 새로운 노드가 Head */
    if ((*Head) == NULL)
    {
        *Head = NewNode;
    }
    else
    {
        /*  테일을 찾아 NewNode를 연결한다. */
        Node* Tail = (*Head);
        while (Tail->NextNode != NULL)
        {
            Tail = Tail->NextNode;
        }

        Tail->NextNode = NewNode;
        NewNode->PrevNode = Tail; /*  기존의 테일을 새로운 테일의 PrevNode가 가리킨다. */
    }
}

/*  노드 삽입 */
void DLL_InsertAfter(Node* Current, Node* NewNode)
{
    NewNode->NextNode = Current->NextNode;
    NewNode->PrevNode = Current;

    if (Current->NextNode != NULL)
    {
        Current->NextNode->PrevNode = NewNode;
        Current->NextNode = NewNode;
    }
}

/*  노드 제거 */
void DLL_RemoveNode(Node** Head, Node* Remove)
{
    if (*Head == Remove)
    {
        *Head = Remove->NextNode;
        if ((*Head) != NULL)
            (*Head)->PrevNode = NULL;

        Remove->PrevNode = NULL;
        Remove->NextNode = NULL;
    }
    else
    {
        Node* Temp = Remove;

        if (Remove->PrevNode != NULL)
            Remove->PrevNode->NextNode = Temp->NextNode;

        if (Remove->NextNode != NULL)
            Remove->NextNode->PrevNode = Temp->PrevNode;

        Remove->PrevNode = NULL;
        Remove->NextNode = NULL;
    }
}

/*  노드 탐색 */
Node* DLL_GetNodeAt(Node* Head, int Location)
{
    Node* Current = Head;

    while (Current != NULL && (--Location) >= 0)
    {
        Current = Current->NextNode;
    }

    return Current;
}

/*  노드 수 세기 */
int DLL_GetNodeCount(Node* Head)
{
    unsigned int  Count = 0;
    Node* Current = Head;

    while (Current != NULL)
    {
        Current = Current->NextNode;
        Count++;
    }

    return Count;
}

/*
* P218번 2번 문제.
* 2. 더블 링크드 리스트는 탐색이 느린 대신, 데이터 요소의 삽입/삭제가 빠른 자료구조입니다.
* 배열을 위해 구현 된 InsertionSortO 함수가 더블 링크드 리스트를 정렬할 수 있게 구현하세요.
*/

void DLL_InsertBefore(Node** Head, Node* Current, Node* NewNode)
{
    if ((*Head) == Current)
        (*Head) = NewNode;

    NewNode->PrevNode = Current->PrevNode;
    NewNode->NextNode = Current;

    if (Current->PrevNode != NULL)
        Current->PrevNode->NextNode = NewNode;

    Current->PrevNode = NewNode;
}

void DLL_InsertionSort(Node** Head)
{
    Node* Value = NULL;
    Node* Temp1 = (*Head);
    Node* Temp2 = NULL;

    if (Temp1 == NULL)
        return 0;

    Temp1 = Temp1->NextNode;
    while (Temp1 != NULL)
    {
        if (Temp1->PrevNode->Data <= Temp1->Data)
        {
            Temp1 = Temp1->NextNode;
            continue;
        }

        Value = Temp1;
        Temp1 = Temp1->NextNode;
        Temp2 = (*Head);

        while(Temp2 != Value)
        {
            if (Temp2->Data > Value->Data)
            {
                DLL_RemoveNode(Head, Value);
                DLL_InsertBefore(Head, Temp2, Value);
                break;
            }
            Temp2 = Temp2->NextNode;
        }
    }
}

void PrintNode(Node* _Node)
{
    if (_Node->PrevNode == NULL)
        printf("Prev: NULL");
    else
        printf("Prev: %d", _Node->PrevNode->Data);

    printf(" Current: %d ", _Node->Data);

    if (_Node->NextNode == NULL)
        printf("Next: NULL\n");
    else
        printf("Next: %d\n", _Node->NextNode->Data);
}
