#include<iostream>
#include <algorithm>
#include <stack>
/*给定整数n和m, 将1到n的这n个整数按字典序排列之后, 求其中的第m个数。
对于n=11, m=4, 按字典序排列依次为1, 10, 11, 2, 3, 4, 5, 6, 7, 8, 9, 因此第4个数是2. */
using namespace std;
struct tireTree{
	int  val;
	tireTree *child[10];
	tireTree(){
		val = 0;
		for (int i = 0; i < 10;i++)
		{
			child[i] = NULL;
		}
	}
};
tireTree* builtTree(int n){
	tireTree *root = new tireTree;
	
	for (int i = 1; i <= n; i++){
		int temp = i;
		int count =0;
		while (temp >= 1){
			temp = temp / 10;
			count++;
		}
		int valu = 0;
		int t = i;
		tireTree*cur = root;
		while (count){
			int x = pow(10, count - 1);
			int j = t / x;
			valu = valu * 10 + j;
			t = t%x;
			if (cur->child[j]==NULL){
				cur->child[j] = new tireTree;
				cur->child[j]->val =valu;
				//cout << "bulid a tree"<<valu<<"\n";
			}
			else
				cur = cur->child[j];
			count--;
		}
	
	}

	return root;
}
int sourchM(tireTree* root,int m){
	int count = -1;
	stack<tireTree*>Mystk;
	
	Mystk.push(root);
	while (!Mystk.empty())
	{
		tireTree*cur = Mystk.top();
		Mystk.pop();
		count++;
		if (count == m)
			return cur->val;
		for (int j = 9; j >=0; j--){
			if (cur->child[j] != NULL){
				Mystk.push(cur->child[j]);
			}
		}
	}
	
	return -1;
}

//int main(){
//	int n, m;
//	cin >> n >> m;
//	tireTree*root=builtTree(n);
//	int res = sourchM(root, m);
//	if (res!=-1)
//	{
//		cout << "find m:" << res<<endl;
//	}
//}