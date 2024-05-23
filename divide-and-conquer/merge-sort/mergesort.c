#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void merge(int *, int, int, int);
void merge_sort(int *, int, int);
void print_line_array(int *, int, int);

int main(void)
{
	int n;
	printf("enter number of elements: ");
	scanf("%i", &n);

	int *arr = (int *)malloc(sizeof(int) * n);
	printf("enter elements: ");
	for (int i = 0; i < n; ++i)
	{
		scanf("%i", arr + i);
	}
	merge_sort(arr, 0, n-1);
	printf("sorted: ");
	print_line_array(arr, 0, n-1);
	return 0;
}

void merge(int *arr, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;

	int L[n1 + 1], R[n2 + 1];

	for (int i = 0; i < n1; ++i)
	{
		L[i] = arr[p + i];
	}

	for (int j = 0; j < n2; ++j)
	{
		R[j] = arr[q + 1 + j];
	}

	L[n1] = R[n2] = INT_MAX;

	int i = 0, j = 0;

	for (int k = p; k <= r; ++k)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			++i;
		}
		else
		{
			arr[k] = R[j];
			++j;
		}
	}
}

void merge_sort(int *arr, int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		printf("left: ");
		print_line_array(arr, p, q);
		merge_sort(arr, p, q);
		printf("sorted left: ");
		print_line_array(arr, p, q);
		printf("right: ");
		print_line_array(arr, q+1, r);
		merge_sort(arr, q+1, r);
		printf("sorted right: ");
		print_line_array(arr, q+1, r);
		merge(arr, p, q, r);
		printf("merged: ");
		print_line_array(arr, p, r);
	}
}

void print_line_array(int *arr, int p, int r)
{
	for (int i = p; i <= r; ++i)
	{
		printf("%i ", arr[i]);
	}
	putchar('\n');
}

