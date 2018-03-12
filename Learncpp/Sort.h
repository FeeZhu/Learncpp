#pragma once
#include <vector>

//≤Â»Î≈≈–ÚÀ„∑®
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

//shell ≈≈–Ú