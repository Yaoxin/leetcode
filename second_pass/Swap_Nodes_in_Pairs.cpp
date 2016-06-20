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
    ListNode* swapPairs(ListNode* head) {
        ListNode * prev = head;
        ListNode * last = head != NULL ? head->next : NULL;
        ListNode * node = NULL; 
        while(prev && last) {
            ListNode * temp = last->next;
            last->next = prev;
            prev->next = temp;
            if(node != NULL) {
                node->next = last;
            } else {
                head = last;
            }
            node = prev;
            prev = temp;
            last = temp != NULL ? temp->next : NULL;
        }
        return head;        
    }
};

int main(int argc, char const *argv[])
{
    int a[] = {1, 2, 3, 4};
    std::vector<int> v(a, a + 4);
    Solution s = Solution();
    ListNode * head =  create_linklist(v);
    print_linklist(head);
    head =  s.swapPairs(head);
    print_linklist(head);
    return 0;
}