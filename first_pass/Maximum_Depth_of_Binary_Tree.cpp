#include <iostream>
#include <algorithm>


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
public:
    int maxDepth(TreeNode *root) {
    	if(node == NULL)
    		return 0;
    	return max(maxDepth(root->left), maxDepth(root->right));
    }
};