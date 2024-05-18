#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *pre;
    struct node *next;
};
struct node *start = NULL, *temp, *q, *p;

void insertFirst();
void insertLast();
void insertMiddle();
void deleteFirst();
void deleteLast();
void deleteMiddle();
void display();

int main()
{

    while (1)
    {
        int choice;
        printf("\n----------------------------\n");
        printf("1. insertfirst\n");
        printf("2. insertlast\n");
        printf("3. insertmiddle\n");
        printf("4. deletefirst\n");
        printf("5. deletelast\n");
        printf("6. deletemiddle\n");
        printf("7. display\n");
        printf("8. exit\n");
        printf("----------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertFirst();
            break;
        case 2:
            insertLast();
            break;
        case 3:
            insertMiddle();
            break;
        case 4:
            deleteFirst();
            break;
        case 5:
            deleteLast();
            break;
        case 6:
            deleteMiddle();
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}

void insertFirst()
{
    int n;
    printf("Enter element to insert: ");
    scanf("%d", &n);

    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = n;
    temp->pre = NULL;
    temp->next = start;
    if (start != NULL)
    {
        start->pre = temp;
    }
    start = temp;
}

void insertLast()
{
    int n;
    printf("Enter element to insert last: ");
    scanf("%d", &n);

    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = n;
    temp->pre = NULL;
    temp->next = NULL;

    if (start == NULL)
    {
        start = temp;
        return;
    }

    q = start;
    while (q->next != NULL)
    {
        q = q->next;
    }
    q->next = temp;
    temp->pre = q;
}

void insertMiddle()
{
    int n, pos, i = 1;
    printf("Enter element to insert middle: ");
    scanf("%d", &n);

    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = n;
    temp->pre = NULL;

    printf("Enter the position: ");
    scanf("%d", &pos);

    q = start;
    while (i < pos && q != NULL)
    {
        p = q;
        q = q->next;
        i++;
    }
    if (q == NULL)
    {
        printf("Position out of range\n");
        free(temp);
        return;
    }
    if (p != NULL)
    {
        p->next = temp;
    }
    else
    {
        start = temp;
    }
    temp->pre = p;
    temp->next = q;
    if (q != NULL)
    {
        q->pre = temp;
    }
}

void deleteFirst()
{
    if (start == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }

    q = start;
    start = start->next;
    if (start != NULL)
    {
        start->pre = NULL;
    }
    printf("Deleted element is %d\n", q->data);
    free(q);
}

void deleteLast()
{
    if (start == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }

    q = start;
    while (q->next != NULL)
    {
        p = q;
        q = q->next;
    }
    if (p != NULL)
    {
        p->next = NULL;
    }
    else
    {
        start = NULL;
    }
    printf("Deleted element is %d\n", q->data);
    free(q);
}

void deleteMiddle()
{
    int pos, i = 1;
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Enter position to delete: ");
    scanf("%d", &pos);

    q = start;
    while (i < pos && q != NULL)
    {
        p = q;
        q = q->next;
        i++;
    }
    if (q == NULL)
    {
        printf("Position out of range\n");
        return;
    }
    if (p != NULL)
    {
        p->next = q->next;
    }
    else
    {
        start = q->next;
    }
    if (q->next != NULL)
    {
        q->next->pre = p;
    }
    printf("Deleted element is %d\n", q->data);
    free(q);
}

void display()
{
    q = start;
    printf("Double linked list: ");
    while (q != NULL)
    {
        printf("%d ", q->data);
        q = q->next;
    }
    printf("\n");
}