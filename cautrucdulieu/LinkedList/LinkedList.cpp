#include "LinkedList.h"

template <class Type>
LinkedList<Type>::LinkedList() {
    first = NULL;
    last = NULL;
    count = 0;
}

template <class Type>
LinkedList<Type>::LinkedList(const LinkedList<Type>& otherList) {
    first = NULL;
    copyList(otherList);
}

template <class Type>
LinkedList<Type>::~LinkedList() {
    destroy();
}

template <class Type>
void LinkedList<Type>::initialize() {
    destroy();
}

template <class Type>
bool LinkedList<Type>::isEmpty() const {
    return (first == NULL);
}

template <class Type>
int LinkedList<Type>::getListSize() const {
    return count;
}

template <class Type>
void LinkedList<Type>::destroy() {
    nodeType<Type> *temp;

    while (first != NULL) {
        temp = first;
        first = first->link;
        delete temp;
    }
    last = NULL;
    count = 0;
}

template <class Type>
void LinkedList<Type>::print() const {
    nodeType<Type> *current;
    current = first;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->link;
    }
}

template <class Type>
void LinkedList<Type>::insertFirst(const Type &newElement) {
    nodeType<Type> *newNode;
    newNode = new nodeType<Type>;

    newNode->data = newElement;
    newNode->link = first;

    first = newNode;

    count++;

    if (last == NULL)
        last = newNode;
}

template <class Type>
void LinkedList<Type>::insertLast(const Type &newElement) {
    nodeType<Type> *newNode;
    newNode = new nodeType<Type>;

    newNode->data = newElement;
    newNode->link = NULL;

    if (first == NULL)  // if (isEmpty())  // if (count == 0)  //if (last == NULL)
        first = newNode;
    else
        last->link = newNode;

    last = newNode;
    count++;
}

template <class Type>
void LinkedList<Type>::replace(int location, const Type &replacedElement) {
    if (this->first == NULL) {
        cout << "Không thể thay thế dữ liệu trong danh sách rỗng." << endl;
        exit(0);
    } else if (location <= 0 || location > count) {
            cerr << "Vị trí phần tử cần thay thế phải là số dương và nhỏ hơn số phần tử của danh sách." << endl;
            exit(0);
    } else {
            nodeType<Type> *current = first;

            if (location > 1)
                for(int i = 2; i <= location; i++)
                    current = current->link;

            current->data = replacedElement;
    }
}

template <class Type>
bool LinkedList<Type>::search(const Type& searchElement) const {
    nodeType<Type> *current;

    bool found = false;
    current = first;

    while (current != NULL && !found)
        if (current->data == searchElement)
            found = true;
        else
            current = current->link;

    return found;
}

template <class Type>
void LinkedList<Type>::retrieve(int location, Type &returnedElement) {
    if (first == NULL) {
        cout << "Không thể lấy dữ liệu trong danh sách rỗng." << endl;
        exit(0);
    } else if (location <= 0 || location > count) {
            cerr << "Vị trí phần tử cần lấy phải là số dương và nhỏ hơn số phần tử của danh sách." << endl;
            exit(0);
    } else {
            nodeType<Type> *current = first;

            if (location > 1)
                for(int i = 2; i <= location; i++)
                    current = current->link;

            returnedElement = current->data;
        }
}

template <class Type>
void LinkedList<Type>::remove(const Type& deletedItem) {
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent;
    bool found;

    if (first == NULL)
        cout << "Không thể xóa dữ liệu trong danh sách rỗng." << endl;
    else {
        if (first->data == deletedItem) {
            current = first;
            first = first->link;
            count--;

            if (first == NULL)
                last = NULL;
            delete current;
        } else {
            found = false;
            trailCurrent = first;
            current = first->link;

            while (current != NULL && !found) {
                if (current->data != deletedItem) {
                    trailCurrent = current;
                    current = current-> link;
                } else
                    found = true;
            }

            if (found) {
                trailCurrent->link = current->link;
                count--;

                if (last == current)
                    last = trailCurrent;

                delete current;
            } else
                cout << "Phần tử cần xóa không nằm trong danh sách." << endl;
        }
    }
}

template <class Type>
const LinkedList<Type>& LinkedList<Type>::operator =(const LinkedList<Type>& otherList) {
    if (this != &otherList) {
        copyList(otherList);
    }
    return *this;
}

template <class Type>
void LinkedList<Type>::copyList(const LinkedList<Type> &otherList) {
    nodeType<Type> *newNode;
    nodeType<Type> *current;

    if (first != NULL)
        destroy();

    if (otherList.first == NULL) {
        first = NULL;
        last = NULL;
        count = 0;
    } else {
        current = otherList.first;
        count = otherList.count;

        first = new nodeType<Type>;
        first->data = current->data;
        first->link = NULL;
        last = first;
        current = current->link;

        while (current != NULL) {
            newNode = new nodeType<Type>;
            newNode->data = current->data;
            newNode->link = NULL;
            last->link = newNode;
            last = newNode;
            current = current->link;
        }
    }
}

template class LinkedList<int>;
