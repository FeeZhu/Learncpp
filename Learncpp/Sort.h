#pragma once
//�����㷨���ܣ����������㷨��ʵ��c++
//�����㷨���ȶ��ԣ�������ͬ�ؼ��ֵļ�¼��������֮��˳������ͬ�ģ�˵���ַ������ȶ���
//�鲢���򣬺�������
std::vector <int> Merge(std::vector<int> l, std::vector<int> r);
void max_heapify(std::vector<int> &a, int i, int n);

//��������
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

