#include <iostream>
using namespace std;

int coreNumber(int a, int b) {
    if(b==1){
        return a;
    }else{
        return a+coreNumber(a,b-1);
    }
}

int main(){
    cout << coreNumber(7,6);
    return 0;
}