#include <stdio.h>
int binarySearch(int arr[], int low, int high, int key);

int main() {
    int n, key;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter sorted array elements:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the key to search: ");
    scanf("%d", &key);
    int result = binarySearch(arr, 0, n - 1, key);
    if (result != -1) 
    {
        printf("Key %d found at index %d.\n", key, result);
    }
    else
    {
        printf("Key %d not found in the array.\n", key);
    }

    return 0;
}

int binarySearch(int arr[], int low, int high, int key) 
{
    if (low <= high) 
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) 
        {
            return mid;  
        } else if (arr[mid] < key) 
        {
            return binarySearch(arr, mid + 1, high, key);  
        } else 
        {
            return binarySearch(arr, low, mid - 1, key);  
        }
    }

    return -1;  
}





#include <stdio.h>

// Function prototype
void bubbleSort(int arr[], int n);

int main()
{
    int n;

    // Input: size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input: array elements
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Perform bubble sort
    bubbleSort(arr, n);

    // Output: Sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

// Function to perform bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
