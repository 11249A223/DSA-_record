#include <stdio.h> 

#define V 5  // Number of vertices
#define E 6  // Number of edges

int parent[V]; // Array to store parent (for union-find)

// Function to find leader (root) of a set
int findLeader(int v) 
{ 
    // Traverse until we find the parent of itself
    while (parent[v] != v) 
        v = parent[v]; 
    return v; 
} 

// Function to merge two sets
void mergeSets(int u, int v) 
{ 
    int a = findLeader(u); // Find leader of u
    int b = findLeader(v); // Find leader of v
    parent[a] = b;         // Merge sets
}

// Function to sort edges based on weight (ascending order)
void sortEdges(int edges[E][3]) 
{ 
    // Using bubble sort (simple method)
    for (int i = 0; i < E - 1; i++) 
    { 
        for (int j = 0; j < E - i - 1; j++) 
        { 
            // Compare weights
            if (edges[j][2] > edges[j + 1][2]) 
            { 
                // Swap entire edge (u, v, weight)
                for (int k = 0; k < 3; k++) 
                { 
                    int temp = edges[j][k]; 
                    edges[j][k] = edges[j + 1][k]; 
                    edges[j + 1][k] = temp; 
                } 
            } 
        } 
    } 
} 

// Function to implement Kruskal's Algorithm
void kruskal(int edges[E][3]) 
{ 
    sortEdges(edges); // First sort edges by weight

    // Initialize each vertex as its own parent
    for (int i = 0; i < V; i++) 
        parent[i] = i; 

    int count = 0; // Number of edges selected
    int cost = 0;  // Total cost of MST

    printf("Selected Edges:\n"); 

    // Go through all edges
    for (int i = 0; i < E; i++) 
    { 
        int u = edges[i][0]; // Source vertex
        int v = edges[i][1]; // Destination vertex
        int w = edges[i][2]; // Weight of edge

        // Check if adding this edge forms a cycle
        if (findLeader(u) != findLeader(v)) 
        { 
            // If no cycle, include the edge in MST
            printf("%d -- %d (Weight: %d)\n", u, v, w); 
            mergeSets(u, v); // Merge the sets
            cost += w;       // Add weight to total cost
            count++;         // Increase edge count
        }

        // Stop when MST has (V-1) edges
        if (count == V - 1) 
            break; 
    } 

    // Print total cost of MST
    printf("Total Cost: %d\n", cost); 
} 

int main() 
{ 
    // Edge list: {u, v, weight}
    int edges[E][3] = { 
        {0, 1, 2}, {0, 2, 3}, {1, 2, 5}, 
        {1, 3, 3}, {2, 4, 4}, {3, 4, 2}
    }; 

    // Call Kruskal's algorithm
    kruskal(edges); 

    return 0; 
}
