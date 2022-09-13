#include "arraylist.cpp"

int main() {
    ArrayList<int> a(10);
    cout << a.getListSize() << endl;
    cout << a.getMaxListSize() << endl;
    cout << a.isEmpty() << endl;

    for(int i=0;i<10;i++) {
        // int x;
        // cin >> x;
        a.insert(i);
    }
    a.print();
    cout << a.getListSize() << endl;
    cout << a.getMaxListSize() << endl;
    cout << a.isFull() << endl;
    a.clearList();
    for(int i=0;i<5;i++) {
        int x;
        cin >> x;
        a.insert(x);
    }
    a.print();

    a.insert(2,23);
    a.print();

    a.replace(4,12);
    a.print();

    a.remove(1);
    a.print();

    a.retrieve(3);

    cout << a.search(3) << endl;

    a.sort();
    a.print();

    a.reverse();
    a.print();

    cout << a.count(23) << endl;
    a.print();

    return 0;
}
