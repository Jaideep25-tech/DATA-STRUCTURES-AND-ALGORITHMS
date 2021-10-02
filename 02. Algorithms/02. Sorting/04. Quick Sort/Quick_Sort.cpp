#include <iostream>
using namespace std;

void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

int partition(int a[], int l, int h){
    int pivot,i,j;
    pivot=a[h];//rightmost element
    i=l-1;
    for(j=l;j<=h-1;j++){
        if (a[j] < pivot){
            i++; swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[h]);
    return (i+1);
}

void quickSort(int a[], int l, int h){
    int index;
    if (l < h){
        index = partition(a, l, h);
        quickSort(a, l, index - 1);
        quickSort(a, index + 1, h);
    }
}

int main(){
    int a[30], n;
    cout<<"Enter no. of elements: ";
    cin>>n;
    cout<<"Enter elements of array: ";
    for(int i=0;i<n;i++){
        cin>>a[i];  
    }
    cout << "\nGiven array: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    quickSort(a, 0, n - 1);
    cout << "\nSorted array: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}