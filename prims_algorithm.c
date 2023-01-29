#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int minKey(int key[], bool mstSet[], int n)
{

    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(int parent[], int g[10][10], int n)
{
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++)
        printf("%d - %d \t%d \n", parent[i], i, g[i][parent[i]]);
}

void prims_algo(int g[10][10], int n)
{
    int parent[n];
    int key[n];
    bool mstSet[n];
    for (int i = 0; i < n; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < n - 1; count++)
    {
        int u = minKey(key, mstSet, n);

        mstSet[u] = true;

        for (int v = 0; v < n; v++)

            if (g[u][v] && mstSet[v] == false && g[u][v] < key[v])
                parent[v] = u, key[v] = g[u][v];
    }

    printMST(parent, g, n);
}
int main()
{
    int n;
    printf("Enter the number of vertices : - ");
    scanf("%d", &n);
    int g[10][10];
    printf("Enter the matrix containing the weights for the edges in graph :- \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &g[i][j]);
        }
    }
    printf("The minimum cost spanning Tree : - \n");
    prims_algo(g, n);
    return 0;
}
