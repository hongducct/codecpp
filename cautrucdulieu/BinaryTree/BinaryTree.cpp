#include "BinaryTree.h"

template <class elementType>
BinaryTree<elementType>::BinaryTree() {
    root = NULL;
}

template <class elementType>
BinaryTree<elementType>::BinaryTree(elementType data) {
    root = NULL;
    setRootData(data);
}

template <class elementType>
BinaryTree<elementType>::BinaryTree(const BinaryTree<elementType>& otherTree) {
    if (otherTree.root == NULL)
        root = NULL;
    else
        copyTree(root, otherTree.root);
}

template <class elementType>
BinaryTree<elementType>::~BinaryTree() {
    destroy(root);
}

template <class elementType>
void BinaryTree<elementType>::setRootData(elementType data) {
    if (root == NULL) {
        root = new BinaryTreeNode<elementType>;
        root->data = data;
        root->llink = NULL;
        root->rlink = NULL;
    } else
        root->data = data;
}

template <class elementType>
void BinaryTree<elementType>::insertLeft(BinaryTree<elementType> &p) {
    if (root != NULL) {
        if (root->llink != NULL)
            destroy(root->llink);
        copyTree(root->llink, p.root);
    } else
        cerr << "Không chèn được vào cây rỗng." << endl;
}

template <class elementType>
void BinaryTree<elementType>::insertRight(BinaryTree<elementType> &p) {
    if (root != NULL) {
        if (root->rlink != NULL)
            destroy(root->rlink);
        copyTree(root->rlink, p.root);
    } else
        cerr << "Không chèn được vào cây rỗng." << endl;

}

template <class elementType>
bool BinaryTree<elementType>::isEmpty() const {
    return (root == NULL);
}

template <class elementType>
void BinaryTree<elementType>::inorderTraversal() const {
    inorder(root);
}

template <class elementType>
void BinaryTree<elementType>::preorderTraversal() const {
    preorder(root);
}

template <class elementType>
void BinaryTree<elementType>::postorderTraversal() const {
    postorder(root);
}

template <class elementType>
int BinaryTree<elementType>::treeHeight() const {
    return height(root);
}

template <class elementType>
void BinaryTree<elementType>::destroyTree() {
    destroy(root);
}

template <class elementType>
const BinaryTree<elementType>& BinaryTree<elementType>::operator=(const BinaryTree<elementType>& otherTree) {
    if (this != &otherTree) {
        if (root != NULL)
            destroy(root);

        if (otherTree.root == NULL)
            root = NULL;
        else
            copyTree(root, otherTree.root);
    }

    return *this;
}

template <class elementType>
void BinaryTree<elementType>::copyTree(BinaryTreeNode<elementType>* &copiedTreeRoot, BinaryTreeNode<elementType>* otherTreeRoot) {
    if (otherTreeRoot == NULL)
        copiedTreeRoot = NULL;
    else {
        copiedTreeRoot = new BinaryTreeNode<elementType>;
        copiedTreeRoot->data = otherTreeRoot->data;
        copyTree(copiedTreeRoot->llink, otherTreeRoot->llink);
        copyTree(copiedTreeRoot->rlink, otherTreeRoot->rlink);
    }
}

template <class elementType>
void BinaryTree<elementType>::destroy(BinaryTreeNode<elementType>* &p) {
    if (p != NULL) {
        destroy(p->llink);
        destroy(p->rlink);
        delete p;
        p = NULL;
    }
}

template <class elementType>
void BinaryTree<elementType>::inorder(BinaryTreeNode<elementType> *p) const {
    if (p != NULL) {
        inorder(p->llink);
        cout << p->data << " ";
        inorder(p->rlink);
    }
}

template <class elementType>
void BinaryTree<elementType>::preorder(BinaryTreeNode<elementType> *p) const {
    if (p != NULL) {
        cout << p->data << " ";
        preorder(p->llink);
        preorder(p->rlink);
    }
}

template <class elementType>
void BinaryTree<elementType>::postorder(BinaryTreeNode<elementType> *p) const {
    if (p != NULL) {
        postorder(p->llink);
        postorder(p->rlink);
        cout << p->data << " ";
    }
}

template <class elementType>
int BinaryTree<elementType>::treeNodeCount() const {
    return nodeCount(root);
}

template <class elementType>
int BinaryTree<elementType>::treeLeavesCount() const {
    return leavesCount(root);
}

template <class elementType>
int BinaryTree<elementType>::height(BinaryTreeNode<elementType> *p) const {
    if (p == NULL)
        return 0;
    else
        return 1 + max(height(p->llink), height(p->rlink));
}

template <class elementType>
int BinaryTree<elementType>::max(int x, int y) const {
    if (x >= y)
        return x;
    else
        return y;
}

template <class elementType>
int BinaryTree<elementType>::nodeCount(BinaryTreeNode<elementType> *p) const {
    if (p == NULL)
        return 0;

    return 1 + nodeCount(p->llink) + nodeCount(p->rlink);
}

template <class elementType>
int BinaryTree<elementType>::leavesCount(BinaryTreeNode<elementType> *p) const {
    if(p == NULL)
        return 0;
    if(p->llink == NULL && p->rlink == NULL)
        return 1;
    else
        return leavesCount(p->llink) + leavesCount(p->rlink);
}

template class BinaryTree<int>;
