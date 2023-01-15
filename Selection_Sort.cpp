

#include <iostream>

using namespace std;
int selectionSort(int a[], int n){ 
    for(int i = 0; i< n -1; i++){    
        int i_min = i;                  
        int v_min = a[i];			
        for(int j=i; j<n; j++){    
        	if(a[j] < v_min){	
        		v_min = a[j];		
        		i_min = j;		
			}
		}
		int temp = a[i];
		a[i] = a[i_min]; 
		a[i_min] = temp;      
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
   selectionSort(a,n);
    cout<<"\nDanh sach sau khi sap xep: ";
   for(int i =0;i<n; i++){
       cout<<a[i]<<" ";
   }

    return 0;
}
