#include <stdio.h>
#include <stdlib.h>

typedef struct item
{
    int weight;
    int profit;
    double ratio;
    double quantity;
} item;

int compareitems(const void *a, const void *b);
double fillknapsack(item arr[], int n, int w);

int main()
{
    int n;
    int i;
    int w;
    double profit;

    printf("enter number of items: ");
    scanf_s("%i", &n);

    item* arr = (item*)malloc(n * sizeof(item));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter weight and profit of items\n");

    for (i = 0; i < n; ++i)
    {
        scanf_s("%i %i", &arr[i].weight, &arr[i].profit);
        arr[i].ratio = arr[i].profit * 1.0 / arr[i].weight;
        arr[i].quantity = 0;
    }

    qsort(arr, n, sizeof(item), compareitems);

    printf("Enter capacity of knapsack: ");
    scanf_s("%i", &w);

    profit = fillknapsack(arr, n, w);

    printf("Profit: %.2lf", profit);

    free(arr);
    return 0;
}

int compareitems(const void *a, const void *b)
{
    item *i1 = (item *)a;
    item *i2 = (item *)b;

    if (i1->ratio < i2->ratio)
    {
        return 1;
    }
    else if (i1->ratio > i2->ratio)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

double fillknapsack(item arr[], int n, int w)
{
    int i;
    double profit;

    profit = 0;
    for (i = 0; i < n; i++)
    {
        if (w == 0)
        {
            break;
        }
        else
        {
            if (arr[i].weight <= w)
            {
                arr[i].quantity = 1;
                w = w - arr[i].weight;
                profit = profit + arr[i].profit;
            }
            else
            {
                arr[i].quantity = w * 1.0 / arr[i].weight;
                w = 0;
                profit = profit + arr[i].profit * arr[i].quantity;
                break;
            }
        }
    }

    return profit;
}
