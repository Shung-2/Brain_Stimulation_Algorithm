#ifndef DOUBLY_LINKEDLIST_H
#define DOUBLY_LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
    ElementType Data;
    struct tagNode* PrevNode;
    struct tagNode* NextNode;
} Node;

/* 함수 원형 선언 */
Node* DLL_CreateNode(ElementType NewData);
void  DLL_DestroyNode(Node* Node);
void  DLL_AppendNode(Node** Head, Node* NewNode);
void  DLL_InsertAfter(Node* Current, Node* NewNode);
void  DLL_RemoveNode(Node** Head, Node* Remove);
Node* DLL_GetNodeAt(Node* Head, int Location);
int   DLL_GetNodeCount(Node* Head);

/* 
* P218번 2번 문제.
* 2. 더블 링크드 리스트는 탐색이 느린 대신, 데이터 요소의 삽입/삭제가 빠른 자료구조입니다.
* 배열을 위해 구현 된 InsertionSortO 함수가 더블 링크드 리스트를 정렬할 수 있게 구현하세요.
*/

void DLL_InsertBefore(Node** Head, Node* Current, Node* NewNode);
void DLL_InsertionSort(Node** Head);

#endif DOUBLY_LINKEDLIST_H