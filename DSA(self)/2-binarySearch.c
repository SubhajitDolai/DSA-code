#include <stdio.h>

int binarySearch(int arr[], int start, int end, int target);

int main()
{
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int target = 12;
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = binarySearch(arr, 0, n - 1, target);
    if (result == -1)
        printf("Element is not present in array\n");
    else
        printf("Element is present at index %d\n", result);
    return 0;
}

// Function to perform binary search
int binarySearch(int arr[], int start, int end, int target)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        // Check if target is present at mid
        if (arr[mid] == target)
            return mid;

        // If target is greater, ignore start half
        if (arr[mid] < target)
            start = mid + 1;

        // If target is smaller, ignore end half
        else
            end = mid - 1;
    }

    // If target is not present in array
    return -1;
}