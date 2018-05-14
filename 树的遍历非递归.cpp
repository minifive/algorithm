#include<iostream>
#include <vector>
using namespace std;

struct TreeNode
{
	int value;
	TreeNode*leftchild;
	TreeNode*rightchild;

};

void middleorder(TreeNode *root){
	vector<TreeNode*>stackbuffer;
	TreeNode *cur = root;
	while (cur!=NULL||!stackbuffer.empty())
	{
		if (cur!=NULL)
		{
			stackbuffer.push_back(cur);
			cur = cur->leftchild;
		}
		else {
			cur = stackbuffer.back();
			stackbuffer.pop_back();
			cout << cur->value<<" ";
			cur = cur->rightchild;

		}
	}
}

void PreOrderWithoutRecursion2(TreeNode* root)
{
	if (root == NULL)
		return;
	TreeNode* cur = root;
	vector<TreeNode*>stackbuffer;
	while (!stackbuffer.empty() || cur)
	{
		if (cur)
		{
			cout << cur->value<<" ";
			stackbuffer.push_back(cur);
			cur = cur->leftchild;
		}
		else
		{
			cur = stackbuffer.back();
			stackbuffer.pop_back();
			cur = cur->rightchild;
		}
	}
	cout << endl;
}


void backVistir(TreeNode*root){
	if (root == NULL)
		return;
	TreeNode* cur = root;
	vector<pair<TreeNode*,int>>stackbuffer;
	while (!stackbuffer.empty() || cur)
	{
		if (cur)
		{
			stackbuffer.push_back(make_pair(cur,1));//1代表其右子节点还没访问
			cur = cur->leftchild;
		}
		else
		{
			auto now = stackbuffer.back();
			stackbuffer.pop_back();
			if (now.second == 1){
				stackbuffer.push_back(make_pair(now.first, 2));//2代表当前节点的右子节点已经访问，下一步访问它本身，因此要把当前节点在此压栈
				cur = now.first->rightchild;//转过去处理右子节点
			}
			else//如果是2,输出当前节点信息
				cout << now.first->value;
		}
	}
}