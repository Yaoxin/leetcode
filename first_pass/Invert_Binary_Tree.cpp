#include <iostream>

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
    TreeNode* invertTree(TreeNode* root) {
    	if(!root)
    		return NULL;
    	invertTree(root->left);
    	invertTree(root->right);
    	TreeNode *node = root->left;
    	root->left = root->right;
    	root->right = node;
        return root;
    }
};