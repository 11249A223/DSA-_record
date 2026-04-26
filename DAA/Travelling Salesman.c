#include <stdio.h>
#include <limits.h>

#define MAXN 15     // Maximum number of cities
#define INF INT_MAX // Represent infinity

int n;                     // Number of cities
int d[MAXN][MAXN];        // Cost matrix
int dp[MAXN][1 << MAXN];  // DP table (memoization)

// Recursive function to find minimum cost
int g(int i, int s)
{
    // If no cities left to visit, return cost to go back to start (city 0)
    if (s == 0)
        return d[i][0];

    // If already calculated, return stored value
    if (dp[i][s] != -1)
        return dp[i][s];

    int min_cost = INF; // Initialize minimum cost

    // Try visiting all cities in set 's'
    for (int k = 0; k < n; k++)
    {
        // Check if city k is in set s
        if (s & (1 << k))
        {
            // Cost = current to k + remaining cities
            int cost = d[i][k] + g(k, s & ~(1 << k));

            // Update minimum cost
            if (cost < min_cost)
                min_cost = cost;
        }
    }

    // Store result in dp table and return
    return dp[i][s] = min_cost;
}

int main()
{
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    // Input cost matrix
    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &d[i][j]);
        }
    }

    // Initialize DP table with -1 (not calculated)
    for (int i = 0; i < n; i++)
    {
        for (int s = 0; s < (1 << n); s++)
        {
            dp[i][s] = -1;
        }
    }

    int s = 0; // Set to store cities to visit

    // Add all cities except starting city (0) to set
    for (int i = 1; i < n; i++)
    {
        s |= (1 << i);
    }

    // Print initial set value (for understanding bitmask)
    printf("S value is: %d\n", s);

    // Start from city 0 with all other cities in set
    int result = g(0, s);

    // Print minimum travelling cost
    printf("Minimum travelling cost: %d\n", result);

    return 0;
}
