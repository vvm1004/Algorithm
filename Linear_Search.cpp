
#include <iostream>

using namespace std;
int linearSearch(int a[], int n, int k){
  for(int i = 0; i<n; i++){
      if(a[i] == k){
          return i;
      }
  }
  return -1;
}
int SentinelSearch(int a[], int n, int k){
    a[n] = k;
    int i = 0;
    while(a[i] != k){
        i = i + 1;
    }
    if(i<n){
        return i;
    }else{
        return -1;
    }
}

int main()
{
    int n = 6;
    int a[] = {6,8,1,4,5,0};
    cout<<"Vi tri cua k la: " << SentinelSearch(a,n,5);

    return 0;
}

