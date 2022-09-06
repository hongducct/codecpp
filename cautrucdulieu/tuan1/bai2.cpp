#include <iostream>
using namespace std;

int getSum(int x[4][4],int i, int j, int k){
    if(i==0 && j==0){
         return x[i][j];
    }
    else if(j==0){
        return x[i][j]+ getSum(x,i-1,k,k);
    }else{
        return x[i][j] + getSum(x,i,j-1,k);
    }
}

int main(){
    int x[4][4]={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    cout << getSum(x, 4-1, 4-1, 4-1)<< endl;
    return 0;
}