#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
int minDistance(int dist[], bool sptSet[], int n)
{

    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[], int n)
{
    printf("-----------------Sortest Distance from source to each vertex---------------\n");
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0, j = 97; i < n; i++, j++)
        printf("%c \t\t %d\n", (char)j, dist[i]);
}

void dijkstra(int graph[10][10], int src, int n)
{
    int dist[n];
    bool sptSet[n];

    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++)
    {

        int u = minDistance(dist, sptSet, n);

        sptSet[u] = true;

        for (int v = 0; v < n; v++)

            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist, n);
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
    char src;
    printf("Enter the starting vertex : - ");
    scanf("%s", &src);
    int s = src - 97;
    dijkstra(g, s, n);
    return 0;
}
