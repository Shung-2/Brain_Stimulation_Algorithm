#include "DoublyLinkedList.h"

/*  ��� ���� */
Node* DLL_CreateNode(ElementType NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;
    NewNode->PrevNode = NULL;
    NewNode->NextNode = NULL;

    return NewNode;
}

/*  ��� �Ҹ� */
void DLL_DestroyNode(Node* Node)
{
    free(Node);
}

/*  ��� �߰� */
void DLL_AppendNode(Node** Head, Node* NewNode)
{
    /*  ��� ��尡 NULL�̶�� ���ο� ��尡 Head */
    if ((*Head) == NULL)
    {
        *Head = NewNode;
    }
    else
    {
        /*  ������ ã�� NewNode�� �����Ѵ�. */
        Node* Tail = (*Head);
        while (Tail->NextNode != NULL)
        {
            Tail = Tail->NextNode;
        }

        Tail->NextNode = NewNode;
        NewNode->PrevNode = Tail; /*  ������ ������ ���ο� ������ PrevNode�� ����Ų��. */
    }
}

/*  ��� ���� */
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

/*  ��� ���� */
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

/*  ��� Ž�� */
Node* DLL_GetNodeAt(Node* Head, int Location)
{
    Node* Current = Head;

    while (Current != NULL && (--Location) >= 0)
    {
        Current = Current->NextNode;
    }

    return Current;
}

/*  ��� �� ���� */
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
* P218�� 2�� ����.
* 2. ���� ��ũ�� ����Ʈ�� Ž���� ���� ���, ������ ����� ����/������ ���� �ڷᱸ���Դϴ�.
* �迭�� ���� ���� �� InsertionSortO �Լ��� ���� ��ũ�� ����Ʈ�� ������ �� �ְ� �����ϼ���.
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
