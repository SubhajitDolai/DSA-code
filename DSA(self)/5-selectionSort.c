#include <stdio.h>

void selectionSort(int arr[], int n);

int main()
{
  int array[] = {25, 19, 15, 2, 11, 17, 3};
  int size = sizeof(array) / sizeof(array[0]);

  selectionSort(array, size);

  return 0;
}

void selectionSort(int array[], int size)
{
  for (int i = 0; i < size; i++)
  {
    for(int j = 0; j < size; j++)
    {
      if(array[j] > array[i])
      {
        int temp = array[j];
        array[j] = array[i];
        array[i] = temp;
      }
    }
  }
  for (int i = 0; i < size; i++)
  {
    printf("%d\t", array[i]);
  }
}