#include "AVLTree.h"

template <class elementType>
AVLTree<elementType>::AVLTree() {
    root = NULL;
}

template <class elementType>
AVLTree<elementType>::AVLTree(const AVLTree<elementType>& otherTree) {
    if (otherTree.root == NULL)
        root = NULL;
    else
        copyTree(root, otherTree.root);
}

template <class elementType>
AVLTree<elementType>::~AVLTree() {
    destroy(root);
}

template <class elementType>
bool AVLTree<elementType>::isEmpty() const {
    return (root == NULL);
}

template <class elementType>
void AVLTree<elementType>::inorderTraversal() const {
    inorder(root);
}

template <class elementType>
void AVLTree<elementType>::preorderTraversal() const {
    preorder(root);
}

template <class elementType>
void AVLTree<elementType>::postorderTraversal() const {
    postorder(root);
}

template <class elementType>
int AVLTree<elementType>::treeHeight() const {
    return height(root);
}

template <class elementType>
void AVLTree<elementType>::destroyTree() {
    destroy(root);
}

template <class elementType>
bool AVLTree<elementType>::search(const elementType& searchItem) const {
    AVLNode<elementType> *current;

    bool found = false;

    if (this->root == NULL)
        cerr << "Không thể tìm kiếm trong cây rỗng." << endl;
    else {
        current = this->root;
        while (current != NULL && !found) {
            if (current->data == searchItem)
                found = true;
            else if (current->data > searchItem)
                current = current->llink;
            else
                current = current->rlink;
        }
    }
    return found;
}

template <class elementType>
void AVLTree<elementType>::insert(const elementType &newItem) {

}

template <class elementType>
void AVLTree<elementType>::deleteNode(const elementType& deleteItem) {

}

template <class elementType>
const AVLTree<elementType>& AVLTree<elementType>::operator=(const AVLTree<elementType>& otherTree) {
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
void AVLTree<elementType>::copyTree(AVLNode<elementType>* &copiedTreeRoot, AVLNode<elementType>* otherTreeRoot) {
    if (otherTreeRoot == NULL)
        copiedTreeRoot = NULL;
    else {
        copiedTreeRoot = new AVLNode<elementType>;
        copiedTreeRoot->data = otherTreeRoot->data;
        copyTree(copiedTreeRoot->llink, otherTreeRoot->llink);
        copyTree(copiedTreeRoot->rlink, otherTreeRoot->rlink);
    }
}

template <class elementType>
void AVLTree<elementType>::destroy(AVLNode<elementType>* &p) {
    if (p != NULL) {
        destroy(p->llink);
        destroy(p->rlink);
        delete p;
        p = NULL;
    }
}

template <class elementType>
void AVLTree<elementType>::inorder(AVLNode<elementType> *p) const {
    if (p != NULL) {
        inorder(p->llink);
        cout << p->data << " ";
        inorder(p->rlink);
    }
}

template <class elementType>
void AVLTree<elementType>::preorder(AVLNode<elementType> *p) const {
    if (p != NULL) {
        cout << p->data << " ";
        preorder(p->llink);
        preorder(p->rlink);
    }
}

template <class elementType>
void AVLTree<elementType>::postorder(AVLNode<elementType> *p) const {
    if (p != NULL) {
        postorder(p->llink);
        postorder(p->rlink);
        cout << p->data << " ";
    }
}

template <class elementType>
int AVLTree<elementType>::treeNodeCount() const {
    return nodeCount(root);
}

template <class elementType>
int AVLTree<elementType>::treeLeavesCount() const {
    return leavesCount(root);
}

template <class elementType>
int AVLTree<elementType>::height(AVLNode<elementType> *p) const {
    if (p == NULL)
        return 0;
    else
        return 1 + max(height(p->llink), height(p->rlink));
}

template <class elementType>
int AVLTree<elementType>::max(int x, int y) const {
    if (x >= y)
        return x;
    else
        return y;
}

template <class elementType>
int AVLTree<elementType>::nodeCount(AVLNode<elementType> *p) const {
    if (p == NULL)
        return 0;

    return 1 + nodeCount(p->llink) + nodeCount(p->rlink);
}

template <class elementType>
int AVLTree<elementType>::leavesCount(AVLNode<elementType> *p) const {
    if(p == NULL)
        return 0;
    if(p->llink == NULL && p->rlink == NULL)
        return 1;
    else
        return leavesCount(p->llink) + leavesCount(p->rlink);
}

template <class elementType>
void AVLTree<elementType>::deleteFromTree(AVLNode<elementType>* &p) {

}

template <class elementType>
void AVLTree<elementType>::rotateToLeft(AVLNode<elementType>* &root) {
    if (this->root == NULL || this->root->rlink == NULL) {
        cerr << "Error" << endl;
    }else {
        AVLNode<elementType> *p = this->root->rlink;
        this->root->rlink = p->llink;
        p->llink = root;
        this->root = p;
    }
}

template <class elementType>
void AVLTree<elementType>::rotateToRight(AVLNode<elementType>* &root) {
    if (this->root == NULL || this->root->llink == NULL) {
        cerr << "Error" << endl;
    }else {
        AVLNode<elementType> *p = this->root->llink;
        this->root->llink = p->rlink;
        p->rlink = root;
        this->root = p;
    }
}

template <class elementType>
void AVLTree<elementType>::balanceFromLeft(AVLNode<elementType>* &root) {
    AVLNode<elementType> *p = this->root->llink;
    if (p.bfactor == -1) {
        p.bfactor = 0;
        root.bfactor = 0;
        rotateToRight(root);
    }else if (p.bfactor == 0) {
        cerr << "Khong the can bang lai cay tu ben trai" << endl;
    }else (p.bfactor == 1) {
        AVLNode<elementType> *w = p->rlink;
        if (w.bfactor == -1) {
            root.bfactor = 1;
            p.bfactor = 0;
        }else if (w.bfactor == 0) {
            root.bfactor = 0;
            p.bfactor = 0;
        }else {
            root.bfactor = 1;
            p.bfactor = -1;
        }
        w.bfactor = 0;
        rotateToLeft(p);
        root->llink = p;
        rotateToRight(root);
        
    }
}

template <class elementType>
void AVLTree<elementType>::balanceFromRight(AVLNode<elementType>* &root) {

}

template <class elementType>
void AVLTree<elementType>::insertIntoAVL(AVLNode<elementType>* &root, AVLNode<elementType> *newNode, bool& isTaller) {

}

template class AVLTree<int>;
