#include <iostream>
using namespace std;

int count = 0;

int partition(int A[], int l, int r) {
    int pivot = A[l];
    int i = l, j = r;

    count += 3; // for initializations

    while (i < j) {
        while (i <= r && A[i] <= pivot) {
            i++;
            count += 3; // for comparison and increment
        }

        while (A[j] > pivot) {
            j--;
            count += 3; // for comparison and decrement
        }

        if (i < j) {
            swap(A[i], A[j]);
            count += 4; // for swap operation
        }
    }

    A[l] = A[j];
    A[j] = pivot;
    count += 3; // for final swap operations

    return j;
}

void QuickSort(int A[], int l, int r) {
    if (l < r) {
        count++; // for if condition
        int p = partition(A, l, r);
        QuickSort(A, l, p - 1);
        QuickSort(A, p + 1, r);
    }
}

int main() {
    int n;
    cout << "Enter the size of an array: ";
    cin >> n;

    int A[n];
    cout << "Enter the data items: \n";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cout << "Before sorting: \n";
    for (int i = 0; i < n; i++) {
        cout << A[i] << "\t";
    }
    cout << endl;

    QuickSort(A, 0, n - 1);

    cout << "After sorting: \n";
    for (int i = 0; i < n; i++) {
        cout << A[i] << "\t";
    }
    cout << endl;

    cout << "No. of Steps required: " << count << endl;

    return 0;
}
