#include <stdio.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

void knapsack(int bag_weight, int weights[], int values[], int n)
{
    int K[n + 1][bag_weight + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= bag_weight; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weights[i - 1] <= w)
                K[i][w] = max(values[i - 1] + K[i - 1][w - weights[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    int res = K[n][bag_weight];
    printf("Max profit : - %d\n", res);
    int w = bag_weight;
    printf("Weights selected to be put in bag : -> \n");
    for (int i = n; i > 0 && res > 0; i--)
    {

        if (res == K[i - 1][w])
            continue;
        else
        {
            printf("Item number : %d ", i);          // optimal set containing item number
            printf("Weight = %d\n", weights[i - 1]); // weights to be included
            res = res - values[i - 1];
            w = w - weights[i - 1];
        }
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the number of weights : - ");
    scanf("%d", &n);
    int weights[n];
    int values[n];
    int bag_weight;
    printf("Enter the capacity of the bag : - ");
    scanf("%d", &bag_weight);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the weight of the object : - ");
        scanf("%d", &weights[i]);
        printf("Enter the profit earned from the object : - ");
        scanf("%d", &values[i]);
    }
    knapsack(bag_weight, weights, values, n);
    return 0;
}
