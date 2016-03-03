#include <iostream>
#include <vector>
#include <algorithm>

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
	//利用先序遍历和level收集层的数据。
	void build(TreeNode *root, vector<vector<int> > &R, int level)
	{
		if(!root)
			return;
		if(R.size() < level + 1)
		{
			R.resize(level + 1);
		}
		R[level].push_back(root->val);
		build(root->left, R, level + 1);
		build(root->right, R, level + 1);
	}

    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    	vector<vector<int> > R;
    	build(root, R, 0);
    	for (int i = 1; i < R.size(); i+=2)
    	{
    		reverse(R[i].begin(), R[i].end());
    	}

    	return R;
    }
};

