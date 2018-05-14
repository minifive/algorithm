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
			stackbuffer.push_back(make_pair(cur,1));//1���������ӽڵ㻹û����
			cur = cur->leftchild;
		}
		else
		{
			auto now = stackbuffer.back();
			stackbuffer.pop_back();
			if (now.second == 1){
				stackbuffer.push_back(make_pair(now.first, 2));//2����ǰ�ڵ�����ӽڵ��Ѿ����ʣ���һ���������������Ҫ�ѵ�ǰ�ڵ��ڴ�ѹջ
				cur = now.first->rightchild;//ת��ȥ�������ӽڵ�
			}
			else//�����2,�����ǰ�ڵ���Ϣ
				cout << now.first->value;
		}
	}
}