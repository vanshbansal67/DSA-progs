#include <stdio.h>
#include <stdlib.h>

struct student
{
    int info;
    struct student *next;
};

struct student *CreateNewNode(int a);
int AddNode_LIFO(struct student **head, struct student *New_node);
int Traverse(struct student *head);
int main()
{
    struct student *head = NULL;
    int ch = 1, a;
    while (ch != 0)
    {
        printf("enter the element;");
        scanf("%d", &a);
        struct student *p = CreateNewNode(a);
        AddNode_LIFO(&head, p);
        printf("press 1 to continue and 0 for exit;");
        scanf("%d", &ch);
    }
    printf("The Linked List is Below;\n");
    Traverse(head);
    return 0;
}

struct student *CreateNewNode(int a)
{
    struct student *p = (struct student *)malloc(sizeof(struct student));
    p->info = a;
    p->next = NULL;
    return p;
}

int AddNode_LIFO(struct student **head, struct student *new_node)
{
    struct student *temp = *head;
    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        new_node->next = temp;
        *head = new_node;
    }
}

int Traverse(struct student *head)
{
    struct student *temp = head;
    while (temp != NULL)
    {
        printf("\n %d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}
