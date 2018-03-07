#include<iostream>
#include<vector>
using namespace std;
//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0
//思路一：排序取中间的数 O(nlgn)
//思路2：遍历数组时保存两个值：一是数组中一个数字，一是次数。遍历下一个数字时，若它与之前保存的数字相同，则次数加1，否则次数减1；若次数为0，则保存下一个数字，并将次数置为1。遍历结束后，所保存的数字即为所求。然后再判断它是否符合条件即可。
int MoreThanHalfNum_Solution(vector<int> numbers) {
	if (numbers.size()==0)
	{
		return 0;
	}

	int result = numbers[0];
	int times = 0;

	for (int i = 0; i < numbers.size(); i++)//思路为用目标数替换其余所有数
	{
		if (times == 0)//times为0时将当前元素设置成result并重新计数
		{
			result = numbers[i];
			times = 1;
		}
		else if (numbers[i] == result)//相同则计数加1
		{
			times++;
		}
		else{//不同则计数减一
			times--;
		}
	}
	//此时result存放的即为目标数
	times = 0;
	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == result)
			times++;
	}
	return times > numbers.size() / 2 ? result : 0;

}