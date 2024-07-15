#include<iostream>
using namespace std;
int count =0;

void InsertionSort(int A[],int n)
{
    int key;
    int j;
    for(int i=1;i<=n-1;i++)
    {
        key =A[i];
    
        for(j=i-1;A[j]>key && j>=0;j--)
        {
            A[j+1] =A[j];
            count += 7;
        }
        A[j+1] = key;
            count += 7;
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
    
    cout<<"Before sorting :\n";
    for( i=0 ;i<n;i++)
    {
        cout<<A[i]<< "\t";
        
    }
     InsertionSort(A,n);
    
    cout<<"\nAfter sorting :\n";
    for( i=0 ;i<n;i++)
    {
        cout<<A[i]<< "\t";
        
    }
    
    cout<<"\nRequired Number of steps for "<< n << " sized data: "<<count;
    return 0;
}