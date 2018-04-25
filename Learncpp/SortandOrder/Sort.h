#pragma once

/*
 * �����������㷨�����е�һ���������⣬�������е��㷨���������������Ϊ�����㷨���ܺû�������
 *  ÿһ���㷨�������õķ�Χ�����ӣ�������˵����ʱ�临�Ӷ�С���㷨���κ������һ����á�
 *  //�����㷨���ܣ����������㷨��ʵ��c++
 *  //�����㷨���ȶ��ԣ�������ͬ�ؼ��ֵļ�¼��������֮��˳������ͬ�ģ�˵���ַ������ȶ���
 * //��ʵ��ÿһ���㷨������д��һ���������
 */

//�鲢���򣬺�������
std::vector <int> Merge(std::vector<int> l, std::vector<int> r);
void max_heapify(std::vector<int> &a, int i, int n);
int Partition(std::vector<int> &a, int p, int r);

//��������ʱ�临�Ӷ�ΪO��n2��
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
   shell sort�ǶԲ�������һ�ָĽ��������ݷֳɼ���С�飬Ȼ��ֱ�����ֱ�Ӳ�������
   ϣ�������㷨һ�ֲ��ȶ������򷽷�
*/

template<typename T>
void ShellSort(std::vector<T> &a)
{
	int gap;//shell����Ĳ���
	int size = a.size();
	//for (gap=size/3;gap>0;gap/=3)
	//{
	//	//ÿһ��ѭ������֤��߼���С���ұ߼���,�ڲ�ʵ������һ����������
	//	for (int i=0;i<gap;i++)
	//	{
	//		for (int j=i+gap;j<size;j+=gap)
	//		{
	//			if (a[j]<a[j-gap])
	//			{
	//				T tmp = a[j];
	//				int k = j - gap;
	//				while (k >= 0 && a[k] > tmp)
	//				{
	//					a[k + gap] = a[k];
	//					k -= gap;
	//				}
	//				a[k + gap] = tmp;
	//			}
	//		}
	//	}
	//}
	//�򻯴���
	for (gap = size / 2; gap > 0; gap /= 2)
		for (int i = gap; i < size; i++)
			for (int j = i - gap; j >= 0 && a[j] > a[j + gap]; j -= gap)
				std::swap(a[j], a[j + gap]);

}

/*
    �鲢����
	������ǳ���������������ֱ�����ʱ�临�Ӷ�ΪO(nlgn)
	����Ҫ����Ĵ���ռ�//std::vector <int> Left, Right,b;
*/
void MergeSort(std::vector<int> &a)
{
	int n = a.size();
	int mid = n / 2;
	std::vector <int> Left, Right,b;
	std::vector <int> Result(n);
	if (mid < 1)
		return;
	//��ֵ����
	Left.assign(a.begin(), a.begin() + mid);
	Right.assign(a.begin() + mid, a.end());
	MergeSort(Left);
	MergeSort(Right);
	a = Merge(Left, Right);
}
//�Թ鲢��������֧��������
std::vector<int> Merge(std::vector<int> l, std::vector<int> r)
{
	int m = l.size();
	int n = r.size();
	//1.�������ֵ���ڱ�
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
	//2.���ò�������ķ���
}

/*
   ������
   ������Heapsort����ָ���ö��������ݽṹ����Ƶ�һ�������㷨��
   ʱ�临�Ӷ�ΪO��nlgn�������ǲ���Ҫ������ڴ濪��
   �������㷨�����ȶ���
*/
void HeapSort(std::vector<int> &a)
{
	int len = a.size();
	//��ʼ���ѣ���������
	for (int i=a.size()/2-1;i>=0;i--)
	{
		max_heapify(a, i,len);
	}
	//�Ȍ���һ��Ԫ�غ��Ѿ��źõ�Ԫ��ǰһλ�����Q���ُ����{��(�յ�����Ԫ��֮ǰ��Ԫ��)��ֱ�������ꮅ
	for (int i = len - 1; i > 0; i--) {
		std::swap(a[0], a[i]);
		max_heapify(a, 0, i);
	}
}
//���ѵ���������һ�����ڵ�����ӽڵ�Ķ�
void max_heapify(std::vector<int> &a, int i,int n)
{
	int dad = i;
	int son = dad * 2 + 1;
	//�õ����ķ�����������
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
   ��������һ��ԭַ���򷽷�������״̬��ʱ�临�Ӷ�ΪO(nlgn)
   ����˼���Ǹ�����Ԫ�����黮��Ϊ����С�飬Ȼ������������÷�ұ��˼������
*/
template<typename T>
void QuickSort(std::vector<T> &a,int p,int r)
{
	if (p<r)//�ǳ���Ҫ����ֹ����Խ��
	{
		int q = Partition(a, p, r);
		QuickSort(a, p, q - 1);
		QuickSort(a, q + 1, r);
	}
}

//������ֳ��������֣���һ��������ֵķ���
template<typename T>
int Partition(std::vector<T> &a, int p, int r)
{
	int Pivot = a[r];//��Ԫ
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
   ���������ʽ���ǻ��ڱȽϵ����򷽷��������������µ�ʱ�临�Ӷ�O��nlgn��
   ������˳������򷽷�������ʱ�临�Ӷȿ��ԴﵽO(N)
   �ֱ��Ǽ������򡢻��������Ͱ����
*/

/*
   �������򣺼��������n��Ԫ�ض�������0-k֮���һ������,
   Ȼ���¼ÿһ�������ֵĴ���,��Ҳ�����ַ����ľ�������Ҫ�ϴ���ڴ濪��
   �����ʱ�临�Ӷ�ΪO��n+k��
   �ռ临�Ӷ�ΪO(n+k)
*/
template<typename T>
void CountSort(std::vector<T> &a,int n)
{

}

/*
    �ھ��£���λ����˳��ͳ������ѡ�������е�iλ��Ԫ�� ѡ������
	ǰ����������������������Ԫ���ǻ����
	�������ʣ�����Ϳ���ֱ�ӽ����һ�����⣬������������൱���ɳ�������������ʱ���ھͿ��Խ���������
*/
