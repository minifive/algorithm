#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include<map>
using namespace std;

//网易实习笔试第三题  给一个9宫格魔方的初始状态和结束状态，
//每次可以选择一个正方形子魔方旋转90 180 或270度，问最少经过几次旋转达最终状态
//思路 广度优先遍历加map记录已经遍历过的点
map<int, int>v;//v中第二个int表示从其实点到第一个int旋转的次数
map<int, int>::iterator it;
int rotate(int m, int n) {//n:0~11
	int s[10];
	for (int i = 9; i > 0; --i) {
		s[i] = m % 10;
		m /= 10;
	}

	int x = n / 3;//x 表示的子魔方 
	int y = n % 3;//y表示旋转的角度
	int start = (x < 2) ? x + 1 : x + 2;

	int temp;
	switch (y) {
	case 0:
		// rotate 90
		temp = s[start];
		s[start] = s[start + 3];
		s[start + 3] = s[start + 4];
		s[start + 4] = s[start + 1];
		s[start + 1] = temp;
		break;
	case 1:
		// rotate 180
		swap(s[start], s[start + 4]);
		swap(s[start + 1], s[start + 3]);
		break;
	case 2:
		temp = s[start];
		s[start] = s[start + 1];
		s[start + 1] = s[start + 4];
		s[start + 4] = s[start + 3];
		s[start + 3] = temp;
		break;
	}

	int ret = 0;
	for (int i = 1; i < 10; ++i) {
		ret *= 10;
		ret += s[i];
	}
	return ret;
}

int main() {

	int n;
	cin >> n;
	while (n--) {
		queue<int> q;

		int b = 0, e = 0;
		int temp;
		for (int i = 0; i < 9; ++i) {
			cin >> temp;
			b *= 10;
			b += temp;//将3*3矩阵转换为9位int数字
		}
		cout << b << endl;
		for (int i = 0; i < 9; ++i) {
			cin >> temp;
			e *= 10;
			e += temp;
		}
		cout << e << endl;
		bool succ = false;
		v[b] = 0;//设置起始状态旋转0次
		q.push(b);//借助队列 广度优先遍历
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int i = 0; i < 12; ++i) {
				int y = rotate(x, i);
				it = v.find(y);
				if (it != v.end())//证明前面已经遍历过这种情况
					continue;
				else {
					v[y] = v[x] + 1;
					if (y == e) {
						cout << v[y] << endl;
						succ = true;
						break;
					}
					q.push(y);
				}
			}
			if (!succ)
				cout << -1 << endl;
		}
	}



	return 0;
}
