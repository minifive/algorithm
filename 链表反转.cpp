#include<iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	ListNode* Head = NULL;
	ListNode* curp = NULL;
	if (pHead1 == NULL)
		return pHead2;
	if (pHead2 == NULL)
		return pHead1;
	while (1){
		if (pHead1 == NULL){
			curp->next = pHead2;
			break;
		}
		if (pHead2 == NULL){
			curp ->next= pHead1;
			break;
		}
		if (pHead1->val > pHead2->val){
			ListNode* tmp = new ListNode(pHead2->val);
			
			if (Head == NULL)
			{
				Head = curp=tmp;
			}
			else{
				curp->next = tmp;
				curp = curp->next;
			}
			pHead2 = pHead2->next;
		}
		else if (pHead1->val <= pHead2->val){
			ListNode* tmp = new ListNode(pHead1->val);
			if (Head == NULL)
			{
				Head = curp = tmp;
			}
			else{
				curp->next = tmp;
				curp = curp->next;
			}
			pHead1 = pHead1->next;
		}

	}
	return Head;
}
//int main()
//{
//	ListNode* pHeaad = new ListNode(1);
//	ListNode*p1 = new ListNode(2);
//	ListNode *p2 = new ListNode(3);
//	pHeaad->next = p1;
//	p1->next = p2;
//	pHeaad = Merge(pHeaad,NULL);
//
//	while (pHeaad != NULL)
//	{
//		cout << pHeaad->val<<" ";
//		pHeaad = pHeaad->next;
//	}
//	return 0;
//}