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

//
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    	ListNode *curA = headA;
    	ListNode *curB = headB;
    	int m = 0;
    	while(curA != NULL && curB != NULL)
    	{
    		curA = curA->next;
    		curB = curB->next;
    	}

    	if(curA != NULL)
    	{
    		while(curA)
    		{
    			m++;
    			curA = curA->next;
    		}
    		curA = headA;
    		curB = headB;
    		while(m--)
    		{
    			curA = curA->next;
    		}
    	}
    	else if(curB != NULL)
    	{
    		while(curB)
    		{
    			m++;
    			curB = curB->next;
    		}
    		curA = headA;
    		curB = headB;
    		while(m--)
    		{
    			curB = curB->next;
    		}
    	}
    	else
    	{
    		curA = headA;
    		curB = headB;
    	}

    	while(curA != NULL && curB != NULL)
    	{
    		if(curA == curB)
    			return curA;
    		curA = curA->next;
    		curB = curB->next;
    	}
    	return NULL;
        
    }

    //very beautiful solution in discuss
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
    	ListNode *p1 = headA;
	    ListNode *p2 = headB;

	    if (p1 == NULL || p2 == NULL) return NULL;
	    while (p1 != NULL && p2 != NULL && p1 != p2) {
	        p1 = p1->next;
	        p2 = p2->next;
	        if (p1 == p2) return p1;
	        if (p1 == NULL) p1 = headB;
	        if (p2 == NULL) p2 = headA;
	    }

	    return p1;
    }

};