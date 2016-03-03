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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	ListNode *Temp = NULL;
    	ListNode *pos1 = l1;
    	ListNode *pos2 = l2;
    	bool carrybit = false;
    	int val = 0;
    	ListNode *head = new ListNode(0);
    	ListNode *pre = head;

    	while(pos1 != NULL || pos2 != NULL)
    	{
    		if(pos1 != NULL && pos2 != NULL)
    		{
    			val = pos1->val + pos2->val;
    			pos1 = pos1->next;
    			pos2 = pos2->next;
    		}
    		else if(pos1 != NULL)
    		{
    			val = pos1->val;
    			pos1 = pos1->next;
    		}
    		else
    		{
    			val = pos2->val;
    			pos2 = pos2->next;
    		}

    		if(carrybit == true)
    		{
    			val += 1;
    			carrybit = false;
    		}
    		if(val > 9)
    		{
    			val -= 10;
    			carrybit = true;
    		}

    		Temp = new ListNode(val);
    		pre->next = Temp;
    		pre = Temp;
    	}

    	if(carrybit == true)
    	{
    		Temp = new ListNode(1);
    		pre->next = Temp;
    	}

    	return head->next;
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}