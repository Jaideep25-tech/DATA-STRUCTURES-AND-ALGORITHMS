#include <iostream>
using namespace std;

void insertion_Sort(int a[], int n){
    int i,j, key;
    for (i = 1; i < n; i++){
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key){
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

int main(){
    int a[] = { 42, 24, 18, 3, 35 };
    int n = sizeof(a) / sizeof(a[0]);
    cout<<"\nElements of Array: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    insertion_Sort(a, n);
    cout << "\nSorted array: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}