#include "common/help.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)
        {
            return NULL;
        }
        ListNode * fast = head;
        ListNode * slow = head;
        ListNode * prev = NULL;
        while(fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        TreeNode * node = new TreeNode(slow->val);
        if(prev != NULL) {
            prev->next = NULL;
        } else {
            head = NULL;
        }
        node->left = sortedListToBST(head);
        node->right = sortedListToBST(slow->next);
        return node;        
    }
};

int main(int argc, char const *argv[])
{
    int a[] = {0};
    std::vector<int> v(a, a + 1);
    Solution s = Solution();
    TreeNode* node = s.sortedListToBST(create_linklist(v));
    print_binary_tree(node);

    return 0;
}