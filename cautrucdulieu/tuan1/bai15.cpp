#include <iostream>
using namespace std;

bool check(string str1, string nguyenAm, int i ,int j,int count){
    int le= str1.length();
    if(i==0&&j==0){
        if(str1[i]==nguyenAm[j]) count++;
        return count >= le/2;
    }else if(j==0){
        if(str1[i]==nguyenAm[j]) count++;
        return check(str1, nguyenAm, i-1 ,le-1,count);
        
    }else{
        if(str1[i]==nguyenAm[j]){
            count++;
        }
        return check(str1, nguyenAm, i ,j-1,count);
        
    }
    return count >= le/2;
}

int main(){
    int count = 0;

    string str1="abcdefghi";
    string str2="oueaikkk";
    string nguyenAm = "ueoai";
    cout << check(str1, nguyenAm, str1.length()-1, nguyenAm.length()-1,count);
    return 0;
}