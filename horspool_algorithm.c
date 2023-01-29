#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 500
int t[MAX];
int comparison = 0;
void shifttable(char pattern[])
{
    int i, j, m;
    m = strlen(pattern);
    for (i = 0; i < MAX; i++)
        t[i] = m;
    for (j = 0; j < m - 1; j++)
        t[pattern[j]] = m - 1 - j;
}

int horspool(char text[], char pattern[])
{
    int i, j, k, m, n;
    n = strlen(text);
    m = strlen(pattern);
    i = m - 1;
    while (i < n)
    {
        k = 0;
        while ((k < m) && (pattern[m - 1 - k] == text[i - k]))
        {
            k++;
            comparison++;
        }
        if (k == m)
            return (i - m + 1);
        else
        {
            i += t[text[i]];
            comparison++;
        }
    }
    return -1;
}

int main()
{
    char text[50];
    char pattern[50];
    int pos;
    printf("Enter the text : - ");
    fgets(text, 100, stdin);
    printf("Enter the pattern to be searched : - ");
    scanf("%s", pattern);
    shifttable(pattern);
    pos = horspool(text, pattern);
    if (pos >= 0)
        printf("\nThe desired pattern was found starting from position %d.", pos + 1);
    else
        printf("\nThe pattern was not found in the text.\n");
    printf("\nTotal number of comparisons is %d.\n", comparison);
}




