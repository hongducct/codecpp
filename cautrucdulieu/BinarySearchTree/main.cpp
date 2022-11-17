#include<iostream>

#include"BinarySearchTree.cpp"
#include"BinaryTree.cpp"

using namespace std;

int main() {
    BinarySearchTree<int> bt;

    bt.insert(8);
    bt.insert(1);
    bt.insert(12);
    bt.insert(9);
    bt.insert(6);
    bt.insert(7);
    bt.insert(11);
    bt.insert(2);


    // bt.deleteNode(4);
    bt.inorderTraversal();
    cout << endl;
    bt.preorderTraversal();
    cout << endl;
    bt.postorderTraversal();
    cout << endl;

    if (bt.search(3)){
        cout << "Co phan tu 3.. " << endl;
    }else cout << "Khong co phan tu 3.. " << endl;

    if (bt.search(5)){
        cout << "Co phan tu 5.. " << endl;
    }else cout << "Khong co phan tu 5.. " << endl;

    if (bt.search(12)){
        cout << "Co phan tu 12.. " << endl;
    }else cout << "Khong co phan tu 12.. " << endl;

    bt.deleteNode(11);
    bt.inorderTraversal();
    cout << endl;

    bt.deleteNode(3);
    bt.inorderTraversal();
    cout << endl;

    bt.deleteNode(1);
    bt.inorderTraversal();
    cout << endl;

    return 0;
}
