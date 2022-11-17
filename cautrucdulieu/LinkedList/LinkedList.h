#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include<iostream>
#include<cassert>

#include "NodeType.h"

using namespace std;

template <class Type>
class LinkedList {
    public:
        LinkedList();
        LinkedList(const LinkedList<Type> &);
        ~LinkedList();

        void initialize();
        bool isEmpty() const;
        int getListSize() const;
        void destroy();
        void print() const;

        void insertFirst(const Type &);
        void insertLast(const Type &);
        void replace(int, const Type &);
        bool search(const Type &) const;
        void retrieve(int, Type &);
        void remove(const Type &);

        const LinkedList<Type>& operator =(const LinkedList<Type> &);

    protected:
        nodeType<Type> *first;
        nodeType<Type> *last;

        int count;

    private:
        void copyList(const LinkedList<Type> &);
};


#endif // LINKEDLIST_H_INCLUDED
