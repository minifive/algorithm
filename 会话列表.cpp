#include<iostream>
#include<stack>
#include<set>
using namespace std;
stack<int> stk;
//���׵�һ�⣬�Ự�б�ÿ�ε���������б���
//˼·��ȫ��ѹջ���Ӻ���ǰ����
int mai6n(){
	int n, m;
	cin >> n;
	while (n--){
		cin >> m;
		while (m--){
			int temp;
			cin >> temp;
			stk.push(temp);
		}
		set<int> s;
		bool flag=true;
		while (!stk.empty()){
			if (s.find(stk.top()) == s.end())
			{
				if (flag){
					flag = false;
				}
				else{
					cout << " ";
				}
				cout << stk.top();
				s.insert(stk.top());
			}
			stk.pop();
		}
		cout << endl;
	}

	return 0;
}