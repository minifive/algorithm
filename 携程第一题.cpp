#include<iostream>
//Я�̵�һ�⣬����һ�����飬������Ϊ0�����ŵ�����ĩβ��
//Ҫ���0����˳�򲻱�
//Ҫ�����¿��ٿռ�
using namespace std;
int main(){
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int index = 0;//indexָ��Ϊ0��λ��
	int cur = 0;//curָ��index�����һ����Ϊ0��λ��
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