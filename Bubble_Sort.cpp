

#include <iostream>

using namespace std;
int bubbleSort(int a[], int n){ 
    for(int i=0; i<n-1; i++){
    	for(int j=0; j<n-1-i; j++){
    		if(a[j] > a[j+1]){
    			int temp = a[j];
    			a[j] = a[j+1];
    			a[j+1] = temp;
			}
		}
	}

}

int main()
{
   int n = 6;
   int a[] = {8,6,1,4,5,0}; 
   							
   cout<<"Danh sach ban dau: ";
   for(int i =0;i<n; i++){
       cout<<a[i]<<" ";
   }
   bubbleSort(a,n);
   	cout<<"\nDanh sach sau khi sap xep: ";
   for(int i =0;i<n; i++){
       cout<<a[i]<<" ";
   }
    

    return 0;
}
