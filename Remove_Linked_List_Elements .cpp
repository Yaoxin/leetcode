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
    ListNode* removeElements(ListNode* head, int val) {
    	ListNode *pre = NULL;
    	ListNode *cur = head;
    	ListNode *temp = NULL;
    	while(cur != NULL)
    	{
    		temp = cur->next;
    		if(cur->val == val)
    		{
    			if(pre == NULL)
    			{
    				head = temp;
    			}
    			else
    			{
    				pre->next = temp;
    			}
    		}
    		else
    		{
    			pre = cur;
    		}
    		cur = temp;
      	}

      	return head;
    }

    //second-level pointer
    ListNode* removeElements(ListNode* head, int val)
    {
    	ListNode **cur = &head;
    	ListNode *del_node = NULL;

    	while(*cur)
    	{
    		if((*cur)->val == val)
    		{
    			*del_node = *cur;
    			*cur = (*cur)->next;
    			delete del_node;
    		}
    		else
    		{
    			cur = &(*cur)->next;
    		}
    	}
    	return head;
    }
};