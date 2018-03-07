#include<iostream>
#include <vector>
using namespace std;

//����һ�ö��������������ö���������ת����һ�������˫������Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
vector<TreeNode*>buffer;
void xConvert(TreeNode* pRootOfTree)//�����������������
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