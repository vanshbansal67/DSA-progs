#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
};

struct node *CreateNode(int info);
int Traverse(struct node *head);
int AddNode(struct node **head, int info);
int AddAtPlace(struct node **head, int k, int data);
int main()
{
    int k, data;
    struct node *head = NULL;
    AddNode(&head, 4);
    AddNode(&head, 5);
    AddNode(&head, 6);
    AddNode(&head, 8);
    AddNode(&head, 9);
    AddNode(&head, 10);
    printf("The linked list is given below!!!!!\n");
    Traverse(head);
    printf("enter the position where you want to add an element;");
    scanf("%d", &k);
    printf("Enter the data to add;");
    scanf("%d", &data);
    AddAtPlace(&head, k, data);
    printf("the linked list after the addition is:\n");
    Traverse(head);
    return 0;
}

int AddNode(struct node **head, int info)
{
    struct node *newnode = CreateNode(info);
    if (*head == NULL)
    {
        *head = newnode;
        return 1;
    }
    struct node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    return 1;
}

struct node *CreateNode(int info)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->info = info;
    p->next = NULL;
    return p;
}

int Traverse(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

int AddAtPlace(struct node **head, int k, int data)
{
    struct node *newnode = CreateNode(data);
    if (k == 1)
    {
        newnode->next = *head;
        *head = newnode;
        return 1;
    }
    struct node *temp = *head;
    for (int i = 1; i < k - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position %d is out of range\n", k);
        free(newnode);
        return 0;
    }
    else
    {
        newnode->next = temp->next;
        temp->next = newnode;
    }
}