#include <iostream>
#include <vector>

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
    ListNode* partition(ListNode* head, int x) {
    	ListNode dummy1(0);
    	ListNode dummy2(0);
    	ListNode *less = &dummy1;
    	ListNode *big = &dummy2;
    	while(head)
    	{
    		if(head->val < x)
    		{
    			less->next = head;
    			less = less->next;
    		}
    		else
    		{
    			big->next = head;
    			big = big->next;
    		}
    		head = head->next;
    	}
    	less->next = dummy2.next;
        big->next = NULL;
    	return dummy1.next;
    }
};


int main(int argc, char const *argv[])
{
	ListNode a(1);
	ListNode b(4);
	ListNode c(3);
	ListNode d(2);
	ListNode e(5);
	ListNode f(2);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;

	Solution s;
	ListNode *l;
	l = s.partition(&a, 3);
    
	while(l)
	{
		cout << l->val << endl;
		l = l->next;
	}
    
	return 0;
}