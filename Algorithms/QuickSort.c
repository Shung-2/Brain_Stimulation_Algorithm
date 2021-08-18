#include <stdio.h>

void Swap(int* A, int* B)
{
	int Temp = *A;
	*A = *B;
	*B = Temp;

/*
* P218번 3번 문제 & 4번 문제.
* 3. QuickSotlc에서 Partition() 함수가 최악의 값을 피해 기준 요소를 선택하도록 개선하세요
* 4. 4. Quicksort의 가장 큰 문제점 중 하나는 대용량의 데이터를 처리하기에 부적합하다는 것입니다.
* 재귀 호출에 사용되는 스택의 크기 때문이지요. 
* 재귀 호출 대신 순환문을 이용하여 알고리즘을 구현하십시오(힌트, 2장에  서 설명한 스택을 이용하세요)
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
