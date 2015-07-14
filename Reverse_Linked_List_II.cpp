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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
    	if(head == NULL || m >= n)
    		return head;
    	ListNode * m_node = head;
    	ListNode * Temp = head;
    	ListNode * prev = NULL;
    	ListNode * next = NULL;
    	ListNode * node = NULL;
    	int i = 1;
    	while(Temp)
    	{
    		if(i == m)
    		{
    			prev = node;
    			m_node = Temp;
    		}
    			
    		if(i == n)
    		{
    			next   = Temp->next;
    		}
    		node = Temp;	
    		Temp = Temp->next;
    		i++;
    	}

    	i = n - m + 1;
    	while(i--)
    	{
    		node = m_node->next;
    		m_node->next = next;
    		next = m_node;
    		m_node = node;
    	}

    	if(prev)
    		prev->next = next;
    	else
    		head = next;
    	return head;
    }
};


int main(int argc, char const *argv[])
{
	ListNode a(1);
	ListNode b(2);
	//ListNode c(3);
	//ListNode d(4);
	//ListNode e(5);
	a.next = &b;
	//b.next = &c;
	//c.next = &d;
	//d.next = &e;

	Solution s;
	ListNode* out =  s.reverseBetween(&a, 1, 2);

	while(out)
	{
		cout << out->val << " ";
		out = out->next;
	}
	cout << endl;

	return 0;
}