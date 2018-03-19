#pragma once
// 最大子数组问题
// 问题描述：从一维数组中找出一个连续的子数组，使得该数组的和最大（最小）

struct subArray
{
	// 定义子数组的数据结构
	int left;
	int right;
	int sum;
};

//1. 暴力枚举法
subArray maxsubarray1(const int A[], int left, int right)
{
	int maxsubsum = -100000;
	int sum = 0;
	subArray result;
	for (int i= left;i<right;i++)
	{
		for (int j= i+1;j<right;j++)
		{
			sum = 0;
			for (int k=i;k<j;k++)
			{
				sum += A[k];
			}
			if (sum > maxsubsum)
			{
				maxsubsum = sum;
				result.left = i;
				result.right = j;
				result.sum = maxsubsum;
			}
		}
	}
	return result;
}
//2. 递归求解法
void maxsubarray(const int A[] , int left, int right)
{
	
}

// 3. 线性求解法（贪心算法）