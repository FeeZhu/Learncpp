// Learncpp.cpp : 定义控制台应用程序的入口点。
//This is a project to learn program 
// 11/30 插入排序

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include "Sort.h"
#include "MaxsubArray.h"
#include "Priority_queue.h"

using namespace std;

int main()
{
	vector<double> A{3.4,6,2,8.5,4,8,23.5 ,10,15};
	//insertSort(A);
	//HeapSort(A);
	ShellSort(A);
	for (int i = 0; i < A.size(); i++)
	{
		cout << A[i] << " ";
	}
	////优先队列
	//QueueAlgorithm::priqueue<int ,int> B(10);
	//cout<<B.pop();
	//B.Insert(1, 15);
	//B.print();
	/*
	//最大子数组问题
	//test maxsubarray function
	int A[16] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	subArray a = maxsubarray1(A, 0, 16);
	a = maxsubarray2(A, 0, 16);
	a = maxsubarray3(A, 0, 16);
	a = maxsubarray4(A, 0, 16);
	*/
	return 0;
}