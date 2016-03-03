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
	TreeNode * buildTree_help(vector<int> &preorder,int pre_start,int pre_end, vector<int> &inorder, int in_start, int in_end)
	{
		if(pre_end < pre_start || in_end < in_start)
			return NULL;
		TreeNode *root = new TreeNode(preorder[pre_start]);
		int mid = 0;
		int i = 0;
		for(mid =in_start; mid <= in_end; mid++)
		{
			if(inorder[mid] == preorder[pre_start])
			{
				break;
			}
			i++;
		}
		root->left = buildTree_help(preorder, pre_start + 1, pre_start + i , inorder, in_start, mid - 1);
		root->right = buildTree_help(preorder, pre_start + i + 1, pre_end, inorder, mid + 1, in_end);

		return root;
	}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    	if(preorder.size() == 0 || inorder.size() == 0)
    		return NULL;
 		return buildTree_help(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() -1);
    }

    void TravelTreeNode(TreeNode *root)
    {
    	if(!root)
    		return;
    	
    	TravelTreeNode(root->left);
    	cout << root->val << endl;
    	TravelTreeNode(root->right);
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	int a[] = {1,2,4,5,3};
	int b[] = {4, 2, 5, 1, 3};
	vector<int> pre(a, a + 5);
	vector<int> inor(b, b + 5);
	TreeNode * root = s.buildTree(pre, inor);
	s.TravelTreeNode(root);


	return 0;
}