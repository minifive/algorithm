#include <iostream>
#include<vector>
using namespace std;
int minNumber(vector<int>rotateArray)//二分查找
{

	if (rotateArray.size() == 0)
		return 0;
	int left = 0;
	int right = rotateArray.size() - 1;
	while (left < right)
	{
		if (left == right - 1)
			return rotateArray[left]>rotateArray[right]?rotateArray[right]:rotateArray[left];
		int mid = left+(right - left) / 2;
		if (rotateArray[left] <= rotateArray[mid])//最小元素在mid右边
		{
			left = mid;
			continue;
		}
		if (rotateArray[left]>rotateArray[mid])
		{
			right = mid;
			continue;
		}
	}
}

//void main()
//{
//	vector<int>a = { 2,3, 4,5, 0, 2 };
//	cout << minNumber(a);
//}