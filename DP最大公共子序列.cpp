#include<iostream>
#include<algorithm>
#include <string>
using namespace std;
//largest common subsequence
//用DP求两个字符串的最大公共子序列
//例 S1="14859763",S2="24869573"，dp[i][j]表示s1[0~i]与s2[0~j]中的最大公共子序列长度
//递推公式：dp[i][j]=max{dp[i-1][j],dp[i][j-1]};  s1[i]!=s2[j];
//                   dp[i-1][j-1];   s1[i]==s2[j];

int dp[10][10];
int pas[10][10];
void LCS(string s1, string s2){
	for (int i = 0; i < s1.length(); i++)
		dp[i][0] = 0;
	for (int j = 0; j < s2.length(); j++)
		dp[0][j] = 0;
	for (int i = 1; i <= s1.length(); i++){
		for (int j = 1; j <= s2.length(); j++){
			if (s1[i - 1] == s2[j - 1]){
				dp[i][j] = dp[i - 1][j - 1] + 1;
				pas[i][j] = 1;
			}
			else if (dp[i - 1][j]>dp[i][j - 1])
			{
				dp[i][j] = dp[i - 1][j];
				pas[i][j] = 2;
			}
			else {
				dp[i][j] = dp[i][j-1];
				pas[i][j] = 3;
			}
			
		}
	}
}

int main3(){
	string s1 = "1486963";
	string s2 = "486933";
	LCS(s1, s2);
	cout <<"largest common subsequence number:"<< dp[s1.length()][s2.length()]<<endl;

	cout << "the common subsequences are:";
	string s="";
	int left = s1.length();
	int right = s2.length();
	while (left>=1&&right>=1)
	{
		if (pas[left][right] == 1)
		{
			s += s1[left - 1];
			left--;
			right--;
		}
		if (pas[left][right] == 2){
			left--;
		}
		if (pas[left][right] == 3){
			right--;
		}
	}
	reverse(s.begin(),s.end());
	cout <<s<<endl;
	return 0;
}