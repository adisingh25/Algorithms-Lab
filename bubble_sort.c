
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void bubbleSort(int *Array, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (Array[j] > Array[j + 1])
            {
                int temp = Array[j];
                Array[j] = Array[j + 1];
                Array[j + 1] = temp;
            }
        }
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
    bubbleSort(Array, n);
    clock_t end = clock();

    printf("\nThe sorted goods are\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", Array[i]);
    }

    double time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\n----------------\n");
    printf("\n The time to sort the goods is :- %lf\n", time);
    printf("\n----------------\n");
}
