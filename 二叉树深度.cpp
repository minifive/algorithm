#include<iostream>
#include <vector>
using namespace std;
//using t = int;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
int TreeDepth(TreeNode* pRoot)//深度
{
	if (pRoot == NULL)
		return 0;
	int left = TreeDepth(pRoot->left);
	int right = TreeDepth(pRoot->right);
	return left > right ? left + 1 : right + 1;
}

bool IsBalanced_Solution(TreeNode* pRoot) {//判断是否Wie平衡二叉树

	if (pRoot == NULL)
		return true;
	if (IsBalanced_Solution(pRoot->left)&&IsBalanced_Solution(pRoot->right))
	{
		int t1 = TreeDepth(pRoot->left);
		int t2 = TreeDepth(pRoot->right);
		if (t2-t1>=-1&&t2-t1<=1)
		{
			return true;
		}
		return false;
	}
	return false;
}

//void main()
//{
//	TreeNode*root = new TreeNode(1);
//	TreeNode*left = new TreeNode(2);
//	TreeNode*right = new TreeNode(3);
//	root->left = left;
//	root->right = right;
//	cout << IsBalanced_Solution(root);
//}