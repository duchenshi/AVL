#include"MyAVL.h"
#include<iostream>
using namespace std;
int AvlTreeHeight(AvlNode *root)
{
	if (root == NULL)
		return 0;
	else
		return (root->height);
}

int max(int a, int b){ return a > b ? a : b; }
pavlNode LL(pavlNode &root)
{
	if (root == NULL)
		return root;
	AvlNode *P = root->lChild;
	root->lChild = P->rChild;
	P->rChild = root;

	root->height = max(AvlTreeHeight(root->lChild), AvlTreeHeight(root->rChild)) + 1;
	P->height = max(AvlTreeHeight(P->lChild), root->height) + 1;

	return P;//新的根节点
}
pavlNode RR(pavlNode &root)
{
	if (NULL == root)
		return root;
	AvlNode *P = root->rChild;
	root->rChild = P->lChild;
	P->lChild = root;

	root->height = max(AvlTreeHeight(root->lChild), AvlTreeHeight(root->rChild)) + 1;
	P->height = max(AvlTreeHeight(P->rChild), root->height) + 1;

	return P;//新的根节点
}
pavlNode RL(pavlNode &root)
{
	root->rChild = LL(root->rChild);
	return RR(root);
}
pavlNode LR(pavlNode &root)
{
	root->lChild = RR(root->lChild);
	return LL(root);
}

pavlNode InsertNode(pavlNode &root, int key)
{
	if (NULL == root)
	{
		root = new AvlNode();
		if (NULL == root)
		{
			cout << "new开辟AvlNode空间失败" << endl;
			return root;
		}
		root->height = 0;
		root->key = key;
		root->lChild = root->rChild = NULL;
	}
	else if (key < root->key)
	{
		root->lChild = InsertNode(root->lChild, key);
		if (2 == abs(AvlTreeHeight(root->lChild) - AvlTreeHeight(root->rChild)))
		{
			if (key < root->lChild->key)
				root = LL(root);
			else
				root = LR(root);
		}
	}
	else if (key >= root->key)
	{
		root->rChild = InsertNode(root->rChild, key);
		if (2 == abs(AvlTreeHeight(root->rChild) - AvlTreeHeight(root->lChild)))
		{
			if (key >root->rChild->key)
				root = RR(root);
			else
				root = RL(root);
		}
	}
	root->height = max(AvlTreeHeight(root->lChild), AvlTreeHeight(root->rChild)) + 1;
	return root;
}

pavlNode DeleteNode(pavlNode &root, int key)
{
	if (key < root->key)
	{
		DeleteNode(root->lChild, key);
		if (AvlTreeHeight(root->rChild) - AvlTreeHeight(root->lChild) == 2)
		{
			AvlNode *p = root->rChild;
			if (AvlTreeHeight(p->lChild)>AvlTreeHeight(p->rChild))
				root = RL(root);
			else
				root = RR(root);
		}
	}
	else if (key > root->key)
	{
		DeleteNode(root->rChild, key);
		if (AvlTreeHeight(root->lChild) - AvlTreeHeight(root->rChild) == 2)
		{
			AvlNode *p = root->lChild;
			if (AvlTreeHeight(p->rChild) > AvlTreeHeight(p->lChild))
				root = LR(root);
			else
				root = LL(root);
		}
	}
	else
	{
		if (root->lChild&&root->rChild)
		{
			if (AvlTreeHeight(root->lChild) > AvlTreeHeight(root->rChild))
			{
				AvlNode *p = TreeNodePre(root->lChild);
				root->key = p->key;
				DeleteNode(root->lChild, p->key);
			}
			else
			{
				AvlNode *p = TreeNodePost(root->rChild);
				root->key = p->key;
				DeleteNode(root->rChild, p->key);
			}
		}
		else
		{
			if (root->lChild)
			{
				root->key = root->lChild->key;
				root->lChild = nullptr;
			}
			else if (root->rChild)
			{
				root->key = root->rChild->key;
				root->rChild = nullptr;
			}
			else
				root = nullptr;
		}
	}
	return root;
}



AvlNode * TreeNodePre(pavlNode root)  //最右结点
{
	if (NULL == root)
		return root;
	while (NULL != root->rChild)
		root = root->rChild;
	return root;
}
AvlNode * TreeNodePost(pavlNode root)
{
	if (NULL == root)
		return root;
	while (NULL != root->lChild)
		root = root->lChild;
	return root;
}

void PreOrder(const pavlNode &root)
{
	if (NULL == root)
		return;
	cout << root->key << "(" << root->height << ")" << " ";
	PreOrder(root->lChild);
	PreOrder(root->rChild);
}
void InOrder(const pavlNode &root)
{
	if (NULL == root)
		return;
	InOrder(root->lChild);
	cout << root->key << "(" << root->height << ")" << " ";
	InOrder(root->rChild);
}

void TreeDestroy(pavlNode &root)
{
	if (NULL == root)
		return;
	if (NULL != root->lChild)
		TreeDestroy(root->lChild);
	if (NULL != root->rChild)
		TreeDestroy(root->rChild);
	delete root;
	root = NULL;
}
