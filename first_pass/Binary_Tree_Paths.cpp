#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

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
	void dfs(TreeNode * root, string cur, vector<string> &out)
	{
		if (!root)
		{
			return;
		}
		char sz[16] = {0};

		cur.length() == 0?sprintf(sz, "%d", root->val):sprintf(sz, "->%d", root->val);
		cur.append(sz);
		cout << cur << endl;
		if(root->left == NULL && root->right == NULL)
		{
			out.push_back(cur);
		}
		dfs(root->left, cur, out);
		dfs(root->right,cur, out);
	}
    vector<string> binaryTreePaths(TreeNode* root) {
    	vector<string> out;
    	string temp;
    	dfs(root, temp, out);
    	return out;
    }
};

int main(int argc, char const *argv[])
{
	TreeNode a(1);
	Solution s;
	vector<string> out = s.binaryTreePaths(&a);
	for (int i = 0; i < out.size(); ++i)
	{
		cout << out[i] << endl;
	}

	return 0;
}