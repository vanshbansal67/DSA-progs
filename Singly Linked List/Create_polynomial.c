#include <stdio.h>
#include <stdlib.h>
struct POLY
{
    int coeff;
    int exp;
    struct POLY *next;
};
int AddNode(struct POLY **head, int coeff, int exp);
struct POLY *CreateNode(int coeff, int exp);
int Traverse(struct POLY *head);
int main()
{
    struct POLY *poly1 = NULL;
    struct POLY *poly2 = NULL;
    AddNode(&poly1, 5, 3);
    AddNode(&poly1, 4, 2);
    AddNode(&poly1, 3, 0);
    printf("\n");
    AddNode(&poly2, 4, 3);
    AddNode(&poly2, 3, 1);
    AddNode(&poly2, 1, 1);
    printf("the polynomial will be\n:");
    Traverse(poly1);
    printf("\n");
    Traverse(poly2);
    return 0;
}

int AddNode(struct POLY **head, int coeff, int exp)
{
    struct POLY *newnode = CreateNode(coeff, exp);
    struct POLY *temp = *head;
    if (*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

struct POLY *CreateNode(int coeff, int exp)
{
    struct POLY *p = (struct POLY *)malloc(sizeof(struct POLY));
    p->coeff = coeff;
    p->exp = exp;
    p->next = NULL;
    return p;
}

int Traverse(struct POLY *head)
{

    if (head == NULL)
    {
        printf("polynomial is empty");
    }
    else
    {
        struct POLY *temp = head;
        while (temp != NULL)
        {
            printf("%dx^%d + ", temp->coeff, temp->exp);
            temp = temp->next;
        }
        printf("\n");
    }
}