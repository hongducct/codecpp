#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED

#include<iostream>
#include<cassert>

#include"BinaryTreeNode.h"
#include"BinaryTree.h"

using namespace std;

template <class elementType>
class BinarySearchTree : public BinaryTree<elementType> {
    public:
        bool search(const elementType& searchItem) const;
        void insert(const elementType& insertItem);
        void deleteNode(const elementType& deleteItem);

    private:
        void deleteFromTree(BinaryTreeNode<elementType>* &p);
};

#endif // BINARYSEARCHTREE_H_INCLUDED
