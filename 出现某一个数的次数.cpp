#include<iostream>
using namespace std;
//就是从1到N中出现x的次数。如从1到12中出现1的有：1,10,11,12共5个1
/*
//参考https://www.nowcoder.com/questionTerminal/bd7f978302044eee894445e244c7eee6
二、X的数目 这里的  X∈[1,9] ，因为  X=0  不符合下列规律，需要单独计算。 首先要知道以下的规律： 从 1 至 10，在它们的个位数中，任意的 X 都出现了 1 次。 从 1 至 100，在它们的十位数中，任意的 X 都出现了 10 次。 从 1 至 1000，在它们的百位数中，任意的 X 都出现了 100 次。 依此类推，从 1 至  10 i ，在它们的左数第二位（右数第  i  位）中，任意的 X 都出现了  10 i−1  次。*/

int NumberOfXBetween1AndN_Solution(int n, int x){
	if (n < 0 || x>9 || x < 0)
		return 0;
	int high, low, curr, tmp, i = 1;
	high = n;
	int total = 0;
	while (high!=0)
	{
		high = n /( i * 10);//取第i位的高位
		tmp = n % (i * 10);//tmp为第i到0位
		curr = tmp / i;//curr为第i位
		low = tmp % i;//low为i位的低位
		if (curr == x)
		{
			total += high*i + low + 1;//如n=453,x=5，当i=10时，high=4，low=3,十位共有44个5
		}
		else if (curr < x)
		{
			total += high*i;
		}
		else{
			total += (high + 1)*i;
		}
		i = i * 10;

	}
	return total;
}
//void main()
//{
//	int t = NumberOfXBetween1AndN_Solution(100, 5);
//	cout << t;
//}