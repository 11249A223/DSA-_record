#include <stdio.h>

// Function to implement First Fit bin packing algorithm
void firstFit(int items[], int n, int capacity) {
    int bin[n];        // Array to store remaining capacity of each bin
    int binCount = 0;  // Number of bins used

    printf("\nExecuting First Fit Algorithm\n");

    // Initially all bins are empty (0 means not used yet)
    for (int i = 0; i < n; i++) {
        bin[i] = 0;
    }

    // Loop through each item
    for (int i = 0; i < n; i++) {

        // If item is larger than bin capacity, skip it
        if (items[i] > capacity) {
            printf("Item %d with size %d cannot be placed in any bin\n", i + 1, items[i]);
            continue;
        }

        int placed = 0; // Flag to check if item is placed

        // Check each existing bin
        for (int j = 0; j < binCount; j++) {
            // If item fits in current bin
            if (bin[j] >= items[i]) {
                bin[j] -= items[i]; // Reduce remaining space
                printf("Item %d placed in Bin %d\n", items[i], j + 1);
                placed = 1;
                break; // Stop after placing in first suitable bin
            }
        }

        // If item is not placed in any bin, create a new bin
        if (!placed) {
            bin[binCount] = capacity;      // Assign full capacity
            bin[binCount] -= items[i];     // Place item in new bin
            printf("Item %d placed in Bin %d\n", items[i], binCount + 1);
            binCount++; // Increase bin count
        }
    }

    // Print total number of bins used
    printf("Total bins used = %d\n", binCount);
}

int main() {
    int n, capacity;

    // Input number of items
    printf("Enter number of items: ");
    scanf("%d", &n);

    int items[n]; // Array to store item sizes

    // Input item sizes
    printf("Enter item sizes:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d", &items[i]);
    }

    // Input bin capacity
    printf("Enter bin capacity: ");
    scanf("%d", &capacity);

    // Call First Fit function
    firstFit(items, n, capacity);

    return 0;
}
