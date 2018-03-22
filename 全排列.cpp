#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Permutation(vector<int>&arr, int index){//全排列递归实现
	if (index >= arr.size())
	{
		for (int i = 0; i < arr.size(); i++){
			cout << arr[i];

		}
		cout << endl;
		return 0;
	}
	else{
		for (int i = index; i < arr.size(); i++){
			swap(arr[index], arr[i]);
			Permutation(arr, index + 1);
			swap(arr[i], arr[index]);
		}

	}
}

void STL(vector<int>&arr){//next_permutation 按字典序查找下一个排列
	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i];
	cout << endl;
	while (next_permutation(arr.begin(), arr.end())){
		for (int i = 0; i < arr.size(); i++)
			cout << arr[i];
		cout << endl;
	}
}

int main(){
	int n;

	vector<int>arr = { 1, 2, 3 };
	//Permutation(arr, 0);
	STL(arr);
	return 0;
}