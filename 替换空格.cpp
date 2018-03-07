#include<iostream>
using namespace std;
void replaceSpace(char* str, int length){
	int n=strlen(str);
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		if (str[i]==' ')
		{
			num++;
		}
	}
	int newlen = n + num * 2;
	
	for (int j = n; j >= 0; j--)//'\0Ò²ÒªÒÆ¶¯'
	{
		if (str[j] == ' ')
		{
			str[newlen--] = '0';
			str[newlen--] = '2';
			str[newlen--] = '%';
		}
		else
		{
			str[newlen--] = str[j];
		}
	}
}
//int main()
//{
//	char str[100]= "12 34";
//	replaceSpace(str, 5);
//	cout << str;
//}