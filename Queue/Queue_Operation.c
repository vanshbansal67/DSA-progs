#include <stdio.h>
#include <stdlib.h>

int Queue_Insertion(int s);
int Queue_Deletion();
int Traverse();
int rear = -1, front = -1;
int Queue[20];
int main()
{
    int ch, size;
    printf("Enter the size of Queue; ");
    scanf("%d", &size);
    do
    {
        printf("\nYour choice are as follows;");
        printf("\n1).Insert\n2).Delete\n3).Display\n4).Exit");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            Queue_Insertion(size);
            printf("\nAfter Insertion the Queue is as follows;\n");
            Traverse();
            break;
        case 2:
            Queue_Deletion();
            printf("\nAfter Deletion the Queue is as follows;\n");
            Traverse();
            break;
        case 3:
            Traverse();
            break;
        case 4:
            printf("\nExiting the Queue\n");
            exit(EXIT_SUCCESS);
        default:
            printf("INVALID CHOICE!!!");
        }
    } while (ch != 4);
    return 0;
}
int Queue_Insertion(int size)
{
    int item;
    printf("Enter the element to be added;");
    scanf("%d", &item);

    if (rear >= size - 1)
    {
        printf("Overflow");
    }

    else
    {
        rear = rear + 1;
        Queue[rear] = item;
        if (front == -1)
        {
            front = 0;
        }
    }
}

int Queue_Deletion()
{
    int item;
    if (front == -1)
    {
        printf("Underflow");
        return 0;
    }
    else
    {
        item = Queue[front];
        printf("Deleted item is %d", item);
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = front + 1;
        }
    }
}

int Traverse()
{
    if (front == -1)
    {
        printf("Queue is empty;");
        return 0;
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d  ", Queue[i]);
        }
    }
}