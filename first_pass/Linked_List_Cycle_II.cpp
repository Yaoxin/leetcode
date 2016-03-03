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
	//颇具技巧性
    ListNode *detectCycle(ListNode *head) {
    	if(head == NULL)
    		return NULL;
    	ListNode *slow = head;
    	ListNode *fast = head;
    	while(fast->next != NULL && fast->next->next != NULL)
    	{
    		slow = slow->next;
    		fast = fast->next->next;
    		if(slow == fast)
    		{
    			fast = head;
    			while(slow != fast)
    			{
    				slow = slow->next;
    				fast = fast->next;
    			}
    			return slow;
    		}
    	}

    	return NULL;
    }
};


