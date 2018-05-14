#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
//��n����ֵ��Ӳ�ң�ÿ���������ޣ�����kԪ�ķ�����
//����DP[i][j]��ʾǰi��Ӳ�������ֵΪj�ķ�����
//����һ��dp[i][j] =sum(dp[i-1][j-k*a[i]]) k<=j/a[i]
//��������dp[i][j] = dp[i-1][j] + dp[i][j-a[i]]  && j>=a[i]
//||dp[i][j] = dp[i - 1][j] && j<a[i]
int main124(){
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		int *a = new int[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		vector<vector<int>>dp(n + 1, vector<int>(k + 1, 0));

		for (int i = 1; i <= k; i++){
			if (i%a[0] == 0)
				dp[0][i] = 1;
		}
		for (int i = 0; i < n; i++){
			dp[i][0] = 1;
		}

		/*for (int i = 1; i < n; i++){
		for (int j = 1; j <= k; j++){

		for (int x = 0; x*a[i] <= j; x++){
		dp[i][j] += dp[i - 1][j - x*a[i]];
		}
		}
		}*/
		for (int i = 1; i < n; i++){
			for (int j = 1; j <= k; j++)
			{
				if (j - a[i] >= 0){
					dp[i][j] = dp[i - 1][j] + dp[i][j - a[i]];
					dp[i][j] %= 100000007;
				}
				else
				{
					dp[i][j] = dp[i - 1][j];
				}
			}
		}


		cout << dp[n - 1][k] % 100000007;
	}
	return 0;
}