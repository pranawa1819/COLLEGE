#include <iostream>
using namespace std;
int count = 0;

void BubbleSort(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                int t = A[j];
                A[j] = A[j + 1];
                A[j + 1] = t;
            }

            count = count + 8;
        }
        count = count + 4;
    }
}

int main()
{

    int A[20] , n ,i;
    cout<<"Enter the size of an array:";
    cin>>n;
    cout<<"ENTER THE DATA ITEMS: \n";
    for(i=0; i<n; i++){
    cin>>A[i];
}

    cout << "Before sorting: \n";
    for ( i = 0; i < n; i++)
    {
        cout << A[i] << "\t";
    }
    cout << endl;
    BubbleSort(A, n);
    cout << "After sorting: \n";
    for (i = 0; i < n; i++)
    {
        cout << A[i] << "\t";
    }
    cout << endl;
    cout << "No. of Steps required : " << count;
    return 0;
}