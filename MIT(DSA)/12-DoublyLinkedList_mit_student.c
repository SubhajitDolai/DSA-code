#include <stdio.h>
#include <stdlib.h>

// Linked List Node
struct node
{
    int info;
    struct node *prev;
    struct node *next;
};

void insertAtFront();
void insertAtEnd();
void insertAtPosition();
void display();

int main()
{
    int choice;
    while (1)
    {
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertAtFront();
            break;
        case 2:
            insertAtEnd();
            break;
        case 3:
            insertAtPosition();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

struct node *start = NULL;

// Function to insert an element at the front of the linked list
void insertAtFront()
{
    int data;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    temp->info = data;
    temp->prev = NULL;
    temp->next = start;
    start = temp;
}

// Function to insert an element at the end of the linked list
void insertAtEnd()
{
    int data;
    struct node *temp, *trav;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    temp->info = data;
    temp->prev = NULL;
    temp->next = NULL;

    trav = start;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        while (trav->next != NULL)
        {
            trav = trav->next;
        }
        temp->prev = trav;
        trav->next = temp;
    }
}

// Function to insert an element at a specified position in the linked list
void insertAtPosition()
{
    int data, pos, i = 1;
    struct node *temp, *newnode;
    newnode = malloc(sizeof(struct node));
    newnode->next = newnode->prev = NULL;

    printf("\nEnter position: ");
    scanf("%d", &pos);

    if (start == NULL)
    {
        start = newnode;
        printf("Node inserted at position %d.\n", pos);
        return;
    }

    temp = start;
    while (temp != NULL && i < pos - 1)
    {
        temp = temp->next;
        i++;
    }

    if (temp == NULL)
    {
        printf("Invalid position.\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &data);
    newnode->info = data;
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newnode;
    temp->next = newnode;

    printf("Node inserted at position %d.\n", pos);
}

// Other functions for deletion and more can be added similarly

void display()
{
    struct node *temp = start;
    if (temp == NULL)
    {
        printf("\nList is empty.\n");
        return;
    }

    printf("\nElements of the doubly linked list:\n");
    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}