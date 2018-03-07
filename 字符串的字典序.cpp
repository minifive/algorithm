#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
//输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
/**
     * 2、字典序排列算法
     *
     * 可参考解析： http://www.cnblogs.com/pmars/archive/2013/12/04/3458289.html  （感谢作者）
     *
     * 一个全排列可看做一个字符串，字符串可有前缀、后缀。
     * 生成给定全排列的下一个排列.所谓一个的下一个就是这一个与下一个之间没有其他的。
     * 这就要求这一个与下一个有尽可能长的共同前缀，也即变化限制在尽可能短的后缀上。
     *
     * [例]839647521是1--9的排列。1—9的排列最前面的是123456789，最后面的987654321，
     * 从右向左扫描若都是增的，就到了987654321，也就没有下一个了。否则找出第一次出现下降的位置。
     *
     * 【例】 如何得到346987521的下一个
     * 1，从尾部往前找第一个P(i-1) < P(i)的位置
     * 3 4 6 <- 9 <- 8 <- 7 <- 5 <- 2 <- 1
     * 最终找到6是第一个变小的数字，记录下6的位置i-1
     *
     * 2，从i位置往后找到最后一个大于6的数
     * 3 4 6 -> 9 -> 8 -> 7 5 2 1
     * 最终找到7的位置，记录位置为m
     *
     * 3，交换位置i-1和m的值
     * 3 4 7 9 8 6 5 2 1
     * 4，倒序i位置后的所有数据
     * 3 4 7 1 2 5 6 8 9
     * 则347125689为346987521的下一个排列
     *
     * @param str
     * @return
     */
void reverse(string &str, int index);
vector<string> Permutation(string str) {
	vector<string> res;
	if (str.length() == 0)
		return res;
	sort(str.begin(),str.end());
	//char* chars;
	//strcpy(chars, str.c_str());
	res.push_back(str);
	while (1)
	{
		int leftindex = str.length() - 1;
		while (leftindex >= 1 && str[leftindex - 1] >= str[leftindex])//从后向前找到第一个减小的数
			leftindex--;
		if (leftindex==0) break;//当从后往前非递减则表示已经完全逆序，此时结束循环
		int rightindex = leftindex;//从leftindex开始往后查找最后一个比str[leftindex]大的数
		while (rightindex < str.length() && str[rightindex] >str[leftindex - 1])
			rightindex++;
		swap(str[leftindex-1],str[rightindex-1]);
		reverse(str, leftindex);

		res.push_back(str);
	}
	return res;
}

void reverse(string &str, int index)
{
	if (str.length() == 0||str.length()<=index)
		return;
	for (int i = 0; i < (str.length() - index) / 2; i++)
	{
		int m = index + i;
		int n = str.length() - i - 1;
		if (m <= n)
		{
			swap(str[m], str[n]);
		}
	}
}

//void main()
//{
//	string s = "abc";
//	vector<string>tmp = Permutation(s);
//	for (int i = 0; i < tmp.size(); i++)
//	{
//		cout << tmp[i] << " ";
//	}
//}