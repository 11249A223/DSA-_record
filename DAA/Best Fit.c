#include <stdio.h>

// Function to implement Best Fit bin packing algorithm
void bestFit(int items[], int n, int capacity)
{
    printf("\nBest Fit Algorithm\n");

    int bin[n];        // Array to store remaining capacity of bins
    int binCount = 0;  // Keeps track of number of bins used

    // Initially, all bins are empty so set capacity
    for (int i = 0; i < n; i++)
    {
        bin[i] = capacity;
    }

    // Loop through each item
    for (int i = 0; i < n; i++) 
    {
        int bestIndex = -1;          // Stores index of best bin
        int minSpace = capacity + 1; // Minimum leftover space after placing item

        // Check all existing bins to find the best fit
        for (int j = 0; j < binCount; j++)
        {
            // Check if item fits and leaves minimum space
            if (bin[j] >= items[i] && (bin[j] - items[i]) < minSpace) 
            {
                bestIndex = j;
                minSpace = bin[j] - items[i];
            }
        }

        // If a suitable bin is found
        if (bestIndex != -1)
        {
            bin[bestIndex] -= items[i]; // Reduce remaining capacity
            printf("Item %d (Weight: %d) placed in Bin %d\n", i + 1, items[i], bestIndex + 1);
        } 
        else 
        {
            // If no bin fits, create a new bin
            bin[binCount] = capacity - items[i];
            printf("Item %d (Weight: %d) placed in Bin %d\n", i + 1, items[i], binCount + 1);
            binCount++; // Increase bin count
        }
    }

    // Print total bins used
    printf("Total bins used = %d\n", binCount);
}

int main() 
{
    int n, capacity;

    // Input number of items
    printf("Enter number of items: ");
    scanf("%d", &n);

    int items[n]; // Array to store item sizes

    // Input bin capacity
    printf("Enter bin capacity: ");
    scanf("%d", &capacity);

    printf("Enter item sizes:\n");

    // Input each item size
    for (int i = 0; i < n; i++) 
    {
        int itemSize;
        printf("Item %d: ", i + 1);
        scanf("%d", &itemSize);

        // Check if item size is valid
        if (itemSize <= capacity) 
        {
            items[i] = itemSize;
        } 
        else 
        {
            // If invalid, ask user again
            printf("Item size exceeds bin capacity. Please enter a valid size.\n");
            i--; 
        }
    }

    // Call best fit function
    bestFit(items, n, capacity);

    return 0;
}
