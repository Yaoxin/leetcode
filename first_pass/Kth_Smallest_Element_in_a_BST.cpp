#include <iostream>
#include <stack>

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
	//非递归中序遍历
    int kthSmallest(TreeNode* root, int k) {
    	stack<TreeNode *> my_stack;
    	int rank = 1;
    	while(root || !my_stack.empty())
    	{
    		while(root)
    		{
    			my_stack.push(root);
    			root = root->left;
    		}

    		if(!my_stack.empty())
    		{
    			root = my_stack.top()->right;
    			if(rank == k)
    			{
    				return my_stack.top()->val;
    			}
    			my_stack.pop();
    			rank++;
    		}
    	}

    	return INT_MAX;
    }

    //这个解法挺赞的，想出它的过程很刺激。
    int find(TreeNode *root, int &k)
    {
    	if(root)
    	{
    		int x = find(root->left, k);
    		if(k <= 0)
    		{
    			return x;
    		}
    		else
    		{
    			k--;
    			if(k == 0)
    			{
    				return root->val;
    			}
    			else
    			{
    				return find(root->right, k);
    			}
    		}
    	}
    	return INT_MAX;
    }

    //递归中序遍历
    int kthSmallest_k(TreeNode* root, int k) {
    	return find(root, k);
    }

};