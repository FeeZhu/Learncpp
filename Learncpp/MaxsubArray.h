#pragma once
// �������������
// ������������һά�������ҳ�һ�������������飬ʹ�ø�����ĺ������С��

struct subArray
{
	// ��������������ݽṹ
	int left;
	int right;
	int sum;
};

//1. ����ö�ٷ�
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
//2. �ݹ���ⷨ
void maxsubarray(const int A[] , int left, int right)
{
	
}

// 3. ������ⷨ��̰���㷨��