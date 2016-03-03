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
    ListNode* rotateRight(ListNode* head, int k) {
    	ListNode *fast = head;
    	ListNode *slow = head;
        ListNode *temp = head;
        int n = 0;
        while(temp)
        {
            n++;
            temp = temp->next;
        }
        k %=n;
    	while(k > 0)
    	{
    		fast = fast->next;
            k--;
    	}
    	while(fast->next)
    	{
    		slow = slow->next;
    		fast = fast->next;
    	}
    	fast->next = head;
        head = slow->next;
        slow->next = NULL;
    	return head;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode e(5);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	ListNode *head = NULL;
	head = s.rotateRight(&a, 2);
	while(head)
	{
		cout << head->val << endl;
		head = head->next;
	}

	return 0;
}