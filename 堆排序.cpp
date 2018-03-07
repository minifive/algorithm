#include<iostream>
#include<vector>
using namespace std;
//�����򹹽�С����

void HeapAdjust(vector<int> &a, int i, int size)//iΪ��ǰ�ڵ�������±�,���������0��ʼ
{
	int lchild = 2 * i+1;
	int rchild = 2 * i+2;
	int minm = i; //max��¼���ֵ����λ��
	if (i < size / 2)//����������iΪ�����±�
	{
		if (lchild < size&&a[lchild] < a[minm])//���ӱȵ�ǰ�ڵ�С
			minm = lchild;
		if (rchild < size&&a[rchild] < a[minm])//�ҵ���С�Ľڵ�
			minm = rchild;
		if (minm != i)
		{
			swap(a[i], a[minm]);//������ڵ㲻����С���򸸽ڵ�����
			HeapAdjust(a, minm, size);
		}
	}
	else
		return;
}

void BuildHeap(vector<int> &a, int size)
{
	int i;
	for (int i = size / 2-1; i >= 0; i--)//���������������ӽڵ�Ľڵ�Ӻ���ǰ����
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