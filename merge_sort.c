#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Merge(int Array[], int l, int mid, int h)
{
    int i = l, j = mid + 1, k = l;
    int B[h + 1];
    while (i <= mid && j <= h)
    {
        if (Array[i] < Array[j])
        {
            B[k++] = Array[i++];
        }
        else
        {
            B[k++] = Array[j++];
        }
    }
    for (; i <= mid; i++)
    {
        B[k++] = Array[i];
    }
    for (; j <= h; j++)
    {
        B[k++] = Array[j];
    }
    for (int i = l; i <= h; i++)
    {
        Array[i] = B[i];
    }
}

void MergeSort(int Array[], int l, int h)
{   
    int mid;
    if (l < h)
    {
        mid = (l + h) / 2;
        MergeSort(Array, l, mid);
        MergeSort(Array, mid + 1, h);
        Merge(Array, l, mid, h);
    }
}

int main()
{   

    int n;
    printf("Enter the number of ISBN of the books : ");
    scanf("%d", &n);
    int Array[n];
    for (int i = 0; i < n; i++)
    {
        Array[i] = rand() % 1000;
    }

    // printf("Books with their ISBN : \n");
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", Array[i]);
    // }

    clock_t start = clock();
    MergeSort(Array, 0, n - 1);
    clock_t end = clock();

    // printf("\nBooks in sorted order based on their ISBN : \n");
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", Array[i]);
    // }

    double time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nThe time taken to sort the books is :- %lf\n", time);
}