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
	ListNode *reverseSubNode(ListNode *prev, ListNode *next, ListNode *start, int k)
	{
		ListNode *ret = start;
		ListNode *Temp = NULL;
		while(k--)
		{
			Temp = start->next;
			start->next = next;
			next = start;
			start = Temp;
		}
		if(prev)
			prev->next = next;
		return ret;
	}

    ListNode* reverseKGroup(ListNode* head, int k) {
    	if(head == NULL || k <= 0)
    		return head;
    	ListNode *prev = NULL;
    	ListNode *next = head;
    	ListNode *start = head;
    	ListNode *node = head;
    	int i = k -1;
    	while(node)
    	{
    		if(i == k - 1)
    		{
    			start = node;
    		}
    		if(i== 0)
    		{
    			next = node->next;
    			if(!prev)
    				head = node;
    			node = node->next;
    			prev = reverseSubNode(prev, next, start, k);
    			i = k - 1;
    			continue;
    		}
    		node = node->next;
    		i--;	
    	}

    	return head;
    }
};

int main(int argc, char const *argv[])
{
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode e(5);

	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;

	Solution s;

	ListNode* out = s.reverseKGroup(&a, 2);
	while(out)
	{
		cout << out->val << " ";
		out = out->next;
	}
	cout << endl;


	return 0;
}