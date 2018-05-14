#include<iostream>
#include<vector>
using namespace std;
/*��Ŀ����  ����һ����������a1,a2,...,an ����a1=0����a2��ʼÿ������������ǰ�������1���1 ������еĺ�Ϊs�����������n��s�������ж�����
*/
struct node 
{
	int deep;
	int val;
	int sum;
	node(int d,int v,int s){
		deep = d; val = v; sum = s;
	}
};
int dfs(int *a, int s,int n){
	vector<node>buffer;
	buffer.push_back(node(1,0,0));
	int count = 0;
	while (!buffer.empty())
	{
		node temp = buffer.back();
		buffer.pop_back();
		if (temp.deep==n){
			if (temp.sum== s)
				count++;
		}
		if (temp.deep + 1 <= n){
			buffer.push_back(node(temp.deep + 1, temp.val + 1, temp.sum + temp.val + 1));
			buffer.push_back(node(temp.deep + 1, temp.val - 1, temp.sum + temp.val - 1));
		}
	}
	return count;
}

//int main(){
//	int n,s;
//	cin >> n >> s;
//	int *a = new int[n];
//	a[0] = 0;
//	cout<<dfs(a, s, n);
//}