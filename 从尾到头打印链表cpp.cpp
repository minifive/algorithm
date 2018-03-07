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

vector<int> printList(ListNode *head)
{
	vector<int> tmp;
	while (head!=NULL)
	{
		tmp.push_back(head->val);
		head = head->next;
	}
	vector<int>tt;
	int t = tmp.size();
	for (int i = 0; i < t; i++)
	{
		tt.push_back(tmp.back());
		tmp.pop_back();
	}
	return tt;
}

//void main()
//{
//	ListNode*head=new ListNode(1);
//	ListNode*valua=new ListNode(2);
//	ListNode*three = new ListNode(3);
//	valua->next = three;
//	head->next = valua;
//	vector<int>tmp = printList(head);
//	for (int i = 0; i < tmp.size(); i++)
//		cout << tmp[i];
//}
