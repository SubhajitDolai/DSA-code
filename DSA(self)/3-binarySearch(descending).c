#include <stdio.h>

int binarySearch(int array[], int start, int end, int target);

int main()
{
    int arr[] = {20, 18, 16, 14, 12, 10, 8, 6, 4, 2};
    int target = 18;
    int size = sizeof(arr) / sizeof(arr[0]);

    int index = binarySearch(arr, 0, size - 1, target);

    if (index != -1)
    {
        printf("Element is present at index: %d", index);
    }
    else
    {
        printf("Element not found!");
    }

    return 0;
}

int binarySearch(int array[], int start, int end, int target)
{

    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (array[mid] == target)
        {
            return mid;
        }
        else if (array[mid] > target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}