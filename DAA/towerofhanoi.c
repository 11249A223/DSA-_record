#include<stdio.h>

// Function to solve Tower of Hanoi problem
void TOH(int n, char s, char t, char d)
{
    // Base case: if only one disk, move it directly
    if(n == 1)
    {
        printf("move %d from %c to %c :\n", n, s, d);
        return;
    }

    // Step 1: Move n-1 disks from source to temporary using destination
    TOH(n-1, s, d, t);

    // Step 2: Move the largest disk from source to destination
    printf("move %d from %c to %c:\n", n, s, d);

    // Step 3: Move n-1 disks from temporary to destination using source
    TOH(n-1, t, s, d);
}

int main()
{
    int n;

    // Ask user for number of disks
    printf("enter number of disks:");
    scanf("%d", &n);

    // Call Tower of Hanoi function
    // s = source, t = temporary, d = destination
    TOH(n, 's', 't', 'd');
}
