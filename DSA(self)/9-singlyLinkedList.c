#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *add;
};
struct node *start = NULL, *temp, *new1, *next, *prev;

void create();
void insertAtFirst();
void insertAtLast();
void insertAtMiddle();
void deleteFromFirst();
void deleteFromLast();
void deleteFromMiddle();
void display();

int main()
{
    int choice;
    do
    {
        printf("\n----------Linked List Menu----------\n");
        printf("1. Create\n");
        printf("2. Insert at first\n");
        printf("3. Insert at last\n");
        printf("4. Insert at middle\n");
        printf("5. Delete from first\n");
        printf("6. Delete from last\n");
        printf("7. Delete from middle\n");
        printf("8. Display\n");
        printf("9. Exit\n");
        printf("------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            insertAtFirst();
            break;
        case 3:
            insertAtLast();
            break;
        case 4:
            insertAtMiddle();
            break;
        case 5:
            deleteFromFirst();
            break;
        case 6:
            deleteFromLast();
            break;
        case 7:
            deleteFromMiddle();
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 9);

    return 0;
}

void create()
{
    int n;
    char ch;
    printf("Enter an Element: ");
    scanf("%d", &n);
    start = (struct node *)malloc(sizeof(struct node));
    start->data = n;
    start->add = NULL;
    temp = start;

    printf("Want to continue? (y-Yes/n-No): ");
    scanf(" %c", &ch);
    while (ch == 'Y' || ch == 'y')
    {
        printf("Enter next Element: ");
        scanf("%d", &n);
        new1 = (struct node *)malloc(sizeof(struct node));
        new1->data = n;
        new1->add = NULL;
        temp->add = new1;
        temp = temp->add;
        printf("Want to continue? (y-Yes/n-No): ");
        scanf(" %c", &ch);
    }
}
void insertAtFirst()
{
    if (start == NULL)
    {
        printf("List not found!");
    }
    else
    {
        int n;
        printf("Enter new element for insertion: ");
        scanf("%d", &n);
        new1 = (struct node *)malloc(sizeof(struct node));
        new1->data = n;
        new1->add = NULL;
        new1->add = start;
        start = new1;
    }
}
void insertAtLast()
{
    if (start == NULL)
    {
        printf("List not found!");
    }
    else
    {
        int n;
        printf("Enter new element for insertion: ");
        scanf("%d", &n);
        new1 = (struct node *)malloc(sizeof(struct node));
        new1->data = n;
        new1->add = NULL;
        temp = start;

        while (temp->add != NULL)
        {
            temp = temp->add;
        }
        temp->add = new1;
    }
}
void insertAtMiddle()
{
    if (start == NULL)
    {
        printf("List not found!");
    }
    else
    {
        int n, pos, i = 1;
        printf("Enter new element for insertion: ");
        scanf("%d", &n);
        new1 = (struct node *)malloc(sizeof(struct node));
        new1->data = n;
        new1->add = NULL;

        printf("Enter the position: ");
        scanf("%d", &pos);

        next = start;
        while (i < pos)
        {
            prev = next;
            next = next->add;
            i++;
        }
        prev->add = new1;
        new1->add = next;
    }
}
void deleteFromFirst()
{
    if (start == NULL)
    {
        printf("List not found!");
    }
    else
    {
        temp = start;
        start = start->add;
        printf("Deleted element is %d", temp->data);
    }
}
void deleteFromLast()
{
    if (start == NULL)
    {
        printf("List not found!");
    }
    else
    {
        temp = start;
        while (temp->add != NULL)
        {
            prev = temp;
            temp = temp->add;
        }
        prev->add = NULL;
        printf("Deleted element is %d", temp->data);
        free(temp);
    }
}
void deleteFromMiddle()
{
    int pos, i = 1;
    if (start == NULL)
    {
        printf("List not found!");
    }
    else
    {
        printf("Enter the position: ");
        scanf("%d", &pos);
        temp = start;
        while (i < pos)
        {
            prev = temp;
            temp = temp->add;
            i++;
        }
        next = temp->add;
        prev->add = next;
        printf("Deleted element is %d", temp->data);
        free(temp);
    }
}
void display()
{
    if (start == NULL)
    {
        printf("List not found!\n");
    }
    else
    {
        temp = start;
        while (temp != NULL)
        {
            printf("  %d", temp->data);
            temp = temp->add;
        }
    }
}