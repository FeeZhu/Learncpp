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
	bool isEmpty() const { return root == NULL; }//不改变对象的成员函数
	bool find(const type& a_data) const;//查找
	void insert(const type& a_data) { insertAux(root, a_data); }
	void remove(const type &a_data);//删除树节点
	void print(bp node);//输出树结构
protected:
	void deleteNode(bp node);//删除二叉树
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
	//若原二叉查找树为空，则直接插入
	//否则，若关键字小于根结点关键字，则插入到左子树中
	//若关键字大于根结点关键字，则插入到右子树中
	//递归实现
	if (a_subRoot == NULL)
		a_subRoot = new BSTree<type>::BSTNode(a_data);
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
	//删除操作分为3中基本情况

}

template<class type>
inline void BSTree<type>::print(bp node)
{
	//涉及到树的遍历
	
	if (node==NULL)
	{
		return;
	}

	std::cout << node->data<<endl;
	print(node->left);
	print(node->right);

}
