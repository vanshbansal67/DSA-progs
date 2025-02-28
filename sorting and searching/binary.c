#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int n, int target)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2; // Avoids overflow

        // Check if the target is present at mid
        if (arr[mid] == target)
            return mid;

        // If the target is smaller, ignore the right half
        if (arr[mid] > target)
            right = mid - 1;
        else
            // If the target is larger, ignore the left half
            left = mid + 1;
    }
    // Return -1 if the target is not found
    return -1;
}

int main()
{
    int n, target;

    // Input array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter %d elements in sorted order:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Input the target value to search
    printf("Enter the target value to search: ");
    scanf("%d", &target);

    // Perform binary search
    int result = binarySearch(arr, n, target);

    // Print the result
    if (result != -1)
        printf("Element found at index %d (0-based indexing)\n", result);
    else
        printf("Element not found in the array\n");

    return 0;
}
