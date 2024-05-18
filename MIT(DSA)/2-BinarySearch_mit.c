#include <stdio.h>

void main()
{
  int arr[10] = {6, 12, 18, 22, 31, 39, 55, 65, 75, 82};
  int target, mid;
  int start = 0, end = 9;

  printf("Enter your target value: ");
  scanf("%d", &target);

  while(start <= end)
    {
      mid = (start + end) / 2;
      if(arr[mid] == target)
      {
        printf("Element %d found at %d position", target, mid + 1);
        break;
      }
      else
      {
        if(arr[mid] < target)
        {
          start = mid + 1;
        }
        else
        {
          end = mid - 1;
        }
      }
    }
  
}