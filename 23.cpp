/*
	题目：23. Merge k Sorted Lists
	题解：
		核心是考察堆排序
		而priority_queue的背后就是堆排序。
		所以可以利用priority_queue。
*/

#include <vector>
#include <iostream>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
	/*
		判断优先级的函数
	*/
	static bool compare(ListNode* a, ListNode* b)
	{
		return (!a || !b) ? (b!=nullptr) : (a->val > b->val);
	}
public:
	ListNode* mergeKLists(vector<ListNode*>& lists)
	{
		if (lists.empty())  //为空
			return nullptr;

		//初始化优先级队列  <type , container , functional>
		priority_queue<ListNode*, vector<ListNode*>, bool(*)(ListNode*, ListNode*)> priori_queue(compare, lists);
		//取出堆顶元素
		ListNode * head = priori_queue.top();
		priori_queue.pop();
		ListNode * pos = head;//pos 定位新链表的尾部
		if (!head)
			return head;
		if (head->next)//如果此元素所在连后面还有元素，就加入到当前堆中
			priori_queue.push(head->next);
		while (!priori_queue.empty())
		{
			//取堆顶元素
			ListNode * temp = priori_queue.top();
			priori_queue.pop();
			if (!temp)//按优先级规则，堆顶为空即所有为空吗，结束
				return head;
			
			pos->next = temp; //链接新元素
			pos = pos->next; //pos指向尾部

			if (temp->next)//此元素所在连后面还有元素，加到当前堆中。
				priori_queue.push(temp->next);
		}
		return head;
	}
};

int main()
{
	Solution sl;
	ListNode * l1 = new ListNode(0);
	ListNode * l2 = new ListNode(2);
	ListNode * l3 = new ListNode(5);
	l1->next = l2;
	l2->next = l3;
	vector<ListNode*> v_list;
	v_list.push_back(l1);
	ListNode * result = sl.mergeKLists(v_list);
	while (result)
	{
		cout << result->val << endl; 
		result = result->next; 
	}
	system("pause");
	return 0;
}