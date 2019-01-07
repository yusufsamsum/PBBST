/**
* Title : Binary Search Trees
* Author : Yusuf Samsum
* Description : Creating a pointer based binary search tree, doing insertion,deletion,
* 		getting height, finding range and height analysis.
*/
#include "PbTreeNode.h"
#include <cstddef>
#include <iostream>
#include <stdlib.h>
using namespace std;


PbTreeNode::PbTreeNode( const int & treeItem, PbTreeNode * leftChild, PbTreeNode * rightChild )
{
        item = treeItem;
        left = leftChild;
        right = rightChild;
}

