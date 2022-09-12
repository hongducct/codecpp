#include "ArrayList.h"

template<class elementType>
ArrayList<elementType>::ArrayList(int size) {
    if (size < 0) {
        cerr << "Số lượng phần tử phải là số dương." << endl;
        cout << "Thiết lập số lượng phần tử tối đa trong danh sách là 100." << endl;
        maxSize = 100;
    } else
        maxSize = size;

    length = 0;

    list = new elementType[maxSize];
}

template <class elementType>
ArrayList<elementType>::ArrayList(const ArrayList<elementType>& otherList) {
    maxSize = otherList.maxSize;
    length = otherList.length;

    list = new elementType[maxSize];
    for (int i = 0; i < length; i++)
        list[i] = otherList.list[i];
}

template<class elementType>
bool ArrayList<elementType>::isEmpty() const {
    return (length == 0);
}

template<class elementType>
bool ArrayList<elementType>::isFull() const {
    return (length == maxSize);
}

template<class elementType>
int ArrayList<elementType>::getListSize() const {
    return length;
}

template<class elementType>
int ArrayList<elementType>::getMaxListSize() const {
    return maxSize;
}

template<class elementType>
void ArrayList<elementType>::clearList() {
    length = 0;
}

template<class elementType>
void ArrayList<elementType>::insert(const elementType& insertedElement) {
    if (length >= maxSize)
        cerr << "Không thể chèn được phần tử do danh sách đã đầy." << endl;
    else {
        list[length] = insertedElement;
        length++;
    }
}
template <class elementType>
void ArrayList<elementType>::insert(int n, const elementType & insertedElement){
    if (length >= maxSize)
        cerr << "Không thể chèn được phần tử do danh sách đã đầy." << endl;
    else{
        for(i=n;i<length;i++){
            list[i+1]=list[i];
        }
        list[n]=insertedElement;
        length++;
    }
}

template <class elementType>
void ArrayList<elementType>::replace(int n, const elementType &insertedElement){
    insertedElement=n;
}

template <class elementType>
void ArrayList<elementType>::remove(int n){
    for(i=n;i<length;i++){
        list[n]=list[n+1];
    }
    length--;
}

template <class elementType>
void ArrayList<elementType>::retrieve(int n, elementType &insertedElement){
    int temp=insertedElement;
    insertedElement=n;
    n=temp;
}

template <class elementType>
int ArrayList<elementType>::search(const elementType &insertedElement) const{
    for(int i=0;i<length;i++){
        if(list[i]==insertedElement){
            return i;
        }
    }
}

template <class elementType>
const ArrayList<elementType>& ArrayList<elementType>::operator=(const ArrayList<elementType>& otherList) {
    if (this != &otherList) {
        delete [] list;
        maxSize = otherList.maxSize;
        length = otherList.length;

        list = new elementType[maxSize];
        for (int i = 0; i < length; i++)
            list[i] = otherList.list[i];
    }
    return *this;
}

template<class elementType>
void ArrayList<elementType>::print() const {
    for (int i = 0; i < length; i++)
        cout << list[i] << " ";
    cout << endl;
}

template class ArrayList<int>;
