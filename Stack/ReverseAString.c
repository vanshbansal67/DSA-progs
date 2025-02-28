// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define MAX 100 // Maximum size of the stack

// char stack[MAX];
// int top = -1;

// // Stack operations
// void push(char c)
// {
//     if (top == MAX - 1)
//     {
//         printf("Stack overflow!\n");
//         exit(EXIT_FAILURE);
//     }
//     stack[++top] = c;
// }

// char pop()
// {
//     if (top == -1)
//     {
//         printf("Stack underflow!\n");
//         exit(EXIT_FAILURE);
//     }
//     return stack[top--];
// }

// void reverseString(char str[])
// {
//     int length = strlen(str);

//     // Push all characters of the string onto the stack
//     for (int i = 0; i < length; i++)
//     {
//         push(str[i]);
//     }

//     // Pop characters from the stack and store them back in the string
//     for (int i = 0; i < length; i++)
//     {
//         str[i] = pop();
//     }
// }

// int main()
// {
//     char str[MAX];

//     printf("Enter a string: ");
//     fgets(str, MAX, stdin);

//     // Remove the newline character from the input if present
//     size_t len = strlen(str);
//     if (str[len - 1] == '\n')
//     {
//         str[len - 1] = '\0';
//     }

//     printf("Original string: %s\n", str);

//     reverseString(str);

//     printf("Reversed string: %s\n", str);

//     return 0;
// }

// printf("\n-----------------------------------------\n");

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 20
int stack[MAX_SIZE], top = -1;
int Pop();
int Push(char n);

int main()
{
    char str[20];
    int i;
    printf("\nEnter a string;");
    gets(str); // store the entered string in the str variable
    for (int i = 0; i < strlen(str); i++)
    {
        Push(str[i]);
    }
    for (int i = 0; i < strlen(str); i++)
    {
        str[i] = Pop();
    }
    printf("\nReverse String is ;");
    puts(str); // print the reversed string
    return 0;
}

int Push(char n)
{
    if (top == MAX_SIZE - 1)
    {
        printf("overflow");
    }
    else
    {
        top++;
        stack[top] = n;
    }
}

int Pop()
{
    if (top == -1)
    {
        printf("stack is empty");
    }
    else
    {
        return stack[top--];
    }
}

// printf("\n----------------------------------\n");
// #include <stdio.h>
// #include <conio.h>
// void main()
// {
//     int a;
//     int res = 1;
//     printf("Enter the no.; ");
//     scanf("%d", &a);
//     for (int i = a; i >= 1; i--)
//     {
//         res = res * i;
//     }
//     printf("%d", res);
//     getch();
// }