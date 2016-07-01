#include "common/help.h"
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
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> v;
        if(!root) {
            return v;
        }
        std::stack<TreeNode *> s;
        TreeNode * T = root;
        while(T || !s.empty()) {
            while(T) {
                s.push(T);
                T = T->left;
            }
            T = s.top();
            s.pop();
            v.push_back(T->val);
            T = T->right;
        }
        return v;
    }
};