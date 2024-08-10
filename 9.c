#include<stdio.h>

// Function prototype
int fact(int n);

int main()
{
    int n, result;
    printf("Enter the number: ");
    scanf("%d", &n);
    result = fact(n);
    printf("Factorial is %d", result);
    return 0;
}

int fact(int n)
{
    if(n == 0)
        return 1;
    else
        return n * fact(n - 1);
}


#include <stdio.h>

// Function prototype
void insertionSort(int arr[], int n);

int main() {
    int n;

    // Input: size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input: array elements
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform insertion sort
    insertionSort(arr, n);

    // Output: Sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

// Function to perform insertion sort
void insertionSort(int arr[], int n)
 {
    int i, key, j;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key to one position ahead of their current position
        while (j >= 0 && arr[j] > key) 
      {
            arr[j + 1] = arr[j];
            j = j - 1;
       }
        arr[j + 1] = key;
    }
}
