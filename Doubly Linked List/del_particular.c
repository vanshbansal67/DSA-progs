#include <stdio.h>
#include <stdlib.h>
struct student
{
    int info;
    struct student *next;
    struct student *prev;
};

struct student *CreateNewNode(int a);
int AddNode_FIFO(struct student **head, struct student *new_node);
int Traverse(struct student *head);
int Del_particular(int data, struct student **head);

int main()
{
    int ch = 1;
    int a, data;
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
    printf("enter the content of the node you want to delete;");
    scanf("%d", &data);
    Del_particular(data, &head);
    printf("\nThe list after deletion of the element");
    Traverse(head);

    return 0;
}

struct student *CreateNewNode(int a)
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

int Del_particular(int data, struct student **head)
{
    struct student *temp = *head;
    if (*head == NULL)
    {
        printf("Deletion not possible; the list is empty.\n");
        return -1;
    }
    while (temp != NULL && temp->info != data)
    {
        temp = temp->next;
        if (temp->info == data)
        {
            if (temp->next != NULL)
            {
                temp->next->prev = temp->prev;
            }
            if (temp->prev != NULL)
            {
                temp->prev->next = temp->next;
            }
            free(temp);
            printf("\nThe entered element is deleted:");
            return 0;
        }
    }
}