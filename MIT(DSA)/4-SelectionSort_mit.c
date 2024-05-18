#include <stdio.h>

void main() {

  int arr[10] = {5, 9, 7, 12, 89, 36, 85, 27, 69, 2};
  int i, j, k, temp;
  
  for(i = 0; i < 10; i++)
  {
    for(j = 0; j < 10; j++)
    {
      if(arr[i] < arr[j])
      {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
  
  for(k = 0; k < 10; k++)
  {
    printf("%d\t", arr[k]);
  }
}