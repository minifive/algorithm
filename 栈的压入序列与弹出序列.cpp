#include<iostream>
#include <vector>
using namespace std;
//���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳��
//���ø���ջ

bool IsPopOrder(vector<int> pushV, vector<int> popV) {
	vector<int>stack;//����ջ
	int i = 0, j = 0;
	int n = pushV.size();
	for (i = 0; i < pushV.size(); i++){
		stack.push_back(pushV[i]);//����pushV�Ĺ���ѹջ
		while(stack.back()==popV[j]&&j<popV.size())//���popV���еĵ�һ��Ԫ�����ѹ���Ԫ����ƥ��ɹ���j++,ֻ��ջ������Ԫ�ض�ƥ��ɹ�
		{
			stack.pop_back();
			j++;
		}
	}
	if (stack.size() == 0)
		return true;
	return false;
}