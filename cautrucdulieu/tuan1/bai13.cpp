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

int main(){
    string str = "pots&pans";
    cout << revertString(str, str.length()) << endl;
}