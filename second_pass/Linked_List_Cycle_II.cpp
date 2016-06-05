#include "common/help.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode * m = this->getMeetPoint(head);
        if(m == NULL)
        {
            return NULL;
        } 
        ListNode *node1 = head;
        ListNode *node2 = m;
        while(m != head)
        {
            m = m->next;
            head = head->next;
        }
        return m;        
    }
private:
    ListNode * getMeetPoint(ListNode * head) {
        ListNode * fast = head;
        ListNode * slow = head;
        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow){
                break;
            }
        }

        if(fast == NULL || fast->next == NULL)
        {
            return NULL;
        }

        return fast;
    }
};