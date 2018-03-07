#include<iostream>
#include <vector>
using namespace std;

//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
vector<TreeNode*>buffer;
void xConvert(TreeNode* pRootOfTree)//二叉搜索树中序遍历
{
	if (pRootOfTree == NULL)
		return;
	xConvert(pRootOfTree->left);
	buffer.push_back(pRootOfTree);
    xConvert(pRootOfTree->right);
}
TreeNode* Convert(TreeNode* pRootOfTree)
{
	xConvert(pRootOfTree);
	if (buffer.size()<1)
	{
		return NULL;
	}
	TreeNode *left = NULL;
	for (int i = 0; i < buffer.size()-1;i++)
	{
		buffer[i]->right = buffer[i + 1];
		buffer[i]->left =left ;
		left = buffer[i];
	}
	buffer[buffer.size() - 1]->left = left;
	return buffer[0];
}

//void main()
//{
//	TreeNode*root = new TreeNode(1);
//	Convert(root);
//}