#include<iostream>
#include<stack>
#include<set>
using namespace std;
stack<int> stk;
//网易第一题，会话列表，每次点击出现在列表顶。
//思路：全部压栈，从后往前处理。
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