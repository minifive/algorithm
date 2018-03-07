#include<iostream>
#include <map>
using namespace std;
//输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head
struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
	}
};
RandomListNode* Clone(RandomListNode* pHead)
{
	map<RandomListNode*, RandomListNode*>table;
	map<RandomListNode*, RandomListNode*>::iterator i_terator;
	RandomListNode *cpyHead=NULL;
	if (pHead == NULL)
		return cpyHead;
	cpyHead = new RandomListNode(pHead->label);
	
	RandomListNode *cH=cpyHead;
	RandomListNode *H = pHead;
	table.insert(pair<RandomListNode*, RandomListNode*>(H, cH));
	while (H->next!= NULL)
	{
		RandomListNode *tmp = new RandomListNode(H->next->label);
		cH->next = tmp;
		table.insert(pair<RandomListNode*, RandomListNode*>(H->next, cH->next));
		H = H->next;
		cH = cH->next;
	}
	cH = cpyHead;
	H = pHead;
	while (H != NULL)
	{
		if (H->random != NULL)
		{
			i_terator = table.find(H->random);
			cH->random = i_terator->second;
		}
		cH = cH->next;
		H = H->next;
	}
	return cpyHead;

}
//void main()
//{
//	RandomListNode*Head = new RandomListNode(1);
//	RandomListNode *tmp=Clone(Head);
//	cout << tmp->label;
//}