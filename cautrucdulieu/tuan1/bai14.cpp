#include <iostream>
using namespace std;

string revertString(string str, int le){
    int n = str.length();
    string newStr;
    if(le==0) return newStr;
    else {
        return newStr=str[le-1] + revertString(str, le-1);
    }
}

bool cmp(string str, string newStr) {
    if( str==newStr){
        return true;
    }else return false;
}

int main(){
    string str = "connoc";
    cout << cmp(str,revertString(str, str.length())) << endl;
}