#include<iostream>
#include <stack>
using namespace std;
stack<int>mdata;
stack<int>minm;
void mpush(int value) {
	mdata.push(value);
	if (minm.size()==0){
		minm.push(value);
	}
	else if (minm.top() >= value){
		minm.push(value);
	}
}
void pop() {
	int data = mdata.top();
	int minmm = minm.top();
	if (data == minmm)
		minm.pop();
	mdata.pop();
}
int top() {
	int tmp = mdata.top();
	return tmp;
}
int smin() {
	int tmp = minm.top();
	return tmp;
}

//void main()
//{
//	mpush(1);
//	int t = smin();
//	cout << t;
//}