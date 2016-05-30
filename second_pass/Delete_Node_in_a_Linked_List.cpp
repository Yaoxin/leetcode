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
    void deleteNode(ListNode* node) {
        if (node == NULL)
        {
            return;
        }

        if(node->next != NULL)
        {
            node->val = node->next->val;
            node->next = node->next->next;
        }
        else
        {
            node->next = NULL;
        }
    }
};