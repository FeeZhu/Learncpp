#pragma once
//�����㷨���ܣ����������㷨��ʵ��c++

//�鲢���򣬺�������
std::vector <int> Merge(std::vector<int> l, std::vector<int> r);


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

//�鲢����
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

// shell sort
