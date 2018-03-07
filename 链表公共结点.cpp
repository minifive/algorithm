#include<iostream>
using namespace std;
//输入两个链表，找出它们的第一个公共结点。
//思路，第一个公共节点之后所有的节点均相同。因为是单链表
//先让长的走两个链表的长度差 然后一起走
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
	int count1 = 0;
	int count2 = 0;
	ListNode*index1 = pHead1;
	ListNode*index2 = pHead2;
	while(index1!=NULL)
	{
		count1++;
		index1 = index1->next;
	}
	while (index2 != NULL)
	{
		count2++;
		index2 = index2->next;
	}
	if (count1>count2)
	{
		int i = count1 - count2;
		while (i!=0)
		{
			pHead1 = pHead1->next;
		}
		
	}
	else{
		int i = count2 - count1;
		while (i != 0)
		{
			pHead2 = pHead2->next;
		}
	}

	index1 = pHead1;
	index2 = pHead2;
	while (index1 != index2&&index1 != NULL&&index2 != NULL)
	{
		index1 = index1->next;
		index2 = index2->next;
	}
	return index1;
}