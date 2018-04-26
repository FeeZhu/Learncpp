#pragma once
/*
 * �ھ��£���λ����˳��ͳ����
 * ��ͳ��ѧ�У�������˳��ͳ����������С��������ʱ�ĵ�k��ֵ
 * ǰ����������������������Ԫ���ǻ����
 * �������ʣ�����Ϳ���ֱ�ӽ����һ�����⣬���ǻ�������ѵĽ������ķ���
 * ��������൱���ɳ���������ͨ��һЩ��������������ʱ���ڽ���������
*/
#include <math.h>

//��������ʱ��Ϊ���Ե�ѡ���㷨:���ѡ���㷨
//�������������A������飬p��r����ķ�Χ��i˳��ֵ
//��������ֵ����i������ֵ
//��������������Ԫ�ض��ǻ���ģ����ǿ�������������ʱ�����ҵ�����ͳ��˳����
template <typename T>
T RandomSelect(std::vector<T> A, int p, int r, int i)
{
	if (p == r)
		return A[p];
	int q = RandomPartition(A, p, r);
	int l = q - p + 1;
	if (l == i)
		return A[q];
	else if (i < l)
	{
		return RandomSelect(A, p, q - 1, i);
	}
	else
	{
		return RandomSelect(A, q + 1, r, i - l);
	}
}


//������ֺ���
template <typename T>
int RandomPartition(std::vector<T> &A, int p, int r)
{
	srand((unsigned int)time(0));
	int randomx = rand() % (r - p + 1) + p;
	std::swap(A[randomx], A[r]);//���ѡȡ��Ԫ�����⼫�����
	T Pivot = A[r];
	int i = p - 1;
	for (int j = p; j < r; j++)
	{
		if (A[j] <= Pivot)
		{
			i = i + 1;
			std::swap(A[i], A[j]);
		}
	}
	std::swap(A[i + 1], A[r]);
	return i+1 ;
}

//������Ϊ����ʱ���ѡ���㷨
//�������������A������飬p��r����ķ�Χ��i˳��ֵ
//��������ֵ����i������ֵ
//��������������Ԫ�ض��ǻ���ģ����ǿ�������������ʱ�����ҵ�����ͳ��˳����
//�ؼ�����������Ļ��ֺ�ѡ��Ĳ���
template <typename T>
T WorstSelect(std::vector<T> &A, int l, int r, int i)
{
	//1.��n��Ԫ�ػ���Ϊ���飬ÿ��5��Ԫ��,�ֱ�����ȷ����λ��
	int N = r - l + 1;
	int NGroup = ceil(N / 5.0);
	vector<T> Median;//��λ������
	if (N <= 5)
	{
		//�����������һ��
		T mid = insertSort(A, l + NGroup * 5 - 5, r);
		Median.push_back(mid);
		return A[l + i - 1];
	}
	for (int i=1;i<NGroup;i++)
	{
		T mid = insertSort(A, l+i * 5 - 5, l+i * 5 + -1);
		Median.push_back(mid);
	}
	//2.Ѱ����λ���������λ��
	int Midofmid = ceil(Median.size() / 2.0);
	T x = WorstSelect(Median, 0, Median.size() - 1, Midofmid);
	//3.������λ����������л���
	int k = Partition(A, l, r, x);
	int kl = k - l + 1;//ǰk��Ԫ��
	if (i==kl)
	{
		return x;
	}
	else if (i < kl)
	{
		return  WorstSelect(A, l, k - 1, i);
	}
	else
	{
		return  WorstSelect(A, k + 1, r, i - kl);
	}
}

//�������򣬶�������p��r��Ԫ�ز������򣬲������������λ��
template <typename T>
T insertSort(std::vector<T> &a,int l,int r)
{
	T key;
	int j;
	for (int i = l+1; i <= r; i++)
	{
		key = a[i];
		j = i - 1;
		while (j >= l && a[j] > key)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
	return a[(r - l) / 2+l];
}

//������λ����������л���
template <typename T>
int Partition(std::vector<T> &a, int low, int high, T x) 
{  
	//��������a��[low,high]�ģ�ע���ұ߽���ൽa[high]
	int i = low;
	while (a[i] != x) i++;
	swap(a[low], a[i]);  //����׼�Ƶ���λ��  
	while (low < high) {
		while (low < high&&a[high] >= x) high--;
		a[low] = a[high];
		while (low < high&&a[low] <= x) low++;
		a[high] = a[low];
	}
	a[low] = x;
	return low;
}