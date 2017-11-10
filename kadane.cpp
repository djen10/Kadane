#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#define MAX 1000

int n3(double* arr, double* start, double* finish, int n)
{
	double sum = 0, total = 0;

	int i;

	*finish = -1;

	int local_start = 0;

	for (i = 0; i < n; ++i)
	{
		sum += arr[i];
		if (sum < 0)
		{
			sum = 0;
			local_start = i + 1;
		}
		else if (sum > total)
		{
			total = sum;
			*start = local_start;
			*finish = i;
		}
	}
	if (*finish != -1)
		return total;

	total = arr[0];
	*start = *finish = 0;

	for (i = 1; i < n; i++)
	{
		if (arr[i] > total)
		{
			total = arr[i];
			*start = *finish = i;
		}
	}


	return total;
}

void findMaxSum(double **M, int row, int col)
{
	int maxSum = INT_MIN, finalLeft, finalRight, finalTop, finalBottom;

	int left, right, i;
	double temp[MAX], sum, start, finish;



	for (left = 0; left < col; ++left)
	{
		memset(temp, 0, sizeof(temp));

		for (right = left; right < col; ++right)
		{
			for (i = 0; i < row; ++i)
				temp[i] += M[i][right];
			sum = n3(temp, &start, &finish, row);

			if (sum > maxSum)
			{
				maxSum = sum;
				finalLeft = left;
				finalRight = right;
				finalTop = start;
				finalBottom = finish;


			}
		}
	}

	printf("(Top, Left) (%d, %d)\n", finalTop, finalLeft);
	printf("(Bottom, Right) (%d, %d)\n", finalBottom, finalRight);
	printf("Max sum is: %d\n", maxSum);
}

void findMinSum(double **M, int col, int row)
{
	int minSum = INT_MIN, finalLeft, finalRight, finalTop, finalBottom;

	int left, right, i;
	double temp[MAX], sum, start, finish;


	for (left = 0; left < col; ++left)
	{
		memset(temp, 0, sizeof(temp));

		for (right = left; right < col; ++right)
		{
			for (i = 0; i < row; ++i)
				temp[i] += -M[i][right];

			sum = n3(temp, &start, &finish, row);
			if (sum > -minSum)
			{
				minSum = -(sum);
				finalLeft = left;
				finalRight = right;
				finalTop = start;
				finalBottom = finish;
			}
		}
	}

	printf("(Top, Left) (%d, %d)\n", finalTop, finalLeft);
	printf("(Bottom, Right) (%d, %d)\n", finalBottom, finalRight);
	printf("Min sum is: %d\n", minSum);
}

int main()
{
	int num;
	double **M = NULL;
	int test;

	scanf_s("%d", &num, sizeof(num));


	M = (double**)malloc(sizeof(double*) * num);

	for (int i = 0; i < num; i++)
		M[i]= (double*)malloc(sizeof(double) * num);

	
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			scanf_s("%d", &test);
			M[i][j] = test;
		}
	}

	getchar();
	findMaxSum(M, num, num);
	findMinSum(M, num, num);
	getchar();
	return 0;
}
