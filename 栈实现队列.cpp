#include<iostream>
#include <stack>
using namespace std;

stack<int> stack1;
stack<int>stack2;
void push(int node){
	if (stack2.size() != 0)
	{
		int len = stack2.size();
		for (int i = 0; i < len; i++)
		{
			int tmp = stack2.top();
			stack1.push(tmp);
			stack2.pop();
		}		
	}
	stack1.push(node);
}

int pop(){
	int len = stack1.size();
	if (len != 0)
	{
		for (int i = 0; i < len;i++)
		{
			int tmp = stack1.top();
			stack2.push(tmp);
			stack1.pop();
		}
	}
	int t = stack2.top();
	stack2.pop();
	return t;
}

//void main()
//{
//	push(1);
//	push(2);
//	int t = pop();
//	cout << t;
//}