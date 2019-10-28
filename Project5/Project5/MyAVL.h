#include<iostream>
typedef struct AVLTreeNode
{
	int key;
	int height;
	AVLTreeNode* lChild;
	AVLTreeNode* rChild;
}AvlNode,*pavlNode;

int AvlTreeHeight(AvlNode *root);
int max(int a, int b);

pavlNode LL(pavlNode &root);
pavlNode RR(pavlNode &root);
pavlNode LR(pavlNode &root);
pavlNode RL(pavlNode &root);

pavlNode InsertNode(pavlNode &root, int key);
pavlNode DeleteNode(pavlNode &root, int key);
AvlNode * TreeNodePre(pavlNode root);
AvlNode * TreeNodePost(pavlNode root);

void PreOrder(const pavlNode &root);
void InOrder(const pavlNode &root);
void TreeDestroy(pavlNode &root);