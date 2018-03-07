#include<iostream>
#include <vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

TreeNode* recon(vector<int>pre,vector<int>vin)
{
	int t = pre.size();
	if (t == 0)
		return NULL;
	TreeNode *curhead = new TreeNode(pre[0]);
	
	for (int i = 0; i < t; i++)
	{
		if (vin[i] == pre[0])
		{
			vector<int>leftpre;
			vector<int>rightpre;
			vector<int>leftvin;
			vector<int>rightvin;
			for (int j = 1; j <= i;j++)
			{
				leftpre.push_back(pre[j]);
				leftvin.push_back(vin[j - 1]);
			}
			for (int p = i+1; p < t;p++)
			{
				rightpre.push_back(pre[p]);
				rightvin.push_back(vin[p]);
			}
			curhead->left = recon(leftpre, leftvin);
			curhead->right = recon(rightpre, rightvin);
			return curhead;
		}
	}
	return NULL;
}

//void main()
//{
//	vector<int>pre = { 1, 2, 4, 7, 3, 5, 6, 8 };
//	vector<int>vin = { 4, 7, 2, 1, 5, 3, 8,6 };
//	TreeNode *head = recon(pre, vin);
//	cout << head->left->val;
//}