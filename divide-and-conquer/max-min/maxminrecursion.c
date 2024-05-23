#include <stdio.h>
#include <stdlib.h>

void max_min(int *arr, int i, int j, int *max, int *min);

int main()
{
    int n;
    int *arr;
    int i;
    int max;
    int min;

    puts("Enter length of array");
    scanf("%i", &n);

    arr = (int *)malloc(sizeof(int) * n);

    puts("Enter elements of array");
    for (i = 0; i < n; ++i)
    {
        scanf("%i", arr + i);
    }

    max_min(arr, 0, n - 1, &max, &min);

    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);

    return 0;
}

void max_min(int *arr, int i, int j, int *max, int *min)
{
    int mid;
    int left_max;
    int right_max;
    int left_min;
    int right_min;

    // if (i > j)
    // {
    //     return;
    // }
    // else
    if (i == j)
    {
        *max = *min = *(arr + 0);
    }
    else if (i == j - 1)
    {
        if (*(arr + i) < *(arr + j))
        {
            *max = *(arr + j);
            *min = *(arr + i);
        }
        else
        {
            *max = *(arr + i);
            *min = *(arr + j);
        }
    }
    else
    {
        mid = (i + j) / 2;

        max_min(arr, i, mid, &left_max, &left_min);

        max_min(arr, mid + 1, j, &right_max, &right_min);

        *max = (left_max > right_max) ? left_max : right_max;
        *min = (left_min < right_min) ? left_min : right_min;
    }
}