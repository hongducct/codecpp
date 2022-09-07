#include <iostream>
using namespace std;


int iHoanVi[5];
int Bool[5];

void hoanvi(int k,int n){
    if(n<1){
        cout << iHoanVi << endl;
    }else{
        for(int i=1;i<=n;i++){
            if(!Bool[i]){
                iHoanVi[k]=i;
                Bool[i]=1;
                if(k==n){
                    for (int i = 1; i <= n; i++)
                        cout << iHoanVi[i] << " ";
                    cout << endl;
                }else hoanvi(k+1,n);
                Bool[i]=0;
            }
        }
    }

}

int main(){
    int n; 
    cin >> n;

    hoanvi(1,n);
    return 0;
}