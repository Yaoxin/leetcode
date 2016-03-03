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
	int sum_help(vector<int> cur, int sum)
	{
		int num = 0;
		for (int i = 0; i < cur.size(); ++i)
		{
			num += cur[i];
		}
		if(num == sum)
		{
		    return 0;
		}
		else
		{
		    return -1;
		}
	}
	void dfs(TreeNode *root, vector<int> cur, int sum, vector<vector<int> > &out)
	{
		if(!root)
			return;
		cur.push_back(root->val);
		if(sum_help(cur, sum) == 0 && !root->left && !root->right)
		{
			out.push_back(cur);
		}
        
		if(root->left)
		{
			dfs(root->left, cur, sum, out);
		}
		if(root->right)
		{
			dfs(root->right, cur, sum, out);
		}	
	}

    vector<vector<int> > pathSum(TreeNode* root, int sum) {
    	vector<vector<int> > out;
    	vector<int> cur;
    	dfs(root, cur,sum, out);
    	return out;
    }
};