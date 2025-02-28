#include <stdio.h>
int Binarysearch(int arr[], int n, int target);
int main()
{
    int target, arr[100], n, result;
    printf("enter the no. of element in an array ; ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("enter the %d element; ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("enter the element to search;");
    scanf("%d", &target);
    result = Binarysearch(arr, n, target);
    if (result != -1)
    {
        printf("element %d found at index %d!!", target, result);
    }
    else
    {
        printf("element not found");
    }
    return 0;
}

int Binarysearch(int arr[], int n, int target)
{
    int beg, end, mid;
    beg = 0;
    end = arr[n - 1];
    while (beg < end)
    {
        mid = beg + (end - beg) / 2;
        if (target == arr[mid])
        {
            return mid;
        }
        else if (target < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            beg = mid + 1;
        }
    }
    return -1; // target not found
}