

#include <iostream>

using namespace std;
void Swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void InterchangeSort(int a[], int n){	
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
	        if(a[i] > a[j])  
		        Swap(a[i], a[j]);
}

int main()
{
   int n = 6;
   int a[] = {8,6,1,4,5,0}; 
   							
   cout<<"Danh sach ban dau: ";
   for(int i =0;i<n; i++){
       cout<<a[i]<<" ";
   }
   InterchangeSort(a,n);
   	cout<<"\nDanh sach sau khi sap xep: ";
   for(int i =0;i<n; i++){
       cout<<a[i]<<" ";
   }
    

    return 0;
}
