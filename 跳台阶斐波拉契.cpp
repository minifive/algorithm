#include <iostream>
#include<vector>
using namespace std;

int jumpFloor(int number)
{
	if (number < 3)
		return number;
	int *a = new int[number + 1];
	a[0] = 0; a[1] = 1; a[2] = 2;
	for (int i = 3; i <= number;i++)
	{
		a[i] = a[i - 1] + a[i - 2];
	}
	return a[number];
}

int main()
{
	cout << jumpFloor(4);
}