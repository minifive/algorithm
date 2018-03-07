#include<iostream>
#include<queue>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
vector<int> PrintFromTopToBottom(TreeNode* root) {
	queue<TreeNode*>bufer;
	vector<int>tmp;
	if (root == NULL)
		return tmp;
	bufer.push(root);
	while(!bufer.empty())
	{
		TreeNode* t = bufer.front();
		bufer.pop();
		tmp.push_back(t->val);
		if (t->left!=NULL)
			bufer.push(t->left);
		if (t->right != NULL)
			bufer.push(t->right);
	}
	return tmp;
}

//void main()
//{
//	TreeNode *root = new TreeNode(1);
//	TreeNode *lef = new TreeNode(2);
//	TreeNode *ri = new TreeNode(3);
//	TreeNode *x = new TreeNode(4);
//	TreeNode *y = new TreeNode(5);
//	root->left = lef;
//	root->right = ri;
//	lef->left = x;
//	ri->right = y;
//
//	vector<int>tmp=	PrintFromTopToBottom(NULL);
//	for (int t = 0; t < tmp.size(); t++)
//	{
//		cout << tmp[t];
//	}
//}