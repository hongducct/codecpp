#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

#include<iostream>

#include "BinaryTree.h"
#include "BinaryTreeNode.h"

using namespace std;

template <class elementType>
class BinaryTree {
    public:
        BinaryTree();
        BinaryTree(elementType);
        BinaryTree(const BinaryTree<elementType>& otherTree);
        ~BinaryTree();

        void setRootData(elementType);
        void insertLeft(BinaryTree<elementType>& p);
        void insertRight(BinaryTree<elementType>& p);

        bool isEmpty() const;
        void inorderTraversal() const;
        void preorderTraversal() const;
        void postorderTraversal() const;
        int treeHeight() const;
        int treeNodeCount() const;
        int treeLeavesCount() const;
        void destroyTree();

        const BinaryTree<elementType>& operator=(const BinaryTree<elementType>&);

    protected:
        BinaryTreeNode<elementType> *root;

    private:
        void copyTree(BinaryTreeNode<elementType>* &copiedTreeRoot, BinaryTreeNode<elementType>* otherTreeRoot);
        void destroy(BinaryTreeNode<elementType>* &p);

        void inorder(BinaryTreeNode<elementType> *p) const;
        void preorder(BinaryTreeNode<elementType> *p) const;
        void postorder(BinaryTreeNode<elementType> *p) const;

        int height(BinaryTreeNode<elementType> *p) const;
        int max(int x, int y) const;
        int nodeCount(BinaryTreeNode<elementType> *p) const;
        int leavesCount(BinaryTreeNode<elementType> *p) const;
};

#endif // BINARYTREE_H_INCLUDED
