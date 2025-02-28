#include <stdio.h>

// Recursive function to solve Tower of Hanoi
void towerOfHanoi(int n, char source, char destination, char auxiliary)
{
    // Base case: If there's only one disk, move it directly
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    // Step 1: Move top (n-1) disks from source to auxiliary peg
    towerOfHanoi(n - 1, source, auxiliary, destination);

    // Step 2: Move the nth disk from source to destination peg
    printf("Move disk %d from %c to %c\n", n, source, destination);

    // Step 3: Move the (n-1) disks from auxiliary to destination peg
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

// Main function
int main()
{
    int n = 3; // Number of disks
    printf("Steps to solve Tower of Hanoi with %d disks:\n", n);
    towerOfHanoi(n, 'A', 'C', 'B'); // Source: A, Destination: C, Auxiliary: B
    return 0;
}
