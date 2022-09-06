#include <iostream>
using namespace std;

int sapxep(int *arr, int n){
    //chẵn đứng trước lẻ
    if(n==0) return *arr;
    else if(arr[n]%2==0){
        for(int i=0; i<n; i++){
             if(arr[n]%2==0){
                int temp=arr[n];
                arr[n]=arr[n-1];
                arr[n-1]=temp;
                sapxep(arr,n-1);
             }
                
        }
        
    }else{
        sapxep(arr,n-1);
    }
    return *arr;
}

int main(){
    // creat 1 array with 10 elements
    int a[10]={23,124,123,12,3,2,4,3,4,90};
    sapxep(a,9);
    for(int i=0; i<10; i++){
        cout << a[i] << " " ;
    }
    return 0;
}