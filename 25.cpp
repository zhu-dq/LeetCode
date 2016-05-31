/*
	题目:
		25. Reverse Nodes in k-Group
		 For example,
			Given this linked list: 1->2->3->4->5
			
			For k = 2, you should return: 2->1->4->3->5
			
			For k = 3, you should return: 3->2->1->4->5 
	思路：
		1.从当前位置，顺序找k个元素(如果不够k个就结束).
		2. 对这k个元素利用头插法逆序排列。
		3. 逆序排列后与原来的串连接上。pre->next = k_start;k_end->next = tail;
		...[pre][...k...][tail]...
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

	ListNode * reverseK(ListNode * &start, ListNode * end, ListNode * &pre, ListNode * tail)
	{

		ListNode * p = start;
		ListNode * lastone = start;
		ListNode * temp_head = nullptr;
		while (p != tail)
		{
			ListNode * temp_p = p;
			p = p->next;
			ListNode * temp = temp_head;
			temp_head = temp_p;
			temp_p->next = temp;
		}
		if (pre)
			pre->next = temp_head;
		else
			start = temp_head;
		lastone->next = tail;
		return lastone;
	}

	ListNode* reverseKGroup(ListNode* head, int k) {

		if (k <= 1 || !head)
			return head;
		ListNode * pre = nullptr;
		ListNode * start = head;
		ListNode * p2 = head;
		int cnt = 1;
		while (cnt<k && p2->next)
		{
			p2 = p2->next;
			cnt++;
		}
		if (cnt != k)
			return head;
		ListNode * end = p2;
		if (!end)
			return head;
		ListNode * tail = p2->next;
		//swap
		p2 = reverseK(head,end,pre,tail);
		while(true)
		{
			pre = p2;
			start = p2->next;
			cnt = 0;
			while (cnt<k && p2->next)
			{
				p2 = p2->next;
				cnt++;
			}
			if (cnt != k)
				return head;
			ListNode * end = p2;
			if (!end)
				return head;
			ListNode * tail = p2->next;
			//swap
			p2 = reverseK(start,end,pre,tail);
		}
		return head;
	}
};
int main()
{
	Solution sl;
	ListNode * l1 = new ListNode(1);
	ListNode * l2 = new ListNode(2);
	ListNode * l3 = new ListNode(3);
	ListNode * l4 = new ListNode(4);
	ListNode * l5 = new ListNode(5);
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;
	ListNode * result =sl.reverseKGroup(l1,3);
	while (result)
	{
		cout << result->val << endl;
		result = result->next;
	}
	system("pause");
	return 0;
}