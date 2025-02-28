#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX_SIZE 10
int stack[MAX_SIZE];
struct stu *top = NULL;
void Pop();
void Push(int n);
void Display();

struct stu
{
    int info;
    struct stu *next;
};

void main()
{
    int choice;
    int data;
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
            printf("Enter the Data;");
            scanf("%d", &data);
            Push(data);
            break;
        case 2:
            Pop();
            break;
        case 3:
            Display();
            break;
        case 4:
            printf("Exiting the program...\n");
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    while (choice != 4);
    getch();
}

void Push(int n)
{
    struct stu *newnode = (struct stu *)malloc(sizeof(struct stu));
    if (newnode == NULL)
    {
        printf("overflow");
        getch();
    }
    newnode->info = n;
    newnode->next = top;
    top = newnode;
    printf("item %d is pushed into the stack;", n);
}

void Pop()
{
    if (top == NULL)
    {
        printf("Underflow");
    }
    int poppeditem = top->info;
    struct stu *temp = top;
    top = top->next;
    free(temp);
    printf("popped %d from the stack;", poppeditem);
}
void Display()
{
    if (top == NULL)
    {
        printf("stack is empty");
    }

    struct stu *temp = top;
    printf("\n");
    while (temp != NULL)
    {
        printf("%d  ", temp->info);
        temp = temp->next;
    }
}
