#include<iostream>
#include <vector>
using namespace std;
//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果



bool ver(vector<int>sequence)
{
	if (sequence.size() == 0)
		return true;
	int p = sequence.back();
	vector<int>left;
	vector<int>right;
	int i = 0;
	for (; i < sequence.size() - 1; i++)
	{
		if (sequence[i] < p)
		{
			left.push_back(sequence[i]);
		}
		else break;
	}
	for (int j = i; j < sequence.size() - 1; j++){
		if (sequence[j] > p)
			right.push_back(sequence[j]);
		else
			return false;
	}
	if (ver(left) && ver(right))
		return true;
	else
		return false;
}
bool VerifySquenceOfBST(vector<int> sequence) {
	if (sequence.size() == 0)
		return false;
	return ver(sequence);
}

//int main()
//{
//	vector<int>t = { 22, 73, 35, 88, 94, 77 };
//	if (VerifySquenceOfBST(t))
//		cout << "yes";
//	else
//		cout << "no";
//}