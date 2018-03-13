// Learncpp.cpp : 定义控制台应用程序的入口点。
//This is a project to learn program 
// 11/30 插入排序

#include "stdafx.h"
#include <iostream>
#include <vector>
#include "Sort.h"

using namespace std;
void insertSort(vector<int> &a);

int main()
{
	vector<int> A{3,6,2,8,4,8,23 ,10,15};
	//insertSort(A);
	MergeSort(A);
	for (int i = 0; i < A.size(); i++)
	{
		cout << A[i] << " ";
	}
	return 0;
}