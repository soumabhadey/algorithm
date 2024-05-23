#include <stdio.h>

void print_array(int arr[], int n)
{
	int i;
	for (i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
}

void bubble_sort(int arr[], int n, int *count)
{
	int i, j;
	int pass, interpass;
	int tmp;
	
	pass = interpass = 0;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			*count = *count + 1;
			printf("\ninterpass %d ", ++interpass);
			print_array(arr, n);
		}
		printf("\npass %d ", ++pass);
		print_array(arr, n);
	}
}

int main(void)
{
	int n;
	int i;
	int count;
	
	printf("\nenter length of array");
	scanf("%i", &n);
	
	int arr[n];
	
	printf("\nenter array");
	for (i = 0; i < n; ++i)
	{
		scanf("%i", &arr[i]);
	}
	
	count = 0;
	bubble_sort(arr, n, &count);
	
	printf("\nresult");
	print_array(arr, n);
	printf("\nsteps %d", count);
}

