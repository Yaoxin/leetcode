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
    bool isPalindrome(ListNode* head) {
    	if(head == NULL)
    		return true;
    	ListNode * slow = head;
    	ListNode * fast = head;

    	while(fast->next && fast->next->next)
    	{
    		slow = slow->next;
    		fast = fast->next->next;
    	}

    	ListNode *node = slow->next;
    	ListNode * temp = NULL;
    	ListNode * newer = NULL;
    	while(node)
    	{
    		temp = node->next;
    		node->next = newer;
    		newer = node;
    		node = temp;
    	}

    	slow = head;
    	while(newer)
    	{
    		if(slow->val != newer->val)
    			return false;
    		slow = slow->next;
    		newer = newer->next;

    	}
    	return true;        
    }
};


int main(int argc, char const *argv[])
{
	ListNode a(3);
	ListNode b(2);
	ListNode c(2);
	ListNode d(3);
	a.next = &b;
	b.next = &c;
	c.next = &d;

	Solution s;
	bool out = s.isPalindrome(&a);
	cout << out << endl;

	return 0;
}