#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


bool cmp(int a, int b)//�Զ���Ƚϲ��ԣ���ƴ���ٱȽϣ����a<b��return true
{
	string A = "";
	string B = "";
	A += to_string(a);
	A += to_string(b);
	B += to_string(b);
	B += to_string(a);
	return A < B;//ab<ba��a<b
}
void sorts(vector<int>&num){
	for (int i = 0; i < num.size(); i++)
	{
		for (int j = i; j < num.size(); j++)
		{
			if (!cmp(num[i], num[j]))
			{
				swap(num[i], num[j]);
			}
		}
	}
}
string PrintMinNumber(vector<int> numbers) {
	string answer = "";
	//sort(numbers.begin(), numbers.end(), cmp);
	sorts(numbers);
	for (int i = 0; i < numbers.size();i++)
	{
		answer += to_string(numbers[i]);
	}
	return answer;
}

//void main()
//{
//	vector<int>tmp = { 3, 32, 321 };
//	string s = PrintMinNumber(tmp);
//	cout << s;
//}