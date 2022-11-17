#include "ArrayStack.h"

template <class Type>
ArrayStack<Type>::ArrayStack(int stackSize) {
    if (stackSize <= 0) {
        cout << "Kích cỡ ngăn xếp phải là một số dương." << endl;
        cout << "Tạo ngăn xếp có kích cỡ 100 phần tử." << endl;
        maxStackSize = 100;
    } else
        maxStackSize = stackSize;

    stackTop = 0;
    list = new Type[maxStackSize];
}

template <class Type>
ArrayStack<Type>::ArrayStack(const ArrayStack<Type>& otherStack) {
    list = NULL;
    copyStack(otherStack);
}

template <class Type>
ArrayStack<Type>::~ArrayStack() {
    delete [] list;
}

template <class Type>
void ArrayStack<Type>::initialize() {
    stackTop = 0;
}

template <class Type>
bool ArrayStack<Type>::isEmpty() const {
    return (stackTop == 0);
}

template <class Type>
bool ArrayStack<Type>::isFull() const {
    return(stackTop == maxStackSize);
}

template <class Type>
void ArrayStack<Type>::push(const Type& newElement) {
    if (!isFull()) {
        list[stackTop] = newElement;
        stackTop++;
    } else
        cout << "Ngăn xếp đã đầy, không thể đưa thêm phần tử vào." << endl;
}

template <class Type>
Type ArrayStack<Type>::top() const {
    if (stackTop == 0) {
        cout << "Không thể lấy phần tử từ danh sách rỗng." << endl;
        exit(0);
     } else
        return list[stackTop - 1];
}

template <class Type>
void ArrayStack<Type>::pop() {
    if (!isEmpty())
        stackTop--;
    else
        cout << "Không thể xóa phần tử từ danh sách rỗng." << endl;
}

template <class Type>
void ArrayStack<Type>::pop(Type& topElement) {
    if (!isEmpty()) {
        topElement = list[stackTop - 1];
        stackTop--;
    }
    else
        cout << "Không thể xóa phần tử từ danh sách rỗng." << endl;
}

template <class Type>
const ArrayStack<Type>& ArrayStack<Type>::operator =(const ArrayStack<Type>& otherStack) {
    if (this != &otherStack)
        copyStack(otherStack);
    return *this;
}

template <class Type>
void ArrayStack<Type>::copyStack(const ArrayStack<Type> &otherStack) {
    delete [] list;
    maxStackSize = otherStack.maxStackSize;
    stackTop = otherStack.stackTop;
    list = new Type[maxStackSize];

    for (int i = 0; i < stackTop; i++)
        list[i] = otherStack.list[i];
}

template class ArrayStack<int>;
