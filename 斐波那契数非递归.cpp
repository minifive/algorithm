#include<iostream>
using namespace std;
int Fibnacci(int n)//�ݹ飬��ʱ
{
	if (n == 0 || n == 1)
		return n;
	else
		return Fibnacci(n - 1) + Fibnacci(n - 2);
}

int fibonacci(int n)//����
{
	if (n <= 1)
		return n;
	int f = 0; int g = 1;
	while (n--)
	{
		g += f; //f��ʾf(n-2)  f(n)=f(n-1)+f(n-2):g=g+f
		f = g-f;  //��ʾԭ��+f֮ǰ��g
	}
	return f;
}
//
//void main()
//{
//	cout<<Fibnacci(6)<<"-- "<<fibonacci(6);
//}