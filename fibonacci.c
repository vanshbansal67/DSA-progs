// with recursion
// #include <stdio.h>
// int fibonacci(int n);
// int main()
// {
//     int n;
//     printf("enter the no. of terms; ");
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d  ", fibonacci(i));
//     }
//     return 0;
// }
// int fibonacci(int n)
// {
//     if (n == 0)
//     {
//         return 0;
//     }
//     else if (n == 1)
//     {
//         return 1;
//     }

//     return fibonacci(n - 1) + fibonacci(n - 2);
// }

// without recursion
#include <stdio.h>
int main()
{
    int n, first = 0, second = 1, next;
    printf("enter the no. of terms ; ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        if (n == 0)
        {
            next = first;
        }
        else if (n == 1)
        {
            next == second;
        }
        else
        {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%d  ", next);
    }
    return 0;
}