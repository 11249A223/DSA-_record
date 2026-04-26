#include <stdio.h>

// Function to calculate Fibonacci using recursion
int fib(int n)
{
    // Base case: fib(0) = 0
    if(n == 0)
    {
        return 0;
    }

    // Base case: fib(1) = 1
    if(n == 1)
    {
        return 1;
    }

    // Recursive case: fib(n) = fib(n-1) + fib(n-2)
    return fib(n-1) + fib(n-2);
}

int main()
{
    int n, result;

    // Take input from user
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Check for invalid input
    if(n < 0)
    {
        printf("Invalid number");
        return 0;
    }

    // Call fibonacci function
    result = fib(n);

    // Print result
    printf("Fibonacci term :%d", result);

    return 0;
}
