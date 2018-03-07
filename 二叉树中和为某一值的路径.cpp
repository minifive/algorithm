#include<iostream>
#include<vector>
using namespace std;
//输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
vector<vector<int>>buffer;
vector<int>tmp;
vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
	if (root == NULL)
		return buffer;
	tmp.push_back(root->val);
	expectNumber = expectNumber - root->val;
	if (expectNumber == 0 && root->left == NULL&&root->right == NULL)
	{
		buffer.push_back(tmp);
	}

	FindPath(root->left, expectNumber);
	FindPath(root->right, expectNumber);
	if (tmp.size()!=0)
		tmp.pop_back();
	return buffer;
}
//void  main()
//{
//	TreeNode*root = new TreeNode(10);
//	TreeNode*n1 = new TreeNode(5);
//	TreeNode*n2 = new TreeNode(12);
//	TreeNode*n3 = new TreeNode(4);
//	TreeNode*n4 = new TreeNode(7);
//	root->left = n1; root->right = n2;
//	n1->left = n3;
//	n1->right = n4;
//	vector<vector<int>>x=FindPath(root,22);
//	for (int i = 0; i < x.size(); i++)
//	{
//		for (int j = 0; j < x[i].size(); j++)
//		{
//			cout << x[i][j] << " ";
//		}
//		cout << endl;
//	}
//		
//}