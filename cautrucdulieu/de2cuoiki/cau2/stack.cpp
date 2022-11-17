#include <iostream>
using namespace std;

template <class Type>
class StackADT{
    virtual void initialize() = 0;
    virtual bool isEmpty() const= 0;
    virtual bool isFull() const= 0;
    virtual void push(const Type&) = 0;
    virtual Type top() const = 0;
    virtual void pop() = 0;
};

template <class Type>
class ArrayStack : public StackADT<Type> {
    public: 
        ArrayStack(int stackSize = 100);
        ArrayStack(const ArrayStack<Type>&);
        ~ArrayStack();

        void initialize();
        bool isEmpty() const;
        bool isFull() const;
        void push(const Type& newItem);
        Type top() const;
        void pop();
        void pop(Type&);

        const ArrayStack<Type>& operator=(const ArrayStack<Type>&);

    private:
        int maxStackSize;
        int stackTop;
        Type *list;

        void copyStack(const ArrayStack<Type>&);
};

template <class Type>
ArrayStack<Type>::ArrayStack(int stackSize){
    if(stackSize <= 0) {
        cout << "The size of the stack must be a positive number." << endl;
        cout << "Creat the stack of size 100 elements." << endl;
        maxStackSize = 100;

    }else {
        maxStackSize = stackSize;
    }

    stackTop = 0;
    list = new Type[maxStackSize];
}

template <class Type>
ArrayStack<Type>::ArrayStack(const ArrayStack<Type>&otherStack){
    list = NULL;
    copyStack(otherStack);
}

template <class Type>
ArrayStack<Type>::~ArrayStack(){
    delete[] list;
}

template <class Type>
void ArrayStack<Type>::initialize(){
    stackTop = 0;
}

template <class Type>
bool ArrayStack<Type>::isEmpty() const{
    return (stackTop == 0);
}

template <class Type>
bool ArrayStack<Type>::isFull() const{
    return (stackTop == maxStackSize);
}

template <class Type>
void ArrayStack<Type>::push(const Type& newElement) {
    if(!isFull()){
        list[stackTop] = newElement;
        stackTop++;
    }else{
        cout << "Stack is full! Cannot push element.. " << endl;
    }
}

template <class Type>
Type ArrayStack<Type>::top() const{
    if(stackTop == 0) {
        cout << "Cannot get the element from empty stack! " << endl;
    }else
        return list[stackTop-1];
};

template <class Type>
void ArrayStack<Type>::pop(){
    if(stackTop == 0) {
        cout << "Cannot get the element from empty stack! " << endl;
    }else{
        stackTop--;
    }
}

template <class Type>
void ArrayStack<Type>::pop(Type& topElement){
    if(stackTop == 0){
        cout << "Cannot delete the element from empty stack! " << endl;
    }else {
        topElement = list[stackTop-1];
        stackTop--;
    }
}

template <class Type>
const ArrayStack<Type>& ArrayStack<Type>::operator=(const ArrayStack<Type>& otherStack){
    if(this != &otherStack){
        copyStack(otherStack);
    }
    return *this;
}

template<class Type>
void ArrayStack<Type>::copyStack(const ArrayStack<Type>& otherStack){
    delete[] list;
    maxStackSize = otherStack.maxStackSize;
    stackTop = otherStack.stackTop;
    list = new Type[maxStackSize];

    for(int i=0; i < stackTop; i++){
        list[i] = otherStack.list[i];
    }
}

template class ArrayStack<int>;

int main() {
    ArrayStack<int> arrStack(3);

    arrStack.push(5);
    arrStack.push(6);
    arrStack.push(7);

    ArrayStack<int> arrStack1 = arrStack;

    while (!arrStack1.isEmpty()) {

        int x;
        arrStack1.pop(x);
        cout << x << " ";
    }
    cout << endl;

    return 0;
}