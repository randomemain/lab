#include <limits.h>
#include <stdio.h>

#define V 5

int minDistance(int dist[], int sptSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[], int prev[], int n)
{
    printf("Vertex Distance from Source Path\n");
    for (int i = 1; i < V; i++)
    {
        printf("%d \t\t %d \t\t ", i, dist[i]);

        int j = i;
        while (prev[j] != -1)
        {
            printf("%d <- ", j);
            j = prev[j];
        }

        printf("%d\n", j);
    }
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V], prev[V];
    int sptSet[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = 0, prev[i] = -1;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet);

        sptSet[u] = 1;

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u;
            }
    }

    printSolution(dist, prev, V);
}

int main()
{
    int graph[V][V];

    printf("Enter the graph (as an adjacency matrix):\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    int src;
    printf("Enter the source vertex: ");
    scanf("%d", &src);

    dijkstra(graph, src);

    return 0;
}
