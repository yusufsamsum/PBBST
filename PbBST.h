/**
* Title : Binary Search Trees
* Author : Yusuf Samsum
* Description : Creating a pointer based binary search tree, doing insertion,deletion,
* 		getting height, finding range and height analysis.
*/
#ifndef PBBST_H
#define PBBST_H
#include "PbTreeNode.h"
#include <cstddef>
#include <iostream>
#include <stdlib.h>
using namespace std;
class PbBST
{
public:
    PbBST(); //constructor
   // PbBST( int & rootItem);
    //PbBST( int& rootItem, PbBST & leftTree, PbBST & rightTree );
    ~PbBST(); //destructor
    PbBST( PbBST & tree ); //copy constructor
    void insert( int key ); //insertion given key
    void deleteKey(int key ); // deletion with wanted key
    int getHeight(); // getting height of the binary tree
    int getNumOfNodesByInOrderTraversal(PbTreeNode * treePtr); //we can get num of nodes by inorder traversal
    void rangeSearch( int min, int max ); // print range if it exists
    double medianOfBST(); //find median and return double
protected:
    void destroyTree( PbTreeNode *& treePtr );
    bool isEmpty();
    //PbBST( PbTreeNode * treePtr);
    //void attachLeftSubTree( PbBST & leftTree );
    //void attachRightSubTree( PbBST & rightTree );
    void copyTree( PbTreeNode * treePtr, PbTreeNode *& newTreePtr); //for copy constructor if needed
    int findNthElementInTree( PbTreeNode * treePtr , int number ); //helper for finding median
    void insertItem( PbTreeNode *& treePtr, int newItem); //insertion helper
    void deleteItem( PbTreeNode*& treePtr, int itemToDelete ); //deletion helper
    void deleteNodeItem( PbTreeNode *& treePtr ); //delete node acc. to 4 case: leaf, no right child, no left child, two children
    void processLeftmost( PbTreeNode*& nodePtr, int& treeItem ); // if there are two children processLeftmost
    int getHeightHelper( PbTreeNode *& treePtr ); // helper for height
    int inOrderTraversalHelper( PbTreeNode * treePtr ); //helper
    void rangeSearchHelper(int min, int max, PbTreeNode * treePtr); //helper
private:
    PbTreeNode* root; // root of tree
};
#endif
