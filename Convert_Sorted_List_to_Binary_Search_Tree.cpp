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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;     
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //slow-fast pointer

    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return new TreeNode(head->val);
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *pre =  NULL;

        while(fast->next != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }

        TreeNode *root = new TreeNode(slow->val);
        root->right = sortedListToBST(slow->next);
        if(pre)
        {
            pre->next = NULL;
            root->left = sortedListToBST(head);
        }
        return root;
    }
    //travel
    void InorderTraverse(TreeNode * T)
    {
         if(T == NULL)
         {
              return ;
         }
         InorderTraverse(T->left);
         cout << T->val << endl;
         InorderTraverse(T->right);
    }

};

int main(int argc, char const *argv[])
{
    Solution s;
    ListNode *head = new ListNode(1);
    ListNode *temp = head;
    for(int i = 2; i < 10; i++)
    {
        temp->next = new ListNode(i);
        temp = temp->next;
    }
    TreeNode *out =  s.sortedListToBST(head);

    cout << "over" << endl;
    s.InorderTraverse(out);

    return 0;
}