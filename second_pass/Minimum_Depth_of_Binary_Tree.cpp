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
    int minDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }
        if(!root->left && !root->right) {
            return 1;
        }

        int left = minDepth(root->left) + 1;
        left = (left == 1) ? INT_MAX : left;
        int right = minDepth(root->right) + 1;
        right = (right == 1) ? INT_MAX : right;
        return std::min(left, right);
    }
};

