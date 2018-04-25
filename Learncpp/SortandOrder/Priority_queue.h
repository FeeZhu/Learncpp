#pragma once
/*
   普通的队列是一种先进先出的数据结构，元素在队列尾追加，而从队列头删除。
   在优先队列中，元素被赋予优先级。当访问元素时，具有最高优先级的元素最先删除。
   用堆这种数据结构实现优先队列,STL已经实现了但是可以试着写一下
   最大优先队列！！！
   created by zhufei in 2018/3/30
*/

#ifndef MINQUEUE
#define MINQUEUE

#include <stdlib.h>

namespace QueueAlgorithm //定义一个在namespace中的类，调用的时候避免库之间函数名的重复
{
	template<typename T, typename TkeyType>//模板编程
	class priqueue
	{ 
	private:
		struct Event
		{
			T data;
			TkeyType key;
		};
		Event *Heap;
		int Heapsize;
	public:
		priqueue(int capacity) {
		//判断是最大优先队列还是最小优先队列
			Heap = new Event[capacity*2];
			for (int i=0;i<capacity;i++)
			{
				//随机产生事件以及优先级key
				Event random_event;
				random_event.data = rand() % 10;
				random_event.key = rand() % 15;
				Heap[i] = random_event;
			}
			Heapsize = capacity;
			buildHeap();
		}
		~priqueue() { delete []Heap; }
		//优先队列基本操作                                                                                                  		void Insert(Event<T, TkeyType> new);//插入带有优先级的元素
		T pop();//删除并返回具有最大关键字的元素
		void peek();//查看最高优先级的元素
		void Insert(T x,TkeyType k);//将元素插入到队列中
		void Increasekey(int index,TkeyType k);//将元素x的key值增加到k
		void print();//打印该堆中的元素
		T &operator[](TkeyType key);//重载运算符，返回特定优先级的数据
	public:
	private:
		//堆的基本操作，是实现队列的基本数据结构
		void buildHeap();//构建最大堆
		void max_heap(int i);
	};


	template<typename T, typename TkeyType>
    T QueueAlgorithm::priqueue<T, TkeyType>::pop()
	{
		//tips:一开始我打算返回private类型的成员数据，这样是不合法的
		if (Heapsize < 0)
		{
			cout << "Error：No Event in the queue!!";
			exit(0);
		}
		Event max_event = Heap[0];
		Heap[0] = Heap[Heapsize - 1];
		Heapsize--;
		max_heap(0);
		//容器才可以动态的分配内存，普通的数组需要分配一个空间然后把原来的值赋值进去
		return max_event.data;
	}

	template<typename T, typename TkeyType>
	inline void priqueue<T, TkeyType>::peek()
	{
		cout << "最大优先级的事件" << endl;
		cout << Heap[0].data << "-" << Heap[0].key;
	}

	template<typename T, typename TkeyType>
	inline void priqueue<T, TkeyType>::Insert(T x, TkeyType k)
	{
		//像队列中插入元素，涉及到改变数组大小
		int size = _msize(Heap)/sizeof(Heap)[0];
		if (Heapsize == size)
		{
			cout << "数组内存太小，需要重新分配内存";
		}
		Heap[Heapsize].data = x;
		Heap[Heapsize].key = k;
		//从叶节点上浮,
		Increasekey(Heapsize, k);
		Heapsize++;
	}
	
	/*增加节点优先级，不停的和父节点比较*/
	template<typename T, typename TkeyType>
	inline void priqueue<T, TkeyType>::Increasekey(int index, TkeyType k)
	{
		//为队列中元素设置优先级
		while (index!=0)
		{
			int p_index= (index - 1) >> 1;
			cout << Heap[index].key << Heap[p_index].key;
			if (Heap[p_index].key<Heap[index].key)
			{
				swap(Heap[p_index], Heap[index]);
			}
			index = p_index;
		}
	}

	template<typename T, typename TkeyType>
	inline void priqueue<T, TkeyType>::print()
	{
		for (int i=0;i<Heapsize;i++)
		{
			cout << Heap[i].data << "-" << Heap[i].key;
			cout << endl;
		}
	}

	template<typename T, typename TkeyType>
	inline T & priqueue<T, TkeyType>::operator[](TkeyType key)
	{
		//最原始的查找方式，可以尝试写成二分查找
		for (int i = 0; i < Heapsize; i++)
		{
			if (key==Heap[i].key)
			{
				return Heap[i].data;
			}
		}
		exit(0);
	}

	template<typename T, typename TkeyType>
	inline void priqueue<T, TkeyType>::buildHeap()
	{
		for (int i = Heapsize / 2 - 1; i >= 0; i--)
		{
			max_heap(i);
		}
		cout << "构建的最大优先队列：" << endl;
		print();
	}

	template<typename T, typename TkeyType>
	inline void priqueue<T, TkeyType>::max_heap(int i)
	{
		int dad = i;
		int son = dad * 2 + 1;
		//用迭代的方法构建最大堆
		while (son < Heapsize)
		{
			if (son + 1 < Heapsize&&Heap[son].key < Heap[son + 1].key)
			{
				son++;
			}
			if (Heap[dad].key > Heap[son].key)
				return;
			else
			{
				swap(Heap[dad], Heap[son]);
				dad = son;
				son = dad * 2 + 1;
			}
		}
	}

}
#endif // MINQUEUE