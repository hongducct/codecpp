#include<iostream>

#include "BinaryTree.h"

using namespace std;

int main() {
    BinaryTree<int> bt(7);
    BinaryTree<int> bt_l(5);
    BinaryTree<int> bt_r(8);

    BinaryTree<int> bt_l_r(4);

    BinaryTree<int> bt_r_l(6);

    bt_l.insertRight(bt_l_r);
    bt_r.insertLeft(bt_r_l);

    bt.insertLeft(bt_l);
    bt.insertRight(bt_r);

    bt.inorderTraversal();
    cout << endl;
    bt.preorderTraversal();
    cout << endl;
    bt.postorderTraversal();
    cout << endl;

    cout << bt.treeLeavesCount() << endl;


    return 0;
}
