#include <iostream>
using namespace std;

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void Bubblesort(int a[],int n){
    int i, j ,flag=0;
    for(i=0; i<n-1; i++){
        for(j=0; j<n-1-i;j++){
            if(a[j]>a[j+1]){
                swap(&a[j],&a[j+1]);
                flag=1;
            }
        }
        if(flag==0){
            break;
        }
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
    cout<<"\nElements of Array: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    Bubblesort(a,n);
    cout<<"\nSorted Array: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}