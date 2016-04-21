/*
 *
 * 题目：给定一个链表，删除列表末尾的第n个节点，并返回其头部。
 * 例子：
 *        Given linked list: 1->2->3->4->5, and n = 2.
 *        After removing the second node from the end, the linked list becomes 1->2->3->5.
 * 思路：
 *      1.设计两个指针 p q
 *      2.使指针p指针q距离相差n
 *      3.p q 一块走，直到q到达终点
 * update:
 *       删除的时候需要p的前趋pre,所以令p q真实差距为n+1;则p即为上面3说的p的前趋
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode * p = head;
        ListNode * q = head;

        if(head == NULL)
            return head;

        int cnt = 1;
        while (q->next!=NULL && cnt != n)
        {
            q=q->next;
            cnt++;
        }

        if(q->next == NULL)
        {
            if(cnt == n)
                return head->next;
            else
                return head;
        }

        q=q->next;  //n+1  =>  p = pre

        while (q->next != NULL)
        {
            q=q->next;
            p=p->next;
        }
        p->next = p->next->next;

        return head;

    }
};
int main()
{
    ListNode * head = new ListNode(1);
    ListNode * l1 = new ListNode(2);
    ListNode * l2 = new ListNode(3);
    ListNode * l3 = new ListNode(4);
    ListNode * l4 = new ListNode(5);
    head->next = l1;
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    Solution sl;
    sl.removeNthFromEnd(head,2);
    delete head;
    delete l1;
    delete l2;
    delete l3;
    delete l4;
    return 0;
}