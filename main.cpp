/**
* Title : Binary Search Trees
* Author : Yusuf Samsum
* Description : Creating a pointer based binary search tree, doing insertion,deletion,
* 		getting height, finding range and height analysis.
*/
#include "PbBST.h"
#include "PbTreeNode.h"
#include <iostream>
#include <stdlib.h>
#include "analysis.h"
using namespace std;

int main()
{
    PbBST mainTest;
    mainTest.insert( 40 );
    mainTest.insert( 50 );
    mainTest.insert( 45 );
    mainTest.insert( 30 );
    mainTest.insert( 60 );
    mainTest.insert( 55 );
    mainTest.insert( 20 );
    mainTest.insert( 35 );
    mainTest.insert( 10 );
    mainTest.insert( 25 );
    cout << "Height: " << mainTest.getHeight() << endl;
    mainTest.deleteKey( 45 );
    mainTest.deleteKey( 50 );
    double median = mainTest.medianOfBST();
    cout << "Median: " << median << endl;
    mainTest.rangeSearch( 15, 53 );
    cout << endl;
    heightAnalysis();

    return 0;
}

