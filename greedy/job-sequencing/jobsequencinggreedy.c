#include <stdio.h>
#include <stdlib.h>

typedef struct job
{
    int number;
    int profit;
    int deadline;
} job;

int comparejobprofit(const void *a, const void *b);
int jobsequencing(job *arr, int n, int *sequence, int d);

int main(void)
{
    int n;
    job *arr;
    int i;
    int d;
    int *sequence;
    int profit;

    printf("Enter number of jobs: ");
    scanf_s("%i", &n);

    arr = (job *) malloc(sizeof (job) * n);

    printf("Enter number, profit and deadline of the jobs\n");
    for (i = 0; i < n; ++i)
    {
        scanf_s("%i %i %i", &arr[i].number, &arr[i].profit, &arr[i].deadline);
    }

    qsort(arr, n, sizeof (job), comparejobprofit);

    printf("Enter maximum deadline: ");
    scanf_s("%i", &d);

    sequence = (int *) calloc(n, sizeof (int));

    profit = jobsequencing(arr, n, sequence, d);

    printf("Job queue: ");
    for (i = 0; i < d; ++i)
    {
        if (sequence[i] != 0)
        {
            printf("Job%i ", arr[sequence[i] - 1].number);
        }
    }
    putchar('\n');

    printf("Profit: %i\n", profit);
    
    free(sequence);
    free(arr);
    return 0;
}

int comparejobprofit(const void *a, const void *b)
{
    job *j1 = (job *) a;
    job *j2 = (job *) b;

    if (j1->profit > j2->profit)
    {
        return -1;
    }
    else if (j1->profit < j2->profit)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int jobsequencing(job *arr, int n, int *sequence, int d)
{
    int i;
    int j;
    int profit;

    profit = 0;
    for (i = 0; i < n; ++i)
    {
        for (j = min(d, arr[i].deadline) - 1; j >= 0; --j)
        {
            if (sequence[j] == 0)
            {
                sequence[j] = i + 1;
                profit = profit + arr[i].profit;
                break;
            }
        }
    }

    return profit;
}

