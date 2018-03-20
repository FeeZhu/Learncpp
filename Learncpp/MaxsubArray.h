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

subArray maxcross(const int A[], int left, int mid, int right);
subArray max3(subArray a, subArray b, subArray c);

//1. 暴力枚举法 时间复杂度O（n3）
subArray maxsubarray1(const int A[], int left, int right)
{
	int maxsubsum = -100000;
	int sum = 0;
	subArray result;
	for (int i= left;i<right;i++)
	{
		for (int j= i;j<right;j++)
		{
			sum = 0;
			for (int k=i;k<=j;k++)
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
//2. 递归求解法 时间复杂度O（nlgn）
subArray maxsubarray2(const int A[] , int left, int right)
{
	subArray result;
	subArray leftsum, rightsum,crosssum;
	//when only one element in array
	if (left == right)
	{
		result.left = left;
		result.right = right;
		result.sum = A[left];
		return result;
	}
	else
	{
		int mid = (left + right) / 2;
		leftsum= maxsubarray2(A, left, mid);
		rightsum = maxsubarray2(A, mid + 1, right);
		crosssum = maxcross(A, left, mid, right);
		return max3(leftsum, rightsum, crosssum);
	}

}

subArray maxcross(const int A[], int left, int mid, int right)
{
	int left_sum = -100000, right_sum = -1000000;;//实际中如何表示无穷？
	int suml = 0, sumr = 0;
	subArray maxArray;
	for (int i = mid; i > left; i--)
	{
		suml += A[i];
		if (suml>left_sum)
		{
			left_sum = suml;
			maxArray.left = i;
		}
	}
	for (int j = mid+1; j < right; j++)
	{
		sumr += A[j];
		if (sumr > right_sum)
		{
		    right_sum = sumr;
			maxArray.right = j;
		}
	}

	maxArray.sum = left_sum + right_sum;
	return maxArray;
}

subArray max3(subArray a, subArray b, subArray c)
{
	//计算三个子数组中的最大值
	subArray maxArray = a.sum > b.sum ? a : b;
	maxArray = maxArray.sum > c.sum ? maxArray : c;
	return maxArray;
}

// 3. 线性求解法（贪心算法）