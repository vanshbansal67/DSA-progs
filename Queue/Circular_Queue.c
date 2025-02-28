#include <stdio.h>
#include <stdlib.h>
int front = -1, rear = -1;
int Circ_Queue[20];

int Queue_Insertion(int size);
int Queue_Deletion(int size);
int Traverse(int size);

int main()
{
    int size;
    int ch = 1;
    printf("Enter the size of Queue;");
    scanf("%d", &size);
    do
    {
        printf("\n---------------------------------");
        printf("\nYour choices are as follows");
        printf("\n1).Insert\n2).Delete\n3).Display\n4).Exit\n");
        printf("-----------------------------------");
        printf("\nEnter your choice;");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            Queue_Insertion(size);
            printf("Queue after insertion\n");
            Traverse(size);
            break;
        case 2:
            Queue_Deletion(size);
            printf("Queue after Deletion\n");
            Traverse(size);
            break;
        case 3:
            Traverse(size);
            break;
        case 4:
            exit(EXIT_SUCCESS);
        default:
            printf("INVALID CHOICE");
        }
    } while (ch != 4);
    return 0;
}

int Queue_Insertion(int size)
{
    int a;
    printf("Enter the element ;");
    scanf("%d", &a);
    if ((front == 0 && rear == size - 1) || (front == rear + 1))
    {
        printf("\n<<<<<<<<<<<<<<Queue is overflow>>>>>>>>>>>>>>>\n");
        return 0;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
        Circ_Queue[rear] = a;
    }
    else if (rear == size - 1)
    {
        rear = 0;
        Circ_Queue[rear] = a;
    }
    else
    {
        rear = rear + 1;
        Circ_Queue[rear] = a;
    }
}

int Queue_Deletion(int size)
{
    int item;
    if (front == -1)
    {
        printf("\nUNDERFLOW");
    }
    else
    {
        item = Circ_Queue[front];
        printf("\nDeleted item is %d", item);
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front = front + 1;
        }
    }
}

int Traverse(int size)
{
    if (front <= rear)
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d  ", Circ_Queue[i]);
        }
    }
    else
    {
        for (int i = front; i < size; i++)
        {
            printf("%d  ", Circ_Queue[i]);
        }
        for (int i = 0; i <= rear; i++)
        {
            printf("%d  ", Circ_Queue[i]);
        }
    }
}