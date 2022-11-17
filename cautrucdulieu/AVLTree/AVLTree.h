#ifndef AVLTREE_H_INCLUDED
#define AVLTREE_H_INCLUDED

#include<iostream>
#include<cassert>

#include "AVLNode.h"

using namespace std;

template <class elementType>
class AVLTree {
    public:
        AVLTree();
        AVLTree(const AVLTree<elementType>& otherTree);
        ~AVLTree();

        bool isEmpty() const;
        void inorderTraversal() const;
        void preorderTraversal() const;
        void postorderTraversal() const;
        int treeHeight() const;
        int treeNodeCount() const;
        int treeLeavesCount() const;
        void destroyTree();

        bool search(const elementType& searchItem) const;
        void insert(const elementType &newItem);
        void deleteNode(const elementType& deleteItem);

        const AVLTree<elementType>& operator=(const AVLTree<elementType>&);

    protected:
        AVLNode<elementType> *root;

    private:
        void copyTree(AVLNode<elementType>* &copiedTreeRoot, AVLNode<elementType>* otherTreeRoot);
        void destroy(AVLNode<elementType>* &p);

        void inorder(AVLNode<elementType> *p) const;
        void preorder(AVLNode<elementType> *p) const;
        void postorder(AVLNode<elementType> *p) const;

        int height(AVLNode<elementType> *p) const;
        int max(int x, int y) const;
        int nodeCount(AVLNode<elementType> *p) const;
        int leavesCount(AVLNode<elementType> *p) const;

        void deleteFromTree(AVLNode<elementType>* &p);

        void rotateToLeft(AVLNode<elementType>* &root);
        void rotateToRight(AVLNode<elementType>* &root);
        void balanceFromLeft(AVLNode<elementType>* &root);
        void balanceFromRight(AVLNode<elementType>* &root);
        void insertIntoAVL(AVLNode<elementType>* &root, AVLNode<elementType> *newNode, bool& isTaller);
};

#endif // AVLTREE_H_INCLUDED
