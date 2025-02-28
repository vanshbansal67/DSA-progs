#include <stdio.h>
int factorial(int n);
int main()
{
    int n;
    printf("enter the no. : ");
    scanf("%d", &n);
    int result;
    result = factorial(n);
    printf("%d", result);
    return 0;
}
int factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}