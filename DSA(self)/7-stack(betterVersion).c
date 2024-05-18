#include <stdio.h>
#include <stdlib.h>
#define max 50

void push();
void pop();
void Top();
void display();
void exitProgram();

int stack[max];
int top = -1;

int main()
{
  while(1)
  {
  
    int choice;
    printf("---------------------");
    printf("\n1: PUSH");
    printf("\n2: POP");
    printf("\n3: TOP");
    printf("\n4: DISPLAY");
    printf("\n5: EXIT");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    printf("---------------------");
  
    switch(choice)
      {
        case 1:
              push();
              break;      
        case 2:
              pop();
              break;      
        case 3:
              Top();
              break;      
        case 4:
              display();
              break;      
        case 5:
              exitProgram();
              break;
        default:
              printf("\nInvalid choice!\n");
      }
  }
  return 0;
}

void push()
{
  if(top == max - 1)
  {
    printf("\nStack is full!\n");
  }
  else
  {
    printf("\nEnter the value to push: ");
    top++;
    scanf("%d", &stack[top]);
  }
}

void pop()
{
  if(top == -1)
  {
    printf("\nStack is empty!\n");
  }
  else
  {
    printf("\nPoped element: %d\n", stack[top]);
    top--;
  }
}

void Top()
{
  if(top == -1)
  {
    printf("\nStack is empty!\n");
  }
  else
  {
    printf("\nTopmost element: %d\n", stack[top]);
  }
}

void display()
{
  if(top == -1)
  {
    printf("\nStack is empty!\n");
  }
  else
  {
    for(int i = top; i >= 0; i--)
      {
        printf("\n|  %d\n", stack[i]);
        printf("|----------");
      }
  }
}

void exitProgram()
{
  printf("\nThanks for using Stack :)\n");
  exit(0);
}