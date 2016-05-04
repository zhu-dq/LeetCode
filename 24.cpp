/*
	题目：24. Swap Nodes in Pairs
		Given a linked list, swap every two adjacent nodes and return its head.

		For example,
		Given 1->2->3->4, you should return the list as 2->1->4->3.

		Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
	思路：
		因为不让交换值，所以只能交换node
		->{prev1}->{node1}->{node2}->{next2}->
		交换：
			prev1->next = node2;
			node2->next = node1;
			node1->next = next2;

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
	ListNode* swapPairs(ListNode* head) {

		if (!head || !head->next)
			return head;

		ListNode * prev1 = head;
		ListNode * node1 = head;
		ListNode * node2 = head->next;
		ListNode * next2 = node2->next;
		//prev1 == head
		head = node2;
		head->next = node1;
		node1->next = next2;

		while (next2)
		{
			node1 = next2;
			node2 = node1->next;
			if (!node2)
				break;
			next2 = node2->next;
			//swap
			prev1->next = node2;
			node2->next = node1;
			node1->next = next2;
			prev1 = node1;
		}
		return head;
	}
};