#Title : Binary Search Trees
#Author : Yusuf Samsum
#Description : Creating a pointer based binary search tree, doing insertion,deletion,
# 		getting height, finding range and height analysis.


PbBST:
	g++ -c PbTreeNode.cpp PbBST.cpp analysis.cpp main.cpp
	g++ PbTreeNode.cpp PbBST.cpp analysis.cpp main.cpp -o hw2
