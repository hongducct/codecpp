#include "sinhvien.cpp"

int main(){
    SinhVien<string> sv(10);
    cout << sv.getListSize() << endl;
    cout << sv.getMaxListSize() << endl;
    cout << sv.isEmpty() << endl;

    for(int i=0;i<4;i++){
        string x;
        cin >> x;
        sv.insert(x);
    }
    sv.print();
    return 0;
}