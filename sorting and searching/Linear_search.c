#include <stdio.h>
int main()
{
    int n;
    int target = 0;
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("enter the element to search;");
    scanf("%d", &n);
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] == n)
        {
            target = 1;
        }
    }
    if (target == 1)
    {
        printf("element found");
    }
    else
    {
        printf("element not found");
    }
    return 0;
}