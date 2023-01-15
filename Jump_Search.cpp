
#include <iostream>

using namespace std;
int jumpSearch(int a[], int n, int k){
   int d = 3; //so tu nhien > 1
   int i = 0;
   int j = i + d;
   while(j<n && a[j] < k){ // nhay theo buoc d
       j = j + d;
       i = i + d;
   }
   if(j >= n){
       j = n -1;
   }
   while(a[i] < k){ // tim kiem khoang i -> j
       i = i + 1;
       if(i >= n || i>j){
           return -1;
       }
   }
   if(a[i] == k)
        return i;
   else
        return -1;
}

int main()
{
    int n = 6;
    int a[] = {6,8,1,4,5,0};
    cout<<"Vi tri cua k la: " << jumpSearch(a,n,5);

    return 0;
}

