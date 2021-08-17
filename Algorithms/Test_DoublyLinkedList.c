#include "DoublyLinkedList.h"
/*
* P218�� 2�� ����.
* 2. ���� ��ũ�� ����Ʈ�� Ž���� ���� ���, ������ ����� ����/������ ���� �ڷᱸ���Դϴ�.
* �迭�� ���� ���� �� InsertionSortO �Լ��� ���� ��ũ�� ����Ʈ�� ������ �� �ְ� �����ϼ���.
*/
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int   i = 0;
    int   Count = 0;
    Node* List = NULL;
    Node* NewNode = NULL;
    Node* Current = NULL;

    /*
    * P218�� 2�� ����.
    * 2. ���� ��ũ�� ����Ʈ�� Ž���� ���� ���, ������ ����� ����/������ ���� �ڷᱸ���Դϴ�.
    * �迭�� ���� ���� �� InsertionSortO �Լ��� ���� ��ũ�� ����Ʈ�� ������ �� �ְ� �����ϼ���.
    */
    srand((unsigned int)time(NULL));

    /*  ��� 5�� �߰� */
    for (i = 0; i < 5; i++)
    {
        //NewNode = DLL_CreateNode(i);
        NewNode = DLL_CreateNode(rand() % 100);
        DLL_AppendNode(&List, NewNode);
    }

    /*  ����Ʈ ��� */
    Count = DLL_GetNodeCount(List);
    for (i = 0; i < Count; i++)
    {
        Current = DLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Data);
    }

    /*  ����Ʈ�� ����° ĭ �ڿ� ��� ���� */
    //printf("\nInserting 3000 After [2]...\n\n");
    //Current = DLL_GetNodeAt(List, 2);
    //NewNode = DLL_CreateNode(3000);
    //DLL_InsertAfter(Current, NewNode);

    printf("\nInsertion Sorting...\n");
    DLL_InsertionSort(&List);
    Count = DLL_GetNodeCount(List);

    /*  ����Ʈ ��� */
    //Count = DLL_GetNodeCount(List);

    for (i = 0; i < Count; i++)
    {
        Current = DLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Data);
    }

    /*  ��� ��带 �޸𸮿��� ����     */
    printf("\nDestroying List...\n");
    Count = DLL_GetNodeCount(List);

    for (i = 0; i < Count; i++)
    {
        Current = DLL_GetNodeAt(List, 0);

        if (Current != NULL)
        {
            DLL_RemoveNode(&List, Current);
            DLL_DestroyNode(Current);
        }
    }

    return 0;
}