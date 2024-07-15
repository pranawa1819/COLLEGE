#include<iostream>
using namespace std;

int count = 0;

void Merge(int A[], int l, int m, int r, int B[]) {
    int x = l;
    int y = m + 1;
    int k = l;

    count += 3; // for initializations
    while(x <= m && y <= r) {
        if(A[x] < A[y]) {
            B[k++] = A[x++];
            count += 6; // for comparison and assignments
        } else {
            B[k++] = A[y++];
            count += 6; // for comparison and assignments
        }
    }

    while(x <= m) {
        B[k++] = A[x++];
        count += 6; // for assignments
    }

    while(y <= r) {
        B[k++] = A[y++];
        count += 6; // for assignments
    }

    for(int i = l; i <= r; i++) {
        A[i] = B[i];
        count += 5; // for assignment
    }
}

void MergeSort(int A[], int l, int r, int B[]) {
    if(l < r) {
        count += 3; // for if condition and mid calculation
        int m = l + (r - l) / 2;
        MergeSort(A, l, m, B);
        MergeSort(A, m + 1, r, B);
        Merge(A, l, m, r, B);
    }
}

int main() {
    int n;
    cout << "Enter the size of an array: ";
    cin >> n;

    int A[n], B[n];
    cout << "Enter the data items: \n";
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cout << "Before sorting: \n";
    for(int i = 0; i < n; i++) {
        cout << A[i] << "\t";
    }
    cout << endl;

    MergeSort(A, 0, n - 1, B);

    cout << "After sorting: \n";
    for(int i = 0; i < n; i++) {
        cout << A[i] << "\t";
    }
    cout << endl;

    cout << "No. of Steps required: " << count << endl;

    return 0;
}
