#include <stdio.h>

void bubbleSort(int arr[], int size);

int main()
{

  int array[] = {5, 9, 7, 12, 2, 67};
  int size = sizeof(array) / sizeof(array[0]);

  bubbleSort(array, size);

  return 0;
}

void bubbleSort(int arr[], int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = 0; j < size - 1 - i; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  for (int i = 0; i < size; i++)
  {
    printf("%d\t", arr[i]);
  }
}