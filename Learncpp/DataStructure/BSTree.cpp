#include "stdafx.h"
#include "BSTree.h"


//ËÑË÷¶ş²æÊ÷µÄ²âÊÔº¯Êı

extern void BSTree_test()
{
	BSTree <int> tree;
	srand((unsigned)time(NULL));
	int  array[6] = { 88,47,19,55,50,98 };
	for (int i = 0; i < 6; i++)
	{
		tree.insert(array[i]);
	}
	tree.print();
	cout << tree.searchNode(88)<<endl;
	tree.remove(88);
	cout << tree.searchNode(88)<<endl;
	tree.print();

}