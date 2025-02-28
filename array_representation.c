#include <stdio.h>
int main()
{
    int n;
    printf("enter the size of array ;");
    scanf("%d", &n);
    int array[n];
    for (int i = 0; i < n; i++)
    {
        printf("enter %d element of array; ", i + 1);
        scanf("%d", &array[i]);
    }
    printf("\n*********************************************\n");
    printf("THE ARRAY YOU MADE IS BELOW !!!!\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}