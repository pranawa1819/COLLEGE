#include <stdio.h>

// Function to perform selection sort and count the number of steps
void Selection_Sort(int A[], int n, int *count) {
    int least, loc, temp;
    for (int i = 0; i < n - 1; i++) {
        least = A[i];
        loc = i;

        for (int j = i + 1; j < n; j++) {
            if (A[j] < least) {
                least = A[j];
                loc = j;
            }
            (*count) += 6; // Increment count for each comparison
        }

        // Swap the elements
        temp = A[i];
        A[i] = A[loc];
        A[loc] = temp;
        (*count) += 9; // Increment count for each swap
    }
}

int main() {
    int n, count = 0; // Initialize count to 0

    // Prompt the user to enter the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Declare the array with the specified size
    int A[n];
    
    // Prompt the user to enter the elements of the array
    printf("Enter the numbers: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    // Display the array before sorting
    printf("Before sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d \t", A[i]);
    }
    printf("\n");

    // Perform selection sort and count the steps
    Selection_Sort(A, n, &count);

    // Display the array after sorting
    printf("After sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d \t", A[i]);
    }
    printf("\n");

    // Display the number of steps required for sorting
    printf("Required number of steps for %d sized data: %d\n", n, count);

    return 0;
}

