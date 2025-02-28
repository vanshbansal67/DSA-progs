#include <stdio.h>
int main()
{
    int found = 0, n, i, target, arr[100];
    printf("enter the no. of element in a array ; ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("enter %d element;", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("enter the element to search; ");

    scanf("%d", &target);
    for (int i = 0; i < n; i++)
    {
        if (target == arr[i])
        {
            found = 1;
            break;
        }
    }
    if (found == 0)
    {
        printf("element not found");
    }
    else
    {
        printf("element found");
    }
    return 0;
}