#include "LCRSTree.h"

LCRSNode* LCRS_CreateNode(ElementType NewData)
{
	LCRSNode* NewNode = (LCRSNode*)malloc(sizeof(LCRSNode));
	NewNode->LeftChild = NULL;
	NewNode->RightSibling = NULL;
	NewNode->Data = NewData;

	return NewNode;
}

void LCRS_DestroyNode(LCRSNode* Node)
{
	free(Node);
}

void LCRS_DestroyTree(LCRSNode* Root)
{
	if (Root->RightSibling != NULL)
		LCRS_DestroyTree(Root->RightSibling);

	if (Root->LeftChild != NULL)
		LCRS_DestroyTree(Root->LeftChild);
	
	Root->LeftChild = NULL;
	Root->RightSibling = NULL;

	LCRS_DestroyNode(Root);
}

void LCRS_AddChildNode(LCRSNode* Parent, LCRSNode* Child)
{
	if (Parent->LeftChild == NULL)
		Parent->LeftChild = Child;
	else
	{
		LCRSNode* TempNode = Parent->LeftChild;
		while (TempNode->RightSibling != NULL)
			TempNode = TempNode->RightSibling;

		TempNode->RightSibling = Child;
	}
}

void LCRS_PrintTree(LCRSNode* Node, int Depth)
{
	for (int i = 0; i < Depth; i++)
	{
		printf(" ");
	}

	printf("%c\n", Node->Data);

	if (Node->LeftChild != NULL)
		LCRS_PrintTree(Node->LeftChild, Depth + 1);

	if (Node->RightSibling != NULL)
		LCRS_PrintTree(Node->RightSibling, Depth);
}

/* Vitamin Quiz */
void LCRS_PrintNodesAtLevel(LCRSNode* Root, int Level)
{
	if (Level == 0)
		printf("%c ", Root->Data);
	else if (Level > 0)
	{
		if (Root->LeftChild != NULL)
			LCRS_PrintNodesAtLevel(Root->LeftChild, Level - 1);
	}
	
	if (Root->RightSibling != NULL)
		LCRS_PrintNodesAtLevel(Root->RightSibling, Level);
}