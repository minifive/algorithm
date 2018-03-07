#include<iostream>
#include <string>
#include <vector>
using namespace std;
string ReverseSentence(string str) {
	string res = "";
	string tmp = "";
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			res = " " + tmp + res;
			tmp = "";
		}
		else
		{
			tmp += str[i];
		}
	}
	if (tmp.size())
	{
		res = tmp + res;
	}
	return res;
}
//void main()
//{
//	string s=ReverseSentence("I am a student.");
//	cout << s;
//}
