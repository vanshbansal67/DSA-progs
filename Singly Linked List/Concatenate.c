#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int info;
    struct Node *next;
};

struct Node *ConcatenateList(struct Node *list1, struct Node *list2);
int AddNode(struct Node **head, int info);
struct Node *CreateNode(int info);
int Traverse(struct Node *head);
int main()
{
    struct Node *list1 = NULL;
    struct Node *list2 = NULL;
    AddNode(&list1, 4);
    AddNode(&list1, 5);
    AddNode(&list1, 6);
    AddNode(&list2, 7);
    AddNode(&list2, 8);
    AddNode(&list2, 9);
    printf("the list 1 is\n");
    Traverse(list1);
    printf("\nthe list 2 is\n");
    Traverse(list2);

    list1 = ConcatenateList(list1, list2);
    printf("the list after Concatenate is\n");
    Traverse(list1);
    return 0;
}

struct Node *CreateNode(int info)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->info = info;
    p->next = NULL;
    return p;
}

int AddNode(struct Node **head, int info)
{
    struct Node *newnode = CreateNode(info);
    if (*head == NULL)
    {
        *head = newnode;
        return 1;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    return 1;
}

int Traverse(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

struct Node *ConcatenateList(struct Node *list1, struct Node *list2)
{
    if (list1 == NULL)
    {
        return list2;
    }
    struct Node *temp = list1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = list2;
    return list1;
}