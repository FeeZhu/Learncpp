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
#include <stack> 
using namespace std;

extern void BSTree_test();

template <class type>
class BSTNode
{
public:
	BSTNode *left;
	BSTNode *right;
	BSTNode *parent;
	type data;
	BSTNode() :left(NULL), right(NULL) {}
	BSTNode(type d) :data(d), left(NULL), right(NULL) {}
};
//template <typename type>
//using bp = BSTNode*;//c++11�����ԣ����ģ���޷�����������

template <class type>
class BSTree
{
private:
public:
	BSTNode<type>* root;
public:
	BSTree():root(NULL){}
	~BSTree() { deleteNode(root); }
	bool isEmpty() const { return root == NULL; }//���ı����ĳ�Ա����
	bool searchNode(const type& a_data);//����
	void insert(const type& a_data) { insertAux(root, a_data); }
	BSTNode<type>* precessor(BSTNode<type>);//ǰ���ڵ�
	BSTNode<type>* sucessor(BSTNode<type>);//��̽ڵ�
	
	void remove(const type &a_data);//ɾ�����ڵ�
	void print(BSTNode<type>* node);//������ṹ

protected:
	void deleteNode(BSTNode<type>* node);//ɾ��������
	void insertAux(BSTNode<type>*& a_subRoot, const type& a_data);
	void PreOrder(BSTNode<type>* node);
	BSTNode<type>* search(BSTNode<type>* T, const type& a_data);//����
};

#endif


template<class type>
inline void BSTree<type>::deleteNode(BSTNode<type>* node)
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
inline void BSTree<type>::insertAux(BSTNode<type>* & a_subRoot, const type & a_data)
{
	//��ԭ���������Ϊ�գ���ֱ�Ӳ���
	//�������ؼ���С�ڸ����ؼ��֣�����뵽��������
	//���ؼ��ִ��ڸ����ؼ��֣�����뵽��������
	//�ݹ�ʵ��

	if (a_subRoot == NULL)
		a_subRoot = new BSTNode<type> (a_data);
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
BSTNode<type>* BSTree<type>::search(BSTNode<type>* T,const type & a_data)
{
	//���ҽڵ㣬���ؽڵ�ָ��
	//�ǵݹ����
	//while (T!=NULL&&a_data!=T->data)
	//{
	//	if (a_data < T->data)
	//	{
	//		T = T->left;
	//	}
	//	else
	//		T = T->right;
	//}
	//return T;
	//�ݹ����
	if (T==NULL||a_data==T->data)
	{
		return T;
	}
	if (a_data < T->data)
		return search(T->left, a_data);
	else
		return search(T->right, a_data);
}

template<class type>
inline bool BSTree<type>::searchNode(const type & a_data)
{
	bool found = false;
	if (search(root,a_data))
	{
		found = true;
	}
	return found;
}

template<class type>
inline BSTNode<type>* BSTree<type>::precessor(BSTNode<type>)
{
	
	return NULL;
}

template<class type>
inline BSTNode<type>* BSTree<type>::sucessor(BSTNode<type>)
{
	return NULL;
}

template<class type>
inline void BSTree<type>::remove(const type & a_data)
{
	//����ɾ����� z ��Ҷ�ӽ�㣬��ֱ��ɾ���������ƻ�����������������
	//����� z ֻ����������ֻ�������������� z ��������Ϊ z ��������������� z ��λ�ã�
	//����� z ���������������������������� z �ĺ�̣�Successor������ z��Ȼ��Ӷ����������ɾ�������̣�������ת�����˵�һ��ڶ������
	BSTNode<type>* x;
	BSTNode<type>* parent;
	BSTNode<type> *node = search(root,a_data);

	if (node->left==NULL&&node->right==NULL)
	{
		if (node->parent!=NULL)
		{

		}
	}
}

template<class type>
inline void BSTree<type>::print(BSTNode<type>* node)
{
	//���ı������ݹ�ʵ�֣����ֱ�ӵķ�ʽ
	//if (node==NULL)
	//{
	//	return;
	//}
	//std::cout << node->data<<endl;
	//print(node->left);
	//print(node->right);
	//�ǵݹ�ʵ��
	PreOrder(node);

}

template<class type>
inline void BSTree<type>::PreOrder(BSTNode<type>* Node)
{
	//�������������������,�ǵݹ�ʵ��
	//����stack�Ƚ�������Դ���ڵ�
	//������������ͺ�������ֱ�����õݹ�ͷǵݹ����ַ�ʽʵ��
	if (Node==NULL)
	{
		cerr << "Tree is NULL............" << endl;
	}
	stack <BSTNode<type> *> nstack;
	BSTNode<type> *node = Node;
	while (node!=NULL||nstack.empty()!=true)
	{
		while (node != NULL)
		{
			cout << node->data<<endl;
			nstack.push(node);
			node = node->left;
		}

		//��ջѰ��
		if (nstack.empty()!=true)
		{
			node = nstack.top();
			nstack.pop();
			node = node->right;
		}
	}
}