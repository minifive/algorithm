//有两种音乐一种长度为A，一种长度为B，各x首和y首
//现需要组成一个长度为k的歌单，问有多少种组合方法
#include <iostream>
using namespace std;
long long  C(int x, int y){

	if (y == 0 || y == x)
		return 1;
	long long temp1 = 1;

	for (int i = x; i > x - y; i--){
		temp1 *= i;
		temp1 %= 1000000007;
	}
	long long temp2 = 1;
	for (int i = y; i > 0; i--){
		temp2 *= i;
	}

	long long temp = temp1 / temp2;
	return temp % 1000000007;
}

int mai2n(){
	int k;
	int a, x, b, y;
	cin >> k;
	cin >> a >> x >> b >> y;
	long long result = 0;
	if (a == 0 && b == 0){
		cout << 0;
		return 0;
	}
	if (a == 0 && b != 0)
	{
		for (int i = 0; i <= k / b; i++){
			if (b*i == k&&i <= y){
				result += C(y, i);
			}
		}
		cout << result;
		return 0;
	}
	if (a != 0 && b == 0)
	{
		for (int i = 0; i <= k / a; i++){
			if (a*i == k&&i <= x){
				result += C(x, i);
			}
		}
		cout << result;
		return 0;
	}


	for (int i = x; i >= 0; i--)
	{
		int temp = k - i*a;
		if (temp == 0){
			result += C(x, i);
			result %= 1000000007;
			continue;
		}
		if (temp >= 0 && temp%b == 0){
			result += C(x, i)*C(y, temp / b);
			result %= 1000000007;
		}
	}

	cout << result;
	return 0;

}