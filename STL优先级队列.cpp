#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
struct cmp
{
	bool operator()(int a, int b){
		return a < b;
	}
};
//int main(){
//	priority_queue<int,vector<int>,cmp>pq;
//	for (int i = 0; i < 10;i++)
//	{
//		pq.push(rand() % 20);
//	}
//	while (!pq.empty())
//	{
//		cout << pq.top()<<" ";
//		pq.pop();
//	}
//}