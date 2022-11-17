#include "BinarySearchTree.h"

template <class elementType>
bool BinarySearchTree<elementType>::search(const elementType& searchItem) const {
    BinaryTreeNode<elementType> *current = this->root;
    while (current != NULL) {
        if (current->data == searchItem) {
            return true;
        }else if (current->data > searchItem) {
            current = current->llink;
        }else {
            current = current->rlink;
        }
    }
    return false;
}

template <class elementType>
void BinarySearchTree<elementType>::insert(const elementType& insertItem) {
    BinaryTreeNode<elementType> *newNode;
    BinaryTreeNode<elementType> *current;
    BinaryTreeNode<elementType> *trailCurrent ;

    newNode = new BinaryTreeNode<elementType>;
    newNode->data = insertItem;
    newNode->llink = NULL;
    newNode->rlink = NULL;

    if (this->root == NULL) {
        this->root = newNode;
    }else {
        current = this->root;

        while (current != NULL) {
            trailCurrent = current;
            if (current->data == insertItem) {
                cerr << "Khong the chen node do bi trung du lieu" << endl;
            }else if (current->data > insertItem) {
                current = current->llink;
            }else {
                current = current->rlink;
            }
        }
        if (trailCurrent->data > insertItem) {
            trailCurrent->llink = newNode;
        }else {
            trailCurrent->rlink = newNode;
        }
    }
}

template <class elementType>
void BinarySearchTree<elementType>::deleteNode(const elementType& deleteItem) {
    if (this->root == NULL) {
        cerr << "Khong the delete node .. " << endl;
    }else {
        if (search(deleteItem)){
            BinaryTreeNode<elementType> *current = this->root;
            if (current->data == deleteItem){
                deleteFromTree(current);
            }else if (current->data > deleteItem){
                current = current->llink;
            }else {
                current = current->rlink;
            }
        }else {
            cerr << "Khong thay gia tri can xoa .. " << endl;
        }
    }
}

template <class elementType>
void BinarySearchTree<elementType>::deleteFromTree(BinaryTreeNode<elementType>* &p) {
    if (p==NULL){
        cerr << "khong cho phep xoa node NULL" << endl;
    }else {
        if (p->llink==NULL && p->rlink==NULL){
            BinaryTreeNode<elementType> *temp;
            temp = p;
            p = NULL;
            delete(temp);
        }else if (p->llink==NULL && p->rlink!=NULL){
            BinaryTreeNode<elementType> *temp;
            p = p->rlink;
            delete(temp);
        }else if (p->llink!=NULL && p->rlink==NULL){
            BinaryTreeNode<elementType> *temp;
            p = p->llink;
            delete(temp);
        }else {
            BinaryTreeNode<elementType> *current = p->llink;
            BinaryTreeNode<elementType> *trailCurrent = NULL;
            BinaryTreeNode<elementType> *MaxLeftTree;

            while (current->rlink != NULL) {
                trailCurrent = current;
                current = current->rlink;
            }
            
            p->data = current->data;

            if (trailCurrent == NULL) {
                p->llink = current->llink;
            }else {
                trailCurrent->rlink = current->llink;
            }
            delete current;
        }
    }
}

template class BinarySearchTree<int>;
