#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;
//��ֻ��������2��3��5��������������Ugly Number��������6��8���ǳ�������14���ǣ���Ϊ����������7�� ϰ�������ǰ�1�����ǵ�һ���������󰴴�С�����˳��ĵ�N������
//˼·����̬�滮����xΪ������2*x,3*x��5*xҲ�ǳ���
//�ӵ�һ��������ʼ��ÿ��ѡdp[i]*2,dp[j]*3,dp[k]*5��i>j>k�н�С��һ����Ϊ��һ������i+1��������

int GetUglyNumber_Solution(int index) {
	vector<int>DP;
	if (index <7)
		return index;
	DP.push_back(1);//DP[0]=1
	int x = 0, y = 0, z = 0;//�ֱ��¼��һ��*2��*3��*5�õ�������DP�±�
	for (int i = 1; i < index;i++)
	{
		int t= min(min(DP[x] * 2, DP[y] * 3), DP[z] * 5 );
		DP.push_back(t);
		if (DP[i] == DP[x] * 2) x++;//����*2�õ��ĳ���DP�±�
		if (DP[i] == DP[y] * 3) y++;
		if (DP[i] == DP[z] * 5) z++;
	}
	return DP[index - 1];
}

//void main()
//{
//	int t = GetUglyNumber_Solution(7);
//	cout << t;
//}