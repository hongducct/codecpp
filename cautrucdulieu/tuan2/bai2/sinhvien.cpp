#include "sinhvien.h"

template<class T>
SinhVien<T>::SinhVien(int size) {
    if (size < 0) {
        cerr << "Số lượng phần tử phải là số dương." << endl;
        cout << "Thiết lập số lượng phần tử tối đa trong danh sách là 100." << endl;
        maxSize = 20;
    } else
        maxSize = size;

    length = 0;

    list = new T[maxSize];
}

template <class T>
SinhVien<T>::SinhVien(const SinhVien<T>& otherList) {
    maxSize = otherList.maxSize;
    length = otherList.length;

    list = new T[maxSize];
    for (int i = 0; i < length; i++)
        list[i] = otherList.list[i];
}

template<class T>
bool SinhVien<T>::isEmpty() const {
    return (length == 0);
}

template<class T>
bool SinhVien<T>::isFull() const {
    return (length == maxSize);
}

template<class T>
int SinhVien<T>::getListSize() const {
    return length;
}

template<class T>
int SinhVien<T>::getMaxListSize() const {
    return maxSize;
}

template<class T>
void SinhVien<T>::clearList() {
    length = 0;
}

template<class T>
void SinhVien<T>::insert(const T& insertedElement) {
    if (length >= maxSize)
        cerr << "Không thể chèn được phần tử do danh sách đã đầy." << endl;
    else {
        list[length] = insertedElement;
        length++;
    }
}

template <class T>
void SinhVien<T>::insert(int n, const T & insertedElement){
    if (length >= maxSize)
        cerr << "Không thể chèn được phần tử do danh sách đã đầy." << endl;
    else{
        for(int i=length;i>=n;i--){
            list[i]=list[i-1];
        }
        list[n-1]=insertedElement;
        length++;
    }
}

template <class T>
const SinhVien<T>& SinhVien<T>::operator=(const SinhVien<T>& otherList) {
    if (this != &otherList) {
        delete [] list;
        maxSize = otherList.maxSize;
        length = otherList.length;

        list = new T[maxSize];
        for (int i = 0; i < length; i++)
            list[i] = otherList.list[i];
    }
    return *this;
}

template<class T>
void SinhVien<T>::print() const {
    for (int i = 0; i < length; i++)
        cout << list[i] << " ";
    cout << endl;
}

template class SinhVien<int>;