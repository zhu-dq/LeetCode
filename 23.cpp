/*
	��Ŀ��23. Merge k Sorted Lists
	��⣺
		�����ǿ��������
		��priority_queue�ı�����Ƕ�����
		���Կ�������priority_queue��
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
		�ж����ȼ��ĺ���
	*/
	static bool compare(ListNode* a, ListNode* b)
	{
		return (!a || !b) ? (b!=nullptr) : (a->val > b->val);
	}
public:
	ListNode* mergeKLists(vector<ListNode*>& lists)
	{
		if (lists.empty())  //Ϊ��
			return nullptr;

		//��ʼ�����ȼ�����  <type , container , functional>
		priority_queue<ListNode*, vector<ListNode*>, bool(*)(ListNode*, ListNode*)> priori_queue(compare, lists);
		//ȡ���Ѷ�Ԫ��
		ListNode * head = priori_queue.top();
		priori_queue.pop();
		ListNode * pos = head;//pos ��λ�������β��
		if (!head)
			return head;
		if (head->next)//�����Ԫ�����������滹��Ԫ�أ��ͼ��뵽��ǰ����
			priori_queue.push(head->next);
		while (!priori_queue.empty())
		{
			//ȡ�Ѷ�Ԫ��
			ListNode * temp = priori_queue.top();
			priori_queue.pop();
			if (!temp)//�����ȼ����򣬶Ѷ�Ϊ�ռ�����Ϊ���𣬽���
				return head;
			
			pos->next = temp; //������Ԫ��
			pos = pos->next; //posָ��β��

			if (temp->next)//��Ԫ�����������滹��Ԫ�أ��ӵ���ǰ���С�
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