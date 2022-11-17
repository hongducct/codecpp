#ifndef AVLNODE_H_INCLUDED
#define AVLNODE_H_INCLUDED

template<class elementType>
struct AVLNode {
    elementType data;
    int bfactor;
    AVLNode<elementType> *llink;
    AVLNode<elementType> *rlink;
};

#endif // AVLNODE_H_INCLUDED
