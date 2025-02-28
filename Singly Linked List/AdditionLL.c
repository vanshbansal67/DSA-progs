#include <stdio.h>
#include <stdlib.h>
struct stu *CreateNode(int a);
struct stu *Addition(struct stu *list1, struct stu *list2);
int Traverse(struct stu *list);
struct stu
{
    int data;
    struct stu *next;
};

int main()
{
    struct stu *list1 = CreateNode(4);
    list1->next = CreateNode(5);
    list1->next->next = CreateNode(6);

    struct stu *list2 = CreateNode(7);
    list2->next = CreateNode(8);
    list2->next->next = CreateNode(9);

    Traverse(list1);
    printf("\n");
    Traverse(list2);
    printf("\n");

    struct stu *result = Addition(list1, list2);
    Traverse(result);
}

int Traverse(struct stu *list)
{
    struct stu *temp = list;
    while (temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
}

struct stu *CreateNode(int a)
{
    struct stu *p = (struct stu *)malloc(sizeof(struct stu));
    p->data = a;
    p->next = NULL;
    return p;
}

struct stu *Addition(struct stu *list1, struct stu *list2)
{
    struct stu *temp = list1;
    if (list1 == NULL)
    {
        return list2;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = list2;
    return list1;
}