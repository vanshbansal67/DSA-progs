#include <stdio.h>
#include <stdlib.h>
struct student
{
    int info;
    struct student *next;
    struct student *prev;
};
struct student *CreateNode(int a);
int AddNode_FIFO(struct student **head, struct student *new_node);
int AddAfter_FIFO(struct student **head, int item, struct student *new_node);
int Traverse(struct student *head);
int main()
{
    int ch = 1, a, data, item;
    struct student *head = NULL;
    while (ch != 0)
    {
        printf("\nEnter the element;");
        scanf("%d", &a);
        struct student *p = CreateNode(a);
        AddNode_FIFO(&head, p);
        printf("\nPress 1 for continue and 0 foe exit;");
        scanf("%d", &ch);
    }
    printf("\nThe list you entered;");
    Traverse(head);
    printf("\nEnter the data to be added;");
    scanf("%d", &data);
    struct student *p = CreateNode(data);
    printf("\nEnter the item to after the content to be added;");
    scanf("%d", &item);
    AddAfter_FIFO(&head, item, p);
    printf("\nThe list after the addition of data;");
    Traverse(head);
    return 0;
}

struct student *CreateNode(int a)
{
    struct student *p = (struct student *)malloc(sizeof(struct student));
    p->info = a;
    p->next = NULL;
    p->prev = NULL;
    return p;
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
        new_node->prev = temp;
    }
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

int AddAfter_FIFO(struct student **head, int item, struct student *new_node)
{

    struct student *temp = *head;
    while (temp != NULL)
    {
        if (temp->info == item)
        {
            new_node->next = temp->next;
            if (temp->next != NULL)
            {
                temp->next->prev = new_node;
            }
            temp->next = new_node;
            new_node->prev = temp;
            return -1;
        }
        temp = temp->next;
    }
}