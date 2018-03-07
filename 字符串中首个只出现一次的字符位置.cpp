#include<iostream>
#include <queue>
#include <map>
using namespace std;

//在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置
//位图法
int FirstNotRepeatingChar(string str) {
	int a[256] = { 0 };
	for (int i = 0; i < str.length(); i++)
	{
		a[str[i]] += 1;
	
	}
	for (int i = 0; i < str.length(); i++)
	{
		if (a[str[i]] == 1)
			return i;
	}
	return -1;
}

//void main()
//{
//	string str = "google";
//	int t=FirstNotRepeatingChar(str);
//	cout << t;
//}