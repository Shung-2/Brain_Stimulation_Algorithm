#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* New! */
#include "Graph.h"  /* New! */

// typedef int ElementType;

typedef struct tagNode
{
    // ElementType Data;
    Vertex* Data; /* New! */
    struct tagNode* NextNode;
} Node;

/* �Լ� ���� ���� */
//Node* SLL_CreateNode(ElementType NewData);
Node* SLL_CreateNode(Vertex* NewData);
void  SLL_DestroyNode(Node* Node);
void  SLL_AppendNode(Node** Head, Node* NewNode);
//void  SLL_InsertAfter(Node* Current, Node* NewNode);
void  SLL_InsertAfter(Node** Current, Node** NewNode); /* new! */
//void  SLL_InsertNewHead(Node** Head, Node* NewHead);
void  SLL_InsertNewHead(Node** Head, Node* NewHead); /* new! */
//void  SLL_RemoveNode(Node** Head, Node* Remove);
void  SLL_RemoveNode(Node** Head, Node** Remove); /* new! */
Node* SLL_GetNodeAt(Node* Head, int Location);
int   SLL_GetNodeCount(Node* Head);

/* P226 �����̵��� �Լ� ���� & Vitamin Quiz */
//Node* SLL_MoveToFront(Node** Head, int Target); /* ���� */
int SLL_MoveToFront(int DataSet[], int Length, int target);

/* P228 ������ �Լ� ���� & Vitamin Quiz */
//Node* SLL_Transpose(Node** Head, int Target);
void Swap(int* A, int* B);
int SLL_Tranpose(int DataSet[], int Length, int target);

#endif
