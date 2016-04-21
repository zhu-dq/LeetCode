/*
	题目：合并两个有序（a<=b<=c）链表
	思路：见代码 easy

*/
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
	{
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;
		ListNode * head;
		if (l1->val > l2->val)
		{
			head = l2;
			l2 = l2->next;
		}
		else
		{
			head = l1;
			l1 = l1->next;
		}
		ListNode * p = head;
		while (l1!=NULL && l2!=NULL)
		{
			if (l1->val > l2->val)
			{
				p->next = l2;
				p = p->next;
				l2 = l2->next;
			}
			else
			{
				p->next = l1;
				p = p->next;
				l1 = l1->next;
			}
		}

		if (l1 != NULL)
			p->next = l1;
		else if (l2 != NULL)
		{
			p->next = l2;
		}

		return head;
	}
};

int main()
{
	Solution sl;
	ListNode * l1 = new ListNode(5);
	ListNode * l2 = new ListNode(1);
	ListNode * l3 = new ListNode(2);
	ListNode * l4 = new ListNode(4);
	l2->next = l3;
	l3->next = l4;
	sl.mergeTwoLists(l1,l2);
	system("pause");
	delete l1;
	delete l2;
	delete l3;
	delete l4;
}