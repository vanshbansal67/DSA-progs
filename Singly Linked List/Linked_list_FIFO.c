#include <stdio.h>
#include <stdlib.h>

// *****************************************************
// Defines a structure (struct stu) for a node in a linked list.
// Each node contains:
// info: An integer that stores the node's data.
// next: A pointer to the next node in the list.
// *****************************************************
// Definition of the struct
struct stu
{
    int info;
    struct stu *next;
};

// Function prototypes
struct stu *CreateNewNode(int a);
void addNode_FIFO(struct stu **head, struct stu *new_node);
void traverse(struct stu *head);

// *************************************************
// Main Function
// The program asks the user to input numbers, creates nodes with those numbers, and adds them to the linked list in FIFO order.
// Once the user finishes entering numbers, the program traverses the list and prints all the elements.
// *************************************************
int main()
{
    int ch = 1, a;
    struct stu *head = NULL;

    while (ch != 0)
    {
        printf("\nEnter an element: ");
        scanf("%d", &a);

        struct stu *p = CreateNewNode(a);
        addNode_FIFO(&head, p);

        printf("\nPress 1 to continue or 0 to end: ");
        scanf("%d", &ch);
    }

    printf("\nThe list is as follows:\n");
    traverse(head);

    // Free allocated memory (optional but recommended)
    return 0;
}
// *******************************************************
// struct stu *CreateNewNode(int a);
// Allocates memory for a new node and initializes it with the given data (a).
// The next pointer is set to NULL since this new node is not yet linked to the list.
// *******************************************************
// Create a new node
struct stu *CreateNewNode(int a)
{
    struct stu *p = (struct stu *)malloc(sizeof(struct stu));
    p->info = a;
    p->next = NULL;
    return p;
}

// Add a node to the end of the list (FIFO)

// ************************************************************
// void addNode_FIFO(struct stu **head, struct stu *new_node);
// Adds a new node to the end of the linked list.
// If the list is empty, the new node becomes the head.
// Otherwise, the function traverses the list to find the last node and links the new node to it.
// ************************************************************

// ----------------------------------------------------------------------------------------------
//*************************************************struct stu **head*****************************

// This is a pointer to a pointer to the head of the linked list.
// The reason for using struct stu **head instead of just struct stu *head is
// to allow the function to modify the actual pointer head if it changes (e.g., when the list is initially empty and a new node becomes the head).

// Why double pointer?
// A single pointer (struct stu *head) allows access to the linked list but doesn't let the function modify the caller's head directly.
// A double pointer (struct stu **head) gives the function the ability to directly change the caller's head pointer.
// Example:

// If the linked list is initially empty (head = NULL), the new node will be assigned to head
// , and this change will be reflected back in the caller because of the double pointer.

void addNode_FIFO(struct stu **head, struct stu *new_node)
{
    if (*head == NULL) // to check if the list is empty because, it is already understood that is the first node is NULL,,the list is empty
    {
        *head = new_node; // assigning the first node to the Head
    }
    else
    {
        struct stu *temp = *head;
        while (temp->next != NULL) // to check weather the temp is at the last or not
        {
            temp = temp->next; // ek node ke andar jaane ke liye fir uske bhi andar jaane ke liye or we can say that to reach to the last node
        }
        temp->next = new_node; // insert the new node at the last of the linked list
    }
}
// ***********************************************
// void traverse(struct stu *head);
// Iterates through the linked list and prints the info of each node.
// Traverse and print the list
// ***********************************************
void traverse(struct stu *head)
{
    struct stu *temp = head;
    while (temp != NULL)
    {
        printf("%d %d ", temp->info, temp->next);
        temp = temp->next;
    }
    printf("\n");
}

// ---------------------------------------------------------------------------------------------
// #include <stdio.h>
// #include <stdlib.h>

// struct student
// {
//     int info;
//     struct student *next;
// };

// struct student *CreateNewNode(int a);
// int AddNode_FIFO(struct student **head, struct student *New_node);
// int Traverse(struct student *head);
// int main()
// {
//     struct student *head = NULL;
//     int ch = 1, a;
//     while (ch != 0)
//     {
//         printf("enter the element;");
//         scanf("%d", &a);
//         struct student *p = CreateNewNode(a);
//         AddNode_FIFO(&head, p);
//         printf("press 1 to continue and 0 for exit;");
//         scanf("%d", &ch);
//     }
//     printf("The Linked List is Below;\n");
//     Traverse(head);
//     return 0;
// }

// struct student *CreateNewNode(int a)
// {
//     struct student *p = (struct student *)malloc(sizeof(struct student));
//     p->info = a;
//     p->next = NULL;
//     return p;
// }

// int AddNode_FIFO(struct student **head, struct student *new_node)
// {
//     // struct student *temp = *head;
//     if (*head == NULL)
//     {
//         *head = new_node;
//     }
//     else
//     {
//         struct student *temp = *head;
//         while (temp->next != NULL)
//         {
//             temp = temp->next;
//         }
//         temp->next = new_node;
//     }
// }

// int Traverse(struct student *head)
// {
//     struct student *temp = head;
//     while (temp != NULL)
//     {
//         printf("\n %d ", temp->info);
//         temp = temp->next;
//     }
//     printf("\n");
// }

// // --------------------------------------------------------------------------------
