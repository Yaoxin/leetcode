#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	//采用合并排序
	ListNode *merge(ListNode *headA, ListNode *headB)
	{
		ListNode dummy(0);
		ListNode *cur = &dummy;
		while(headA && headB)
		{
			if(headA->val < headB->val)
			{
				cur->next = headA;
				cur = cur->next;
				headA = headA->next;
			}
			else
			{
				cur->next = headB;
				cur = cur->next;
				headB = headB->next;
			}
		}

		if(headA)
		{
			cur->next = headA;
		}

		if(headB)
		{
			cur->next = headB;
		}

		return dummy.next;

	}

	//fast-slow pointer
    ListNode* sortList(ListNode* head) {
    	if(!head || !head->next)
    		return head;
    	ListNode *slow = head;
    	ListNode *fast = head;
    	while(fast->next && fast->next->next)
    	{
    		fast = fast->next->next;
    		slow = slow->next;
    	}
    	ListNode *headb = slow->next;
    	slow->next = NULL;

    	return merge(sortList(head), sortList(headb));
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	ListNode a(1);
	ListNode b(5);
	ListNode c(2);
	ListNode d(6);
	ListNode e(3);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	ListNode *head = NULL;
	head = s.sortList(&a);
	while(head)
	{
		cout << head->val << endl;
		head = head->next;
	}

	return 0;
}