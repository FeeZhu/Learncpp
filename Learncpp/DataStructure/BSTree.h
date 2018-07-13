#pragma once
/*************************************************************************
> File Name: BTREE.h
> ������������������ҡ���ֵ��ǰ����̡����ӡ�ɾ������
> ����дһ��
************************************************************************/

#ifndef BTREE_H_
#define BTREE_H_

#include <iostream>
#include <iomanip>
using namespace std;

template <class type>
class BSTree
{
private:
	class BSTNode
	{
	public:
		BSTNode *left;
		BSTNode *right;
		BSTNode *parent;
		type data;
		BSTNode():left(NULL),right(NULL){}
		BSTNode(type d):data(d), left(NULL), right(NULL) {}
	};
	typedef BSTNode* bp;
public:
	bp root;
public:
	BSTree():root(NULL){}
	~BSTree() { deleteNode(root); }
	bool isEmpty() const { return root == NULL; }//���ı����ĳ�Ա����
	bool find(const type& a_data) const;//����
	void insert(const type& a_data) { insertAux(root, a_data); }
	void remove(const type &a_data);//ɾ�����ڵ�
	void print(bp node);//������ṹ
protected:
	void deleteNode(bp node);//ɾ��������
	void insertAux(bp& a_subRoot, const type& a_data);
};

#endif


template<class type>
inline void BSTree<type>::deleteNode(bp node)
{
	if (node->left != NULL)
		deleteNode(node->left);
	else if (node->right != NULL)
		deleteNode(node->right);
	else if (node != NULL)
	{
		delete node;
		node = NULL;
	}
}

template<class type>
inline void BSTree<type>::insertAux(bp & a_subRoot, const type & a_data)
{
	//��ԭ���������Ϊ�գ���ֱ�Ӳ���
	//�������ؼ���С�ڸ����ؼ��֣�����뵽��������
	//���ؼ��ִ��ڸ����ؼ��֣�����뵽��������
	//�ݹ�ʵ��
	if (a_subRoot == NULL)
		a_subRoot = new BSTree<type>::BSTNode(a_data);
	else if (a_data < a_subRoot->data)
		insertAux(a_subRoot->left, a_data);
	else if (a_data > a_subRoot->data)
		insertAux(a_subRoot->right, a_data);
	else
		std::cerr << "data has already in the tree";//data == key�����
	////�ǵݹ�ʵ�֣����ṹ�����仯
	//BSTNode *pre = NULL;//��¼��һ���ڵ�
	//BSTNode *cur = a_subRoot;//��ǰ�ڵ�
	//while (cur!=NULL)
	//{
	//	pre = cur;
	//	if (a_data < a_subRoot->data)
	//		cur = cur->left;
	//	else if (a_data > a_subRoot->data)
	//		cur = cur->right;
	//	else
	//		std::cerr << "data has already in the tree";//data == key�����
	//}
	//BSTNode *node = new BSTree<type>::BSTNode(a_data);
	//node->parent = pre;
	//if (pre == NULL)
	//{
	//	a_subRoot = node;
	//}
	//else if (node->data < pre->data)
	//{
	//	pre->left = node;
	//}
	//else
	//	pre->right = node;
}

template<class type>
inline bool BSTree<type>::find(const type & f_data) const
{
	bp locPtr = root;
	bool found = false;
	while (!found&&locPtr != NULL)
	{
		if (f_data < locPtr->data)
		{
			locPtr = locPtr->left;
		}
		else if (f_data > locPtr->data)
		{
			locPtr = locPtr->right;
		}
		else
			found = true;
	}
	return found;
}

template<class type>
inline void BSTree<type>::remove(const type & a_data)
{
	//ɾ��������Ϊ3�л������

}

template<class type>
inline void BSTree<type>::print(bp node)
{
	//�漰�����ı���
	
	if (node==NULL)
	{
		return;
	}

	std::cout << node->data<<endl;
	print(node->left);
	print(node->right);

}
