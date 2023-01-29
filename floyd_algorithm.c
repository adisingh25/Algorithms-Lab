#include <stdio.h>

void floyd(int r[10][10], int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (r[i][k] + r[k][j] < r[i][j])
                {
                    r[i][j] = r[i][k] + r[k][j];
                }
            }
        }
    }
}

void main()
{
    int n;
    printf("Enter the number of cities : - ");
    scanf("%d", &n);
    int r[10][10];
    printf("Enter the distance matrix : \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &r[i][j]);
        }
    }  

    floyd(r, n);

    printf("The shortest distance matrix : -\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", r[i][j]);
        }
        printf("\n");
    }
}