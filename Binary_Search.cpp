
#include <iostream>

using namespace std;
int binarySearch(int a[], int n, int k){
    int left = 0; int right = n-1;
    while(left<=right){
        int mid = (left + right ) /2; //lay phan nguyen
        if(a[mid] == k)
            return mid;
        else if (a[mid] < k)
            left = mid + 1;
        else 
            right = mid -1;
    }
    return -1;
}

int main()
{
    int n = 6;
    int a[] = {6,8,1,4,5,0};
    cout<<"Vi tri cua k la: " << binarySearch(a,n,5);

    return 0;
}

