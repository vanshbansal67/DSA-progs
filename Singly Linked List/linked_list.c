#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    head = malloc(sizeof(struct node));
    second = malloc(sizeof(struct node));
    third = malloc(sizeof(struct node));

    head->data = 55;
    head->link = second;

    second->data = 60;
    second->link = third;
    third->data = 65;
    third->link = NULL;

    printf("the linked list will be; ");
    printf("%d %d ", head->data, second);
    printf("%d %d ", second->data, third);
    printf("%d %d ", third->data, NULL);
    return 0;
}