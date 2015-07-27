#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution {
public:
    //1、采用递归去解
    //2、层序遍历
    bool isSymmetric(TreeNode* root) {
        return root?isSymmetric(root->left, root->right):true;
    }

    bool isSymmetric(TreeNode * left, TreeNode *right)
    {
        if(!left && !right)
            return true;
        if(!left || !right)
            return false;
        return left->val == right->val && isSymmetric(left->left, right->right) && \
            isSymmetric(left->right, right->left);
    }
};



