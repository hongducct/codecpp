#include <iostream>
using namespace std;

int findMax(int *a,int n,int max){
    if(max<a[n]){
        max=a[n];
    }
    if(n==0){
        return max;
    }else{
        return findMax(a,n-1,max);
    }
}

int main(){
    int a[10]={23,124,123,12,3,2,4,3,4,90};
    int max=a[0];
    cout<<findMax(a,10,max);
    return 0;
}