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
	//quick sort
    ListNode* sortList(ListNode* head) {
        
    }

    //merge sort
    merge_sort(ListNode *root)
    {
    	ListNode *fast = root, slow = root;
    	




    	while(fast )
    	{
    		fast = root->next;
    	}
    }


    ListNode *sortList(ListNode *head)
    {
    	if(head == NULL || head->next == NULL)
    		return head;
    	merge_sort(head);

    }
};