#include <iostream>
using namespace std;

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void selSort(int a[],int n){
    int i, j, ind;
    for (i = 0; i < n-1; i++)
    {
        ind = i;
        for (j = i+1; j < n; j++)
        if (a[j] < a[ind]){
            ind = j;
        }
        if(ind!=i)
            swap(&a[ind], &a[i]);
    }
}
    
int main()
{
    int a[] = {2,6,4,8,1,3};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<"\nElements of Array: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    selSort(a, n);
    cout << "\nSorted array: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}