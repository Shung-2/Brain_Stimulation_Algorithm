#include "DoublyLinkedList.h"
/*
* P218번 2번 문제.
* 2. 더블 링크드 리스트는 탐색이 느린 대신, 데이터 요소의 삽입/삭제가 빠른 자료구조입니다.
* 배열을 위해 구현 된 InsertionSortO 함수가 더블 링크드 리스트를 정렬할 수 있게 구현하세요.
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
    * P218번 2번 문제.
    * 2. 더블 링크드 리스트는 탐색이 느린 대신, 데이터 요소의 삽입/삭제가 빠른 자료구조입니다.
    * 배열을 위해 구현 된 InsertionSortO 함수가 더블 링크드 리스트를 정렬할 수 있게 구현하세요.
    */
    srand((unsigned int)time(NULL));

    /*  노드 5개 추가 */
    for (i = 0; i < 5; i++)
    {
        //NewNode = DLL_CreateNode(i);
        NewNode = DLL_CreateNode(rand() % 100);
        DLL_AppendNode(&List, NewNode);
    }

    /*  리스트 출력 */
    Count = DLL_GetNodeCount(List);
    for (i = 0; i < Count; i++)
    {
        Current = DLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Data);
    }

    /*  리스트의 세번째 칸 뒤에 노드 삽입 */
    //printf("\nInserting 3000 After [2]...\n\n");
    //Current = DLL_GetNodeAt(List, 2);
    //NewNode = DLL_CreateNode(3000);
    //DLL_InsertAfter(Current, NewNode);

    printf("\nInsertion Sorting...\n");
    DLL_InsertionSort(&List);
    Count = DLL_GetNodeCount(List);

    /*  리스트 출력 */
    //Count = DLL_GetNodeCount(List);

    for (i = 0; i < Count; i++)
    {
        Current = DLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Data);
    }

    /*  모든 노드를 메모리에서 제거     */
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