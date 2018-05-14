#include<iostream>
#include <stack>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* Reverse(ListNode* head){//����ת
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

ListNode *findMiddle(ListNode*head){//����ָ�����м�ڵ�
	ListNode* quick=head;
	ListNode* slow = head;
	while (quick->next!=NULL&&quick->next->next!=NULL)
	{
		quick = quick->next->next;
		slow = slow->next;
	}

	return slow;

}

ListNode* hasCycle(ListNode*head){//�ж��Ƿ񻷣����з��ػ�����ʼ�ڵ�
	if (head == NULL || head->next == NULL)
		return NULL;
	ListNode*fast = head;
	ListNode*slow = head;
	while (fast != NULL&&fast->next != NULL){//��ͨ������ָ���ж��Ƿ���ڻ�
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			break;
	}
	if (fast == NULL || fast->next == NULL)
		return NULL;

	/*������ڻ���������ɾ��ǰһ��Node��next�����ʣ�µľ��ǻ������*/
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