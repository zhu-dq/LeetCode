/*
	���⣺
		��������洢���������������ϣ�����������ӣ����������һ�������������沢����

	���磺
		Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
		Output: 7 -> 0 -> 8

	˼·��
		1.ע���λ
		2.ע������ͷβ�ڵ������
		3.�������������ȳ�ʱ����������˽�λ��
		4.�����Ͼ�������ָ��ָ���������飬�߱�������ӣ��ѽ���浽�µ������
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