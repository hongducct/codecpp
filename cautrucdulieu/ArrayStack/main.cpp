#include<iostream>

#include "ArrayStack.cpp"

using namespace std;

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
