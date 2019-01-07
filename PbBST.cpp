/**
* Title : Binary Search Trees
* Author : Yusuf Samsum
* Description : Creating a pointer based binary search tree, doing insertion,deletion,
* 		getting height, finding range and height analysis.
*/
#include "PbBST.h"
#include "PbTreeNode.h"
#include <iostream>
#include <cstddef>
#include <stdlib.h>
using namespace std;
PbBST::PbBST()
{
    root = NULL;
}

PbBST::PbBST( PbBST & tree )
{
    copyTree( tree.root, root );
}

void PbBST::copyTree( PbTreeNode * treePtr, PbTreeNode *& newTreePtr )
{
    if ( treePtr != NULL )
    {
        newTreePtr = new PbTreeNode( treePtr->item, NULL, NULL );
        copyTree( treePtr->left, newTreePtr->left);
        copyTree( treePtr->right, newTreePtr->right);
    }
    else
        newTreePtr = NULL; //copy empty tree
}

PbBST::~PbBST()
{
    destroyTree(root);
}

void PbBST::destroyTree( PbTreeNode *& treePtr)
{
    if( treePtr != NULL )
    {
        destroyTree( treePtr->left );
        destroyTree( treePtr->right );
        delete treePtr;
        treePtr = NULL;
    }
}


bool PbBST::isEmpty()
{
    if( root == NULL )
        return true;
    return false;
}

void PbBST::insert( int key )
{
    insertItem(root,key);
}

void PbBST::insertItem( PbTreeNode *&treePtr, int newItem)
{
    //cout << "item " << newItem << endl;
    if( treePtr  == NULL )
        treePtr = new PbTreeNode( newItem,NULL,NULL);
    else if( treePtr->item > newItem )
        insertItem( treePtr->left, newItem );
    else
        insertItem(treePtr->right, newItem);
}

void PbBST::deleteKey( int key )
{
    deleteItem( root, key );
}

void PbBST::deleteItem( PbTreeNode*& treePtr, int itemToDelete )
{
    if ( treePtr == NULL )
        return;
        //cout<< "Deletion Failed" << endl;
    //if item is found send it to the node deleter
    else if ( treePtr->item == itemToDelete )
        deleteNodeItem( treePtr );
    //if item is bigger than what we are searching for go to left child and keep searching
    else if ( treePtr->item > itemToDelete )
        deleteItem( treePtr->left , itemToDelete);
    //if item is smaller than what we are searching for go to right child and keep searching
    else
        deleteItem( treePtr->right, itemToDelete );
}

void PbBST::deleteNodeItem(PbTreeNode*& treePtr )
{
    PbTreeNode * delPtr;
    int replacementItem;

    //No child, in other words a leaf
    if ( treePtr->left == NULL && treePtr->right == NULL )
    {
        delete treePtr;
        treePtr = NULL;
    }
    //test for no left child
    else if( treePtr ->left == NULL )
    {
        delPtr = treePtr;
        treePtr = treePtr->right;
        delPtr->right = NULL;
        delete delPtr;
    }
    //test for no right child
    else if ( treePtr->right == NULL )
    {
        delPtr = treePtr;
        treePtr = treePtr->left;
        delPtr->left =NULL;
        delete delPtr;
    }
    //if there are two children
    else
    {
        processLeftmost( treePtr->right, replacementItem);
        treePtr->item = replacementItem;
    }
}

//Process left most take the the left most item which will be removed item's right
void PbBST::processLeftmost(PbTreeNode *&nodePtr, int& treeItem)
{
    if( nodePtr->left == NULL )
    {
        treeItem = nodePtr->item;
        PbTreeNode *delPtr = nodePtr;
        nodePtr = nodePtr->right;
        delPtr->right = NULL;
        delete delPtr;
    }
    else
       processLeftmost(nodePtr->left,treeItem);
}

int PbBST::getHeight()
{
    return getHeightHelper(root);
}

int PbBST::getHeightHelper( PbTreeNode *& treePtr )
{
    if ( treePtr == NULL )
        return 0;
    else
        return 1 + max( getHeightHelper(treePtr->left), getHeightHelper( treePtr->right) );
}

int PbBST::getNumOfNodesByInOrderTraversal( PbTreeNode * treePtr )
{
    return inOrderTraversalHelper( treePtr );
}

int PbBST::inOrderTraversalHelper( PbTreeNode * treePtr )
{
    if ( treePtr != NULL)
        return inOrderTraversalHelper(treePtr->left)+ 1 +
                                            inOrderTraversalHelper(treePtr->right);
    return 0;
}

double PbBST::medianOfBST()
{
    int count = getNumOfNodesByInOrderTraversal( root );

    if ( count == 1)
        return root->item;
    else if( count % 2 == 1 )
    {
        return findNthElementInTree( root , count / 2 + 1 );
    }
    else
    {
        return ( findNthElementInTree( root , count / 2 ) + findNthElementInTree( root, count / 2 + 1 ) ) / 2.0;
    }
}

int PbBST::findNthElementInTree( PbTreeNode * treePtr, int number)
{
    int leftCount = getNumOfNodesByInOrderTraversal( treePtr ->left);
    if( leftCount + 1 == number )
        return treePtr -> item;
    else if( leftCount + 1 < number )
        return findNthElementInTree( treePtr->right ,number - leftCount - 1 );
    else
        return findNthElementInTree( treePtr->left , number );
}

void PbBST::rangeSearch( int min, int max )
{
    rangeSearchHelper(min, max, root);
}

void PbBST::rangeSearchHelper( int min, int max, PbTreeNode* treePtr )
{
    if( treePtr != NULL )
    {
        if ( treePtr -> item > min )
            rangeSearchHelper( min, max, treePtr -> left);
        if( treePtr -> item >= min && treePtr -> item <= max )
            cout << treePtr-> item << " ";
        if( treePtr -> item < max )
            rangeSearchHelper(min, max, treePtr-> right );
    }
}

