#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;
//把只包含因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数
//思路：动态规划，若x为丑数则2*x,3*x，5*x也是丑数
//从第一个丑数开始，每次选dp[i]*2,dp[j]*3,dp[k]*5，i>j>k中较小的一个作为下一个（第i+1个）丑数

int GetUglyNumber_Solution(int index) {
	vector<int>DP;
	if (index <7)
		return index;
	DP.push_back(1);//DP[0]=1
	int x = 0, y = 0, z = 0;//分别记录上一次*2，*3，*5得到丑数的DP下标
	for (int i = 1; i < index;i++)
	{
		int t= min(min(DP[x] * 2, DP[y] * 3), DP[z] * 5 );
		DP.push_back(t);
		if (DP[i] == DP[x] * 2) x++;//更新*2得到的丑数DP下标
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