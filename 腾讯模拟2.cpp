//С���кܶ�öӲ�ң���ֵΪ2��k�η���������2�����ж�������Ϸ�ʽ��ϳ���ֵΪn
//���  DFS,��k������ȣ����ͳ���n�����
#include<iostream>
#include <stack>
#include <vector>
#include <set>

using namespace std;

set<vector<int>>buffer;//��������
int getcount(int deepth, int sum, int target, vector<int>res){
	if (sum > target)
		return 0;
	if (sum == target){
		vector<int>temp;
		for (int i = 0; i < res.size(); i++)
		{
			temp.push_back(res[i]);
			cout << res[i] << " ";
		}
		cout << endl;
		buffer.insert(temp);
		return 1;
	}
	for (int i = deepth; i < target * 2; i++)//sum<target
	{
		sum += pow(2, (i / 2));//��i/2��ָ���ɷֱ�ö�ٳ�1 1 2 2 4 4 8 8...
		res.push_back(pow(2, (i / 2)));
		getcount(i + 1, sum, target, res);
		res.pop_back();
		sum -= pow(2, (i / 2));
	}
	return 0;
}
int main(){
	int n;

	cin >> n;
	vector<int>tmp;
	getcount(0, 0, n, tmp);
	cout << buffer.size();


	return  0;
}
