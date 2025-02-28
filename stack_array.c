#include <stdio.h>
#include <conio.h>
#define MAX_SIZE 10
int stack[MAX_SIZE], top = -1;
void Pop();
void Push();
void Display();
void main()
{
    int choice;
    do
    {
        printf("\n----------STACK IMPLEMENTATION---------\n");
        printf("1).Push\n2).Pop\n3).Display\n4).Exit\n");
        printf("---------------------------------------\n");
        printf("Enter your choice;");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Push();
            break;
        case 2:
            Pop();
            break;
        case 3:
            Display();
            break;
        default:
            printf("invalid choice");

        }
    }

    while (choice != 4);
    getch();
}

void Push()
{
    int n;
    if (top == MAX_SIZE-1)
    {
        printf("overflow");
    }
    else
    {
        printf("Enter the element:");
        scanf("%d", &n);
        top++;
        stack[top] = n;
    }
}

void Pop()
{
    int n;
    if (top == -1)
    {
        printf("stack is empty");
    }
    else
    {

        n = stack[top];
        top--;
    }
}
void Display()
{
    if (top == -1)
    {
        printf("stack is empty");
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("\n%d", stack[i]);
        }
    }
}
