#include <iostream>
#include <deque>
#include <vector>

using namespace std;


/**
 * Definition for binary tree
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

 void levelOrder(TreeNode *node, std::vector<vector<int> > &v, int level)
 {
 	if(node == NULL)
 		return;
 	if(v.empty() || level > v.size() - 1)
 		v.push_back(vector<int>());

 	v[level].push_back(node->val);

 	levelOrder(node->left, v, level + 1);
 	levelOrder(node->right, v, level + 1);
 }

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
    	std::vector<vector<int> > v;
    	::levelOrder(root, v, 0);

    	return v;
    	        
    }
};


