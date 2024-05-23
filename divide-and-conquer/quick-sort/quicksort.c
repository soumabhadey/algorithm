#include <stdio.h>
#include <stdlib.h>

int partition(int *, int, int);
void print_line_array(int *, int, int);
void quick_sort(int *, int, int);
void swap(int *, int *);

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
	
	quick_sort(arr, 0, n - 1);
	
	printf("sorted: ");
	print_line_array(arr, 0, n - 1);

	return 0;
}

int partition(int *arr, int p, int r)
{
	int x = arr[r];
	int i = p - 1;
	for (int j = p; j < r; ++j)
	{
		if (arr[j] <= x)
		{
			++i;
			swap(arr + i, arr + j);
		}
	}
	swap(arr + i + 1, arr + r);
	return (i + 1);
}

void print_line_array(int *arr, int p, int r)
{
	for (int i = p; i <= r; ++i)
	{
		printf("%i ", arr[i]);
	}
	putchar('\n');
}

void quick_sort(int *arr, int p, int r)
{
	if (p < r)
	{
		int q = partition(arr, p, r);
		printf("pivot: %i\n", arr[q]);
		printf("left: ");
		print_line_array(arr, p, q - 1);
		printf("right: ");
		print_line_array(arr, q + 1, r);
		quick_sort(arr, p, q - 1);
		quick_sort(arr, q + 1, r);
		printf("sorted left: ");
		print_line_array(arr, p, q - 1);
		printf("sorted right: ");
		print_line_array(arr, q + 1, r);
	}
}

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

