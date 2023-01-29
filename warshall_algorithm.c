#include <stdio.h>
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}
void warshall(int r[10][10], int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                r[i][j] = max(r[i][j], r[i][k] && r[k][j]);
            }
        }
    }
}
void main()
{
    int n;
    printf("Enter the number of vertices : - ");
    scanf("%d", &n);
    int r[10][10];
    printf("Enter the adjacency matrix : \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &r[i][j]);
        }
    }
    warshall(r, n);
    printf("The transitive closure : -\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", r[i][j]);
        }
        printf("\n");
    }
}