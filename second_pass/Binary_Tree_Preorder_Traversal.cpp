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
    vector<int> preorderTraversal_bak(TreeNode* root) {
        std::vector<int> result;
        preorder(root, result);
        return result;
    }

    void preorder(TreeNode * root, std::vector<int> &result) {
        if(root) {
            result.push_back(root->val);
            preorder(root->left, result);
            preorder(root->right, result);
        }
    }

    std::vector<int> preorderTraversal(TreeNode * root) {
        stack<TreeNode *> s;
        std::vector<int> result;
        if(root) {
            s.push(root);
        }
        while(!s.empty()) {
            TreeNode * temp =  s.top();
            result.push_back(temp->val);
            s.pop();
            if(temp->left) {
                s.push(temp->left);
            }
            if(temp->right) {
                s.push(temp->right);
            }
        }
        return result;
    }


};