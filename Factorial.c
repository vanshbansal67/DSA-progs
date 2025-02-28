// #include <stdio.h>
// int factorial(int n);
// int main()
// {
//     int n;
//     printf("enter the no. : ");
//     scanf("%d", &n);
//     int result;
//     result = factorial(n);
//     printf("%d", result);
//     return 0;
// }
// int factorial(int n)
// {
//     if (n == 1)
//     {
//         return 1;
//     }
//     return n * factorial(n - 1);
// }

#include <Stdio.h>
int Factorial(int n, int acc);
int main()
{
    int n, result;
    printf("enter the no. ");
    scanf("%d", &n);
    result = Factorial(n, 1);
    printf("%d", result);
    return 0;
}

int Factorial(int n, int acc)
{
    if (n == 0)
    {
        return acc;
    }
    return Factorial(n - 1, n * acc);
}