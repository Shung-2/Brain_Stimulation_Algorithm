#include <stdio.h>
#include <stdlib.h>

void MergeSort(int DataSet[], int StartIndex, int EndIndex);
void Merge(int Dataset[], int StartIndex, int MiddleIndex, int EndIndex);

void MergeSort(int DataSet[], int StartIndex, int EndIndex)
{
	int MiddileIndex;

	if (EndIndex - StartIndex < 1)
		return;

	MiddileIndex = (StartIndex + EndIndex) / 2;

	MergeSort(DataSet, StartIndex, MiddileIndex);
	MergeSort(DataSet, MiddileIndex + 1, EndIndex);

	Merge(DataSet, StartIndex, MiddileIndex, EndIndex);
}

void Merge(int Dataset[], int StartIndex, int MiddleIndex, int EndIndex)
{
	int i;
	int LeftIndex = StartIndex;
	int RightIndex = MiddleIndex + 1;
	int DestIndex = 0;

	int* Destination = (int*)malloc(sizeof(int) * (EndIndex - StartIndex + 1));

	while (LeftIndex <= MiddleIndex && RightIndex <= EndIndex)
	{
		if (Dataset[LeftIndex] < Dataset[RightIndex])
		{
			Destination[DestIndex] = Dataset[LeftIndex];
			LeftIndex++;
		}
		else
		{
			Destination[DestIndex] = Dataset[RightIndex];
			RightIndex++;
		}
		DestIndex++;
	}

	while (LeftIndex <= MiddleIndex)
		Destination[DestIndex++] = Dataset[LeftIndex++];

	while (RightIndex <= EndIndex)
		Destination[DestIndex++] = Dataset[RightIndex++];

	DestIndex = 0;
	for (i = StartIndex; i <= EndIndex; i++)
	{
		Dataset[i] = Destination[DestIndex++];
	}

	free(Destination);
}

int main(void)
{
	int DataSet[] = { 334, 6 , 4 , 2 , 3 , 1, 5, 117 , 12 , 34 };
	int Length = sizeof DataSet / sizeof DataSet[0];
	int i = 0;

	MergeSort(DataSet, 0, Length - 1);

	for (i = 0; i < Length; i++)
	{
		printf("%d ", DataSet[i]);
	}

	printf("\n");

	return 0;
}
