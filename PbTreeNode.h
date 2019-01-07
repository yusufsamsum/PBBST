/**
* Title : Binary Search Trees
* Author : Yusuf Samsum
* Description : Creating a pointer based binary search tree, doing insertion,deletion,
* 		getting height, finding range and height analysis.
*/
#ifndef __PBTREENODE_H
#define __PBTREENODE_H
#include <iostream>
#include <cstddef>
#include <stdlib.h>
using namespace std;
class PbTreeNode
{
private:
    PbTreeNode();
    PbTreeNode( const  int& treeItem, PbTreeNode * leftChild = NULL, PbTreeNode * rightChild = NULL );
    int item;
    PbTreeNode * left;
    PbTreeNode * right;
    friend class PbBST; //friend class can reach private item
};

#endif // PBPbTreeNode_H
