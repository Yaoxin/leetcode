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
    //one pass, and no test. haha~
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) {
            return head;
        }
        ListNode * odd = head;
        ListNode * even = head->next;
        while(even && even->next) {
            ListNode * temp = even->next;
            even->next = temp->next;
            temp->next = odd->next;
            odd->next = temp;
            odd = temp;
            even = even->next;
        }
        return head;
    }
};