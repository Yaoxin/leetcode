/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    ListNode *deleteDuplicates(ListNode *head) {
    	if(head == NULL)
    		return NULL;
    	ListNode * prev = head;
    	ListNode * cur = head->next;

    	while(cur != NULL)
    	{
    		if(cur->val == prev->val)
    		{
    			prev->next = cur->next;
    		}
    		else
    		{
    			prev = cur;
    		}
    		cur = cur->next;
    	}

    	return head;
    }
};


int main(int argc, char const *argv[])
{
	Solution s;
	ListNode * head = NULL;
	s.deleteDuplicates(head);

	return 0;
}