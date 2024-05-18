#include <stdio.h>

int fact(int);

int main()
{
  int n, result;
  printf("Enter your number: ");
  scanf("%d", &n);

  if(n < 0)
  {
    printf("Factorial of negative number does not exist.");
  }
  else
  {
    result = fact(n);
    printf("Factorial of %d is %d", n, result);
  }
  
  return 0;
}

int fact(int num)
{
  if(num == 0)
  {
    return 1;  //base case
  }
  else
  {
    return (num * fact(num - 1));  //recursive case
  }
}