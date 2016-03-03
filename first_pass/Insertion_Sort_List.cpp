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
    ListNode* insertionSortList(ListNode* head) {
    	ListNode dummy(INT_MIN);
    	ListNode *temp = &dummy;
    	ListNode *next = NULL;
    	while(head)
    	{
    		temp = &dummy;
    		next = head->next;
    		while(temp->next)
    		{
    			if(temp->next->val >= head->val)
    			{
    				head->next = temp->next;
    				temp->next = head;
    				break;
    			}
    			temp = temp->next;
    		}

    		if(temp->next == NULL)
    		{
    			temp->next = head;
    			head->next = NULL;
    		}

       		head = next;
    	}

    	return dummy.next;
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
	head = s.insertionSortList(&a);
	while(head)
	{
		cout << head->val << endl;
		head = head->next;
	}

	return 0;
}