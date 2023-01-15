

#include <iostream>

using namespace std;
void insertionSort(int a[], int n){
    for(int i = 1; i<n; i++){
        int j = i;
        while(j>0 && a[j]<= a[j-1]){
            int temp = a[j];
            a[j] = a[j-1];
            a[j-1] = temp;
            j--;
        }
    }
}
void insertionSort2(int a[], int n){
    for(int i = 1; i<n; i++){
        int key = a[i];
        int j = i - 1;
        while(j>=0 && a[j] > key){
           a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}
int main()
{
   int n = 6;
   int a[] = {6,8,1,4,5,0};
   cout<<"Danh sach ban dau: ";
   for(int i =0;i<n; i++){
       cout<<a[i]<<" ";
   }
   insertionSort2(a,n);
   cout<<"\nDanh sach sau khi sap xep: ";
   for(int i =0;i<n; i++){
       cout<<a[i]<<" ";
   }

    return 0;
}
