#include<iostream>
#include<cstdlib>
using namespace std;
int count=0;

 

int partition(int A[],int l, int r)
{
    int x=l;
    int y=r;
    int pivot = A[l];
    
    count = count+3;
    
    while(x<y)
    {
        while(A[x]<=pivot)
        {
            x++;
            count =count+3;    
        }
    
        while(A[y]>pivot)
        {
             y--;
            count =count+3;        
        }
    
        if(x<y)
        {
            int t = A[x];
            A[x]=A[y];
            A[y] = t;
            count =count+4;    
            
        }
        
    }
     A[l] =A[y];
    A[y]= pivot;
    count = count+3;
    return y;
    
    
}


int randpartition(int A[],int l, int r)
{
    
int k = l+rand()%(r-l);
int t = A[l];
A[l]=A[k];
A[k]=t;
count =count +4;
return partition(A,l,r);    
}
void RandQuickSort(int A[],int l ,int r)
{
    if(l<r)
    {
        count++;
    int p = randpartition(A,l,r);
    RandQuickSort(A,l,p-1);
    RandQuickSort(A,p+1,r);
        
    }    
}


int main()
{
 int n;
    cout << "Enter the size of an array: ";
    cin >> n;

    int A[n];
    cout << "Enter the data items: \n";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }


cout<<"Before sorting: \n";
   for(int i=0 ;i<n ;i++)
        {
    cout<<A[i]<<"\t" ;
        }
        
    cout<<endl;
    
RandQuickSort(A,0,n-1);

cout<<"After sorting: \n";
 for(int i=0 ;i<n ;i++)
        {
    cout<<A[i]<<"\t" ;
        }
cout<<endl;        
cout<<"No. of Steps required : "<<count;        
        
return 0;

}

