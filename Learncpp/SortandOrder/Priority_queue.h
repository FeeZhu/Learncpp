#pragma once
/*
   ��ͨ�Ķ�����һ���Ƚ��ȳ������ݽṹ��Ԫ���ڶ���β׷�ӣ����Ӷ���ͷɾ����
   �����ȶ����У�Ԫ�ر��������ȼ���������Ԫ��ʱ������������ȼ���Ԫ������ɾ����
   �ö��������ݽṹʵ�����ȶ���,STL�Ѿ�ʵ���˵��ǿ�������дһ��
   ������ȶ��У�����
   created by zhufei in 2018/3/30
*/

#ifndef MINQUEUE
#define MINQUEUE

#include <stdlib.h>

namespace QueueAlgorithm //����һ����namespace�е��࣬���õ�ʱ������֮�亯�������ظ�
{
	template<typename T, typename TkeyType>//ģ����
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
		//�ж���������ȶ��л�����С���ȶ���
			Heap = new Event[capacity*2];
			for (int i=0;i<capacity;i++)
			{
				//��������¼��Լ����ȼ�key
				Event random_event;
				random_event.data = rand() % 10;
				random_event.key = rand() % 15;
				Heap[i] = random_event;
			}
			Heapsize = capacity;
			buildHeap();
		}
		~priqueue() { delete []Heap; }
		//���ȶ��л�������                                                                                                  		void Insert(Event<T, TkeyType> new);//����������ȼ���Ԫ��
		T pop();//ɾ�������ؾ������ؼ��ֵ�Ԫ��
		void peek();//�鿴������ȼ���Ԫ��
		void Insert(T x,TkeyType k);//��Ԫ�ز��뵽������
		void Increasekey(int index,TkeyType k);//��Ԫ��x��keyֵ���ӵ�k
		void print();//��ӡ�ö��е�Ԫ��
		T &operator[](TkeyType key);//����������������ض����ȼ�������
	public:
	private:
		//�ѵĻ�����������ʵ�ֶ��еĻ������ݽṹ
		void buildHeap();//��������
		void max_heap(int i);
	};


	template<typename T, typename TkeyType>
    T QueueAlgorithm::priqueue<T, TkeyType>::pop()
	{
		//tips:һ��ʼ�Ҵ��㷵��private���͵ĳ�Ա���ݣ������ǲ��Ϸ���
		if (Heapsize < 0)
		{
			cout << "Error��No Event in the queue!!";
			exit(0);
		}
		Event max_event = Heap[0];
		Heap[0] = Heap[Heapsize - 1];
		Heapsize--;
		max_heap(0);
		//�����ſ��Զ�̬�ķ����ڴ棬��ͨ��������Ҫ����һ���ռ�Ȼ���ԭ����ֵ��ֵ��ȥ
		return max_event.data;
	}

	template<typename T, typename TkeyType>
	inline void priqueue<T, TkeyType>::peek()
	{
		cout << "������ȼ����¼�" << endl;
		cout << Heap[0].data << "-" << Heap[0].key;
	}

	template<typename T, typename TkeyType>
	inline void priqueue<T, TkeyType>::Insert(T x, TkeyType k)
	{
		//������в���Ԫ�أ��漰���ı������С
		int size = _msize(Heap)/sizeof(Heap)[0];
		if (Heapsize == size)
		{
			cout << "�����ڴ�̫С����Ҫ���·����ڴ�";
		}
		Heap[Heapsize].data = x;
		Heap[Heapsize].key = k;
		//��Ҷ�ڵ��ϸ�,
		Increasekey(Heapsize, k);
		Heapsize++;
	}
	
	/*���ӽڵ����ȼ�����ͣ�ĺ͸��ڵ�Ƚ�*/
	template<typename T, typename TkeyType>
	inline void priqueue<T, TkeyType>::Increasekey(int index, TkeyType k)
	{
		//Ϊ������Ԫ���������ȼ�
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
		//��ԭʼ�Ĳ��ҷ�ʽ�����Գ���д�ɶ��ֲ���
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
		cout << "������������ȶ��У�" << endl;
		print();
	}

	template<typename T, typename TkeyType>
	inline void priqueue<T, TkeyType>::max_heap(int i)
	{
		int dad = i;
		int son = dad * 2 + 1;
		//�õ����ķ�����������
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