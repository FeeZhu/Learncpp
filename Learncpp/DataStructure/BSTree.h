#pragma once
/*************************************************************************
> File Name: BTREE.h
> 二插查找树，包括查找、最值、前驱后继、增加、删除操作
> 重新写一遍
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
//using bp = BSTNode*;//c++11新特性，解决模板无法重命名问题

template <class type>
class BSTree
{
private:
public:
	BSTNode<type>* root;
public:
	BSTree():root(NULL){}
	~BSTree() { deleteNode(root); }
	bool isEmpty() const { return root == NULL; }//不改变对象的成员函数
	bool searchNode(const type& a_data);//查找
	void insert(const type& a_data) { insertAux(root, a_data); }
	BSTNode<type>* precessor(BSTNode<type>);//前驱节点
	BSTNode<type>* sucessor(BSTNode<type>);//后继节点
	
	void remove(const type &a_data);//删除树节点
	void print(BSTNode<type>* node);//输出树结构

protected:
	void deleteNode(BSTNode<type>* node);//删除二叉树
	void insertAux(BSTNode<type>*& a_subRoot, const type& a_data);
	void PreOrder(BSTNode<type>* node);
	BSTNode<type>* search(BSTNode<type>* T, const type& a_data);//查找
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
	//若原二叉查找树为空，则直接插入
	//否则，若关键字小于根结点关键字，则插入到左子树中
	//若关键字大于根结点关键字，则插入到右子树中
	//递归实现

	if (a_subRoot == NULL)
		a_subRoot = new BSTNode<type> (a_data);
	else if (a_data < a_subRoot->data)
		insertAux(a_subRoot->left, a_data);
	else if (a_data > a_subRoot->data)
		insertAux(a_subRoot->right, a_data);
	else
		std::cerr << "data has already in the tree";//data == key的情况
	////非递归实现，树结构发生变化
	//BSTNode *pre = NULL;//记录上一个节点
	//BSTNode *cur = a_subRoot;//当前节点
	//while (cur!=NULL)
	//{
	//	pre = cur;
	//	if (a_data < a_subRoot->data)
	//		cur = cur->left;
	//	else if (a_data > a_subRoot->data)
	//		cur = cur->right;
	//	else
	//		std::cerr << "data has already in the tree";//data == key的情况
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
	//查找节点，返回节点指针
	//非递归查找
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
	//递归查找
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
	//若被删除结点 z 是叶子结点，则直接删除，不会破坏二叉排序树的性质
	//若结点 z 只有左子树或只有右子树，则让 z 的子树成为 z 父结点的子树，替代 z 的位置；
	//若结点 z 既有左子树，又有右子树，则用 z 的后继（Successor）代替 z，然后从二叉查找树中删除这个后继，这样就转换成了第一或第二种情况
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
	//树的遍历，递归实现，最简单直接的方式
	//if (node==NULL)
	//{
	//	return;
	//}
	//std::cout << node->data<<endl;
	//print(node->left);
	//print(node->right);
	//非递归实现
	PreOrder(node);

}

template<class type>
inline void BSTree<type>::PreOrder(BSTNode<type>* Node)
{
	//树的先序遍历，根左右,非递归实现
	//借助stack先进后出特性储存节点
	//其他中序遍历和后序遍历分别可以用递归和非递归两种方式实现
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

		//出栈寻找
		if (nstack.empty()!=true)
		{
			node = nstack.top();
			nstack.pop();
			node = node->right;
		}
	}
}