#include <stdio.h>
int main()
{
    int n, count = 0;
    int arr[10] = {2, 4, 6, 2, 4, 2, 2, 2, 7, 9};
    printf("enter the element;");
    scanf("%d", &n);
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] == n)
        {
            count++;
        }
    }
    if (count != 0)
    {
        printf("%d occurs %d time;", n, count);
    }
    else
    {
        printf("element is not present in the array");
    }
    return 0;
}