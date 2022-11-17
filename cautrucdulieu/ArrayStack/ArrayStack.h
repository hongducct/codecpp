#ifndef ARRAYSTACK_H_INCLUDED
#define ARRAYSTACK_H_INCLUDED

#include<iostream>

#include "StackADT.h"

using namespace std;

template <class Type>
class ArrayStack : public StackADT<Type> {
    public:
        ArrayStack(int stackSize = 100);
        ArrayStack(const ArrayStack<Type> &);
        ~ArrayStack();

        void initialize();
        bool isEmpty() const;
        bool isFull() const;
        void push(const Type& newItem);
        Type top() const;
        void pop();
        void pop(Type &);

        const ArrayStack<Type>& operator=(const ArrayStack<Type> &);

    private:
        int maxStackSize;
        int stackTop;
        Type *list;

        void copyStack(const ArrayStack<Type> &);
};

#endif // ARRAYSTACK_H_INCLUDED
