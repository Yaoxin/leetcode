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
      ListNode(int x) : val(x),next(NULL){}
  };


class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
    	if(n == 0 || head == NULL)
    		return NULL;

    	ListNode * node = head;
    	int m = 1;
    	while(node->next != NULL)
    	{
    		node = node->next;
    		m++;
    	}

    	m = m -n - 1;
    	node = head;
        if(m == -1 )
        {
            return node->next;
        }
    	while(node->next != 0 && m--)
    	{
    		node = node->next;
    	} 
    	node->next = node->next->next;

    	return head;            
    }


};


class Solution_bak {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode * dummy=new ListNode(0);
        dummy->next = head;
        ListNode * quick=dummy, * slow=dummy;
        while(n-->=0){
            quick = quick->next;
        }
        while(quick){
            slow=slow->next;
            quick=quick->next;
        }
        slow->next = (slow->next)->next;
        return dummy->next;
    }
};



int main(int argc, char const *argv[])
{
	Solution s;
	ListNode * head = (ListNode *)new char(sizeof(ListNode));
	head->val = 1;
	head->next = NULL;
	ListNode * cur = NULL;
	ListNode * temp = head;
    /*
	for(int i = 0; i < 4; i++)
	{
		cur = (ListNode *)new char(sizeof(ListNode));
		cur->val = i + 2;
		cur->next = NULL;
		temp->next = cur;
		temp = cur;

	}
    */


	ListNode *out =  s.removeNthFromEnd(head, 1);
    //ListNode *out = head;
	while(out->next != NULL)
	{
		cout << out->val << endl;
        out = out->next;
	}
	cout << out->val << endl;


	return 0;
}