#include <stdio.h>

void main()
{
  int arr[50], size, target, i, flag = 0;
  printf("Enter the number of elements in array: ");
  scanf("%d", &size);
  
  printf("Enter %d integer(s): \n", size);
  for(i = 0; i < size; i++)
    {
      scanf("%d", &arr[i]);
    }

  printf("Enter the number to search: ");
  scanf("%d", &target);

  for(i = 0; i < size; i++)
    {
      if(arr[i] == target)
      {
        printf("%d is present at location %d.\n", target, i + 1);
        flag = 1;
        break;
      }
    }
  
  if(flag == 0)
  {
    printf("%d is not present in the array.\n", target);
  }
}