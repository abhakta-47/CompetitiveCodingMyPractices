//  assignment CA2 for CSC303

// Q1. Write a C-program to concatenate two doubly linked linear lists.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node node;

// node structure
struct node
{
    int data;
    struct node *next, *prev;
};

void insert();

// creating a node
node *create_list()
{
    int k, n, v;
    node *head;
    head = NULL;

    printf("\n\nCreating a new list...............");
    printf("Enter number of elements to enter : ");
    scanf("%d", &n);

    for (k = 0; k < n; k++)
    {
        printf("\nEnter value to be entered at position %d : ", k + 1);
        scanf("%d", &v);
        insert(&head, v);
    }

    printf("\nNew linked list successfully created !!! \n");
    return head;
}

void insert(node **head, int value)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = value;
    new_node->next = (*head);
    new_node->prev = NULL;

    if ((*head) != NULL)
        (*head)->prev = new_node;

    (*head) = new_node;
}

void display(node *head)
{
    int count = 1;
    node *p;
    p = head;
    printf("\nDisplaying contents of given node........................\n");
    while (p != NULL)
    {
        printf("%d", p->data);
        count++;
        if (p->next != NULL)
            printf(" -> ");
        else
            printf(" ");
        p = p->next;
    }
}

node *add_list(node *head1, node *head2)
{
    node *p;
    if (head1 == NULL) // if the first linked list is empty
        return (head2);
    if (head2 == NULL)  // if second linked list is emptyreturn (head1);
        return (head1); // place p on the first node of the first linked list
    p = head1;
    while (p->next != NULL) // move p to the last node
        p = p->next;
    /* address of the first node of the second linked list stored in the last node of
the first linked list */
    p->next = head2;
    head2->prev = p;
    return (head1);
}

void main()
{
    node *a, *b, *c;
    a = create_list();
    display(a);
    b = create_list();
    display(b);
    // c = add_list(a, b);
    // display(c);
    printf("\n\nAttempting to add two linked list .......");
    add_list(a, b);
    printf("Successfully added.\n");
    printf("displaying contents of sumed result....");
    display(a);
    printf("\n");
}