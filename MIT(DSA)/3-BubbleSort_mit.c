#include <stdio.h>

void main() {

  int arr[10] = {5, 9, 7, 12, 89, 36, 85, 27, 69, 2};
  int i, j, k, temp;
  int n = 10;

  for(i = 0; i < n - 1; i++)
  {
     for(j = 0; j < n - 1 - i; j++)
     {
        if(arr[j] > arr[j + 1])
        {
          temp = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = temp;
        }
     }
  }
  for(k = 0; k < n; k++)
  {
    printf("%d\t", arr[k]);
  }
  
}