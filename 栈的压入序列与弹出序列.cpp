#include<iostream>
#include <vector>
using namespace std;
//输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序
//借用辅助栈

bool IsPopOrder(vector<int> pushV, vector<int> popV) {
	vector<int>stack;//辅助栈
	int i = 0, j = 0;
	int n = pushV.size();
	for (i = 0; i < pushV.size(); i++){
		stack.push_back(pushV[i]);//按照pushV的规则压栈
		while(stack.back()==popV[j]&&j<popV.size())//如果popV序列的第一个元素与刚压入的元素则匹配成功，j++,只当栈内所有元素都匹配成功
		{
			stack.pop_back();
			j++;
		}
	}
	if (stack.size() == 0)
		return true;
	return false;
}