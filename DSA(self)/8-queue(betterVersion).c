#include <stdio.h>
#include <stdlib.h>
#define max 50

void insert();
void Delete();
void display();

int front = -1;
int rear = -1;
int queue[max];

void main()
{
  int choice;

    while(1)
    {
      printf("-------------------------");
      printf("\n1. INSERT");
      printf("\n2. DELETE");
      printf("\n3. DISPLAY");
      printf("\n4. EXIT");
      printf("\nEnter your choice: ");
      scanf("%d", &choice);
      printf("-------------------------");

      switch(choice)
        {
          case 1:
                insert();
                break;
          case 2:
                Delete();
                break;
          case 3:
                display();
                break;
          case 4:
                exit(0);
          default:
                printf("\nInvalid choice!\n");
        }
    }
}

void insert()
{
  if(rear == max - 1)
  {
    printf("\nQueue is full!\n");
  }
  else
  {
    int num;
    printf("\nEnter your queue element: ");
    scanf("%d", &num);
    if(front == -1)
    {
      front++;
    }
    rear++;
    queue[rear] = num;
  }
}

void Delete()
{
  if(front == -1 || front == rear + 1)
  {
    printf("\nQueue is empty!\n");
  }
  else
  {
    printf("\nDeleted element is %d\n", queue[front]);
    front++;
  }
}

void display()
{
  if(front == -1 || front == rear + 1)
  {
    printf("\nQueue is empty!\n");
  }
  else
  {
    printf("\n");
    for(int i = front; i <= rear; i++)
      {
        printf("  %d  |", queue[i]);
      }
    printf("\n");
  }
}