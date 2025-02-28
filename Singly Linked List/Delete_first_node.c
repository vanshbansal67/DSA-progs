#include <stdio.h>
#include <stdlib.h>
struct student
{
    int info;
    struct student *next;
};

struct student *CreateNewNode(int a);
int AddNode_FIFO(struct student **head, struct student *new_node);
int Traverse(struct student *head);
int Delete(struct student **head);

int main()
{
    int ch = 1;
    int a;
    struct student *head = NULL;
    while (ch != 0)
    {
        printf("Enter the element;");
        scanf("%d", &a);
        struct student *p = CreateNewNode(a);
        AddNode_FIFO(&head, p);
        printf("\nPress 1 for continue and 0 for exit;");
        scanf("%d", &ch);
    }
    printf("\nThe list you entered");
    Traverse(head);
    Delete(&head);
    printf("\nThe list after deletion of first element");
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

int Delete(struct student **head)
{
    struct student *temp = *head;
    if (*head == NULL)
    {
        printf("deletion not possible;");
    }
    *head = (*head)->next;
    free(temp);
}