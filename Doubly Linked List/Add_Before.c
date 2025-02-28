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
int Traverse(struct student *head);
int AddBefore_FIFO(struct student **head, int item, struct student *new_node);

int main()
{
    int ch = 1, a, data, item;
    struct student *head = NULL;
    while (ch != 0)
    {
        printf("Enter the element;");
        scanf("%d", &a);
        struct student *p = CreateNode(a);
        AddNode_FIFO(&head, p);
        printf("\nPress 1 for continue and 0 for exit;");
        scanf("%d", &ch);
    }
    printf("\nThe list you entered;");
    Traverse(head);
    printf("\nenter the data to add;");
    scanf("%d", &data);
    struct student *p = CreateNode(data);
    printf("\nEnter the Item before which the Data to be added;");
    scanf("%d", &item);
    AddBefore_FIFO(&head, item, p);
    printf("\n The list after addition of element is ;");
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
        printf("%d  ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

int AddBefore_FIFO(struct student **head, int item, struct student *new_node)
{
    if ((*head)->info == item)
    {
        new_node->next = *head;
        *head = new_node;
        return 0;
    }
    struct student *temp = *head;
    struct student *r = temp;

    while (temp != NULL && temp->info != item)
    {
        r = temp;
        temp = temp->next;
    }
    r->next = new_node;
    new_node->next = temp;
    new_node->prev = r;
    while (temp == NULL && temp->info != item)
    {
        printf("item not found");
        return 1;
    }
}