#pragma once
/*
 * 第九章：中位数和顺序统计量
 * 在统计学中，样本的顺序统计量即它从小到大排列时的第k个值
 * 前提条件：假设数组内所有元素是互异的
 * 毫无疑问，排序就可以直接解决这一类问题，但是还不是最佳的解决问题的方法
 * 这个问题相当于松弛了条件，通过一些条件可以在线性时间内解决这个问题
*/
#include <math.h>

//期望运行时间为线性的选择算法:随机选择算法
//函数输入参数：A随机数组，p，r数组的范围，i顺序值
//函数返回值：第i个数的值
//假设数组中所有元素都是互异的，我们可以在期望线性时间内找到任意统计顺序量
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


//随机划分函数
template <typename T>
int RandomPartition(std::vector<T> &A, int p, int r)
{
	srand((unsigned int)time(0));
	int randomx = rand() % (r - p + 1) + p;
	std::swap(A[randomx], A[r]);//随机选取主元，避免极端情况
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

//最坏情况下为线性时间的选择算法
//函数输入参数：A随机数组，p，r数组的范围，i顺序值
//函数返回值：第i个数的值
//假设数组中所有元素都是互异的，我们可以在期望线性时间内找到任意统计顺序量
//关键就是做好组的划分和选择的策略
template <typename T>
T WorstSelect(std::vector<T> &A, int l, int r, int i)
{
	//1.将n个元素划分为几组，每组5个元素,分别排序确定中位数
	int N = r - l + 1;
	int NGroup = ceil(N / 5.0);
	vector<T> Median;//中位数数组
	if (N <= 5)
	{
		//单独处理最后一组
		T mid = insertSort(A, l + NGroup * 5 - 5, r);
		Median.push_back(mid);
		return A[l + i - 1];
	}
	for (int i=1;i<NGroup;i++)
	{
		T mid = insertSort(A, l+i * 5 - 5, l+i * 5 + -1);
		Median.push_back(mid);
	}
	//2.寻找中位数数组的中位数
	int Midofmid = ceil(Median.size() / 2.0);
	T x = WorstSelect(Median, 0, Median.size() - 1, Midofmid);
	//3.按照中位数对数组进行划分
	int k = Partition(A, l, r, x);
	int kl = k - l + 1;//前k个元素
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

//插入排序，对数组中p到r的元素插入排序，并返回数组的中位数
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

//按照中位数对数组进行划分
template <typename T>
int Partition(std::vector<T> &a, int low, int high, T x) 
{  
	//这里数组a是[low,high]的，注意右边界最多到a[high]
	int i = low;
	while (a[i] != x) i++;
	swap(a[low], a[i]);  //将基准移到首位置  
	while (low < high) {
		while (low < high&&a[high] >= x) high--;
		a[low] = a[high];
		while (low < high&&a[low] <= x) low++;
		a[high] = a[low];
	}
	a[low] = x;
	return low;
}