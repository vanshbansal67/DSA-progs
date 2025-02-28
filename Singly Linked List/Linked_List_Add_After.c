#include <stdio.h>
#include <stdlib.h>
struct student
{
    int info;
    struct student *next;
};

struct student *CreateNewNode(int a);
int AddNode_FIFO(struct student **head, struct student *new_node);
int Add_After_FIFO(struct student **head, int item, struct student *new_node);
int Traverse(struct student *head);
int main()
{
    struct student *head = NULL;
    int ch = 1;
    int data, item, a;
    while (ch != 0)
    {
        printf("enter a element;");
        scanf("%d", &a);
        struct student *p = CreateNewNode(a);
        AddNode_FIFO(&head, p);
        printf("\nPress 1 for continue and 0 for exit;");
        scanf("%d", &ch);
    }
    printf("\nThe list you have entered ;");
    Traverse(head);

    printf("\nEnter the data to be added;");
    scanf("%d", &data);
    struct student *p = CreateNewNode(data);
    printf("Enter the item after which you want to add the data;");
    scanf("%d", &item);
    Add_After_FIFO(&head, item, p);
    printf("\nThe linked list after the Addition of new node;");
    Traverse(head);

    return 0;
}

struct student *CreateNewNode(int a)
{
    struct student *p = (struct student *)malloc(sizeof(struct student));
    p->info = a;
    p->next = NULL;
}

int AddNode_FIFO(struct student **head, struct student *new_node)
{
    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        struct student *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

int Add_After_FIFO(struct student **head, int item, struct student *new_node)
{
    struct student *temp = *head;
    if (*head == NULL)
    {
        printf("list is empty");
        return 0;
    }
    if (temp->info == item)
    {
        temp->next = new_node;
        *head = new_node;
        return 1;
    }
    while (temp != NULL && temp->info != item)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        return 0; // item not found
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

int Traverse(struct student *head)
{
    struct student *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}