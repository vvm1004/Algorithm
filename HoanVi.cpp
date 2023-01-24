
#include <iostream>
using namespace std;


bool check[100];
int hoanVi[100];


void printHoanVi(int hoanVi[100], int n){
	for(int j=1; j<=n; j++){
		cout<<hoanVi[j];
	}
	
	cout<< "\n";

}

void timHoanVi(int k, int n){ 
    for(int i=1; i<=n; i++){
    	if(check[i]){
			hoanVi[k] = i;
			if(k==n){
				printHoanVi(hoanVi, n);
			}else{
				check[i] = false;
				timHoanVi(k+1,n);
				check[i] = true;
			}
		}
	}

}

int main()
{
   int n;
   cout<< " Nhap vao n: ";
   cin>>n;
   
   for(int i=1; i<=n; i++){
   		check[i] = true;
   }
    timHoanVi(1,n);

    return 0;
}
