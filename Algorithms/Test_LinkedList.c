#include "LinkedList.h"

int main(void)
{
    //int   i = 0;
    //int   Count = 0;
    //Node* List = NULL;
    //Node* Current = NULL;
    //Node* NewNode = NULL;

    ///*  ��� 5�� �߰� */
    //for (i = 0; i < 5; i++)
    //{
    //    NewNode = SLL_CreateNode(i);
    //    SLL_AppendNode(&List, NewNode);
    //}

    //NewNode = SLL_CreateNode(-1);
    //SLL_InsertNewHead(&List, NewNode);

    //NewNode = SLL_CreateNode(-2);
    //SLL_InsertNewHead(&List, NewNode);

    ///*  ����Ʈ ��� */
    //Count = SLL_GetNodeCount(List);
    //for (i = 0; i < Count; i++)
    //{
    //    Current = SLL_GetNodeAt(List, i);
    //    printf("List[%d] : %d\n", i, Current->Data);
    //}

    ///*  ����Ʈ�� ����° ��� �ڿ� �� ��� ���� */
    //printf("\nInserting 3000 After [2]...\n\n");

    //Current = SLL_GetNodeAt(List, 2);
    //NewNode = SLL_CreateNode(3000);

    //SLL_InsertAfter(Current, NewNode);

    ///*  ����Ʈ ��� */
    //Count = SLL_GetNodeCount(List);
    //for (i = 0; i < Count; i++)
    //{
    //    Current = SLL_GetNodeAt(List, i);
    //    printf("List[%d] : %d\n", i, Current->Data);
    //}

    ///*  ��� ��带 �޸𸮿��� ����     */
    //printf("\nDestroying List...\n");

    //for (i = 0; i < Count; i++)
    //{
    //    Current = SLL_GetNodeAt(List, 0);

    //    if (Current != NULL)
    //    {
    //        SLL_RemoveNode(&List, Current);
    //        SLL_DestroyNode(Current);
    //    }
    //}

    /* P226 Vitamin Quiz */
    //int DataSet[] = { 6, 4, 2, 3, 1, 5 };
    //int Length = sizeof DataSet / sizeof DataSet[0];
    //
    //SLL_MoveToFront(DataSet, Length, 1);
    //
    //for (int i = 0; i < Length; i++)
    //    printf("%d ", DataSet[i]);
    //printf("\n");

    /* P228 Vitamin Quiz */
    int DataSet[] = { 6, 4, 2, 3, 1, 5 };
    int Length = sizeof DataSet / sizeof DataSet[0];
    
    SLL_Tranpose(DataSet, Length, 3);
    
    for (int i = 0; i < Length; i++)
        printf("%d ", DataSet[i]);
    printf("\n");

    return 0;
}
