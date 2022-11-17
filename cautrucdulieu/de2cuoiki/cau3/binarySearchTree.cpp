#include <iostream>
using namespace std;

template <class elementType>
struct BinaryTreeNode{
    elementType data;
    BinaryTreeNode<elementType> *llink;
    BinaryTreeNode<elementType> *rlink;
};

template <class elementType>
class BinaryTree {
    public:
        BinaryTree();
        BinaryTree(const BinaryTree<elementType>& otherTree);
        ~BinaryTree();

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

template <class elementType>
BinaryTree<elementType>::BinaryTree() {
    root = NULL;
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

template <class elementType>
class BinarySearchTree : public BinaryTree<elementType> {
    public:
        bool search(const elementType& searchItem) const;
        void insert(const elementType& insertItem);
        void deleteNode(const elementType& deleteItem);

    private:
        void deleteFromTree(BinaryTreeNode<elementType>* &p);
};

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
