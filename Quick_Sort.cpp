#include <iostream>
using namespace std;
void swap(int a[], int x, int y){
	int temp = a[x];
	a[x] = a[y];
	a[y] = temp;

}
int partition(int a[], int left, int right){
	//Gia tri pivot bang gia tri phan tu dau tien
	int pivot = a[left];
	
	int count = 0;
	
	//Dem so luong phan tu nam ben trai pivot
	
	for(int i = left+1; i<=right; i++){
		if(a[i] <= pivot)
			count++;
	}
	
	//Lay vi tri cho gia tri pivot
	int pivotIndex = left+count;
	
	//Hoan vi
	swap(a, left, pivotIndex);
	
	int i = left;
	int j = right;
	while(i<pivotIndex && j>pivotIndex){
		while(a[i]<=pivot){
			i++;
		}
		while(a[j]>pivot){
			j--;
		}
		if(i<pivotIndex && j>pivotIndex){
			swap(a,i,j);
		}
	}
	return pivotIndex;

}
void quickSort(int a[], int left, int right){
	if(left>=right){
		return;
	}
	//Chia
	int pivot = partition(a, left, right);
	
	//Tri
	//Sap xep ben trai
	 quickSort(a, left, pivot-1);
	 
	 //Sap xep ben phai
	 quickSort(a, pivot+1, right);
	 

}
int main()
{
   int n;
   int a[1000];
   							
   cout<<"Nhap vao n: ";
   cin>>n;
   
   cout<<"Nhap vao day so gom n phan tu: ";
   for(int i=0; i<n; i++){
   		cin>>a[i];
   }
   quickSort(a, 0 , n-1);
   cout<<"Day so sau khi duoc sap xep: ";
   for(int i=0; i<n; i++){
   		cout<<a[i]<<" ";
   }
    

    return 0;
}
