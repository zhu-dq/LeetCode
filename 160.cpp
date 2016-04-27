/*
 * 题目：求两个链表的公共后缀
 *      Write a program to find the node at which the intersection of two singly linked lists begins.

        For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3
 *  思路：
 *      求headA 与headB的串的长度的差值k
 *      ABCDEFGHIGKLMN
 *      |--K--|ASDDFFF
 *      串长的先走k个，一个一块走，边走边比较
 */

#include <iostream>
#include <algorithm>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            if(!headA || !headB)
                return NULL;
            int a_size = 0;
            int b_size = 0;
            ListNode * pa = headA;
            ListNode * pb = headB;
            while (pa)
            {
                pa=pa->next;
                a_size++;
            }
            while (pb)
            {
                pb=pb->next;
                b_size++;
            }
            int k = 0;
            if(a_size<b_size)
            {
                pa = headB;
                pb = headA;
                k = b_size - a_size;
            } else
            {
                pa = headA;
                pb = headB;
                k = a_size-b_size;
            }
            while (k!=0)
            {
                pa=pa->next;
                k--;
            }
            ListNode *pos = NULL;
            while(pa && pb)
            {
                if(pa->val != pb->val)
                {
                    pos = NULL;
                } else if(!pos)
                {
                    pos = pa;
                }
                pa = pa->next;
                pb = pb->next;
            }
            return pos;
    }
};
int main()
{
    ListNode * l1 = new ListNode(1);
    ListNode * l2 = new ListNode(3);
    ListNode * l3 = new ListNode(5);
    ListNode * l4 = new ListNode(7);
    ListNode * l5 = new ListNode(9);
    ListNode * l6 = new ListNode(11);
    ListNode * l7 = new ListNode(13);
    ListNode * l8 = new ListNode(15);
    ListNode * l9 = new ListNode(17);
    ListNode * l10 = new ListNode(19);
    ListNode * l11 = new ListNode(21);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;
    l6->next = l7;
    l7->next = l8;
    l8->next = l9;
    l9->next = l10;
    l10->next = l11;
    ListNode * l12 = new ListNode(21);
    Solution sl;
    ListNode * ll= sl.getIntersectionNode(l1,l12);
    while (ll)
    {
        cout<<ll->val<<endl;
        ll=ll->next;
    }

    return 0;
}