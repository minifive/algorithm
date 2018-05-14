#include <iostream>
#include <vector>
//���б��Եڶ���
//��֪n����ׯ����һ������ÿ��������a[i]��������ݣ���ţţ�չ��˵�i����ׯ����ݣ�������ȡ��i-1��i+1����ׯ����ݣ���������չ��������
using namespace std;

int dfs(vector<pair<int, int>>stackbuffer, int n, int *a){
	
	pair<int, int>temp = stackbuffer.back();
	int i = temp.first;
	int val = temp.second;
	if (i + 2 >= n)
		return val;
	int Max = 0;
	for (int j = i + 2; j < n; j++){
		stackbuffer.push_back(make_pair(j, val + a[j]));
		int temp = dfs(stackbuffer, n, a);
		if (temp > Max)
			Max = temp;
		stackbuffer.pop_back();
	}
	return Max;

}

//int main(){
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n;
//		cin >> n;
//
//		int *a = new int[n];
//		for (int i = 0; i < n; i++)
//			cin >> a[i];
//		vector<pair<int, int>>stackbuffer;
//
//		int val = 0;
//
//
//		stackbuffer.push_back(make_pair(0, val + a[0]));
//		int n1 = dfs(stackbuffer, n - 1, a);
//		stackbuffer.clear();
//		stackbuffer.push_back(make_pair(1, val + a[1]));
//		int n2 = dfs(stackbuffer, n, a);
//		cout << (n1 > n2 ? n1 : n2);
//		
//	}
//}