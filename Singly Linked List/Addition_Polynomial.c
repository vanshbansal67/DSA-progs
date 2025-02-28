// Representation of a Polynomial Using a Linked List
// A polynomial of a single variable can be represented as a linked list where:

// Each node contains:

// The coefficient of the term.
// The exponent of the variable.
// A pointer to the next node.
// The linked list is sorted in decreasing order of exponents for easier manipulation.

// For example, the polynomial
// 5
// 𝑥
// 3
// +
// 4
// 𝑥
// 2
// +
// 2
// 5x
// 3
//  +4x
// 2
//  +2 can be represented as:

// css
// Copy
// Edit
// [5, 3] → [4, 2] → [2, 0] → NULL
// Operations on Polynomial Represented by Linked Lists
// Addition of Two Polynomials
// To add two polynomials represented as linked lists:

// Traverse both linked lists.
// Compare the exponents of the terms from both lists:
// If exponents are equal, add the coefficients and create a new node.
// If one exponent is greater, copy that term to the result and move to the next term in that list.
// Append remaining terms from either list.

#include <stdio.h>
#include <stdlib.h>

struct po *CreateNode(int coeff, int exp);

int Traverse(struct po *head);
int AddNode(struct po **head, int coeff, int exp);
struct po *AddPolynomial(struct po *poly1, struct po *poly2);

struct po
{
    int coeff;
    int exp;
    struct po *next;
};

int main()
{
    int coeff, exp;
    struct po *poly1 = NULL;
    struct po *poly2 = NULL;

    AddNode(&poly1, 5, 3);
    AddNode(&poly1, 4, 2);
    AddNode(&poly1, 2, 0);
    printf("\n");
    AddNode(&poly2, 3, 3);
    AddNode(&poly2, 2, 1);
    AddNode(&poly2, 1, 0);

    Traverse(poly1);
    printf("\n");
    Traverse(poly2);
    struct po *result = AddPolynomial(poly1, poly2);
    printf("\n");
    Traverse(result);
}

int Traverse(struct po *head)
{
    if (head == NULL)
    {
        printf("polynomial is empty");
    }
    while (head != NULL)
    {
        printf("%dx^%d ", head->coeff, head->exp);
        head = head->next;
        if (head != NULL)
        {
            printf("+");
        }
    }
    printf("\n");
    return 0;
}

struct po *CreateNode(int coeff, int exp)
{
    struct po *p = (struct po *)malloc(sizeof(struct po));
    p->coeff = coeff;
    p->exp = exp;
    p->next = NULL;
    return p;
}

int AddNode(struct po **head, int coeff, int exp)
{
    struct po *newnode = CreateNode(coeff, exp);
    struct po *temp = *head;
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

struct po *AddPolynomial(struct po *poly1, struct po *poly2)
{
    struct po *result = NULL;
    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->exp > poly2->exp)
        {
            AddNode(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        }
        else if (poly1->exp < poly2->exp)
        {
            AddNode(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        }
        else
        {
            int sumcoeff = poly1->coeff + poly2->coeff;
            if (sumcoeff != 0)
            {
                AddNode(&result, sumcoeff, poly1->exp);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL)
    {
        AddNode(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }
    while (poly2 != NULL)
    {
        AddNode(&result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }
    return result;
}