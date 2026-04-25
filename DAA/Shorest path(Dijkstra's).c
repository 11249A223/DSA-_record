#include <stdio.h>

#define V 5
#define INF 999999

// Function to find the vertex with minimum distance
int extractMin(int dist[], int visited[])
{
    int min = INF, min_index = -1;

    for (int v = 0; v < V; v++)
    {
        if (!visited[v] && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Dijkstra's Algorithm
void dijkstra(int graph[V][V])
{
    int dist[V], visited[V];

    // Initialize all distances as INF and visited as 0
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    // Source vertex is 0
    dist[0] = 0;

    for (int count = 0; count < V; count++)
    {
        int u = extractMin(dist, visited);

        if (u == -1)
            break;

        visited[u] = 1;

        // Update distances of adjacent vertices
        for (int j = 0; j < V; j++)
        {
            if (graph[u][j] > 0 && !visited[j])
            {
                if (dist[j] > dist[u] + graph[u][j])
                {
                    dist[j] = dist[u] + graph[u][j];
                }
            }
        }
    }

    // Print result
    printf("\nVertex \t Distance from Source (0)\n");
    for (int i = 0; i < V; i++)
    {
        printf("%d --> %d\n", i, dist[i]);
    }
}

int main()
{
    int graph[V][V] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    dijkstra(graph);

    return 0;
}
