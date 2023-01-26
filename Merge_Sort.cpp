#include <iostream>
using namespace std;
void merge(int a[], int left, int middle, int right){
	//Ben trai: left -> middle
	int len_left = middle - left + 1;
	//Ben phai: middle + 1 -> right
	int len_right = right - middle;
	
	//Tao mang tam thoi
	int a_left[len_left];
	int a_right[len_right];
	
	for(int i=0; i<len_left; i++){
		a_left[i] = a[left+i];
	}
	
	for(int i=0; i<len_right; i++){
		a_right[i] = a[middle+1+i];
	}
	//Gop hai mang thep quy tac phan tu nho hon dua vao mang gop truoc
	int i1 = 0; //Vi tri hien tai cua phan tu mang ben trai
	int i2 = 0; //Vi tri hien tai cua phan tu mang ben phai
	int k =left;
	while(i1 < len_left && i2 < len_right){
		if(a_left[i1] <= a_right[i2]){
			a[k] = a_left[i1];
			i1++;
		}else{
			a[k] = a_right[i2];
			i2++;
		}
		k++;
	
	}
	//Copy nhung phan cua mang ben trai chua duoc dua vao 
	while(i1 < len_left ){
		a[k] = a_left[i1];
		i1++;
		k++;
	}
	//Copy nhung phan cua mang ben phai chua duoc dua vao 
	while(i1 < len_right ){
		a[k] = a_right[i2];
		i2++;
		k++;
	}

}
void mergeSort(int a[], int left, int right){
	if(left < right){
		//Tim vi tri o giua
		int middle = (left + right) / 2;
		
		//Goi de quy sort tung phan ben trai va ben phai
		mergeSort(a, left, middle);
		mergeSort(a, middle + 1 , right);
		
		//Gop 2 phan ben trai va ben phai
		merge(a, left, middle, right);	
	
	}

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
   mergeSort(a, 0 , n-1);
   for(int i=0; i<n; i++){
   		cout<<a[i];
   }
    

    return 0;
}
