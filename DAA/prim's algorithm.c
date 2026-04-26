#include <stdio.h> 
#include <stdlib.h> 

#define V 5   // Number of vertices in the graph

// Function to find the vertex with minimum key value
int minKey(int key[], int visited[]) 
{ 
    int min = 999999;     // Initialize minimum value
    int min_index = 0;    // To store index of minimum value

    // Loop through all vertices
    for (int i = 0; i < V; i++) 
    { 
        // Check if vertex is not visited and has smaller key value
        if (!visited[i] && key[i] < min) 
        { 
            min = key[i]; 
            min_index = i; 
        } 
    } 
    return min_index;   // Return index of minimum key
} 

// Function to print the MST and total cost
void printPrimMST(int parent[], int graph[V][V]) 
{ 
    printf("\nPrim's MST:\n"); 
    printf("Edge \tWeight\n"); 

    int total = 0;  // Variable to store total cost

    // Start from 1 because 0 is root
    for (int i = 1; i < V; i++) 
    { 
        // Print edge and its weight
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]); 
        
        // Add weight to total cost
        total += graph[i][parent[i]];
    } 

    // Print total cost of MST
    printf("Total Cost = %d\n", total); 
} 

// Function to implement Prim's Algorithm
void primMST(int graph[V][V]) 
{ 
    int parent[V];   // Array to store MST
    int key[V];      // Key values to pick minimum weight edge
    int visited[V];  // To track visited vertices

    // Initialize all keys as infinite and visited as false
    for (int i = 0; i < V; i++) 
    { 
        key[i] = 999999; 
        visited[i] = 0; 
    } 

    key[0] = 0;      // Start from first vertex
    parent[0] = -1;  // Root node has no parent

    // Loop to construct MST
    for (int count = 0; count < V - 1; count++) 
    { 
        int u = minKey(key, visited);  // Pick minimum key vertex
        visited[u] = 1;                // Mark as visited

        // Update key values of adjacent vertices
        for (int v = 0; v < V; v++) 
        { 
            // Check if there is an edge and vertex is not visited
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) 
            { 
                parent[v] = u;         // Update parent
                key[v] = graph[u][v];  // Update key value
            } 
        } 
    } 

    // Print the resulting MST
    printPrimMST(parent, graph); 
} 

// Main function
int main() 
{ 
    // Adjacency matrix representation of graph
    int graph[V][V] = { 
        {0, 2, 3, 0, 0}, 
        {2, 0, 5, 3, 0}, 
        {3, 5, 0, 0, 4}, 
        {0, 3, 0, 0, 2}, 
        {0, 0, 4, 2, 0}
    }; 

    // Call Prim's MST function
    primMST(graph); 

    return 0; 
}
