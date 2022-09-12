#ifndef ARRAYLIST_H_INCLUDED
#define ARRAYLIST_H_INCLUDED

#include<iostream>

using namespace std;

template <class elementType>
class ArrayList {
    private:
        elementType *list;
        int length;
        int maxSize;

    public:
        ArrayList(int size = 100);
        ArrayList(const ArrayList<elementType>&);
        bool isEmpty() const;
        bool isFull() const;
        int getListSize() const;
        int getMaxListSize() const;
        void clearList();
        void insert(const elementType &);
        void insert(int, const elementType &);
        void replace(int, const elementType &);
        void remove(int);
        void retrieve(int, elementType &);
        int search(const elementType &) const;

        const ArrayList<elementType>& operator=(const ArrayList<elementType>& otherList);

        void print() const;
};

#endif // ARRAYLIST_H_INCLUDED
