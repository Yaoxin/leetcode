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
    ListNode* swapPairs(ListNode* head) {
    	if(head == NULL)
    	{
    		return head;
    	}

    	if(head->next == NULL)
    	{
    		return head;
    	}

    	ListNode * one = head;
    	ListNode * two = head->next;
    	ListNode * temp = NULL;

    	ListNode *new_head = two;
        ListNode * pre = NULL;


    	while(one != NULL && two != NULL)
    	{
    		temp = two->next;
    		two->next = one;
    		one->next = temp;
            if(pre != NULL)
            {
                pre->next = two;
            }
            pre = one;
    		one = temp;
    		if(temp != NULL)
    		{
    			two = temp->next;
    		}
    	}

    	return new_head; 
    }
};


int main(int argc, char const *argv[])
{
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);

	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = NULL;

	Solution s;
	ListNode * test =  s.swapPairs(&a);
	while(test != NULL)
	{
		cout << " " << test->val ;
		test = test->next;
	}
	cout << endl;
	return 0;
}
