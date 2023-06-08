#include <stdio.h>

#define MAX_NODES 10

int a[MAX_NODES][MAX_NODES], n;

void adj(int k)
{
    int i, j;
    printf("Adjacent nodes of the root node:\n");
    printf("%d\n", k);
    for (j = 1; j <= n; j++)
        if (a[k][j] == 1 || a[j][k] == 1)
            printf("%d\t", j);
    printf("\n");
    for (i = 1; i <= n; i++)
    {
        if (a[k][i] == 0 && a[i][k] == 0 && i != k)
            printf("%d\t", i);
    }
    printf("\n");
}

int main()
{
    int i, j, root;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("Enter the connection from %d to %d: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the root node: ");
    scanf("%d", &root);
    adj(root);
    return 0;
}
