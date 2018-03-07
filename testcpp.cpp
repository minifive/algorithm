#include<iostream>
#include<string>
using namespace std;
int main(){
	string str;
	cin >> str;
	int map[256];
	int count = 0;
	int maxnum = 0;
	int index = 0;
	int i = 0;
	for (char c : str){
		if (c >= '0'&&c <= '9'){
			count++;
			if (count > maxnum){
				maxnum = count;
				index = i;
			}
		}
		else{
			count = 0;
		}
		i++;
	}

	for (int j = maxnum-1; j>=0; j--)
	{
		cout << str[index - j];
	}
}