#include <stdio.h>
#include <stdlib.h>

void build_max_heap(int *arr, int n, int *heap_size);
void heap_sort(int *arr, int n);
int left(int index);
void max_heapify(int *arr, int *heap_size, int index);
void print_array(int *arr, int l, int r);
int right(int index);
void swap(int *a, int *b);

int main(void)
{
    int n;
    int *arr;
    int i;

    puts("Enter length of array");
    scanf("%i", &n);

    arr = (int *)malloc(sizeof(int) * n);

    puts("Enter elements of array");
    for (i = 0; i < n; ++i)
    {
        scanf("%i", arr + i);
    }

    heap_sort(arr, n);

    puts("Sorted array");
    print_array(arr, 0, n - 1);

    return 0;
}

void build_max_heap(int *arr, int n, int *heap_size)
{
    int i;

    *heap_size = n;

    for (i = (n - 2) / 2; i >= 0; --i)
    {
        max_heapify(arr, heap_size, i);
    }
}

void heap_sort(int *arr, int n)
{
    int i;
    int heap_size;

    build_max_heap(arr, n, &heap_size);

    for (i = n - 1; i >= 1; --i)
    {
        printf("Max-heap: ");
        print_array(arr, 0, heap_size - 1);
        putchar('\n');

        swap(arr, arr + i);
        --heap_size;

        printf("Delete first: ");
        print_array(arr, 0, heap_size - 1);
        putchar('\n');

        max_heapify(arr, &heap_size, 0);
    }
}

int left(int index)
{
    return (2 * index + 1);
}

void max_heapify(int *arr, int *heap_size, int index)
{
    int l;
    int r;
    int largest;

    l = left(index);
    r = right(index);

    if (l<*heap_size &&*(arr + l)> * (arr + index))
    {
        largest = l;
    }
    else
    {
        largest = index;
    }

    if (r<*heap_size &&*(arr + r)> * (arr + largest))
    {
        largest = r;
    }

    if (largest != index)
    {
        swap(arr + index, arr + largest);
        max_heapify(arr, heap_size, largest);
    }
}

void print_array(int *arr, int l, int r)
{
    int i;

    for (i = l; i <= r; ++i)
    {
        printf("%i ", *(arr + i));
    }
}

int right(int index)
{
    return (2 * index + 2);
}

void swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}
