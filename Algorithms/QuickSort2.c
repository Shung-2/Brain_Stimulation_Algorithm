#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/* 콩쥐 문제 */
#include "Score.h"

/* 리턴값이 */
/* < 0이면, _elem1이 _elem2 보다 작다. */
/* 0  이면, _elem1이 _elem2   와 같다. */
/* > 0이면, _elem1이 _elem2 보다 크다. */

int CompareScore(const void* _elem1, const void* _elem2)
{
	//int* elem1 = (int*)_elem1;
	//int* elem2 = (int*)_elem2;

	Score* elem1 = (Score*)_elem1;
	Score* elem2 = (Score*)_elem2;

	//if (*elem1 > *elem2)
	//	return 1;
	//else if (*elem1 < *elem2)
	//	return -1;
	//else
	//	return 0;

	if (elem1->score > elem2->score)
		return 1;
	else if (elem1->score < elem2->score)
		return -1;
	else
		return 0;
}

int main(void)
{
	/*
	int DataSet[] = { 6, 4, 2, 3, 1, 5 };
	int Length = sizeof DataSet / sizeof DataSet[0];
	int i = 0;

	qsort((void*)DataSet, Length, sizeof(int), CompareScore);

	for (i = 0; i < Length; i++)
		printf("%d ", DataSet[i]);
	printf("\n");

	return 0;
	*/

	int Length = sizeof DataSet / sizeof DataSet[0];
	int FindIdx = 17213;

	qsort((void*)DataSet, Length, sizeof(Score), CompareScore);

	for (size_t i = 0; i < 10; i++)
		printf("Rank : %d \t id : %d \t score : %lf \n", i+1, DataSet[i].number, DataSet[i].score);
	printf("...\n");

	for (size_t i = FindIdx - 5; i < FindIdx + 5; i++)
		printf("Rank : %d \t id : %d \t score : %lf \n", i + 1, DataSet[i].number, DataSet[i].score);
	printf("...\n");

	printf("Rank : %d \t id : %d \t score : %lf \n", FindIdx, DataSet[FindIdx-1].number, DataSet[FindIdx-1].score);
}