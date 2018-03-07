#include<iostream>
#include <vector>
using namespace std;

int FindGreatestSumOfSubArray(vector<int> array) {
	if (array.size() == 0)
		return NULL;
	vector<int>dp;
	dp.push_back(array[0]);
	int max = dp[0];
	for (int i = 1; i < array.size(); i++){
		if (dp[i - 1] > 0){
			dp.push_back(dp[i - 1] + array[i]);
		}
		else{
			dp.push_back( array[i]);
		}
		if (dp[i] > max)
			max = dp[i];
	}
	return max;
}

//void main()
//{
//	vector<int>a = { 6, -3, -2, 7, -15, 1, 2, 2 };
//	int t=FindGreatestSumOfSubArray(a);
//	cout << t;
//}