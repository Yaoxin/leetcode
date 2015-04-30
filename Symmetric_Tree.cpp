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

void help(TreeNode * node, int level, vector<vector<int> > &v)
{
	
	
	level = level + 1;
	if(node->left)
		help(node->left, level, v);
	if(node->right)
		help(node->right, level, v);
}


class Solution {
public:
    bool isSymmetric(TreeNode* root) {
    	if(root == NULL)
    		return false;
    	int level = 0;
    	std::vector<vector<int> > v;
    	help(root, level, v);

        
    }
};