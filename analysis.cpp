/**
* Title : Binary Search Trees
* Author : Yusuf Samsum
* Description : Creating a pointer based binary search tree, doing insertion,deletion,
* 		getting height, finding range and height analysis.
*/
#include "PbTreeNode.h"
#include "PbBST.h"
#include <iostream>
#include <stdlib.h>
#include <cstddef>
#include "analysis.h"
using namespace std;


void heightAnalysis()
{
    PbBST test;
    cout << "Part f - Analysis of BST height - part 1 " << endl;
    cout << " ----------------------------------------- " << endl;
    cout << "Tree Size                      Tree Height  " << endl;
    cout << "--------------------------------------------------" << endl;
    int * array = new int[20000];
    for( int i = 1; i <= 20000; i++ )
    {
        if( (i )  % 1000 == 0 )
            cout <<  i   << "                            " << test.getHeight() << endl;
        array[ i - 1 ] = rand() ;
        test.insert( array[ i - 1 ] );

    }

    //Shuffle the array
    for (int i = 20000; i >= 1; i--)
    {
        int randomIndex = rand() % i ;
        // Swap arr[i] with the element at random index
        swap( array[ i - 1 ] , array [ randomIndex] );
    }



    cout << "Part f - Analysis of BST height - part 2 " << endl;
    cout << " ----------------------------------------- " << endl;
    cout << "Tree Size                      Tree Height  " << endl;
    cout << "--------------------------------------------------" << endl;
    for( int i = 19999; i >= 0 ; i--)
    {
        test.deleteKey( array[ i ] );
        if( i % 1000 == 0)
        {
            cout <<  i << "                            " << test.getHeight() << endl;
        }
    }
}


void swap( int & first, int & second )
{
    int temp = first;
    first = second;
    second = temp;
}

