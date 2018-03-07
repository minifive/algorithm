#include<iostream>
#include<vector>
using namespace std;
//本程序构建小跟堆

void HeapAdjust(vector<int> &a, int i, int size)//i为当前节点的数组下标,数组坐标从0开始
{
	int lchild = 2 * i+1;
	int rchild = 2 * i+2;
	int minm = i; //max记录最大值所在位置
	if (i < size / 2)//结束条件。i为数组下标
	{
		if (lchild < size&&a[lchild] < a[minm])//左孩子比当前节点小
			minm = lchild;
		if (rchild < size&&a[rchild] < a[minm])//找到最小的节点
			minm = rchild;
		if (minm != i)
		{
			swap(a[i], a[minm]);//如果父节点不是最小，则父节点下移
			HeapAdjust(a, minm, size);
		}
	}
	else
		return;
}

void BuildHeap(vector<int> &a, int size)
{
	int i;
	for (int i = size / 2-1; i >= 0; i--)//对数组中所有有子节点的节点从后往前调整
	{
		HeapAdjust(a, i, size);
	}
}

vector<int> HeapSort(vector<int> &a, int size)
{
	int i;
	BuildHeap(a, size);
	for (i = size-1; i >=0; i--)
	{
		swap(a[0], a[i]);
		HeapAdjust(a, 0, i);
	}
	return a;
}

//void main()
//{
//	vector<int >tmp= { 1, 44, 233, 4, 55};
//	tmp=HeapSort(tmp,5);
//	for (int i = 0; i <5 ; i++)
//	{
//		cout << tmp.back()<<" ";
//		tmp.pop_back();
//	}
//}