#include"MyAVL.h"
#include<iostream>
#define len 10
using namespace std;

int main()
{
	int a[len] = { 3, 2, 1, 4, 5, 6, 7, 10, 9, 8 };
	cout << "待插入元素为：";
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	pavlNode root = NULL;
	for (int i = 0; i < len; i++)
	{
		root = InsertNode(root,a[i]);
		if (NULL == root)
			cout << "插入" << a[i] << "失败" << endl;
	}
	cout << "中序遍历：";
	InOrder(root);
	cout << endl;
	cout << "前序遍历：";
	PreOrder(root);
	cout << endl;

	cout << "删除指定节点后："<<endl;
	root = DeleteNode(root, 7);
	cout << "中序遍历：";
	InOrder(root);
	cout << endl;
	cout << "前序遍历：";
	PreOrder(root);
	cout << endl;
	TreeDestroy(root);

	system("pause");
	return 0;

}