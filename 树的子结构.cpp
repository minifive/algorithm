#include<iostream>
using namespace std;
//�������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��
//�����뵽���ǵݹ飬�϶����ظ��ж�
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
