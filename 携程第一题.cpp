#include<iostream>
//携程第一题，输入一个数组，把其中为0的数放到数组末尾，
//要求非0的数顺序不变
//要求不能新开辟空间
using namespace std;
int main(){
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int index = 0;//index指向为0的位置
	int cur = 0;//cur指向index后面第一个不为0的位置
	while (index <= cur&&cur < n){
		while (a[index] != 0 && index < n) index++;
		cur = index + 1;
		while (a[cur] == 0 && cur < n) cur++;
		if (cur == n)
			break;
		a[index] = a[cur];
		a[cur] = 0;
		index++;
	}
	for (int i = 0; i < n; i++)
		cout << a[i] << endl;
	return 0;
}