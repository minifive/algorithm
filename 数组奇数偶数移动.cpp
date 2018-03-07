#include <iostream>
#include <vector>
using namespace std;
void reOrderArray(vector<int> &array) {
	int n = array.size();
	int count = 0;
	vector<int>tmp;
	for (int i = 0; i < n; i++)
	{
		tmp.push_back(array[i]);
		if (array[i] & 1 == 1)
			count++;
	}
	int l = 0;
	for (int j = 0; j < n; j++)
	{
		if (tmp[j] & 1 == 1)//Êý
		{
			array[l] = tmp[j];
			l++;
		}
		else
		{
			array[count] = tmp[j];
			count++;
		}

	}
}
//int main()
//{
//	vector<int> t = { 1, 2, 3, 4, 5,3 };
//	reOrderArray(t);
//	for (int i = 0; i < t.size(); i++)
//		cout << t[i];
//	return 0;
//}