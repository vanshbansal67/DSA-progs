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
// int Add_Before(struct student **head, int item, struct student *new_node);
// int main()
// {
//     struct student *head = NULL;
//     int ch = 1, a;
//     int data, item;

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
//     printf("Enter the data to add;");
//     scanf("%d", &data);
//     struct student *p = CreateNewNode(data);
//     printf("enter the item before which you want to add the node;");
//     scanf("%d", &item);
//     Add_Before(&head, item, p);
//     printf("\nThe linked list after the addition of node");
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

// int Add_Before(struct student **head, int item, struct student *new_node)
// {
//     struct student *temp = head;
//     if (temp->info == item)
//     {
//         new_node->next = temp;
//         *head = new_node;
//     }
//     else
//     {
//         struct student *temp = *head;

//         while (temp->next != NULL && temp->next->info != item)
//         {
//             struct student *r = temp;
//             temp = temp->next;
//             if (temp->info == item)
//             {
//                 new_node->next = temp;
//                 r->next = new_node;
//             }
//         }
//     }
// }

#include <stdio.h>
#include <stdlib.h>

struct student
{
    int info;
    struct student *next;
};

struct student *CreateNewNode(int a);
void AddNode_FIFO(struct student **head, struct student *new_node);
void Traverse(struct student *head);
int Add_Before(struct student **head, int item, struct student *new_node);

int main()
{
    struct student *head = NULL;
    int ch = 1, a;
    int data, item;

    while (ch != 0)
    {
        printf("Enter the element: ");
        scanf("%d", &a);
        struct student *p = CreateNewNode(a);
        AddNode_FIFO(&head, p);
        printf("Press 1 to continue and 0 to exit: ");
        scanf("%d", &ch);
    }

    printf("The linked list is below:\n");
    Traverse(head);

    printf("Enter the data to add: ");
    scanf("%d", &data);
    struct student *p = CreateNewNode(data);

    printf("Enter the item before which you want to add the node: ");
    scanf("%d", &item);

    if (Add_Before(&head, item, p))
    {
        printf("\nThe linked list after the addition of the node:\n");
        Traverse(head);
    }
    else
    {
        printf("\nItem %d not found in the list.\n", item);
        free(p); // Free the newly created node if not added.
    }

    return 0;
}

struct student *CreateNewNode(int a)
{
    struct student *p = (struct student *)malloc(sizeof(struct student));
    // if (!p)
    // {
    //     printf("Memory allocation failed.\n");
    //     exit(EXIT_FAILURE);
    // }
    p->info = a;
    p->next = NULL;
    return p;
}

void AddNode_FIFO(struct student **head, struct student *new_node)
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

void Traverse(struct student *head)
{
    struct student *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

int Add_Before(struct student **head, int item, struct student *new_node)
{
    if (*head == NULL)
        return 0; // List is empty.

    // Check if the first node is the target.
    if ((*head)->info == item)
    {
        new_node->next = *head;
        *head = new_node;
        return 1;
    }

    struct student *temp = *head;

    // Traverse the list to find the node before the target.
    while (temp->next != NULL && temp->next->info != item)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
        return 0; // Item not found.

    new_node->next = temp->next;
    temp->next = new_node;
    return 1;
}
