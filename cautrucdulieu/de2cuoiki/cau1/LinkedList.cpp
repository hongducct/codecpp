#include <iostream>
using namespace std;

template <class Type> 
struct nodeType {
    Type data;
    nodeType<Type>* link;
};

template <typename Type>
class LinkedList{
    public:
        LinkedList();
        LinkedList(const LinkedList<Type>&);
        ~LinkedList();

        void initialize();
        bool isEmpty() const;
        int getListSize() const;
        void destroy();
        void print() const;
        
        void insert(const Type&);
        void insert(int, const Type&);
        void insertFirst(const Type&);
        void insertLast(const Type&);
        void replace(int, const Type&);
        bool search(const Type&) const;
        int rEndLocation(const Type&);
        void retrieve(int, Type&);
        // void remove(const Type&);
        void remove(int);

        const LinkedList<Type>& operator =(const LinkedList<Type>&);

    protected:
        nodeType<Type> *first;
        nodeType<Type> *last;

        int count;
    private:
        void copyList(const LinkedList<Type>&);
};

template <typename Type>
LinkedList<Type>::LinkedList(){
    first = NULL;
    last = NULL;
    count = 0;
}

template <typename Type>
LinkedList<Type>::LinkedList(const LinkedList<Type>&otherList){
    first = NULL;
    copyList(otherList);
}

template <typename Type>
LinkedList<Type>::~LinkedList(){
    destroy();
}

template <typename Type>
void LinkedList<Type>::initialize(){
    destroy();
}

template <typename Type>
bool LinkedList<Type>::isEmpty() const {
    return (first == NULL);
}

template <typename Type>
int LinkedList<Type>::getListSize() const {
    return count;
}

template <typename Type>
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

template <typename Type>
void LinkedList<Type>::print() const{
    nodeType<Type> *current;
    current = first;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->link;
    }
    cout << endl;
}

template <typename Type>
void LinkedList<Type>::insert(const Type &newElement){
    insertFirst(newElement);
}

template <typename Type>
void LinkedList<Type>::insert(int location, const Type& newElement){
    nodeType<Type> *newNode;
    newNode = new nodeType<Type>;

    newNode->data = newElement;

    if (location < 0 || location > count){
        cerr << "Không thể chèn phần tử." << endl;
    }else{
        nodeType<Type> *current = first;
        for (int i = 0; i < location; i++){
            current = current->link;
        }
        newNode->link = current->link;
        current->link = newNode;
    }
}

template <typename Type>
void LinkedList<Type>::insertFirst(const Type& newElemnt){
    nodeType<Type> *newNode;
    newNode = new nodeType<Type>;
    
    newNode->data = newElemnt;
    newNode->link = first;

    first = newNode;

    count++;

    if(last==NULL){
        last = newNode;
    }
}

template <typename Type>
void LinkedList<Type>::insertLast(const Type& newElement){
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

template <typename Type>
void LinkedList<Type>::replace(int location, const Type &replacedElement){
    if (this->first == NULL){
        cout << "Không thể thay thế dữ liệu trong danh sách rỗng." << endl;
    }else if (location <= 0 || location > count){
        cerr << "Vị trí phần tử cần thay thế phải là số dương và nhỏ hơn số phần tử của danh sách." << endl;
    }else {
        nodeType<Type> *current = first;

        if (location > 1){
            for(int i = 2; i <= location; i++){
                current = current->link;
            }
        }
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
int LinkedList<Type>::rEndLocation(const Type& element){
    int countEnd = 0;
    nodeType<Type> *current = first;
    while(current != NULL){
        if(current->data == element){
            countEnd++;
        }
        current = current->link;
    }
    if(countEnd == 0){
        return -1;
    }else{
        return countEnd;
    }
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

// template <class Type>
// void LinkedList<Type>::remove(const Type& deletedItem) {
//     nodeType<Type> *current;
//     nodeType<Type> *trailCurrent;
//     bool found;

//     if (first == NULL)
//         cout << "Không thể xóa dữ liệu trong danh sách rỗng." << endl;
//     else {
//         if (first->data == deletedItem) {
//             current = first;
//             first = first->link;
//             count--;

//             if (first == NULL)
//                 last = NULL;
//             delete current;
//         } else {
//             found = false;
//             trailCurrent = first;
//             current = first->link;

//             while (current != NULL && !found) {
//                 if (current->data != deletedItem) {
//                     trailCurrent = current;
//                     current = current-> link;
//                 } else
//                     found = true;
//             }

//             if (found) {
//                 trailCurrent->link = current->link;
//                 count--;

//                 if (last == current)
//                     last = trailCurrent;

//                 delete current;
//             } else
//                 cout << "Phần tử cần xóa không nằm trong danh sách." << endl;
//         }
//     }
// }

template <class Type>
void LinkedList<Type>::remove(int location){
    if (location <= 0 || location > count){
        cerr << "Không thể xóa. " << endl;
    }else{
        if(location == 1) {
            first = first->link;
        }else if(location == 2) {
            first->link = first->link->link;
        }else{
            nodeType<Type> *current = first;
            for(int i=0;i<location - 2;i++){
                current= current->link;
            }
            current->link = current->link->link;
        }
        count--;
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

int main(){
    LinkedList<int> mylist;

    mylist.insert(4);
    mylist.insert(5);
    mylist.insert(9);
    mylist.insertLast(3);
    mylist.insertLast(10);
    mylist.insert(7);
    mylist.insert(8);
    mylist.insert(1);
    mylist.insert(3,9);

    mylist.print();

    mylist.remove(2);
    mylist.print();

    cout << mylist.search(10) << endl;

    cout << mylist.rEndLocation(9) << endl;

    return 0;
}