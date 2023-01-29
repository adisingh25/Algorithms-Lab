#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void SelectionSort(int *Array, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (Array[j] < Array[min_index])
            {
                min_index = j;
            }
        }
        int temp = Array[i];
        Array[i] = Array[min_index];
        Array[min_index] = temp;
    }
}


int main()
{
    int n;
    printf("\nEnter the number of goods:\t");
    scanf("%d", &n);
    int Array[n];
    for (int i = 0; i < n; i++)
    {
        Array[i] = rand() % 1000;
    }

    clock_t start = clock();
    SelectionSort(Array, n);
    clock_t end = clock();

    double time = ((double)(end - start)) / CLOCKS_PER_SEC;
    // printf("\nThe sorted goods are\n");
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", Array[i]);
    // }

    printf("\n The time to sort the goods is :- %lf\n", time);
}