#include<iostream>
#include<string>
using namespace std;

string add(string a, string b)
{
	//首先将a,b切分成整数部分和小数部分
	string a1 = "";
	string a2 = "";
	string b1 = "";
	string b2 = "";
	bool flag1 = false;
	bool flag2 = false;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] >= '0'&&a[i] <= '9')
			if (!flag1)
				a1 += a[i];
			else
				a2 += a[i];
		else if (a[i] == '.')
			flag1 = true;
		else
			return "false";
	}
	for (int i = 0; i < b.size(); i++)
	{
		if (b[i] >= '0'&&b[i] <= '9')
			if (!flag2)
				b1 += b[i];
			else
				b2 += b[i];
		else if (b[i] == '.')
			flag2 = true;
		else
			return "false";
	}
	//小数部分
	string max, min;
	if (a2.size() > b2.size())
	{
		max = a2;
		min = b2;
	}
	else
	{
		max = b2;
		min = a2;
	}
	int l1 = max.size();
	int l2 = min.size();
	bool isJinWei = false;
//	int j = l1 - 1;  //小数部分只需按照短的那一个数的所有位置相加
	for (int i = l2 - 1; i >= 0; i--)
		max[i] += min[i] - '0';
	for (int i = l1 - 1; i >= 1; i--)
	{
		if (max[i] > '9')
		{
			max[i] = max[i] - 10;
			max[i - 1]++;
		}
	}
	if (max[0] > '9')
	{
		isJinWei = true;
		max[0] -= 10;
	}
	//整数部分
	string max1, min1;
	if (a1.size() > b1.size())
	{
		max1 = a1;
		min1 = b1;
	}
	else
	{
		max1 = b1;
		min1 = a1;
	}
	l1 = max1.size();
	l2 = min1.size();
	int j = l1 - 1;   //整数部分两个数的下标分别控制从而确保从低位往高位求和
	if (isJinWei)
		max1[l1 - 1]++;
	for (int i = l2 - 1; i >= 0; i--,j--)
		max1[j] = max1[j] + min1[i] - '0';
	for (int i = l1 - 1; i > 0; i--)
	{
		if (max1[i] > '9')
		{
			max1[i] = max1[i] - 10;
			max1[i - 1]++;
		}
	}
	if (max1[0] > '9')
	{
		max1[0] -= 10;
		max1 = "1" + max1;
	}
	return max1+"."+max;
}

//
//int main()
//{
//	string s1, s2;
//	//cin >> s1 >> s2;
//	cout << add("999.9", "10.1");
//	return 0;
//}
