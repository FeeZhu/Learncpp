#include "stdafx.h"
#include "BSTree.h"


//ËÑË÷¶ş²æÊ÷µÄ²âÊÔº¯Êı

extern void BSTree_test()
{
	BSTree <int> tree;
	srand((unsigned)time(NULL));
	for (int i = 1; i < 10; i++)
	{
		tree.insert(i);
	}
	tree.print(tree.root);
	tree.remove(1);
	cout << tree.searchNode(1);
}