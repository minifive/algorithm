#include<iostream>
#include <vector>
using namespace std;

int InversePairs(vector<int>data){
	if (data.size()==0)
	{
		return 0;
	}

}

int guibing(vector<int>&data,int left,int right){

	if (data.size()==0||left>=right)
		return 0;
	int mid = ((right - left) / 2)+left;
	int leftIn=guibing(data, left, mid);
	int rightIn = guibing(data, mid + 1, right);
	int count = 0;
	//merge//
	vector<int>tmp;
	int leftindex = left;
	int rightindex = mid + 1;	
	while (leftindex<=mid&&rightindex<=right)
	{
		if (data[leftindex]<=data[rightindex])
		{
			tmp.push_back(data[leftindex]);
			leftindex++;
		}
		else{
			tmp.push_back(data[rightindex]);
			count += (mid-leftindex+1);
			rightindex++;
		}
	}
	while (rightindex<=right)
	{
		tmp.push_back(data[rightindex]);
		rightindex++;
	}
	while (leftindex<=mid)
	{
		tmp.push_back(data[leftindex]);
		leftindex++;
	}
	for (int i = 0; i < tmp.size();i++)
	{
		data[i+left] = tmp[i];
	}
	return count + leftIn + rightIn;
}
//void main()
//{
//	vector<int>a = { 4,9,3,3,3,0,2,7,7 };
//	int t = guibing(a, 0, a.size()-1);
//	cout << t<<endl;
//	for (int i = 0; i < a.size();i++)
//	{
//		cout << a[i];
//	}
//
//}