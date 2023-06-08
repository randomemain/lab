#include <stdio.h>

#define MAX_NODES 10

void findAdjacentNodes(int root, int adjacencyMatrix[MAX_NODES][MAX_NODES], int n)
{
    int i, j;
    printf("Adjacent nodes of the root node:\n");
    printf("%d\n", root);

    for (j = 0; j < n; j++)
    {
        if (adjacencyMatrix[root][j] == 1 || adjacencyMatrix[j][root] == 1)
        {
            printf("%d\t", j);
        }
    }
    printf("\n");

    for (i = 0; i < n; i++)
    {
        if (i != root && adjacencyMatrix[root][i] == 0 && adjacencyMatrix[i][root] == 0)
        {
            printf("%d\t", i);
        }
    }
    printf("\n");
}

int main()
{
    int adjacencyMatrix[MAX_NODES][MAX_NODES];
    int n, i, j, root;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("Enter the connection from %d to %d: ", i, j);
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    printf("Enter the root node: ");
    scanf("%d", &root);

    findAdjacentNodes(root, adjacencyMatrix, n);

    return 0;
}
