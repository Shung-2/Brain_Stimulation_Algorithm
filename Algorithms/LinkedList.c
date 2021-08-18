#include "LinkedList.h"

/*  ��� ���� */
Node* SLL_CreateNode(ElementType NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;  /*  �����͸� �����Ѵ�. */
    NewNode->NextNode = NULL; /*  ���� ��忡 ���� �����ʹ� NULL�� �ʱ�ȭ �Ѵ�. */

    return NewNode;/*  ����� �ּҸ� ��ȯ�Ѵ�. */
}

/*  ��� �Ҹ� */
void SLL_DestroyNode(Node* Node)
{
    free(Node);
}

/*  ��� �߰� */
void SLL_AppendNode(Node** Head, Node* NewNode)
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
    }
}

/*  ��� ���� */
void SLL_InsertAfter(Node* Current, Node* NewNode)
{
    NewNode->NextNode = Current->NextNode;
    Current->NextNode = NewNode;
}

void  SLL_InsertNewHead(Node** Head, Node* NewHead)
{
    if (Head == NULL)
    {
        (*Head) = NewHead;
    }
    else
    {
        NewHead->NextNode = (*Head);
        (*Head) = NewHead;
    }
}

/*  ��� ���� */
void SLL_RemoveNode(Node** Head, Node* Remove)
{
    if (*Head == Remove)
    {
        *Head = Remove->NextNode;
    }
    else
    {
        Node* Current = *Head;
        while (Current != NULL && Current->NextNode != Remove)
        {
            Current = Current->NextNode;
        }

        if (Current != NULL)
            Current->NextNode = Remove->NextNode;
    }
}

/*  ��� Ž�� */
Node* SLL_GetNodeAt(Node* Head, int Location)
{
    Node* Current = Head;

    while (Current != NULL && (--Location) >= 0)
    {
        Current = Current->NextNode;
    }

    return Current;
}

/*  ��� �� ���� */
int SLL_GetNodeCount(Node* Head)
{
    int   Count = 0;
    Node* Current = Head;

    while (Current != NULL)
    {
        Current = Current->NextNode;
        Count++;
    }

    return Count;
}

// SLL_MoveToFront ����
/* 
Node* SLL_MoveToFront(Node** Head, int Target)
{
    Node* Current = (*Head);
    Node* Previous = NULL;
    Node* Match = NULL;

    while (Current != NULL)
    {
        if (Current->Data == Target)
        {
            Match = Current;
            if (Previous != NULL)
            {
                // �ڽ��� �� ���� ���� ��带 ����
                Previous->NextNode = Current->NextNode;
                
                // �ڽ��� ����Ʈ�� ���� ������ �ű��
                Current->NextNode = (*Head);
                (*Head) = Current;
            }
            break;
        }
        else
        {
            Previous = Current;
            Current = Current->NextNode;
        }
    }

    return Match;
}
*/

int SLL_MoveToFront(int DataSet[], int Length, int target)
{
    for (int i = 0; i < Length; i++)
    {
        if (DataSet[i] == target)
        {
            if (i > 0)
            {
                memmove(DataSet + 1, DataSet, sizeof(int) * i);
                DataSet[0] = target;
            }
            return 0;
        }
    }
    return -1;
}

// SLL_Transpose ����
/*
Node* SLL_Transpose(Node** Head, int Target)
{
    Node* Current = (*Head);
    Node* PPrevious = NULL;
    Node* Previous = NULL;
    Node* Match = NULL;

    while (Current != NULL)
    {
        if (Current->Data = Target)
        {
            Match = Current;
            if (Previous != NULL)
            {
                if (PPrevious != NULL)
                    PPrevious->NextNode = Current;
                else
                    (*Head) = Current;

                Previous->NextNode = Current->NextNode;
                Current->NextNode = Previous;
            }
            break;
        }
        else
        {
            if (Previous != NULL)
                PPrevious = PPrevious;
            Previous = Current;
            Current = Current->NextNode;
        }
    }
    return Match;
}
*/

void Swap(int* A, int* B)
{
    int Temp = *A;
    *A = *B;
    *B = Temp;
}

int SLL_Tranpose(int DataSet[], int Length, int target)
{
    for (int i = 0; i < Length; i++)
    {
        if (DataSet[i] == target)
        {
            if (i > 0)
            {
                Swap(&DataSet[i - 1], &DataSet[i]);
            }
            return i;
        }
    }
    return -1;
}
