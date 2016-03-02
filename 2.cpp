/*
	题意：
		两数反序存储在两个单向链表上，两个链表相加，将结果存在一个单向链表里面并返回

	例如：
		Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
		Output: 7 -> 0 -> 8

	思路：
		1.注意进位
		2.注意量表头尾节点的设置
		3.考虑连个链表不等长时情况（别忘了进位）
		4.总体上就是两个指针指向两个数组，边遍历边相加，把结果存到新的链表里。
*/

#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr)
			return l2;
		if (l2 == nullptr)
			return l1;
		int up = 0;
		ListNode* p1 = l1;
		ListNode* p2 = l2;

		ListNode* result = new ListNode(0);
		ListNode* p = result;

		while (p1 != nullptr && p2 != nullptr)
		{
			int value = (p1->val + p2->val + up) % 10;
			up = (p1->val + p2->val + up) / 10;
			ListNode* curLN = new ListNode(value);
			p->next = curLN;
			p = p->next;
			p1 = p1->next;
			p2 = p2->next;
		}
		while (p1 != nullptr)
		{
			int value = (p1->val + up) % 10;
			up = (p1->val + up) / 10;
			ListNode* curLN = new ListNode(value);
			p->next = curLN;
			p = p->next;
			p1 = p1->next;
		}
		while (p2 != nullptr)
		{
			int value = (p2->val + up) % 10;
			up = (p2->val + up) / 10;
			ListNode* curLN = new ListNode(value);
			p->next = curLN;
			p = p->next;
			p2 = p2->next;
		}
		if (up != 0)
		{
			ListNode* curLN = new ListNode(up);
			p->next = curLN;
			p = p->next;
		}
		p->next = nullptr;
		return result->next;
	}
};