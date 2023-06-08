#include <stdio.h>

#define MAX_NODES 20

struct node
{
    unsigned int dist[MAX_NODES];
    unsigned int from[MAX_NODES];
};

void calculateShortestPaths(struct node *rt, int dmat[MAX_NODES][MAX_NODES], int n)
{
    int i, j, k, count;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            rt[i].dist[j] = dmat[i][j];
            rt[i].from[j] = j;
        }
    }

    count = n;
    while (count--)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                for (k = 0; k < n; k++)
                {
                    if (rt[i].dist[j] > dmat[i][k] + rt[k].dist[j])
                    {
                        rt[i].dist[j] = rt[i].dist[k] + rt[k].dist[j];
                        rt[i].from[j] = k;
                    }
                }
            }
        }
    }
}

void printRouterState(const struct node *rt, int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        printf("\n\nState value for router %d:\n", i + 1);
        for (j = 0; j < n; j++)
        {
            printf("Node %d via %d Distance %d\n", j + 1, rt[i].from[j] + 1, rt[i].dist[j]);
        }
    }
}

int main()
{
    int dmat[MAX_NODES][MAX_NODES];
    struct node rt[MAX_NODES];
    int n, i, j;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &dmat[i][j]);
        }
    }

    calculateShortestPaths(rt, dmat, n);

    printRouterState(rt, n);

    return 0;
}
