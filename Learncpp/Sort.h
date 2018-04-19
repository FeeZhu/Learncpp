#pragma once
//排序算法汇总，各种排序算法的实现c++
//排序算法的稳定性：具有相同关键字的记录经过排序之后顺序还是相同的，说这种方法是稳定的
//先实现每一种算法，考虑写成一个排序的类

//归并排序，函数申明
std::vector <int> Merge(std::vector<int> l, std::vector<int> r);
void max_heapify(std::vector<int> &a, int i, int n);
int Partition(std::vector<int> &a, int p, int r);

//插入排序
void insertSort(std::vector<int> &a)
{
	int key;
	int j;
	for (int i = 1; i < a.size(); i++)
	{
		key = a[i];
		j = i - 1;
		while (j >= 0 && a[j] < key)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}

/*
    归并排序
	将数组非常左右两个字数组分别排序，时间复杂度为O(nlgn)
	但需要额外的储存空间//std::vector <int> Left, Right,b;
*/
void MergeSort(std::vector<int> &a)
{
	int n = a.size();
	int mid = n / 2;
	std::vector <int> Left, Right,b;
	std::vector <int> Result(n);
	if (mid < 1)
		return;
	//赋值操作
	Left.assign(a.begin(), a.begin() + mid);
	Right.assign(a.begin() + mid, a.end());
	MergeSort(Left);
	MergeSort(Right);
	a = Merge(Left, Right);
}
//对归并的两个分支进行排序
std::vector<int> Merge(std::vector<int> l, std::vector<int> r)
{
	int m = l.size();
	int n = r.size();
	//1.设置最大值的哨兵
	l.push_back(100000000000);
	r.push_back(100000000000);
	std::vector <int> Result(m+n);
	int i = 0, j = 0;
	for (int k =0 ; k < Result.size(); k++)
	{
		if (l[i] <= r[j])
		{
			Result[k]=l[i];
			i = i + 1;
		}
		else
		{
			Result[k] = r[j];
			j = j + 1;
		}
	}
	return Result;
	//2.采用插入排序的方法
}
/*
   shell sort，希尔排序算法一种不稳定的排序方法
   将数据分成几个小块，然后分别排序
*/

template<typename T>
void ShellSort(std::vector<T> &a)
{

}

/*
   堆排序
   堆排序（Heapsort）是指利用堆这种数据结构所设计的一种排序算法。
   时间复杂度为O（nlgn），但是不需要额外的内存开销
   堆排序算法不是稳定的
*/
void HeapSort(std::vector<int> &a)
{
	int len = a.size();
	//初始化堆，创建最大堆
	for (int i=a.size()/2-1;i>=0;i--)
	{
		max_heapify(a, i,len);
	}
	//先將第一個元素和已经排好的元素前一位做交換，再從新調整(刚调整的元素之前的元素)，直到排序完畢
	for (int i = len - 1; i > 0; i--) {
		std::swap(a[0], a[i]);
		max_heapify(a, 0, i);
	}
}
//最大堆调整，构建一个父节点大于子节点的堆
void max_heapify(std::vector<int> &a, int i,int n)
{
	int dad = i;
	int son = dad * 2 + 1;
	//用迭代的方法构建最大堆
	while (son<n)
	{
		if (son+1<n&&a[son]<a[son+1])
		{
			son++;
		}
		if (a[dad] > a[son])
			return;
		else
		{
			std::swap(a[dad], a[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}

/*
   快速排序：一种原址排序方法，最优状态下时间复杂度为O(nlgn)
   基本思想是根据主元将数组划分为两个小组，然后对两个部分用分冶的思想排序
*/
template<typename T>
void QuickSort(std::vector<T> &a,int p,int r)
{
	if (p<r)//非常重要，防止数组越界
	{
		int q = Partition(a, p, r);
		QuickSort(a, p, q - 1);
		QuickSort(a, q + 1, r);
	}
}

//将数组分成两个部分
template<typename T>
int Partition(std::vector<T> &a, int p, int r)
{
	int Pivot = a[r];//主元
	int i = p - 1;
	for (int j=p;j<r;j++)
	{
		if (a[j]<=Pivot)
		{
			i = i + 1;
			std::swap(a[i], a[j]);
		}
	}
	std::swap(a[i+1], a[r]);
	return i+1 ;
}

/*
   上面的排序方式都是基于比较的排序方法，理论上需要的最小排序时间一定是O（nlgn）
   而基于顺序的排序方法理论上时间复杂度可以达到O(N)

*/