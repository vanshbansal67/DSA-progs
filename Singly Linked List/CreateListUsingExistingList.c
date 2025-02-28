#include <stdio.h>
#include <stdlib.h>

struct stu
{
    int info;
    struct stu *next;
};

struct stu *CreateNode(int data)
{
    struct stu *p = (struct stu *)malloc(sizeof(struct stu));
    p->info = data;
    p->next = NULL;
    return p;
}

struct stu *CreateNode(int data);
int AddNode(struct stu **head, struct stu *newnode);
int Traverse(struct stu *head);
struct stu *CreateAlternateList(struct stu *head);

int main()
{
    int ch = 1;
    int n, a;
    struct stu *head = NULL;
    struct stu *alternatelist = NULL;
    // printf("enter the size of original list;");
    // scanf("%d", &n);
    while (ch != 0)
    {
        printf("enter the element ;");
        scanf("%d", &a);
        struct stu *p = CreateNode(a);
        AddNode(&head, p);
        printf("\nPress 1 for continue and 0 for exit;");
        scanf("%d", &ch);
    }
    printf("\nThe original list is below;\n");
    Traverse(head);
    alternatelist = CreateAlternateList(head);
    printf("the new Alternate List is below\n");
    Traverse(alternatelist);
    return 0;
}

int AddNode(struct stu **head, struct stu *newnode)
{
    struct stu *temp = *head;
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
        // newnode->next = NULL;
    }
}

int Traverse(struct stu *head)
{
    struct stu *temp = head;
    while (temp != NULL)
    {
        printf("%d ->", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct stu *CreateAlternateList(struct stu *head)
{
    struct stu *newhead = NULL;
    struct stu *current = head;
    int count = 0;
    while (current != NULL)
    {
        if (count % 2 == 0)
        {
            struct stu *p = CreateNode(current->info);
            AddNode(&newhead, p);
        }
        count++;
        current = current->next;
    }
    return newhead;
}

// printf("\n------------------------------------\n");
// #include <stdio.h>
// #include <stdlib.h>

// // Define a structure for the linked list node
// struct Node
// {
//     int data;
//     struct Node *next;
// };

// // Function to create a new node
// struct Node *createNode(int data)
// {
//     struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->next = NULL;
//     return newNode;
// }

// // Function to append a node to the linked list
// void appendNode(struct Node **head, int data)
// {
//     struct Node *newNode = createNode(data);
//     if (*head == NULL)
//     {
//         *head = newNode;
//         return;
//     }
//     struct Node *temp = *head;
//     while (temp->next != NULL)
//     {
//         temp = temp->next;
//     }
//     temp->next = newNode;
// }

// // Function to display the linked list
// void displayList(struct Node *head)
// {
//     struct Node *temp = head;
//     while (temp != NULL)
//     {
//         printf("%d -> ", temp->data);
//         temp = temp->next;
//     }
//     printf("NULL\n");
// }

// // Function to create a new linked list with alternate elements
// struct Node *createAlternateList(struct Node *head)
// {
//     struct Node *newHead = NULL;
//     struct Node *current = head;
//     int count = 0;

//     while (current != NULL)
//     {
//         if (count % 2 == 0)
//         {
//             appendNode(&newHead, current->data);
//         }
//         count++;
//         current = current->next;
//     }

//     return newHead;
// }

// // Main function to test the implementation
// int main()
// {
//     struct Node *originalList = NULL;
//     struct Node *alternateList = NULL;

//     // Create the original list
//     appendNode(&originalList, 2);
//     appendNode(&originalList, 4);
//     appendNode(&originalList, 6);
//     appendNode(&originalList, 9);

//     printf("Original List: ");
//     displayList(originalList);

//     // Create the alternate list
//     alternateList = createAlternateList(originalList);

//     printf("Alternate List: ");
//     displayList(alternateList);

//     return 0;
// }
