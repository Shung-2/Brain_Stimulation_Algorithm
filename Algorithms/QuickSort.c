#include <stdio.h>

void Swap(int* A, int* B)
{
	int Temp = *A;
	*A = *B;
	*B = Temp;

/*
* P218�� 3�� ���� & 4�� ����.
* 3. QuickSotlc���� Partition() �Լ��� �־��� ���� ���� ���� ��Ҹ� �����ϵ��� �����ϼ���
* 4. 4. Quicksort�� ���� ū ������ �� �ϳ��� ��뷮�� �����͸� ó���ϱ⿡ �������ϴٴ� ���Դϴ�.
* ��� ȣ�⿡ ���Ǵ� ������ ũ�� ����������. 
* ��� ȣ�� ��� ��ȯ���� �̿��Ͽ� �˰����� �����Ͻʽÿ�(��Ʈ, 2�忡  �� ������ ������ �̿��ϼ���)
*/

#include "LinkedListStack.h"

int getMedian(int a, int b, int c)
{
    if (b >= a && a >= c)
        return a;
    else if (a >= b && b >= c)
        return b;
    return c;
}

int Partition(int DataSet[], int Left, int Right)
{
    int First = Left;
    int Index = getMedian(Left, Right, (Left + Right) / 2); // New!
    int Pivot = DataSet[Index];                             // Modify
    Swap(&DataSet[Index], &DataSet[Left]);                  // New!

    ++Left;

    while (Left <= Right)
    {
        while (DataSet[Left] <= Pivot && Left < Right)
            ++Left;

        while (DataSet[Right] >= Pivot && Left <= Right)
            --Right;

        if (Left < Right)
            Swap(&DataSet[Left], &DataSet[Right]);
        else
            break;
    }

    Swap(&DataSet[First], &DataSet[Right]);

    return Right;
}

void QuickSort(int DataSet[], int Left, int Right)
{
    LinkedListStack* Stack;
    LLS_CreateStack(&Stack);
    LLS_Push(Stack, LLS_CreateNode(Left, Right));

    while (!LLS_IsEmpty(Stack))
    {
        Node* Popped = LLS_Pop(Stack);
        Left = Popped->Left;
        Right = Popped->Right;

        if (Left < Right)
        {
            int Index = Partition(DataSet, Left, Right);
            LLS_Push(Stack, LLS_CreateNode(Left, Index - 1));
            LLS_Push(Stack, LLS_CreateNode(Index + 1, Right));
        }
    }
}

int main(void)
{
    int DataSet[] = { 6, 4, 2, 3, 1, 5 };
    int Length = sizeof DataSet / sizeof DataSet[0];
    int i = 0;

    QuickSort(DataSet, 0, Length - 1);

    for (i = 0; i < Length; i++)
    {
        printf("%d ", DataSet[i]);
    }

    printf("\n");

    return 0;
}
