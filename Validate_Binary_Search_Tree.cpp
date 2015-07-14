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
	/* this solution have bugs.72/74
	bool isValidBST(TreeNode *root, int num, bool direction)
	{
		if(!root)
			return true;
		bool ret = true;
		if(root->left)
		{
			if(direction)
			{
				ret = (root->left->val < root->val && root->left->val > num)?ret:false;
			}
			else
			{
				ret = (root->left->val < root->val && root->left->val < num)?ret:false;
			}
		}

		if(root->right)
		{
			if(direction)
			{
				ret = (root->right->val > root->val && root->right->val > num)?ret:false;
			}
			else
			{
				ret = (root->right->val > root->val && root->right->val < num)?ret:false;
			}
		}

		return ret && isValidBST(root->left, root->val, false) && isValidBST(root->right, root->val, true);
	}
    bool isValidBST(TreeNode* root) {
    	if(!root)
    		return true;
    	bool ret = true;
    	if(root->left)
    		ret = (root->left->val < root->val)?ret:false;
    	if(root->right)
    		ret = (root->right->val > root->val)?ret:false;

    	return ret && isValidBST(root->left, root->val, false) && isValidBST(root->right, root->val, true);
    }
    */

    void travelNode(TreeNode *root, vector<TreeNode *> &v)
    {
    	if(!root)
    		return;
    	travelNode(root->left, v);
    	v.push_back(root);
    	travelNode(root->right, v);
    }

    bool isValidBST(TreeNode *root)
    {
    	if(!root)
    		return true;
    	vector<TreeNode *> v;
    	travelNode(root, v);
    	for (int i = 1; i < v.size(); ++i)
    	{
    		if(v[i]->val <= v[i-1]->val)
    			return false;
    	}
    	return true;
    }
};

int main(int argc, char const *argv[])
{
	TreeNode a(10);
	TreeNode b(5);
	TreeNode c(15);
	TreeNode d(6);
	TreeNode e(20);
	a.left = &b;
	a.right = &c;
	c.left = &d;
	c.right = &e;

	Solution s;
	bool out = s.isValidBST(&a);

	cout << out <<endl;

	return 0;
}