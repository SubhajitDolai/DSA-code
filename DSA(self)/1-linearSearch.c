#include <stdio.h>

int linearSearch(int arr[], int size, int target);

int main()
{
  int num[] = {2, 4, 5, 3, 7, 9, 8, 1, 6, 10};

  int size = sizeof(num) / sizeof(num[0]);

  int target = 10;

  int index = linearSearch(num, size, target);

  if (index != -1)
  {
    printf("Element found at index: %d", index);
  }
  else
  {
    printf("Element not found!");
  }

  return 0;
}

int linearSearch(int arr[], int size, int target)
{
  for (int i = 0; i < size; i++)
  {
    if (arr[i] == target)
    {
      return i;
      break;
    }
  }
  return -1;
}
