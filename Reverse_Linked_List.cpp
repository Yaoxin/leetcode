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
    ListNode* reverseList(ListNode* head) {
    	ListNode *new_head = NULL;
    	ListNode * temp = NULL;
    	while(head != NULL)
    	{
    		temp = head->next;
    		head->next = new_head;
    		new_head = head;
    		head = temp;
    	}

    	return new_head;
    }
};