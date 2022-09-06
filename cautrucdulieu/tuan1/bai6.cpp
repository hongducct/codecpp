#include <iostream>
#include "math.h"
using namespace std;

int stringToInt(string str,int le) {
    int n = str.length()-1;
    if(le==0){
        return (str[n]-48);
    }else {
        return (str[n-le]-48)*pow(10,le) + stringToInt(str,le-1);
    }
}

int main(){
    string str = "123456789";
    cout << stringToInt(str, str.length()-1) << endl;
    return 0;
}