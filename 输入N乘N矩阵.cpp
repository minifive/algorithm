#include <iostream>
#include <algorithm>
#include <vector>
//携程第二题  输入一个N*N的数组，将其旋转90度输出
using namespace std;

int main(){
	vector<vector<int>>buffer;
	vector<int>vec;
	int temp;
	int n = 0;
	do{
		cin >> temp;
		vec.push_back(temp);
		n++;
	} while (cin.get() != '\n');

	buffer.push_back(vec);
	vec.clear();
	for (int j = 1; j < n; j++){
		for (int i = 0; i < n; i++){
			cin >> temp;
			vec.push_back(temp);

		}
		buffer.push_back(vec);
		vec.clear();
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (j < n - 1)
				cout << buffer[n - j - 1][i] << " ";
			else
				cout << buffer[n - j - 1][i];
		}
		if (i != n - 1)
			cout << endl;
	}

	return 0;

}

