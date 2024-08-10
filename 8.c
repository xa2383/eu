#include <stdio.h>
void tower(int N,char From , char To, char Aux);
int moves;
void main()
{

    int N;
    printf("Enter the number of disks:");
    scanf("%d",&N);
    tower(N,'A','C','B');
    printf("\n Total number of disk moves = %d",moves);
}
void tower(int N,char From , char To, char Aux)
{
    if(N==1)
    {
        printf("\n Move Disk 1 from stand %c to stand %c",From,To);
        moves++;
        return;
    }
    tower(N-1,From,Aux,To);
    printf("\n  Move Disk %d from stand %c to stand %c ",N,From,To);
    moves++;
    tower(N-1,Aux,To,From);
}


#include <stdio.h>

// Function prototype
void selectionSort(int arr[], int n);

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

    // Perform selection sort
    selectionSort(arr, n);

    // Output: Sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

// Function to perform selection sort
void selectionSort(int arr[], int n)
{
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++)
        {
        // Assume the current index is the minimum
        minIndex = i;

        // Find the index of the minimum element in the unsorted part of the array
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}
