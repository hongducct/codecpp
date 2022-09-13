#ifndef SINHVIEN_H
#define SINHVIEN_H

#include <iostream>

using namespace std;

template <class T>
class SinhVien {
    private: 
        T *list;
        int length;
        int maxSize;
    
    public:
        SinhVien(int size = 20);
        SinhVien(const SinhVien<T>&);
        bool isEmpty() const;
        bool isFull() const;
        int getListSize() const;
        int getMaxListSize() const;
        void clearList();
        void insert(const T &);
        void insert(int, const T &);
        const SinhVien<T>& operator=(const SinhVien<T>& otherList);
        void print() const;
};

#endif