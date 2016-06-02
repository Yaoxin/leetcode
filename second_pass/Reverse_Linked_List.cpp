/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 #include "common/help.h"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
        {
            return head;
        }

        ListNode * node1 = head;
        ListNode * node2 = head->next;
        while(node1 && node2){
            ListNode * temp = node2->next;
            node2->next = node1;
            if(node1->next == node2){
                node1->next = NULL;
            }
            node1 = node2;
            node2 = temp;
        }
        return node1;
    }
};

int main(int argc, char const *argv[])
{
    int a[] = {1, 2, 3, 4, 5};
    ListNode* head = create_linklist(std::vector<int>(a, a+5));
    Solution s;
    ListNode * new_head =  s.reverseList(head);
    print_linklist(new_head);
    return 0;
}