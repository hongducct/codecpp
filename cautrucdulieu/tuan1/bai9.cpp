#include <iostream>
using namespace std;

void findMaxMin(int *arr , int n, int max, int min ){
    if(max<arr[n]){
        max = arr[n];
    }
    if(min>arr[n]){
        min = arr[n];
    }

    if(n==0){
        cout << "max: " << max << endl;
        cout << "min: " << min << endl;
    }else return findMaxMin(arr,n-1, max,min);
}

int main(){
    int a[10]={23,124,123,12,3,2,4,3,4,90};
    int min=a[0];
    int max=a[0];
    findMaxMin(a,10, max, min);
}