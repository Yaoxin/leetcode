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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = nums.size();
        TreeNode * root = NULL;
        if(len > 0) {
            build(nums, root, 0, len - 1);
        }
        return root;        
    }

    void build(std::vector<int> &nums, TreeNode * &node, int left, int right) {
        if(left > right) {
            return;
        }
        int mid = (left + right)/2;
        node = new TreeNode(nums[mid]);
        build(nums, node->left, left, mid - 1);
        build(nums, node->right, mid + 1, right);
    }
};