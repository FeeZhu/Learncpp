#include "stdafx.h"
#include "kdTree.h"

void demo_kdtree()
{
	int data[6][2] = { { 2,3 },{ 5,4 },{ 9,6 },{ 4,7 },{ 8,1 },{ 7,2 } };
	vector<vector<double> > train(6, vector<double>(2, 0));
	for (unsigned i = 0; i < 6; ++i)
		for (unsigned j = 0; j < 2; ++j)
			train[i][j] = data[i][j];

	KdTree* kdTree = new KdTree;
	buildKdTree(kdTree, train, 0);

	printKdTree(kdTree, 0);

	vector<double> goal;
	goal.push_back(3);
	goal.push_back(4.5);
	vector<double> nearestNeighbor = searchNearestNeighbor(goal, kdTree);
	vector<double>::iterator beg = nearestNeighbor.begin();
	cout << "The nearest neighbor is: ";
	while (beg != nearestNeighbor.end()) cout << *beg++ << ",";
	cout << endl;
}