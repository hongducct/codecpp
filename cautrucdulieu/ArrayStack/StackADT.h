#ifndef STACKADT_H_INCLUDED
#define STACKADT_H_INCLUDED

template <class Type>
class StackADT {
    public:
        virtual void initialize() = 0;
        virtual bool isEmpty() const = 0;
        virtual bool isFull() const = 0;
        virtual void push(const Type &) = 0;
        virtual Type top() const = 0;
        virtual void pop() = 0;
};

#endif // STACKADT_H_INCLUDED
