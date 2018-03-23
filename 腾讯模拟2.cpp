//小明有很多枚硬币，面值为2的k次方，数量均2，问有多少种组合方式组合出面值为n
//深度  DFS,将k看做深度，若和超过n则回溯
#include<iostream>
#include <stack>
#include <vector>
#include <set>

using namespace std;

set<vector<int>>buffer;//用于判重
int getcount(int deepth, int sum, int target, vector<int>res){
	if (sum > target)
		return 0;
	if (sum == target){
		vector<int>temp;
		for (int i = 0; i < res.size(); i++)
		{
			temp.push_back(res[i]);
			cout << res[i] << " ";
		}
		cout << endl;
		buffer.insert(temp);
		return 1;
	}
	for (int i = deepth; i < target * 2; i++)//sum<target
	{
		sum += pow(2, (i / 2));//用i/2做指数可分别枚举出1 1 2 2 4 4 8 8...
		res.push_back(pow(2, (i / 2)));
		getcount(i + 1, sum, target, res);
		res.pop_back();
		sum -= pow(2, (i / 2));
	}
	return 0;
}
int main(){
	int n;

	cin >> n;
	vector<int>tmp;
	getcount(0, 0, n, tmp);
	cout << buffer.size();


	return  0;
}
