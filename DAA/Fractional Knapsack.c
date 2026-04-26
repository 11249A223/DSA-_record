#include <stdio.h>

// Structure to store item details
struct Item {
    int Weight;   // वजन (weight of item)
    int Value;    // value of item
    float PPW;    // Profit Per Weight (value/weight ratio)
};

// Function to sort items based on profit per weight (descending order)
void sort(struct Item items[], int n) {
    struct Item temp;

    // Bubble sort (simple sorting method)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if next item has higher ratio
            if (items[j].PPW < items[j + 1].PPW) {
                temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }

    // Print sorted items
    printf("Items sorted by value/weight ratio:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: Weight = %d, Value = %d, Ratio = %.2f\n", 
                i + 1, items[i].Weight, items[i].Value, items[i].PPW);
    }
}

int main() {
    int n;
    float capacity;

    // Input number of items
    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n]; // Array of items

    // Input weight and value of each item
    printf("Enter weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].Weight, &items[i].Value);

        // Calculate profit per weight ratio
        items[i].PPW = (float)items[i].Value / items[i].Weight;
    }

    // Input knapsack capacity
    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    // Sort items based on ratio (greedy step)
    sort(items, n);

    float totalProfit = 0.0; // Store maximum profit

    // Traverse items and add them to knapsack
    for (int i = 0; i < n; i++) {

        // If full item can be taken
        if (capacity >= items[i].Weight) {
            totalProfit += items[i].Value;   // Add full value
            capacity -= items[i].Weight;     // Reduce capacity
        } 
        else {
            // Take only fraction of item
            totalProfit += items[i].PPW * capacity;
            capacity = 0; // Knapsack is full now
            break;
        }
    }

    // Print maximum profit
    printf("Maximum profit = %.2f\n", totalProfit);

    return 0;
}
