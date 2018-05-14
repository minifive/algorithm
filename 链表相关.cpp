#include<iostream>
#include <stack>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* Reverse(ListNode* head){//链表反转
	if (head == NULL || head->next == NULL)
		return head;
	ListNode*cur = head;
	ListNode*temp;
	ListNode*pre=NULL;
	while (cur!= NULL)
	{
		temp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = temp;
	}
	return pre;
}

ListNode *findMiddle(ListNode*head){//快慢指针找中间节点
	ListNode* quick=head;
	ListNode* slow = head;
	while (quick->next!=NULL&&quick->next->next!=NULL)
	{
		quick = quick->next->next;
		slow = slow->next;
	}

	return slow;

}

ListNode* hasCycle(ListNode*head){//判断是否环，若有返回环的起始节点
	if (head == NULL || head->next == NULL)
		return NULL;
	ListNode*fast = head;
	ListNode*slow = head;
	while (fast != NULL&&fast->next != NULL){//先通过快慢指针判定是否存在环
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			break;
	}
	if (fast == NULL || fast->next == NULL)
		return NULL;

	/*如果存在环，则依次删除前一个Node的next，最后剩下的就是环的起点*/
	ListNode * pre = head;
	ListNode*cur = head->next;
	while (cur != NULL){
		if (pre == cur)
			return pre;
		pre->next = NULL;
		pre = cur;
		cur = cur->next;
	}
	return pre;
}




//int main(){
//	ListNode *head = new ListNode(1);
//	ListNode *head1 = new ListNode(2);
//	ListNode *head2 = new ListNode(3);
//	ListNode *head3 = new ListNode(4);
//	ListNode *head4 = new ListNode(5);
//	head->next = head1;
//	head1->next = head2;
//	head2->next = head3;
//	head3->next = head4;
//	head = Reverse(head);
//	ListNode* cur = head;
//	while (cur != NULL){
//		cout << cur->val << " ";
//		cur = cur->next;
//	}
//
//	ListNode* middle = findMiddle(head);
//	cout << endl << middle->val << endl;
//}