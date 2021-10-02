#include <iostream>
using namespace std;

void Merge(int a[], int l, int m, int r){
	int i, j, k;
	int n1=m-l+1;
	int n2=r-m;
	int temp1[n1], temp2[n2];
	for(i=0;i<n1;i++){
			temp1[i]=a[l+i];
		}
	for(j=0;j<n2;j++){
		temp2[j]=a[m+j+1];
	}
	i=0;
	j=0;
	k=l;
	while(i<n1 && j<n2){
		if(temp1[i]<=temp2[j]){
			a[k]=temp1[i]; 
			i++;
		}
		else{
			a[k]=temp2[j]; 
			j++;
		}
		k++;
	}
	while(i<n1){
		a[k]=temp1[i]; 
		i++; 
		k++;
	}
	while(j<n2){
		a[k]=temp2[j]; 
		j++; 
		k++;
	}
}

void MergeSort(int a[], int l, int r){
	if(l<r){
		int m= l+(r-l)/2;
		MergeSort(a, l , m);
		MergeSort(a, m+1, r);
		Merge(a, l , m , r);
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
	cout<<"\nElements of array is: [ ";
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";}
	cout<<"]";
	MergeSort(a, 0, n-1);
	cout<<"\nElements of array is: [ ";
	for(int j=0;j<n;j++){
		cout<<a[j]<<" ";}
	cout<<"]";
	return 0;
}