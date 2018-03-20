#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include<map>
using namespace std;

//����ʵϰ���Ե�����  ��һ��9����ħ���ĳ�ʼ״̬�ͽ���״̬��
//ÿ�ο���ѡ��һ����������ħ����ת90 180 ��270�ȣ������پ���������ת������״̬
//˼· ������ȱ�����map��¼�Ѿ��������ĵ�
map<int, int>v;//v�еڶ���int��ʾ����ʵ�㵽��һ��int��ת�Ĵ���
map<int, int>::iterator it;
int rotate(int m, int n) {//n:0~11
	int s[10];
	for (int i = 9; i > 0; --i) {
		s[i] = m % 10;
		m /= 10;
	}

	int x = n / 3;//x ��ʾ����ħ�� 
	int y = n % 3;//y��ʾ��ת�ĽǶ�
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
			b += temp;//��3*3����ת��Ϊ9λint����
		}
		cout << b << endl;
		for (int i = 0; i < 9; ++i) {
			cin >> temp;
			e *= 10;
			e += temp;
		}
		cout << e << endl;
		bool succ = false;
		v[b] = 0;//������ʼ״̬��ת0��
		q.push(b);//�������� ������ȱ���
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int i = 0; i < 12; ++i) {
				int y = rotate(x, i);
				it = v.find(y);
				if (it != v.end())//֤��ǰ���Ѿ��������������
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
