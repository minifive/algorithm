/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
For example, given
s ="leetcode",
dict =["leet", "code"].
Return true because"leetcode"can be segmented as"leet code".
*/
//bool DP[i]表示0~i是否可分，
//递推公式：DP[i]=DP[j]&f(j+1,i)

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
bool wordBreak(string s, unordered_set<string> &dict) {
	int n = s.size();
	vector<bool>DP(n+1, false);
	DP[0] = true;
	for (int i = 1; i <= n; i++){  //设i=1表示s的第一个字符
		for (int j = 0; j < i; j++){
			string temp = s.substr(j, i-j);//从j开始，长度为i-j的字符串，即s(j,i)
			if (dict.find(temp) != dict.end() && DP[j]){
				DP[i] = true;
				break;
			}
		}
	}

	return DP[n];
}


int main(){
	string s = "a";
	unordered_set<string>dict;
	dict.insert("a");
	cout << wordBreak(s, dict);
	return 0;
}