////输入两个大整数a  b
////输出a*b
#include<iostream>
#include <string>
using namespace std;

string  mutiple(string s1, string s2){
	int n1 = s1.length();
	int n2 = s2.length();
	int *result = new int[n1 + n2];
	for (int i = 0; i < n1 + n2; i++){
		result[i] = 0;
	}//初始化
	for (int i = n1 - 1; i >= 0; --i){
		int k = n2 + i;
		for (int j = n2 - 1; j >= 0; --j){
			result[k--] += (s1[i] - '0')*(s2[j] - '0');
		}
	}

	for (int i = n2 + n1 - 1; i > 0; i--)
	{
		if (result[i] > 9){
			result[i - 1] += result[i] / 10;
			result[i] = result[i] % 10;
		}
	}

	string s;
	for (int i = 0; i < n2 + n1; i++){
		s += to_string(result[i]);
	}
	return s;
}

int main(){
	string s1, s2;
	cin >> s1 >> s2;
	cout << mutiple(s1, s2);
}