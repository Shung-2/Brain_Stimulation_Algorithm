#ifndef LCRS_TREE_H
#define LCRS_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct tagLCRSNode
{
	struct tagLCRSNode* LeftChild;
	struct tagLCRSNode* RightSibling;

	ElementType Data;
} LCRSNode;

LCRSNode*	LCRS_CreateNode(ElementType NewData);
void		LCRS_DestroyNode(LCRSNode* Node);
void		LCRS_DestroyTree(LCRSNode* Root);

void		LCRS_AddChildNode(LCRSNode* ParentNode, LCRSNode* ChildNode);
void		LCRS_PrintTree(LCRSNode* Node, int Depth);

/* Vitamin Quiz */
/* 이 예제 프로그램에서 특정 레벨의 모든 노드를 출력하는 함수 LCRS_PrintNodesAtLevel(LCRSNode* Root, int Level)를 작성하세요. */
void		LCRS_PrintNodesAtLevel(LCRSNode* Root, int Level);

#endif