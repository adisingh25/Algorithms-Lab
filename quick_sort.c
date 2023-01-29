#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int l, int h)
{
    int pivot = A[l];
    int i = l, j = h;
    do
    {
        do
        {
            i++;
        } while (A[i] <= pivot);
        do
        {
            j--;
        } while (A[j] > pivot);
        if (i < j)
        {
            swap(&A[i], &A[j]);
        }
    } while (i < j);
    swap(&A[l], &A[j]);
    return j;
}

void QuickSort(int A[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = partition(A, l, h);
        QuickSort(A, l, j);
        QuickSort(A, j + 1, h);
    }
}

int main()
{
    int n;
    printf("Enter the number of files : ");
    scanf("%d", &n);
    int Array[n];
    for (int i = 0; i < n; i++)
    {
        Array[i] = rand() % 1000;
    }

    printf("ID's of the files are : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", Array[i]);
    }

    clock_t start = clock();
    QuickSort(Array, 0, n - 1);
    clock_t end = clock();

    printf("\nFiles in sorted order based on their ID's : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", Array[i]);
    }

    double time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nThe time taken to sort the books is :- %lf\n", time);
}
