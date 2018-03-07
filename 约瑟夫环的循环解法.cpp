#include<iostream>
using namespace std;

int LastRemaining_Solution(int n, int m)
{
	int *array = new int[n];
	for (int i = 0; i < n; i++)
		array[i] = 0;
	int steep = 0;
	int count = n;
	int j = -1;
	while (count > 0){
		j = (j + 1) % n;
		if (array[j] == 1){
			continue;
		}
		steep++;
		if (steep == m){
			count--;
			steep = 0;
			array[j] = 1;
		}
		
	}
	return j;
}

//int main()
//{
//	cout<<LastRemaining_Solution(5, 3)<<endl;
//}