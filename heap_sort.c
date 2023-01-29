
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *a, int *b)
{

    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void heapify(int array[], int n, int i)
{

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && array[left] > array[largest])
    {

        largest = left;
    }

    if (right < n && array[right] > array[largest])
    {

        largest = right;
    }

    if (largest != i)
    {

        swap(&array[i], &array[largest]);

        heapify(array, n, largest);
    }
}

void heapSort(int array[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
    {

        heapify(array, n, i);
    }

    //printf("Resumes Heapfied  :  \n");
    //printArray(array, n);

    for (int i = n - 1; i >= 0; i--)
    {

        swap(&array[0], &array[i]);

        heapify(array, i, 0);
    }
}



int main()
{
    int n;
    printf("Enter the number of resumes :- ");
    scanf("%d", &n);
    int array[n];
    // printf("Enter the rankings of the resumes : - ");
    for (int i = 0; i < n; i++)
    {
        array[i] = rand() % 1000;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", &array[i]);
    // }
    clock_t start = clock();
    heapSort(array, n);
    clock_t end = clock();
    //printf("Sorted resumes based on ranking  :  \n");
    //printArray(array, n);
    double time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\n----------------\n");
    printf("\nThe time to sort the goods is :- %lf\n", time);
    printf("\n----------------\n");
    return 0;
}
