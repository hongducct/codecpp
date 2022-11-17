#include<iostream>

#include "LinkedList.h"

using namespace std;

int main() {
    LinkedList<int> mylist;

    mylist.insertFirst(5);
    mylist.insertFirst(8);
    mylist.insertFirst(9);
    mylist.insertLast(19);
    mylist.insertLast(19);

    int x;

    mylist.retrieve(2, x);

    cout << x << endl;

    mylist.print();

    return 0;
}
