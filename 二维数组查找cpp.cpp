#include <iostream>
#include <vector>
using namespace std;

bool find(int target, vector<vector<int>>array)
{
	int rowcount = array.size();
	int colcount = array[0].size();
	int x = rowcount-1;
	int y = 0;
	while (1)
	{
		if (x<0||y>colcount-1)
			break;
		if (array[x][y] < target)
			y++;
		else if (array[x][y]>target)
			x--;
		else if (array[x][y] == target)
		{
			cout << x<< y;
			return true;
		}
	}
	return false;
}
//int main()
//{
//	int n = 1;
//	vector<vector<int>>a(4, vector<int>(4));
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			a[i][j] = n;
//			n++;
//		}
//	}
//	find(3, a);
//	return 0;
//}