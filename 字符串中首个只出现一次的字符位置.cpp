#include<iostream>
#include <queue>
#include <map>
using namespace std;

//��һ���ַ���(1<=�ַ�������<=10000��ȫ������ĸ���)���ҵ���һ��ֻ����һ�ε��ַ�,����������λ��
//λͼ��
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