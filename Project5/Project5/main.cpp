#include"MyAVL.h"
#include<iostream>
#define len 10
using namespace std;

int main()
{
	int a[len] = { 3, 2, 1, 4, 5, 6, 7, 10, 9, 8 };
	cout << "������Ԫ��Ϊ��";
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
			cout << "����" << a[i] << "ʧ��" << endl;
	}
	cout << "���������";
	InOrder(root);
	cout << endl;
	cout << "ǰ�������";
	PreOrder(root);
	cout << endl;

	cout << "ɾ��ָ���ڵ��"<<endl;
	root = DeleteNode(root, 7);
	cout << "���������";
	InOrder(root);
	cout << endl;
	cout << "ǰ�������";
	PreOrder(root);
	cout << endl;
	TreeDestroy(root);

	system("pause");
	return 0;

}