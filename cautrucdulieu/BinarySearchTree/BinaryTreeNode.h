#ifndef BINARYTREENODE_H_INCLUDED
#define BINARYTREENODE_H_INCLUDED

template <class elementType>
struct BinaryTreeNode
{
    elementType data;
    BinaryTreeNode<elementType> *llink;
    BinaryTreeNode<elementType> *rlink;
};

#endif // BINARYTREENODE_H_INCLUDED
