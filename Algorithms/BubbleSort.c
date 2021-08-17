#include <stdio.h>

void BubbleSort(int Dataset[], int Length)
{
	int i = 0;
	int j = 0;
	int temp = 0;
	/* Vitamin Quiz, BubbleSort °³¼± */
	int count = 0;

	for (i = 0; i < Length - 1; i++)
	{
		for (j = 0; j < Length - (i + 1); j++)
		{
			if (Dataset[j] > Dataset[j + 1])
			{
				temp = Dataset[j + 1];
				Dataset[j + 1] = Dataset[j];
				Dataset[j] = temp;
				count++;
			}
		}
		if (count == 0)
			break;
	}
}

int main(void)
{
	int DataSet[] = { 6, 4, 2, 3, 1, 5 };
	int Length = sizeof DataSet / sizeof DataSet[0];
	int i = 0;

	BubbleSort(DataSet, Length);

	for (i = 0; i < Length; i++)
		printf("%d ", DataSet[i]);

	printf("\n");

	return 0;
}