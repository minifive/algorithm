#include<iostream>
using namespace std;
//输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
//首先想到的是递归，肯定有重复判断
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};



bool isSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if (pRoot2 == NULL)
		return true;
	if (pRoot1 == NULL)
		return false;
	if (pRoot1->val == pRoot2->val)
	{
		if (isSubtree(pRoot1->left, pRoot2->left) && isSubtree(pRoot1->right, pRoot2->right))
			return true;
	}
	else
		return false;
}


bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if (pRoot1 == NULL || pRoot2 == NULL)
		return false;
	if (isSubtree(pRoot1, pRoot2))
		return true;
	if (HasSubtree(pRoot1->left, pRoot2))
		return true;
	if (HasSubtree(pRoot1->right, pRoot2))
		return true;
	return false;

}
