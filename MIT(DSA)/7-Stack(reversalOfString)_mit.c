#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define size 100

void push(char);
char pop();

int stack[size];
char str[size];
char top = -1;

int main()
{
  int i;
  printf("Enter your string: ");
  fgets(str, size, stdin);
  
  for(i = 0; i < strlen(str); i++)
    {
      push(str[i]);
    }
  for(i = 0; i < strlen(str); i++)
    {
      str[i] = pop();
    }

  printf("\nReversed string: %s", str);
  
  return 0;
}

void push(char ch)
{
  if(top == size - 1)
  {
    printf("Stack is full!\n");
  }
  else
  {
    top++;
    stack[top] = ch;
  }
}
char pop()
{ 
  char c;
  if(top == -1)
  {
    printf("Stack is empty!\n");
  }
  else
  {
    c = stack[top];
    top--;
    return c;
  }
}