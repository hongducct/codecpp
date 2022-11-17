#include<iostream>

#include"AVLTree.h"

using namespace std;

int main() {
    AVLTree<int> bt;

    bt.insert(5);
    bt.insert(7);
    bt.insert(4);

    //bt.deleteNode(4);

    bt.postorderTraversal();
}
